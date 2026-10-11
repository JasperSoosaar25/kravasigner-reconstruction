// Offline behavioral tests: no calls to KravaSign and no real key material.
import Foundation
#if canImport(FoundationNetworking)
import FoundationNetworking
#endif

final class FixtureProtocol: URLProtocol {
	static var requests: [URLRequest] = []
	static var failKey = false
	static var invalidKey = false
	override class func canInit(with request: URLRequest) -> Bool { true }
	override class func canonicalRequest(for request: URLRequest) -> URLRequest { request }
	override func startLoading() {
		Self.requests.append(request)
		let isKey = request.url!.path.hasSuffix(".pem")
		if isKey && Self.failKey {
			client?.urlProtocol(self, didFailWithError: URLError(.notConnectedToInternet))
			return
		}
		let data = isKey && Self.invalidKey ? Data([0xff, 0xfe]) : Data((isKey ? "fixture-key" : "fixture-certificate").utf8)
		let response = HTTPURLResponse(url: request.url!, statusCode: 200, httpVersion: "HTTP/1.1", headerFields: nil)!
		client?.urlProtocol(self, didReceive: response, cacheStoragePolicy: .notAllowed)
		client?.urlProtocol(self, didLoad: data)
		client?.urlProtocolDidFinishLoading(self)
	}
	override func stopLoading() {}
}

struct TestFailure: Error { let message: String }
func require(_ condition: @autoclosure () -> Bool, _ message: String) throws {
	if !condition() { throw TestFailure(message: message) }
}

@main struct TLSAssetDownloaderTests {
	static func main() async throws {
		let config = URLSessionConfiguration.ephemeral
		config.protocolClasses = [FixtureProtocol.self]
		let session = URLSession(configuration: config)
		defer { session.invalidateAndCancel() }
		var writes: [(String, String)] = []
		func download() async throws {
			try await TLSAssetDownloader.download(
				certificateURL: "https://fixture.invalid/local.crt",
				privateKeyURL: "https://fixture.invalid/local.pem", session: session
			) { writes.append(($0, $1)) }
		}
		try await download()
		try require(writes.map { $0.1 } == ["server.crt", "server.pem"], "Wrong write order/names")
		try require(writes.map { $0.0 } == ["fixture-certificate", "fixture-key"], "Content differs")
		try require(FixtureProtocol.requests.map { $0.url!.path } == ["/local.crt", "/local.pem"], "Wrong request order")
		try require(FixtureProtocol.requests.allSatisfy { $0.timeoutInterval == 60 && $0.cachePolicy == .reloadIgnoringLocalCacheData }, "Request policy differs")
		print("PASS successful paired download and exact request policy")
		writes = []; FixtureProtocol.failKey = true
		do { try await download(); throw TestFailure(message: "Download error swallowed") }
		catch is URLError {}
		try require(writes.isEmpty, "Partial files written after network failure")
		print("PASS second download failure leaves files untouched")
		FixtureProtocol.failKey = false; FixtureProtocol.invalidKey = true
		do { try await download(); throw TestFailure(message: "Invalid UTF-8 accepted") }
		catch is CocoaError {}
		try require(writes.isEmpty, "Files written with invalid UTF-8")
		print("PASS invalid UTF-8 leaves files untouched")
		FixtureProtocol.invalidKey = false
		var writeCount = 0
		do {
			try await TLSAssetDownloader.download(
				certificateURL: "https://fixture.invalid/local.crt",
				privateKeyURL: "https://fixture.invalid/local.pem", session: session
			) { _, _ in writeCount += 1; throw CocoaError(.fileWriteNoPermission) }
			throw TestFailure(message: "Write error swallowed")
		} catch is CocoaError {}
		try require(writeCount == 1, "Continued after failing write")
		print("PASS filesystem failure propagates")
		print("4 TLS behavior tests passed")
	}
}
