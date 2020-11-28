#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    float a, b;
    char c;
    int i;
    while (true) {
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
        cout << "Enter operation: ";
        cin >> c;
     
        switch (c) {
        case '+':
            cout << a << "+" << b << "=" << a + b << '\n';
            break;
        case '-':
            cout << a << "-" << b << "=" << a - b << '\n';
            break;
        case '*':
            cout << a << "*" << b << "=" << a * b << '\n';
            break;
        case '/': 
            if ((b == 0) ) {
                 cout << "Error\n";
            break;
        }
            cout << a << "/" << b << "=" << a / b << '\n';
            break;
        default:
            cout << "Error\n";
        }
        Sleep(3000);
        system("cls");
        cout << "reboot\n 1-yes, 0-no\n";
        cin >> i;
        if (i != 1) {
            break;
        }
    }
}
