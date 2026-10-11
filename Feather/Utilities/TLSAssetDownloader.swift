// Reconstructed from KravaSigner 2.8.2 ARM64 routines 0x10003cc60–0x10003d424.
// This is independently written Swift, not recovered developer source.
import Foundation
#if canImport(FoundationNetworking)
import FoundationNetworking
#endif

enum TLSAssetDownloader {
	static func download(
		certificateURL: String,
		privateKeyURL: String,
		session: URLSession = .shared,
		write: (String, String) throws -> Void
	) async throws {
		guard let certificateURL = URL(string: certificateURL),
			let privateKeyURL = URL(string: privateKeyURL) else {
			throw URLError(.badURL)
		}
		let certificateRequest = URLRequest(
			url: certificateURL, cachePolicy: .reloadIgnoringLocalCacheData, timeoutInterval: 60
		)
		let privateKeyRequest = URLRequest(
			url: privateKeyURL, cachePolicy: .reloadIgnoringLocalCacheData, timeoutInterval: 60
		)
		let (certificateData, _) = try await session.data(for: certificateRequest)
		let (privateKeyData, _) = try await session.data(for: privateKeyRequest)
		guard let certificate = String(data: certificateData, encoding: .utf8),
			let privateKey = String(data: privateKeyData, encoding: .utf8) else {
			throw CocoaError(.fileReadInapplicableStringEncoding)
		}
		// Binary writes certificate first, then key; HTTP status/PEM validation was
		// not observed. Keep that behavior visible instead of claiming validation.
		try write(certificate, "server.crt")
		try write(privateKey, "server.pem")
	}
}
