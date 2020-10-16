#include <iostream>
#include <conio.h>
using namespace std;



int main() {

    float a;
    float b;
    char operation_sign;
    bool right_input = false;
    char ch;



    do
    {
        while (!right_input)
        {
            cout << "Enter two numbers and an operator sign in this format (number1 number2 operation_sign) : ";

            cin >> a >> b;
            while (std::cin.fail()) {
                std::cout << "Wrong input try again\n" << "Enter two numbers and an operator sign in this format (number1 number2 operation_sign)  ";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> a >> b;
            }

            cin >> operation_sign;



            switch (operation_sign)
            {

            case '+':
                std::cout << "Your answer is : " << a + b << endl;
                right_input = true;
                break;

            case '-':
                std::cout << "Your answer is : " << a - b << endl;
                right_input = true;
                break;

            case '*':
                std::cout << "Your answer is : " << a * b << endl;
                right_input = true;
                break;

            case '/':
                if ((b == 0)) { std::cout << "You can't divide by ZERO! try again\n"; }
                else {
                    std::cout << "Your answer is : " << a / b << endl;
                    right_input = true;
                }
                break;


            default:
                std::cout << "Wrong operation sign try again\n";
                break;
            }


        }
        std::cout << "press ESC to close the program or anything else to continue : ";
        right_input = false;
        ch = _getch();
        std::cout << "\n";

    } while (ch != 27);


    return 0;

}