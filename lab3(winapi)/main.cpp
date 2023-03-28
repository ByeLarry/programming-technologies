#include "WNDmain.h"

//в данном приложении матрица имеет строго фиксированный размер 6 на 6,
//а так же граф является невзвешенным


//точка входа для программы 
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

	//инициализация класса главного окна
	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), 
		L"MainWndClass", SoftwareMainProcedure);

	//инициализация окна дочернего 
	WNDCLASS wc = NewWindowChildClass((HBRUSH)GetStockObject(WHITE_BRUSH), NULL, NULL, NULL, L"ChildWndClass", SoftwareChildProcedure);
				if (!RegisterClass(&wc)) {
					MessageBox(hWnd, L"Не удалось зарегистрировать класс дочернего окна", L"Ошибка", MB_OK | MB_ICONERROR);
					return -1;
				}
	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };

	//создание главного окна с заданным классом 
	hWnd = CreateWindow(L"MainWndClass", L"Ввод матрицы", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 350, 220, NULL, NULL, NULL, NULL);

	//цикл обработки сообщений 
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	return 0;
}

