#pragma once
#ifdef __cplusplus
extern "C++" {
#endif
#include <Windows.h>
#ifdef __cplusplus
}
#endif


__declspec(dllimport) HWND WndEditFromChild(HWND hWnd);
__declspec(dllimport) HWND WndStaticControlChild(HWND hWnd);
__declspec(dllimport) HWND WndNumberAControlChild(HWND hWnd);
__declspec(dllimport) HWND WndNumberBControlChild(HWND hWnd);
__declspec(dllimport) HWND WndStaticControlNumsChild(HWND hWnd);
__declspec(dllimport) void MainWndAddWidgetsChild(HWND hWnd);

