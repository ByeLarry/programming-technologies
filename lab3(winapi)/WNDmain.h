#pragma once
#include<Windows.h>
#include<string>
#include <sstream>

//макросы для облегчения работы
#define OnButtonClicked 1
#define TextBufferSize 50
#define DlgIndexNumberA 200
#define DlgIndexNumberB 210



char Buffer[TextBufferSize];
int readChar;
//беззнаковое целое число
unsigned numA;
unsigned numB;

//инициализация оконных переменных для передачи их значений между функциями
HWND childText;
HWND hEditControl;
HWND hStaticControl;
HWND hStaticControlNums;
HWND hNumberAControl;
HWND hNumberBControl;
HWND hWnd;

//инициализация необходимых глобальных переменных
int matrix[6][6];
std::string StrMat;
std::string path;

//прототипы функций 
void MainWndAddWidgets(HWND hWnd);
LRESULT CALLBACK SoftwareChildProcedure(HWND childWindow, UINT msg, WPARAM wp, LPARAM lp);


//конструктор класса главного окна
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

//конструктор класса дочернего окна 
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

//процедура преобразования текстовой матрицы в матрицу типа int 
void ParseMatrix()
{
	int k = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (StrMat[k] == '0') { matrix[i][j] = 0; };
			if (StrMat[k] == '1') { matrix[i][j] = 1; };
			k++;
		}
	}
}

//проверка корректности введенных значений
bool ValidateMatrix() {
	if (StrMat.size() != 36) {
		return false;
	}
	for (int i = 0; i < 36; i++) {
		//если символ не 1 и не 0, то проверка не пройдена
		if (StrMat[i] != 48 && StrMat[i] != 49) { return false; };

	}
	return true;
}

//проверка корректного выбора вершин
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

//процедура обработки сообщений главного окна 
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp)
		{
		//при нажатии кнопки 
		case OnButtonClicked:

			//получение значений из полей выбора вершин
			numA = GetDlgItemInt(hWnd, DlgIndexNumberA, NULL, false);
			numB = GetDlgItemInt(hWnd, DlgIndexNumberB, NULL, false);
			readChar = GetWindowTextA(hEditControl, Buffer, TextBufferSize);

			//замена переносов строк в текстовой матрице
			StrMat = Buffer;
			StrMat.erase(std::remove(StrMat.begin(), StrMat.end(), '\r'), StrMat.end());
			StrMat.erase(std::remove(StrMat.begin(), StrMat.end(), '\n'), StrMat.end());

			//запуск проверок корректности ввода
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
				SetWindowTextA(hStaticControlNums, "Вершины не заданы !");
			}

			if (CheckNums() && ValidateMatrix()) {

				//выключаем главное окно
				//это необходимо, так как дочернее окно должно быть модальным
				EnableWindow(hWnd, FALSE);

				//если пройдены все проверки, то запускается алгоритм Дийкстры 
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
				//формируется вывод на основании результатов работы алгоритма Дийкстры
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
				//создается дочернее окно
				HWND childWindow = CreateWindowEx(
					0, L"ChildWndClass", L"Дочернее окно", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
					300, 300, 300, 150, hWnd, NULL, NULL, NULL
				);
				//проверка на случай если есть проблемы с созданием дочернего окна
				if (childWindow == NULL) {
					MessageBox(childWindow, L"Не удалось создать дочернее окно", L"Ошибка", MB_OK | MB_ICONERROR);
					return -1;
				}
			}
			break;
		default: break;
		}
		break;
	//при создании
	case WM_CREATE:
		//процедура с созданием необходимых компонентов главного окна 
		MainWndAddWidgets(hWnd);
		break;
	//при уничтожении
	case WM_DESTROY:
		//этот код передастся в цикл, после чего приложение закроется 
		PostQuitMessage(0);
		break;

	default: return DefWindowProc(hWnd, msg, wp, lp);
	}

}

//процедура обработки сообщений дочернего окна 
LRESULT CALLBACK SoftwareChildProcedure(HWND childWindow, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_CREATE: {

		//создание статического текста, куда будет записан разультат Дийкстры
		if (!IsWindow(childText)) {
			childText = CreateWindowA( "STATIC", "", WS_CHILD | WS_VISIBLE,
				0, 0, 300, 300, childWindow, NULL, NULL, NULL);
		}
		//вывод на дочернее окно ответа
		SetWindowTextA(childText, path.c_str());
		break; }
	//при закрытии
	case WM_CLOSE:
		//включаем главное окно и удаляем дочернее
		EnableWindow(hWnd, TRUE);
		DestroyWindow(childWindow);
		break;
	

	default: return DefWindowProc(childWindow, msg, wp, lp);
	}

}

//процедура создания компонентов главного окна
//некоторые компоненты заносятся в переменные
//сделано это для того, чтобы в обработке сообщений главного окна можно было 
//использовать функции, изменяющие окна, либо же функции, 
//которые получают данные введенные в эти компоненты 
void MainWndAddWidgets(HWND hWnd) {
	hStaticControl = CreateWindowA("static", "Введите матрицу смежности(6 на 6)", WS_VISIBLE | WS_CHILD , 0, 0, 490, 20, hWnd, NULL, NULL, NULL, NULL);

	hEditControl = CreateWindowA("edit", "000000\r\n000000\r\n000000\r\n000000\r\n000000\r\n000000", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_NUMBER, 0, 30, 55, 100, hWnd, NULL, NULL, NULL, NULL);
	//в таких компонентах как кнопка необходимо указывать идентификаторы для обработки нажатия
	//в данном случае это макрос OnButtonClicked со значением 1
	CreateWindowA("button", "Посчитать", WS_VISIBLE | WS_CHILD | ES_CENTER, 200, 140, 100, 30, hWnd, (HMENU)OnButtonClicked, NULL, NULL, NULL);

	//в данном случае добавляется идентификатор для того, 
	//чтобы в будущем можно было использовать функцию GetDlgItemInt
	hNumberAControl = CreateWindowA("edit", "0", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 60, 50, 20, hWnd, (HMENU)DlgIndexNumberA, NULL, NULL);

	hNumberBControl = CreateWindowA("edit", "1", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 100, 50, 20, hWnd, (HMENU)DlgIndexNumberB, NULL, NULL);

	CreateWindowA("static", "А", WS_VISIBLE | WS_CHILD, 130, 60, 20, 20, hWnd, NULL, NULL, NULL, NULL);
	CreateWindowA("static", "B", WS_VISIBLE | WS_CHILD, 130, 100, 20, 20, hWnd, NULL, NULL, NULL, NULL);

	hStaticControlNums = CreateWindowA("static", "Введите вершины", WS_VISIBLE | WS_CHILD , 0, 140, 200, 20, hWnd, NULL, NULL, NULL, NULL);

}

