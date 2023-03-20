#pragma once
#ifdef __cplusplus
extern "C++" {
#endif
#include <Windows.h>
#ifdef __cplusplus
}
#endif

#ifdef MY_DLL_EXPORTS
#define MY_DLL_API __declspec(dllexport)
#else
#define MY_DLL_API __declspec(dllimport)
#endif

__declspec(dllimport) void MainWndAddWidgets(HWND hWnd, HWND hStaticControl, HWND hNumberAControl, HWND hNumberBControl);
__declspec(dllimport) HWND WndEdit(HWND hWnd);

