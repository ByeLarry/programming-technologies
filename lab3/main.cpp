#include <iostream>
using namespace std;

int nnn(int a, int b) {
    if (b == 0) {
        throw "division by zero"; // ��������� ����������
    }
    return a / b;
}

int main() {
    int a, b, c;
    cout << "enter a and b" << endl;
    cin >> a;
    cin >> b;
    try {
        c = nnn(a, b); // ����� �������, ������� ����� ������������ ����������
        cout << "c = " << c << endl;
    }
    catch (const char* message) { // ��������� ���������� ���� const char*
        cerr << "Error: " << message << endl;
    }
    cout << " Sucsessful!" << endl;
    return 0;
}

