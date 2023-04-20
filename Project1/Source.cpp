#include <Windows.h>
#include <string>

#define OnButtonClicked 1
#define StartVvod 3
#define EnterIndexA 5
#define EnterIndexB 7

#define DlgIndexNumber 500
#define DlgIndexA 550
#define DlgIndexB 600

int i, j;
unsigned n;
std::string s;
int a[10][10];
int a1[10][10];
int b[10];
double x[10];

HWND Poryadok;
HWND hWND;
HWND childWindow;
HWND childStart;
HWND Index;
HWND MatrA;
HWND MatrB;
HWND IndA;
HWND IndB;
HWND Header;


LRESULT CALLBACK SoftwareMainProcedure(HWND hWND, UINT msg, WPARAM wp, LPARAM lp);
LRESULT CALLBACK SoftwareChildProcedure(HWND childWindow, UINT msg, WPARAM wp, LPARAM lp, int n);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
WNDCLASS NewWindowChildClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC ProcedureChild);
void MainWindow(HWND hWND);
void ChildCreate(HWND childWindow);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), L"SoftwareMainClass", SoftwareMainProcedure);
	WNDPROC NewChildWndProc = (WNDPROC)SoftwareChildProcedure;
	WNDCLASS Child = NewWindowChildClass((HBRUSH)GetStockObject(WHITE_BRUSH), NULL, NULL, NULL, L"ChildWndClass", NewChildWndProc);
	if (!RegisterClass(&Child)) {
		MessageBox(hWND, L"Не удалось зарегестрировать класс дочернего окна", L"Ошибка", MB_OK | MB_ICONERROR);
		return -1;
	}

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };

	CreateWindow(L"SoftwareMainClass", L"Система уравнений", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 300, 120, NULL, NULL, NULL, NULL);
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}

	return 0;

}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
	WNDCLASS NWC = { 0 };

	NWC.hIcon = Icon;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

WNDCLASS NewWindowChildClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC ProcedureChild) {
	WNDCLASS NWC = { 0 };

	NWC.hCursor = Cursor;
	NWC.hIcon = Icon;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = ProcedureChild;

	return NWC;
}

bool Check() {
	if (n == 0) {
		return false;
	}
	return true;
}


LRESULT CALLBACK SoftwareMainProcedure(HWND hWND, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case OnButtonClicked:
			n = GetDlgItemInt(hWND, DlgIndexNumber, NULL, false);
			if (Check()) {
				//EnableWindow(hWND, FALSE);
				HWND childWindow = CreateWindowEx(0, L"ChildWndClass", L"Дочернее окно", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 250, 250, 300, 120, hWND, NULL, NULL, NULL);
				if (childWindow == NULL) {
					MessageBox(childWindow, L"Не удалось создать дочернее окно", L"Ошибка", MB_OK | MB_ICONERROR);
					return -1;
				}
				LRESULT res = SendMessage(childWindow, WM_COMMAND, StartVvod, (LPARAM)n);
			}
			else {
				MessageBoxA(hWND, "Введен неверный порядок! \nПовторите ввод.", "Ошибка", MB_OK);
			}
			break;
		default: break;
		}
		break;
	case WM_CREATE:
		MainWindow(hWND);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hWND, msg, wp, lp);
	}
}

LRESULT CALLBACK SoftwareChildProcedure(HWND childWindow, UINT msg, WPARAM wp, LPARAM lp, int n) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case StartVvod: {
			DestroyWindow(childStart);
			IndA = CreateWindowA("button", "Ввод", WS_VISIBLE | WS_CHILD | ES_CENTER, 220, 50, 50, 20, childWindow, (HMENU)EnterIndexA, NULL, NULL);
			Index = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD, 20, 30, 60, 20, childWindow, NULL, NULL, NULL);
			i = 1;
			j = 1;
			s = "a[" + std::to_string(i) + "," +
				std::to_string(j) + "] =";
			SetWindowTextA(Index, s.c_str());
			MatrA = CreateWindowA("edit", "0", WS_VISIBLE | WS_CHILD | ES_NUMBER, 100, 30, 40, 20, childWindow, (HMENU)DlgIndexA, NULL, NULL);
		}
					  break;
		case EnterIndexA:
			a[i][j] = GetDlgItemInt(childWindow, DlgIndexA, NULL, true);
			a1[i][j] = a[i][j];
			if (j < n) {
				j = j + 1;
				s = "a[" + std::to_string(i) + "," + std::to_string(j) + "] =";
				SetWindowTextA(Index, s.c_str());
				SetWindowTextA(MatrA, "0");
			}
			else {
				DestroyWindow(MatrA);
				DestroyWindow(IndA);
				MatrB = CreateWindowA("edit", "0", WS_VISIBLE | WS_CHILD | ES_NUMBER, 100, 30, 40, 20, childWindow, (HMENU)DlgIndexB, NULL, NULL);
				IndB = CreateWindowA("button", "Ввод", WS_VISIBLE | WS_CHILD | ES_CENTER, 220, 50, 50, 20, childWindow, (HMENU)EnterIndexB, NULL, NULL);
				s = "b[" + std::to_string(i) + "] =";
				SetWindowTextA(Index, s.c_str());
			}

			break;
		case EnterIndexB:
			b[i] = GetDlgItemInt(childWindow, DlgIndexB, NULL, true);
			if (i + 1 <= n) {
				i = i + 1;
				j = 1;
				DestroyWindow(MatrB);
				DestroyWindow(IndB);
				MatrA = CreateWindowA("edit", "0", WS_VISIBLE | WS_CHILD | ES_NUMBER, 100, 30, 40, 20, childWindow, (HMENU)DlgIndexA, NULL, NULL);
				IndA = CreateWindowA("button", "Ввод", WS_VISIBLE | WS_CHILD | ES_CENTER, 220, 50, 50, 20, childWindow, (HMENU)EnterIndexA, NULL, NULL);
				s = "a[" + std::to_string(i) + "," + std::to_string(j) + "] =";
				SetWindowTextA(Index, s.c_str());
			}
			else {
				int k;
				double d, c;
				for (k = 1; k <= n; k++) {// прямой ход
					for (j = k + 1; j <= n; j++) {
						d = a[j][k] / a[k][k];
						for (i = k; i <= n; i++) {
							a[j][i] = a[j][i] - d * a[k][i];
						}
						b[j] = b[j] - d * b[k];
					}
				}
				for (k = n; k >= 1; k--) // обратный ход
				{
					d = 0;
					for (j = k + 1; j <= n; j++) {
						c = a[k][j] * x[j];
						d = d + c;
					}
					x[k] = (b[k] - d) / a[k][k];
				}
				DestroyWindow(MatrB);
				DestroyWindow(IndB);
				DestroyWindow(Index);
				SetWindowTextA(Header, "Корни уравнения");
				s = ' ';
				for (i = 1; i <= n; i++) {
					s = s + "x[" + std::to_string(i) + "] = " + std::to_string(x[i]) + "; ";
				}
				Index = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD, 20, 30, 250, 100, childWindow, NULL, NULL, NULL);
				SetWindowTextA(Index, s.c_str());

			}
			break;
		default: break;
		}
		break;
	case WM_CREATE: {
		ChildCreate(childWindow);
		break;
	case WM_DESTROY:
		//EnableWindow(hWND, TRUE);
		DestroyWindow(childWindow);
		break;
	default: return DefWindowProc(childWindow, msg, wp, lp);
	}
	}
}

void MainWindow(HWND hWND) {
	CreateWindowA("static", "Решение системы уравнений", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 290, 20, hWND, NULL, NULL, NULL);
	CreateWindowA("static", "Введите порядок:", WS_VISIBLE | WS_CHILD, 10, 30, 150, 40, hWND, NULL, NULL, NULL);
	Poryadok = CreateWindowA("edit", "1", WS_VISIBLE | WS_CHILD | ES_NUMBER, 150, 30, 40, 20, hWND, (HMENU)DlgIndexNumber, NULL, NULL);
	CreateWindowA("button", "Ввод", WS_VISIBLE | WS_CHILD | ES_CENTER, 220, 50, 50, 20, hWND, (HMENU)OnButtonClicked, NULL, NULL);
}

void ChildCreate(HWND childWindow) {
	Header = CreateWindowA("static", "Ввод коэффициентов", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 275, 20, childWindow, NULL, NULL, NULL);
	childStart = CreateWindowA("button", "Начать ввод", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 30, 275, 20, childWindow, (HMENU)StartVvod, NULL, NULL);
}