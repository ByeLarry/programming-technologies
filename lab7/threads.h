#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace chrono;

//константы для тестирования
const int BARBER_WORKING_TIME = 100;
const int CLIENT_COMES_TIME = 500;
const int MAX_QUEUE = 5;


//инициализация семафорa
HANDLE customer_sem = CreateSemaphore(NULL, 0, MAX_QUEUE, NULL);;

//функции для потоков
//функция для парикмахера
void barber() {
	int num_served = 0;
	//пока не обслужатся все клиенты
	while (true) {
		WaitForSingleObject(customer_sem, INFINITE); //пока семафор customer_sem равен 0 идет ожидаение(так же эта функция декрементирует семафор)
		cout << "Парикмахер стрижет волосы для клиента " << num_served + 1 << endl;
		this_thread::sleep_for(milliseconds(BARBER_WORKING_TIME)); //задержка для потока 
		cout << "Клиент " << num_served + 1 <<  " готов" << endl;
		num_served++;
	}
}

//функция для клиента
void customer() {
	int id = 0;
	LONG prevSemVal;
	while (true) {
		this_thread::sleep_for(milliseconds(CLIENT_COMES_TIME));//задержка для симуляции прихода клиентов
		ReleaseSemaphore(customer_sem, 1, &prevSemVal);//увеличение очереди на 1(очередь реализована через семафор customer_sem)
		if (prevSemVal == MAX_QUEUE - 1) {
			WaitForSingleObject(customer_sem, INFINITE);
			cout << "Клиент " << id + 1 << " не хочет ждать" << endl;
			break;
		}
		else {
			cout << "Клиент " << id + 1 << " пришел\n";
		}
		id++;
	}
}