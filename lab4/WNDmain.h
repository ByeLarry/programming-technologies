#pragma once
#pragma comment(lib, "Childform\\x64\\Debug\\Childform.lib")
//путь для подключения динамической библиотеки
//это нужно для того чтобы подключить библиотеку во время запуска программы, а не во время работы
//либ в данном случае не содержит реализации функций, поэтому длл должна быть в файле с проектом


#include<Windows.h>
#include<string>
#include <sstream>

#define WM_SET_PATH 22
#define WM_CREATEchild 3
#define TextBufferSize 50
#define MatrixString 1000


char Buffer[TextBufferSize];
int readChar;
unsigned numA;
unsigned numB;



//заголовочный файл с интерфейсом из статической библиотеки 
//#include"interface/interface.h"
//заголовочный файл с интерфейсом из динамической библиотеки
#include"Childform/Child.h"



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
	if (numA == numB || numA == 0 || numB == 0) {
		return false;
	}
	if (numA > 6) {
		return false;
	}
	if (numB > 6) {
		return false;
	}
	return true;
}


LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	//при явной загрузке надо создавать указатель на адресс функции  
	typedef std::string(*Mydij)(int, int, int(*)[6]);
	HINSTANCE hinstDLL = LoadLibrary(TEXT("Dijkstra\\x64\\Debug\\Dijkstra.dll"));
	Mydij myD = (Mydij)GetProcAddress(hinstDLL, "Mydijkstra");
	
	
	switch (msg) {
	case WM_COMMAND:
		switch (wp)
		{
		case 1:
			numA = GetDlgItemInt(hWnd, 200, NULL, false);
			numB = GetDlgItemInt(hWnd, 210, NULL, false);
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
				SetWindowTextA(hStaticControlNums, "Вершины не заданы!");
			}

			if (CheckNums() && ValidateMatrix()) {
				EnableWindow(hWnd, FALSE);

				if (hinstDLL == NULL) {
					MessageBox(hWnd, L"Библиотека Dijkstra.dll не найдена!", L"Ошибка!", NULL);
				}
				else {
					int start = numA - 1 ;
					int end = numB - 1;
					//явный вызов из динамической библиотеки, обращаясь к переменной, хранящей в себе адресс функции 
					path = myD (start, end, matrix);
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
		//вызов функций из статической библиотеки 
		/*hStaticControl = WndStaticControl(hWnd);
		hNumberAControl = WndNumberAControl(hWnd);
		hNumberBControl = WndNumberBControl(hWnd);
		MainWndAddWidgets(hWnd);
		hStaticControlNums = WndStaticControlNums(hWnd);*/


		//неявный вызов функции динамической библиотеки 
		hStaticControl = WndStaticControlChild(hWnd);
		hNumberAControl = WndNumberAControlChild(hWnd);
		hNumberBControl = WndNumberBControlChild(hWnd);
		MainWndAddWidgetsChild(hWnd);
		hEditControl = WndEditFromChild(hWnd);
		hStaticControlNums = WndStaticControlNumsChild(hWnd);
		break;

	case WM_DESTROY:
		FreeLibrary(hinstDLL);
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




