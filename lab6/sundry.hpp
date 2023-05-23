#pragma once
#include "pch.hpp"

const string error = "Ошибка ввода!";

//проверка строки 
bool check(string inp) {
	for (char c : inp) {
		if (!isdigit(c) or c == '-' or c == '.') {
			return false;
		}
	}
	return true;
}


//Кастомный ввод
int input() {
	string inp;
	cin >> inp;
	while (!check(inp)) {
		cout << "Ошибка ввода! \n" << "Повторите: ";
		cin.clear();
		cin >> inp;
	}
	return stoi(inp);
}

void header_start() {
	PRINT "Выберите класс, с которым хотите работать:" << endl;
	PRINT "1) Car" << endl;
	PRINT "2) Owner" << endl;
	PRINT "3) Engine" << endl;
}

void header() {
	PRINT endl << "1) Вывести поля объекта" << endl;
	PRINT "2) Изменить поле объекта" << endl;
	PRINT "3) Ожидаемый пробег" << endl;
	PRINT "4) Ожидаемый возраст" << endl;
	PRINT "5) Вывести собственные поля класса" << endl;
	PRINT "6) Сменить класс" << endl;
	PRINT "7) Закрыть программу" << endl;
}