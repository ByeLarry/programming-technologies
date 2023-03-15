#include "WNDmain.h"


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), 
		L"MainWndClass", SoftwareMainProcedure);
	//child
	WNDCLASS SoftwareChildClass = NewWindowChildClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION),
		L"MainWndClass", SoftwareChildProcedure);
	WNDCLASS wc = NewWindowChildClass((HBRUSH)GetStockObject(WHITE_BRUSH), NULL, NULL, NULL, L"ChildWndClass", SoftwareChildProcedure);
				if (!RegisterClass(&wc)) {
					MessageBox(hWnd, L"Не удалось зарегистрировать класс дочернего окна", L"Ошибка", MB_OK | MB_ICONERROR);
					return -1;
				}

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }

	MSG SoftwareMainMessage = { 0 };
	
	hWnd = CreateWindow(L"MainWndClass", L"Ввод матрицы", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);
	
	
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}


	return 0;
}

