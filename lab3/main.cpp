#include <iostream>
using namespace std;

int nnn(int a, int b) {
    if (b == 0) {
        throw "division by zero"; // генерация исключения
    }
    return a / b;
}

int main() {
    int a, b, c;
    cout << "enter a and b" << endl;
    cin >> a;
    cin >> b;
    try {
        c = nnn(a, b); // вызов функции, которая может генерировать исключение
        cout << "c = " << c << endl;
    }
    catch (const char* message) { // обработка исключения типа const char*
        cerr << "Error: " << message << endl;
    }
    cout << " Sucsessful!" << endl;
    return 0;
}

