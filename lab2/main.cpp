#include <iostream>
#include <string>
using namespace std;

//проверка ввода int
bool check(string inp) {
	int ii = 0;
	for (char c : inp) {
		ii++;
		if (!isdigit(c)) return false;
		if (ii > 1) {
			cout << endl;
			cout << "Нельзя вводить больше 2 символов!" << endl;
			return false;
		}
	}
	return true;
}

//проверка на то, что введенный символ один
bool checkChar(string inp) {
	int ii = 0;
	for (char c : inp) {
		ii++;
		if (ii > 1) {
			cout << endl;
			return false;
		}
	}
	return true;
}


//самодельный ввод int
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

//самодельный ввод char
char inputChar() {
	string inp;
	cin >> inp;
	while (!checkChar(inp)) {
		cout << "Ошибка ввода! \n" << "Повторите: ";
		cin.clear();
		cin >> inp;
	}
	return inp[0];
}

//класс узла списка
class Node {
public:
	int* ai;
	char ch;
	int si;
	Node* prev, * next;

public:
	//конструктор
	//при инициализации узла, значения заносятся в объект класса
	Node(int* ai, char ch, int si) {
		this->ai = ai;
		this->ch = ch;
		this->si = si;
		this->prev = this->next = nullptr;
	}
};

//класс списка 
class LinkedList {
public:
	Node* head, * tail;

public:
	//конструктр списка
	LinkedList() {
		head = tail = nullptr;
	}
	//диструктор списка
	~LinkedList(){
		while (head != nullptr) {
			pop_front();
		}
	}

	//вставка в начало(голову) списка
	Node* push_front(int* ai, char ch, int si) {
		Node* ptr = new Node(ai, ch, si);
		ptr->next = head;
		if (head != nullptr) head->prev = ptr;
		if (tail == nullptr) tail = ptr;
		head = ptr;
		return ptr;
	}

	//вставка в конец(хвост) списка
	Node* push_back(int* ai, char ch, int si) {
		Node* ptr = new Node(ai, ch, si);
		ptr->prev = tail;
		if (tail != nullptr) tail->next = ptr;
		if (head == nullptr) head = ptr;
		tail = ptr;
		return ptr;
	}

	//удаление с начала(головы) списка
	void pop_front() {
		if (head == nullptr) {
			cout << "Нет элементов для удаления!" << endl;
			return;
		}	
		Node* ptr = head->next;
		if (ptr != nullptr) ptr->prev = nullptr;
		else tail = nullptr;
		free(head->ai);
		delete head;
		head = ptr;
		cout << "Элемент удален" << endl;
	}

	//удаление с конца(хвоста) списка
	void pop_back() {
		if (tail == nullptr) {
			cout << "Нет элементов для удаления!" << endl;
			return;
		}
			
		Node* ptr = tail->prev;
		if (ptr != nullptr) ptr->next = nullptr;
		else head = nullptr;
		free(tail->ai);
		delete tail;
		tail = ptr;
		cout << "Элемент удален" << endl;
	}

	//метод для получения узла с нужным индексом
	//пробегает от головы списка до конца
	Node* getAt(int index) {
		Node* ptr = head;
		int n = 0;
		while (n != index) {
			if (ptr == nullptr) return ptr;
			ptr = ptr->next;
			n++;
		}
		return ptr;
	}

	//оператор для упрощения обращения 
	Node* operator  () (int index) {
		Node* ptr = getAt(index);
		if (ptr != nullptr) return ptr;
	}

	//вставка по идексу
	//здесь и далее(erase) используем getAt
	//для получения нужного узла
	Node* insert(int index, int* ai, char ch, int si) {
		Node* right = getAt(index);
		if (right == nullptr) return push_back(ai, ch, si);

		Node* left = right->prev;
		if (left == nullptr) return push_front(ai, ch, si);

		Node* ptr = new Node(ai, ch, si);
		ptr->prev = left;
		ptr->next = right;
		left->next = ptr;
		right->prev = ptr;
	}

	//удаляем элемент по индексу
	//если такого нет, то удаляем либо с головы, либо с хвоста,
	//в зависимости от индекса
	void erase(int index) {
		Node* ptr = getAt(index);
		if (ptr == nullptr) {
			cout << "Элемента с выбранным индексом не существует!" << endl;
			return;
		}	
		if (ptr->prev == nullptr) {
			pop_front();
			return;
		}
			
		if (ptr->next == nullptr) {
			pop_back();
			return;
		}
			
		Node* left = ptr->prev;
		Node* right = ptr->next;
		left->next = right;
		right->prev = left;
		cout << "Элемент удален" << endl;
	}
};


int main()
{
	bool ex_fl = false;
	int sel;
	LinkedList ml;
	srand(time(0));
	int si;
	int* ai;
	char ch;
	int ind;
	setlocale(LC_ALL, "Rus");
	cout << "1)Добавить элемент сверху\n";
	cout << "2)Добавить элемент снизу\n";
	cout << "3)Удалить элемент сверху\n";
	cout << "4)Удалить элемент снизу\n";
	cout << "5)Вывести список\n";
	cout << "6)Добавить элемент по индексу\n";
	cout << "7)Удалить элемент по индексу\n";
	cout << "8)Вывести элемент по индексу\n";
	cout << "9)Выход\n \n";
	//реализация консольных вводов
	while (!ex_fl)
	{
		cout << "Выберите команду:  "; 
		sel = input();
		cout << endl;
		switch (sel)
		{
		case 1:
			//задается размер массива, после чего он генерируется радномно, затем ввод char
			cout << "Введите размер массива:  ";
			si = input();
			ai = (int*)malloc(si * sizeof(int)) ;
			for (int i = 0; i < si; i++)
				ai[i] = rand() % 100;
			cout << "Введите символ:  ";
			ch = inputChar();
			cout << endl;
			ml.push_front(ai, ch, si);
			break;
		case 2: 
			//задается размер массива, после чего он генерируется радномно, затем ввод char
			cout << "Введите размер массива:  ";
			si = input();
			ai = (int*)malloc(si * sizeof(int));
			for (int i = 0; i < si; i++)
				ai[i] = rand() % 100;
			cout << "Введите символ:  ";
			ch = inputChar();
			cout << endl;
			ml.push_back(ai, ch, si);
			break;
		case 3:
			//удаление с начала списка
			ml.pop_front();
			break;
		case 4:
			//удаление с конца списка
			ml.pop_back();
			break;
		case 5:
			//вывод всего списка с головы до хвоста 
			for (Node* ptr = ml.head; ptr != nullptr;ptr = ptr->next) {
				cout << ptr->ch << " ";
				for (int i = 0; i < ptr->si; i++) {
					cout << ptr->ai[i] << " ";
				}
				cout << endl;
			}
			cout << endl;
			break;
		case 6:
			//вставка по индексу
			cout << "Если введенный индекс будет больше максимального, то элемент списка добавится в конец!" << endl;
			cout << "Введите индекс:  ";
			ind = input();
			cout << "Введите размер массива:  ";
			si = input();
			ai = (int*)malloc(si * sizeof(int));
			for (int i = 0; i < si; i++)
				ai[i] = rand() % 100;
			cout << "Введите символ:  ";
			ch = inputChar();
			cout << endl;
			ml.insert(ind,ai, ch, si);
			break;
		case 7:
			//удаление по индексу
			cout << "Введите индекс:  ";
			ind = input();
			ml.erase(ind);
			break;
		case 8:
			//вывод по индексу
			cout << "Введите индекс:  ";
			ind = input();
			if (ml(ind) != nullptr) {
				cout << ml(ind)->ch << " ";
				for (int i = 0; i < ml(ind)->si; i++) {
					cout << ml(ind)->ai[i] << " ";
				}
				cout << endl;
			}
			else cout << "Элемента с выбранным индексом не существует!" << endl;
			break;
		case 9:
			//выход 
			ex_fl = true;
			break;
		default:
			cout << "Неверный ввод!" << endl;
			break;
		}
	}
	;
}