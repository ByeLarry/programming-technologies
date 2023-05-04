#include "threads.h"


int main() {
	setlocale(LC_ALL, "Rus");

	//создание новых потоков
	//в эти потоки передаются процедуру, которые будут выполняться 
	thread barber_thread(barber);
	thread customer_thread(customer);

	//блокировка основного потока программы до тех пор, пока не будут завершены эти потоки
	//метод join заставляет основной поток дожидаться окончания выполнения операций
	barber_thread.join();
	customer_thread.join();

	//освобождение ресурсов ос после работы с семафором
	CloseHandle(customer_sem);
}
