#include <iostream>
#include <Windows.h>
#include "ServerSock.h"
#include <locale.h>
int main() {
	_wsetlocale(LC_ALL, L"");
	ShellExecute(NULL, "open", "https://discord.gg/bw67XNE2EH", NULL, NULL, SW_SHOWNORMAL);
	std::cout << "\x1b[94m" << "에버플래닛 서버 by 이시프" << "\x1b[39m" << std::endl;
	ServerSock* socket = new ServerSock();
	socket->Run();
	return 0;
}