#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "");
    double first, second, n = 1, exit = 0;
    char znak;
    while (n == 1)
    {
        cout << "Add first number: " << endl;
        cin >> first;
        cout << "Add action" << endl;
        cin >> znak;
        cout << "Add second number:" << endl;
        cin >> second;
        switch (znak) {
        case '+':cout << "Sum of numbers = " << first + second << endl; break;
        case '-':cout << "Difference of numbers = " << first - second << endl; break;
        case '*':cout << "Product of numbers = " << first * second << endl; break;
        case '/':
            if (second == 0) {
                cout << "Can not be divided by 0" << endl; break;
            }
            else {
                cout << "Quotient of numbers = " << first / second << endl; break;
            }
        default:cout << "Wrong action sign" << endl; break;
        }
        cout << "To exit press 1\n";
        cin >> exit;
        if (exit == 1) {
            n = 0;
        }
    }
    system("pause");
    return 0;
}
