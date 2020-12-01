#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    float number_a, number_b;
    char c_char;
    int i;
    while (true) {
        cout << "Enter first number: ";
        cin >> number_a;
        cout << "Enter second number: ";
        cin >> number_b;
        cout << "Enter operation: ";
        cin >> c_char;

        switch (c_char) {
        case '+':
            cout << number_a << "+" << number_b << "=" << number_a + number_b << '\n';
            break;
        case '-':
            cout << number_a << "-" << number_b << "=" << number_a - number_b << '\n';
            break;
        case '*':
            cout << number_a << "*" << number_b << "=" << number_a * number_b << '\n';
            break;
        case '/':
            if ((number_b == 0)) {
                cout << "Error\n";
                break;
            }
            cout << number_a << "/" << number_b << "=" << number_a / number_b << '\n';
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
