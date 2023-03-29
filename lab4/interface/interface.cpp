// interface.cpp : Определяет функции для статической библиотеки.
//в лабораторной работе 4 статические библиотеки не используются

#include "pch.h"
#include "framework.h"


//определение функций 
void MainWndAddWidgets(HWND hWnd) {
	CreateWindowA("button", "Посчитать", WS_VISIBLE | WS_CHILD | ES_CENTER, 200, 140, 100, 30, hWnd, (HMENU)1, NULL, NULL, NULL);
	CreateWindowA("static", "А", WS_VISIBLE | WS_CHILD, 130, 60, 20, 20, hWnd, NULL, NULL, NULL, NULL);
	CreateWindowA("static", "B", WS_VISIBLE | WS_CHILD, 130, 100, 20, 20, hWnd, NULL, NULL, NULL, NULL);
	CreateWindowA("static", "Введите вершины", WS_VISIBLE | WS_CHILD, 0, 140, 200, 20, hWnd, NULL, NULL, NULL, NULL);

}

HWND WndEdit(HWND hWnd) {
	HWND hEditControl = CreateWindowA("edit", "000000\r\n000000\r\n000000\r\n000000\r\n000000\r\n000000", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_NUMBER, 0, 30, 55, 100, hWnd, NULL, NULL, NULL, NULL);
	return hEditControl;
}

HWND WndStaticControl(HWND hWnd) {
	HWND hStaticControl = CreateWindowA("static", "Введите матрицу смежности(6 на 6)", WS_VISIBLE | WS_CHILD, 0, 0, 490, 20, hWnd, NULL, NULL, NULL, NULL);
	return hStaticControl;
}

HWND WndNumberAControl(HWND hWnd) {
	HWND hNumberAControl = CreateWindowA("edit", "1", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 60, 50, 20, hWnd, (HMENU)200, NULL, NULL);
	return hNumberAControl;
}

HWND WndNumberBControl(HWND hWnd) {
	HWND hNumberBControl = CreateWindowA("edit", "2", WS_VISIBLE | WS_CHILD | ES_NUMBER, 70, 100, 50, 20, hWnd, (HMENU)210, NULL, NULL);
	return hNumberBControl;
}

HWND WndStaticControlNums(HWND hWnd) {
	HWND hStaticControlNums = CreateWindowA("static", "Введите вершины", WS_VISIBLE | WS_CHILD, 0, 140, 200, 20, hWnd, NULL, NULL, NULL, NULL);
	return hStaticControlNums;
}