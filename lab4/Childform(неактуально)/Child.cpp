// MyDLL.cpp
#include "pch.h" 

#define DLL_EXPORT1 __declspec(dllexport)
#define DLL_EXPORT2 __declspec(dllexport)
extern "C++" {

    DLL_EXPORT1 void MainWndAddWidgets(HWND hWnd, HWND hStaticControl, HWND hNumberAControl, HWND hNumberBControl) {
		 hStaticControl = CreateWindowA("static", "Введите матрицу смежности(6 на 6)", WS_VISIBLE | WS_CHILD, 0, 0, 490, 20, hWnd, NULL, NULL, NULL, NULL);

		 CreateWindowA("button", "Посчитать", WS_VISIBLE | WS_CHILD | ES_CENTER, 200, 140, 100, 30, hWnd, (HMENU) 1, NULL, NULL, NULL);

		 hNumberAControl = CreateWindowA("edit", "0", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 60, 50, 20, hWnd, (HMENU) 200, NULL, NULL);

		 hNumberBControl = CreateWindowA("edit", "1", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 100, 50, 20, hWnd, (HMENU) 210, NULL, NULL);

		 CreateWindowA("static", "А", WS_VISIBLE | WS_CHILD, 130, 60, 20, 20, hWnd, NULL, NULL, NULL, NULL);
		 CreateWindowA("static", "B", WS_VISIBLE | WS_CHILD, 130, 100, 20, 20, hWnd, NULL, NULL, NULL, NULL);

		 CreateWindowA("static", "Введите вершины", WS_VISIBLE | WS_CHILD, 0, 140, 200, 20, hWnd, NULL, NULL, NULL, NULL);

	}

	DLL_EXPORT2 HWND WndEdit(HWND hWnd) {
		HWND hEditControl = CreateWindowA("edit", "000000\r\n000000\r\n000000\r\n000000\r\n000000\r\n000000", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_NUMBER, 0, 30, 55, 100, hWnd, NULL, NULL, NULL, NULL);
		return hEditControl;
	}

}
