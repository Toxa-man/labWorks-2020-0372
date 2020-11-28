#include <iostream>
#include <windows.h>

using namespace std;

int my_pow(int n, double a);

long double my_fact(int N);

double my_sqrt(int number);

void my_N(int n);

int main()
{
    while (true) {
        int v;
        cout << "Selected action:\n 1)Raising an arbitrary number to an integer power.\n 2)Factorial of a number.\n 3)Square root of a number.\n 4)Function for checking the number for simplicity.\n";
        cin >> v;
        enum choice { pow = 1, fact, sqrt, N };
        switch (v)
        {
        case(pow):
            int number,a;
            cout << "Enter the number and degree separated by a space\n";
            cin >> number >> a;
            cout <<"Result: "<< my_pow(number, a);
            break;
        case(fact):
            cout << "Enter the number:\n";
            cin >> number;
            cout << "Result: " << my_fact(number);
            break;
        case(sqrt):
            cout << "Enter the number:\n";
            cin >> number;
            cout << "Result: " << my_sqrt(number);
            break;
        case(N):
            cout << "Enter the number:\n";
            cin >> number;
             my_N(number);
            break;
        default:
            system("cls");
            cout << "ERROR\n";
            break;
        }
        int i;
        Sleep(3000);
        system("cls");
        cout << "Reboot\n 1)yes\n 2)no\n";
        cin >> i;
        if (i != 1) {
            break;
        }
    }
}
int my_pow(int n, double a) {
    int nsave = n;
    if (a == 0) { return 1; }
    for (int i = 1; i < a; i++)
    {
        n *= nsave;
    }
    return n;
}

long double my_fact(int N)
{
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * my_fact(N - 1);
}

double my_sqrt(int number) {
    double t;
    double squareRoot = number / 2;
    do {
        t = squareRoot;
        squareRoot = (t + (number / t)) / 2;
    } while ((t - squareRoot) != 0);
    return squareRoot;
}

void my_N(int n)
{
    bool pr = true;
    if (n <= 1) { cout << "NE PROSTOY."; }
    else {
        for (int i = 2; i <= my_sqrt(n); i++)
        {
            if (n % i == 0)
                pr = false;
        }
        if (pr == true)
            cout << "Prime number";

        else
            cout << "not a Prime number";
    }
}
