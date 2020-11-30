#include <iostream>
#include "Source.h"
using namespace std;
int main()
{
    float num1;
    float num2;
    char m;
    char ch;
    do {

        cout << "entrer num1 premier nombre: ";
        cin >> num1;
        cout << "entrer num2  desieme nombre: ";
        cin >> num2;
        cout << "choisire votre opiration: ";
        cin >> m;
        switch (ch)
        {
        case '+':
            if (m == '+')
            {
                cout << num1 + num2 << endl;
            }
        case '-':
            if (m == '-')
            {
                cout << num1 - num2 << endl;
            }
        case '*':
            if (m == '*')
            {
                cout << num1 * num2 << endl;
            }
        case '/':
            if (m == '/')
            {
                if (num2 == 0) { std::cout << "you canot divide be 0\n"; }
                else { cout << num1 / num2 << endl; }
                ;

            }
            if (m != '-' && m != '+' && m != '*' && m != '/') {
                cout << "wrong opreation sign\n";
            }


            std::cout << "press ESC to end the program or anything else to start agin : ";
            cin >> ch;
        }
        while (ch != 27);
        return 0;
    }
}