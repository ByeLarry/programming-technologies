#include <iostream>
#include <string>
using namespace std;


bool check(string inp) {
	int ii = 0;
	for (char c : inp) {
		ii++;
		if (!isdigit(c)) return false;
		if (ii > 1) {
			cout << endl;
			cout << "������ ������� ������ 2 ��������!" << endl;
			return false;
		}
	}
	//if (stoi(inp) >= 2 or stoi(inp) <= 10)
	return true;
}

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



int input() {
	string inp;
	cin >> inp;
	while (!check(inp)) {
		cout << "������ �����! \n" << "���������: ";
		cin.clear();
		cin >> inp;
	}
	return stoi(inp);
}


char inputChar() {
	string inp;
	cin >> inp;
	while (!checkChar(inp)) {
		cout << "������ �����! \n" << "���������: ";
		cin.clear();
		cin >> inp;
	}
	return inp[0];
}


class Node {
public:
	int* ai;
	char ch;
	int si;
	Node* prev, * next;

public:
	Node(int* ai, char ch, int si) {
		this->ai = ai;
		this->ch = ch;
		this->si = si;
		this->prev = this->next = nullptr;
	}
};


class LinkedList {
public:
	Node* head, * tail;
public:
	LinkedList() {
		head = tail = nullptr;
	}
	Node* push_front(int* ai, char ch, int si) {
		Node* ptr = new Node(ai, ch, si);
		ptr->next = head;
		if (head != nullptr) head->prev = ptr;
		if (tail == nullptr) tail = ptr;
		head = ptr;
		return ptr;
	}

	Node* push_back(int* ai, char ch, int si) {
		Node* ptr = new Node(ai, ch, si);
		ptr->prev = tail;
		if (tail != nullptr) tail->next = ptr;
		if (head == nullptr) head = ptr;
		tail = ptr;
		return ptr;
	}

	void pop_front() {
		if (head == nullptr) {
			cout << "��� ��������� ��� ��������!" << endl;
			return;
		}
			
		Node* ptr = head->next;
		if (ptr != nullptr) ptr->prev = nullptr;
		else tail = nullptr;
		free(head->ai);
		free(head);
		head = ptr;
		cout << "������� ������" << endl;
	}

	void pop_back() {
		if (tail == nullptr) {
			cout << "��� ��������� ��� ��������!" << endl;
			return;
		}
			
		Node* ptr = tail->prev;
		if (ptr != nullptr) ptr->next = nullptr;
		else head = nullptr;
		free(tail->ai);
		free(tail);
		tail = ptr;
		cout << "������� ������" << endl;
	}

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

	void erase(int index) {
		Node* ptr = getAt(index);
		if (ptr == nullptr) {
			cout << "�������� � ��������� �������� �� ����������!" << endl;
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
		//free(ptr);
		cout << "������� ������" << endl;
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
	cout << "1)�������� ������� ������\n";
	cout << "2)�������� ������� �����\n";
	cout << "3)������� ������� ������\n";
	cout << "4)������� ������� �����\n";
	cout << "5)������� ������\n";
	cout << "6)�������� ������� �� �������\n";
	cout << "7)������� ������� �� �������\n";
	cout << "8)�����\n \n";
	
	while (!ex_fl)
	{
		cout << "�������� �������:  "; 
		sel = input();
		cout << endl;
		switch (sel)
		{
		case 1:
			cout << "������� ������ �������:  ";
			si = input();
			ai = (int*)malloc(si * sizeof(int)) ;
			for (int i = 0; i < si; i++)
				ai[i] = rand() % 100;
			cout << "������� ������:  ";
			ch = inputChar();
			cout << endl;
			ml.push_front(ai, ch, si);
			break;
		case 2: 
			cout << "������� ������ �������:  ";
			si = input();
			ai = (int*)malloc(si * sizeof(int));
			for (int i = 0; i < si; i++)
				ai[i] = rand() % 100;
			cout << "������� ������:  ";
			ch = inputChar();
			cout << endl;
			ml.push_back(ai, ch, si);
			break;
		case 3:
			ml.pop_front();
			break;
		case 4:
			ml.pop_back();
			break;
		case 5:
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
			cout << "������� ������:  ";
			ind = input();
			cout << "������� ������ �������:  ";
			si = input();
			ai = (int*)malloc(si * sizeof(int));
			for (int i = 0; i < si; i++)
				ai[i] = rand() % 100;
			cout << "������� ������:  ";
			ch = inputChar();
			cout << endl;
			ml.insert(ind,ai, ch, si);
			//delete[] ai;
			break;
		case 7:
			cout << "������� ������:  ";
			ind = input();
			ml.erase(ind);
			break;
		case 8:
			while (ml.head != nullptr) {
				ml.pop_front();
			}
			ex_fl = true;
			break;
		default:
			cout << "�������� ����!" << endl;
			break;
		}
	}
	;
}