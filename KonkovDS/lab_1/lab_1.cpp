#include <iostream>

using namespace std;

int calculator()
{
    cout << "введите 2 числа, а потом знак операции" << endl;
    long double first, second;
    char znack;

    cin >> first >> second >> znack;
    switch (znack) {
    case '+': cout << first << '+' << second << '=' << first + second << endl;
        break;
    case '-': cout << first << '-' << second << '=' << first - second << endl;
        break;
    case '*': cout << first << '*' << second << '=' << first * second << endl;
        break;
    case '/': if (second == 0) {
        cout << "MATH ERROR\n";
    }
            else {
        cout << first << '/' << second << '=' << first / second << endl;
    }
            break;
    default: cout << "idk what is  " << znack << endl;
    }
    
    return 0;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    cout << "Welcome to lab # 1\n";
    bool flag = 1;
    while (flag) {
        cout << "Enter 1 to perform a math operation or enter 0 to exit\n";
        cin >> flag;
        if (flag)
            calculator();
    }
    return 0;
}
