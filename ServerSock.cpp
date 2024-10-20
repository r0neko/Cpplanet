#include "ServerSock.h"
#include "ClientSession.h"
#include <iostream>
#include "Config.h"
#include <ip2string.h>
#include "Logger.h"

ServerSock::ServerSock() {
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr = {};
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons((u_short)Config::BindingPort);
	sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
}
void ServerSock::Run() {
	if (SOCKET_ERROR == bind(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr))) {
		Logger::Warn(L"소켓 바인딩 실패");
		closesocket(sock);
		WSACleanup();
		return;
	}
	Logger::Info(L"서버 소켓이 생성되었습니다.");
	listen(sock, SOMAXCONN);
	while (1) {
		sockaddr_in ClientAddress;
		int len = sizeof(ClientAddress);
		SOCKET client = accept(sock, (SOCKADDR*)&ClientAddress, &len);
		wchar_t ClientIP[16];
		RtlIpv4AddressToStringW((in_addr*) & ClientAddress.sin_addr.S_un.S_addr, ClientIP);
		Logger::Info(L"새로운 요청\n 클라이언트 IP : %s", ClientIP);

		ClientSession* clientSession = new ClientSession(client);
	}
}