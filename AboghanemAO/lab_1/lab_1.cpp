#include <iostream>
#include <conio.h>
using namespace std;



int main() {

    float first_number;
    float second_number;
    char operation_sign;
    bool right_input = false;
    char ch;



    do
    {
        while (!right_input)
        {
            cout << "Enter two numbers and an operator sign in this format (number1 number2 operation_sign) : ";

            cin >> first_number >> second_number;
            while (std::cin.fail()) {
                std::cout << "Wrong input try again\n" << "Enter two numbers and an operator sign in this format (number1 number2 operation_sign)  ";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> first_number >> second_number;
            }

            cin >> operation_sign;


            std::cout << "Your answer is : ";
            switch (operation_sign)
            {

            case '+':
                std::cout << first_number + second_number << endl;
                right_input = true;
                break;

            case '-':
                std::cout  << first_number - second_number << endl;
                right_input = true;
                break;

            case '*':
                std::cout << first_number * second_number << endl;
                right_input = true;
                break;

            case '/':
                if ((second_number == 0)) { std::cout << "You can't divide by ZERO! try again\n"; }
                else {
                    std::cout  << first_number / second_number << endl;
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