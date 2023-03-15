//#include<Windows.h>
//
//
//LRESULT CALLBACK SoftwareChildProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
//WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
//void MainWndAddWidgets(HWND hWnd);
//
//int WINAPI WinChild(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
//
//	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION),
//		L"MainWndClass", SoftwareChildProcedure);
//
//	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
//
//	MSG SoftwareMainMessage = { 0 };
//
//	CreateWindow(L"MainWndClass", L"¬вод матрицы", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);
//	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
//		TranslateMessage(&SoftwareMainMessage);
//		DispatchMessage(&SoftwareMainMessage);
//	}
//	return 0;
//}
//
//WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
//	WNDCLASS NWC = { 0 };
//
//	NWC.hCursor = Cursor;
//	NWC.hIcon = Icon;
//	NWC.hInstance = hInst;
//	NWC.lpszClassName = Name;
//	NWC.hbrBackground = BGColor;
//	NWC.lpfnWndProc = Procedure;
//
//	return NWC;
//}
//
//
//WNDCLASS NewWindowSecondClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
//	WNDCLASS NWC = { 0 };
//
//	NWC.hCursor = Cursor;
//	NWC.hIcon = Icon;
//	NWC.hInstance = hInst;
//	NWC.lpszClassName = Name;
//	NWC.hbrBackground = BGColor;
//	NWC.lpfnWndProc = Procedure;
//
//	return NWC;
//}
//
//	LRESULT CALLBACK SoftwareChildProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
//		switch (msg) {
//		case WM_COMMAND:
//			switch (wp)
//			{
//			
//			default: break;
//			}
//			break;
//
//		case WM_CREATE:
//			MainWndAddWidgets(hWnd);
//			break;
//
//		case WM_DESTROY:
//			PostQuitMessage(0);
//			break;
//
//		default: return DefWindowProc(hWnd, msg, wp, lp);
//		}
//
//	}
