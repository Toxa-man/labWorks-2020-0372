#include <iostream>
using namespace std;

int calculator()
{
    long double a, b;
    char zn;

    cin >> a >> b >> zn;
    switch (zn) {
    case '+': cout << a << '+' << b << '=' << a + b << endl;
        break;
    case '-': cout << a << '-' << b << '=' << a - b << endl;
        break;
    case '*': cout << a << '*' << b << '=' << a * b << endl;
        break;
    case '/': if (b == 0) {
        cout << "MATH ERROR\n";
    }
            else {
        cout << a << '/' << b << '=' << a / b << endl;
    }
            break;
    default: cout << "idk what is  " << zn << endl;
    }
    
    return 0;
}

int main() 
{
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

