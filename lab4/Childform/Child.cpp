// MyDLL.cpp
#include "pch.h" 

#define DLL_EXPORT __declspec(dllexport)
extern "C++" {
	DLL_EXPORT HWND WndEditFromChild(HWND hWnd) {
		HWND hEditControl = CreateWindowA("edit", "000000\r\n000000\r\n000000\r\n000000\r\n000000\r\n000000", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_NUMBER, 0, 30, 55, 100, hWnd, NULL, NULL, NULL, NULL);
		return hEditControl;
	}

}
