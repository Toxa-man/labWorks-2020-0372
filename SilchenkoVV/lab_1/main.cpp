#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    char exit_char, sign;
    double first_num, second_num;
    do {
        cout << "Enter first number:";
        while (!(cin >> first_num)) {
            cout << "Wrong first number input\nEnter right first number:" << endl;
            cin.clear();
            cin.ignore();
        }

        cout << "Enter second number:";
        while (!(cin >> second_num)) {
            cout << "Wrong second number input\nEnter right second number:" << endl;
            cin.clear();
            cin.ignore();
        }

        cout << "Enter sign:";
        cin >> sign;
        while ((sign != '+') and (sign != '-') and (sign != '*') and (sign != '/')) {
            cout << "Wrong sign input\nEnter right sign:" << endl;
            cin >> sign;
        }

        switch (sign){
            case '+':
                cout << first_num + second_num << endl;
                break;
            case '-':
                cout << first_num - second_num << endl;
                break;
            case '*':
                cout << first_num * second_num << endl;
                break;
            case '/':
                while (second_num == 0) {
                    cout << "You can't divide by zero\nEnter right divisor:" << endl;
                    cin >> second_num;
                }
                cout << first_num / second_num << endl;
        }

        cout << "Enter Q to exit or any symbol to continue" << endl;
        exit_char = _getch();
    } while (exit_char != 'Q' and exit_char != 'q');
    return 0;
}