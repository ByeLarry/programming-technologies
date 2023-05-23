#include "car.hpp"
#include "owner.hpp"
#include "engine.hpp"
#include "sundry.hpp"


int main() {
	RUS;
	start:

	//инициализация переменных
	//копмилятор не разрешает иницилизировать внутри блока case, поэтому так
	bool exitFlag = false;
	string brand, model, owner, engine, gender;
	int year, power, type, msg;

	Car* classPointer = nullptr;
	header_start();

	//пока не будет выбран класс
	while (!exitFlag) {
		type = input();
		switch (type)
		{
		case 1:
			PRINT "Введите производителя авто" << endl;
			INPUT brand;
			PRINT "Введите модель авто" << endl;
			INPUT model;
			PRINT "Введите год производства" << endl;
			year = input();
			classPointer = new Car(brand, model, year);
			exitFlag = true;
			break;
		case 2:
			PRINT "Введите владельца" << endl;
			INPUT owner;
			PRINT "Введите пол владельца" << endl;
			INPUT gender;
			PRINT "Введите производителя авто" << endl;
			INPUT brand;
			PRINT "Введите модель авто" << endl;
			INPUT model;
			PRINT "Введите год производства" << endl;
			year = input();
			classPointer = new Owner(owner, gender, brand, model, year);
			exitFlag = true;
			break;
		case 3:
			PRINT "Введите название двигателя" << endl;
			INPUT engine;
			PRINT "Введите мощность" << endl;
			power = input();
			PRINT "Введите производителя авто" << endl;
			INPUT brand;
			PRINT "Введите модель авто" << endl;
			INPUT model;
			PRINT "Введите год производства" << endl;
			year = input();
			classPointer = new Engine(engine, power, brand, model, year);
			exitFlag = true;
			break;
		default:
			PRINT error << endl;
			exitFlag = false;
			break;
		}
	}

	exitFlag = false;
	header();

	//цикл обработки сообщений для работы с методами класса
	while (!exitFlag) {
		PRINT "Выберите метод: ";
		msg = input();
		PRINT endl;

		//не смотря на то, что объекты имеют разные классы - методы их одинаковы
		//это связано с тем, что некоторые методы являются переопределенными, а некоторые
		// унаследованными от родительского класса
		switch (msg)
		{
		case 1: //вывод всех полей
			classPointer->output();
			break;
		case 2:
			classPointer->update(); //обновление одного поля
			break;
		case 3:
			classPointer->getMileage(); //ожидаемый пробег
			break;
		case 4:
			classPointer->getAge(); //ожидаемый возраст
			break;
		case 5:
			//явное приведение типов
			if (type == 1) {
				//собственные методы класса Car
				PRINT "Производитель: " << classPointer->get_brand() << endl;
				PRINT "Модель: " << classPointer->get_model() << endl;
				PRINT "Год производства: " << classPointer->get_year() << endl;
			}
			if (type == 2) {
				//собственные методы класса Owner
				PRINT "Владелец: " << ((Owner*)classPointer)->get_owner() << endl;
				PRINT "Пол: " << ((Owner*)classPointer)->get_gender() << endl;
			}
			if (type == 3) {
				//собственные методы класса Engine
				PRINT "Двигатель: " << ((Engine*)classPointer)->get_engine() << endl;
				PRINT "Мощность: " << ((Engine*)classPointer)->get_power() << endl;
			}
			break;
		case 6:
			delete classPointer;

			//очень плохая практика использовать goto
			//тут используется исключительно для примера
			goto start; //9 строка
			break;
		case 7:
			//очистка памяти
			delete classPointer;
			exitFlag = true;
			break;
		default:
			PRINT error << endl;
			break;
		}
	}
}