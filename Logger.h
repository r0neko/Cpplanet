#pragma once
#include <stdio.h>
#include <iostream>
#include "Config.h"
#define Normal L"\x1b[39m"
#define Red L"\x1b[91m"
#define Blue L"\x1b[94m"
class Logger {
public:
	template<typename ... Args>
	static void Info(const wchar_t* Message, Args ... args) {
		if ((int)Config::IsDebug == 1 ) {
			wprintf(L"%s%s%s", Blue, L"[정보]", Normal);
			wprintf(Message, args...);
			wprintf(L"\n");
		}
	}
	template<typename ... Args>
	static void Warn(const wchar_t* Message, Args ... args) {
		if ( ( int ) Config::IsDebug == 1 ) {
			wprintf(L"%s%s%s", Red, L"[경고]", Normal);
			wprintf(Message, args...);
			wprintf(L"\n");
		}
	}
};