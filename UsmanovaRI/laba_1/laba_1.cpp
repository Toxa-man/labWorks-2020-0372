#include<iostream>
#include <conio.h>
using namespace std;
int main() {
	double number_1, number_2;
	char sing;
	const int out = 27;
	do {

		cout << "Enter two numbers: "<< endl;
		cin >> number_1 >> number_2;
		cout << "Enter the operation" << endl;
		cin >> sing;
		switch (sing)
		{
		case '+':
			cout << "Result: " << number_1 + number_2 << endl;
			break;
		case '-':
			cout << "Result: " << number_1 - number_2 << endl;
			break;
		case '*':
			cout << "Result: " << number_1 * number_2 << endl;
			break;
		case '/':
			if (number_2 != 0) {
				cout << "Result: " << number_1 / number_2 << endl;
				break;
			}
			else {
				cout << "Error: division by 0" << endl;
			}
		default:
			cout << "Invalid input data" << endl;
			break;
		}
		cout << "Click 'Esc' to exit" << endl;
	} while (_getch() != out);
	system("pause");
		return 0;
}
