#pragma once
//h файл будет подключен к проекту 
#ifdef __cplusplus
extern "C" {
#endif
#include <Windows.h>
#ifdef __cplusplus
}
#endif

//ипорт функций из срр файла
//эти функции будут вызывается в программе
__declspec(dllimport) HWND WndEditFromChild(HWND hWnd);
__declspec(dllimport) HWND WndStaticControlChild(HWND hWnd);
__declspec(dllimport) HWND WndNumberAControlChild(HWND hWnd);
__declspec(dllimport) HWND WndNumberBControlChild(HWND hWnd);
__declspec(dllimport) HWND WndStaticControlNumsChild(HWND hWnd);
__declspec(dllimport) void MainWndAddWidgetsChild(HWND hWnd);

