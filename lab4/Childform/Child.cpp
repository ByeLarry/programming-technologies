// MyDLL.cpp
#include "pch.h" 

#define DLL_EXPORT1 __declspec(dllexport)
#define DLL_EXPORT2 __declspec(dllexport)
#define DLL_EXPORT3 __declspec(dllexport)
#define DLL_EXPORT4 __declspec(dllexport)
#define DLL_EXPORT5 __declspec(dllexport)
#define DLL_EXPORT6 __declspec(dllexport)

extern "C++" {
	DLL_EXPORT1 HWND WndEditFromChild(HWND hWnd) {
		HWND hEditControl = CreateWindowA("edit", "000000\r\n000000\r\n000000\r\n000000\r\n000000\r\n000000", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_NUMBER, 0, 30, 55, 100, hWnd, NULL, NULL, NULL, NULL);
		return hEditControl;
	}

	DLL_EXPORT2 HWND WndStaticControlChild(HWND hWnd) {
		HWND hStaticControl = CreateWindowA("static", "Введите матрицу смежности(6 на 6)", WS_VISIBLE | WS_CHILD, 0, 0, 490, 20, hWnd, NULL, NULL, NULL, NULL);
		return hStaticControl;
	}

	DLL_EXPORT3 HWND WndNumberAControlChild(HWND hWnd) {
		HWND hNumberAControl = CreateWindowA("edit", "1", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 60, 50, 20, hWnd, (HMENU)200, NULL, NULL);
		return hNumberAControl;
	}

	DLL_EXPORT4 HWND WndNumberBControlChild(HWND hWnd) {
		HWND hNumberBControl = CreateWindowA("edit", "2", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 100, 50, 20, hWnd, (HMENU)210, NULL, NULL);
		return hNumberBControl;
	}

	DLL_EXPORT5 HWND WndStaticControlNumsChild(HWND hWnd) {
		HWND hStaticControlNums = CreateWindowA("static", "Введите вершины", WS_VISIBLE | WS_CHILD, 0, 140, 200, 20, hWnd, NULL, NULL, NULL, NULL);
		return hStaticControlNums;
	}

	DLL_EXPORT6 void MainWndAddWidgetsChild(HWND hWnd) {
		CreateWindowA("button", "Посчитать", WS_VISIBLE | WS_CHILD | ES_CENTER, 200, 140, 100, 30, hWnd, (HMENU)1, NULL, NULL, NULL);
		CreateWindowA("static", "А", WS_VISIBLE | WS_CHILD, 130, 60, 20, 20, hWnd, NULL, NULL, NULL, NULL);
		CreateWindowA("static", "B", WS_VISIBLE | WS_CHILD, 130, 100, 20, 20, hWnd, NULL, NULL, NULL, NULL);
		CreateWindowA("static", "Введите вершины", WS_VISIBLE | WS_CHILD, 0, 140, 200, 20, hWnd, NULL, NULL, NULL, NULL);

	}
}
