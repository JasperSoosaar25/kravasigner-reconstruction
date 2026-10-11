//
//  ServerView.swift
//  Feather
//
//  Created by samara on 6.05.2025.
//

import SwiftUI
import NimbleJSON
import NimbleViews

// MARK: - View
struct ServerView: View {
	@AppStorage("Feather.ipFix") private var _ipFix: Bool = false
	@AppStorage("Feather.serverMethod") private var _serverMethod: Int = 0
	private let _serverMethods: [String] = [.localized("Fully Local"), .localized("Semi Local")]
	
	private let _dataService = NBFetchService()
	
	// MARK: Body
	var body: some View {
		Group {
			Section {
				Picker(.localized("Server Type"), systemImage: "server.rack", selection: $_serverMethod) {
					ForEach(_serverMethods.indices, id: \.description) { index in
						Text(_serverMethods[index]).tag(index)
					}
				}
				Toggle(.localized("Only use localhost address"), systemImage: "lifepreserver", isOn: $_ipFix)
					.disabled(_serverMethod != 1)
			}
			
			Section {
				Button(.localized("Update SSL Certificates"), systemImage: "arrow.down.doc") {
					FR.downloadSSLCertificates(
						certificateURL: "https://www.kravasign.com/local.crt",
						privateKeyURL: "https://www.kravasign.com/local.pem"
					) { success in
						if success {
							DispatchQueue.main.async {
								UIAlertController.showAlertWithOk(
									title: .localized("SSL Certificates"),
									message: .localized("Certificates updated successfully.")
								)
							}
						} else {
							DispatchQueue.main.async {
								UIAlertController.showAlertWithOk(
									title: .localized("SSL Certificates"),
									message: .localized("Failed to download, check your internet connection and try again.")
								)
							}
						}
					}
				}
			}
		}
	}
}
