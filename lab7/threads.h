#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace chrono;

//константы для тестирования
const int COUNT_CUSTOMERS = 8;
const int BARBER_WORKING_TIME = 300;
const int CLIENT_COMES_TIME = 00;


int num_served = 0;

//инициализация семафоров
HANDLE barber_sem = CreateSemaphore(NULL, 0, 1, NULL);
HANDLE customer_sem = CreateSemaphore(NULL, 0, COUNT_CUSTOMERS, NULL);;


//функции для потоков
//функция для парикмахера
void barber() {

    //пока не обслужатся все клиенты
    //можно было бы сделать бесконечный цикл работы парикмахера, но тогда программа бесконечно ждала бы новых клиентов
    while (num_served < COUNT_CUSTOMERS) {
        WaitForSingleObject(customer_sem, INFINITE); //пока семафор customer_sem равен 0 идет ожидаение(так же эта функция декрементирует семафор)
        cout << "\nПарикмахер стрижет волосы для клиента " << num_served + 1 << "\n";
        this_thread::sleep_for(milliseconds(BARBER_WORKING_TIME)); //задержка для потока 
        cout << "Клиент " << num_served + 1 << " готов\n\n";
        ReleaseSemaphore(barber_sem, 1, NULL); //инкремент семафора barber_sem
        num_served++;
    }
}

//функция для клиента
void customer(int id) {
    cout << "Клиент " << id << " пришел\n";
    ReleaseSemaphore(customer_sem, 1, NULL);//увеличение очереди на 1(очередь реализована через семафор customer_sem)
    WaitForSingleObject(barber_sem, INFINITE);//ожидаение пока парикмахер не освободится
}