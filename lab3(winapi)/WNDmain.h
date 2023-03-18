#pragma once
#include<Windows.h>
#include<string>
#include <sstream>

#define OnButtonClicked 1
#define WM_SET_PATH 22
#define WM_CREATEchild 3
#define TextBufferSize 50
#define DlgIndexNumberA 200
#define DlgIndexNumberB 210
#define MatrixString 1000


char Buffer[TextBufferSize];
int readChar;
unsigned numA;
unsigned numB;


HWND childText;
HWND hEditControl;
HWND hStaticControl;
HWND hStaticControlNums;
HWND hNumberAControl;
HWND hNumberBControl;
HWND hWnd;

int matrix[6][6];
int len;
std::string str;
bool checklenmat = true;
std::string path;


void MainWndAddWidgets(HWND hWnd);
LRESULT CALLBACK SoftwareChildProcedure(HWND childWindow, UINT msg, WPARAM wp, LPARAM lp);



WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
	WNDCLASS NWC = { 0 };

	NWC.hCursor = Cursor;
	NWC.hIcon = Icon;
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


void ParseMatrix()
{
	int k = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (str[k] == '0') { matrix[i][j] = 0; };
			if (str[k] == '1') { matrix[i][j] = 1; };
			k++;
		}
	}
}


bool ValidateMatrix() {
	if (str.size() != 36) {
		return false;
	}
	for (int i = 0; i < 36; i++) {
		if (str[i] != 48 && str[i] != 49) { return false; };

	}
	return true;
}


bool CheckNums() {
	if (numA == numB) {
		return false;
	}
	if (numA > 5) {
		return false;
	}
	if (numB > 5) {
		return false;
	}
	return true;
}


LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp)
		{
		case OnButtonClicked:
			numA = GetDlgItemInt(hWnd, DlgIndexNumberA, NULL, false);
			numB = GetDlgItemInt(hWnd, DlgIndexNumberB, NULL, false);
			readChar = GetWindowTextA(hEditControl, Buffer, TextBufferSize);

			str = Buffer;
			str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
			str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

			if (ValidateMatrix()) {
				SetWindowTextA(hStaticControl, "Матрица задана корректно");
				ParseMatrix();
			}
			else {
				SetWindowTextA(hStaticControl, "Матрица задана некорректно!");
			}

			if (CheckNums()) {
				SetWindowTextA(hStaticControlNums, "Вершины заданы корректно");
			}
			else {
				SetWindowTextA(hStaticControlNums, "Вершины заданы некорректно!");
			}

			if (CheckNums() && ValidateMatrix()) {
				EnableWindow(hWnd, FALSE);

				int start = numA;
				int end = numB;
				int dist[6];
				bool visited[6];
				for (int i = 0; i < 6; i++) {
					dist[i] = 999999;
					visited[i] = false;
				}
				dist[start] = 0;

				for (int i = 0; i < 6 - 1; i++) {
					int u = -1;
					for (int j = 0; j < 6; j++) {
						if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
							u = j;
						}
					}
					visited[u] = true;
					for (int v = 0; v < 6; v++) {
						if (matrix[u][v] > 0) {
							int alt = dist[u] + matrix[u][v];
							if (alt < dist[v]) {
								dist[v] = alt;
							}
						}
					}
				}

				if (dist[end] == 999999) {
					path = "No way!";
				}
				else {
					path = std::to_string(end + 1) + "\nCount steps: " + std::to_string(dist[end]) + "\n";
					int curend = end;
					while (curend != start) {
						for (int i = 0; i < 6; i++) {
							if (matrix[i][curend] > 0 && dist[i] + matrix[i][curend] == dist[curend]) {
								path = std::to_string(i + 1) + " -> " + path;
								curend = i;
								break;
							}
						}
					}
				}

				HWND childWindow = CreateWindowEx(
					0, L"ChildWndClass", L"Дочернее окно", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
					300, 300, 300, 150, hWnd, NULL, NULL, NULL
				);
				if (childWindow == NULL) {
					MessageBox(childWindow, L"Не удалось создать дочернее окно", L"Ошибка", MB_OK | MB_ICONERROR);
					return -1;
				}

			}
			break;
		default: break;
		}
		break;

	case WM_CREATE:
		MainWndAddWidgets(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default: return DefWindowProc(hWnd, msg, wp, lp);
	}

}

LRESULT CALLBACK SoftwareChildProcedure(HWND childWindow, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_CREATE: {

		if (!IsWindow(childText)) {
			childText = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE,
				0, 0, 300, 300, childWindow, NULL, NULL, NULL);
		}
		int size_needed = MultiByteToWideChar(CP_UTF8, 0, path.c_str(), static_cast<int>(path.size()), NULL, 0);
		std::wstring wstrTo(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, path.c_str(), static_cast<int>(path.size()), &wstrTo[0], size_needed);
		LPCWSTR lpwstr = wstrTo.c_str();

		SetWindowText(childText, lpwstr);
		break; }
	case WM_CREATEchild:
		break;
	case WM_CLOSE:
		EnableWindow(hWnd, TRUE);
		DestroyWindow(childWindow);
		break;
	case WM_DESTROY:
		EnableWindow(GetParent(childWindow), TRUE);
		break;

	default: return DefWindowProc(childWindow, msg, wp, lp);
	}

}


void MainWndAddWidgets(HWND hWnd) {
	hStaticControl = CreateWindowA("static", "Введите матрицу смежности(6 на 6)", WS_VISIBLE | WS_CHILD , 0, 0, 490, 20, hWnd, NULL, NULL, NULL, NULL);

	hEditControl = CreateWindowA("edit", "000000\r\n000000\r\n000000\r\n000000\r\n000000\r\n000000", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_NUMBER, 0, 30, 55, 100, hWnd, NULL, NULL, NULL, NULL);

	CreateWindowA("button", "Посчитать", WS_VISIBLE | WS_CHILD | ES_CENTER, 200, 140, 100, 30, hWnd, (HMENU)OnButtonClicked, NULL, NULL, NULL);

	hNumberAControl = CreateWindowA("edit", "0", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 60, 50, 20, hWnd, (HMENU)DlgIndexNumberA, NULL, NULL);

	hNumberBControl = CreateWindowA("edit", "1", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 100, 50, 20, hWnd, (HMENU)DlgIndexNumberB, NULL, NULL);

	CreateWindowA("static", "А", WS_VISIBLE | WS_CHILD, 130, 60, 20, 20, hWnd, NULL, NULL, NULL, NULL);
	CreateWindowA("static", "B", WS_VISIBLE | WS_CHILD, 130, 100, 20, 20, hWnd, NULL, NULL, NULL, NULL);

	hStaticControlNums = CreateWindowA("static", "Введите вершины", WS_VISIBLE | WS_CHILD , 0, 140, 200, 20, hWnd, NULL, NULL, NULL, NULL);

}

std::wstring StringToWideString(const std::string& str)
{
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
}

