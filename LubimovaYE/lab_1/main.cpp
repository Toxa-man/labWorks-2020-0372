#include <iostream>
using namespace std;

int main()
{
	
	float operand_1, operand_2;
	char operation_sign;
	cout << "Enter 2 numbers and an action sign(+,-,*,/)" << endl;
	cout << "To exit the program, enter '-1' three times" << endl;
	cin >> operand_1 >> operand_2 >> operation_sign;
	while (operand_1 != -1 && operand_2 != -1 && operation_sign != '-1')
	{
		switch (operation_sign)
		{
		case '+':
			cout << operand_1 + operand_2 << endl;
			cout << "Enter new values" << endl;
			break;
		case '-':
			cout << operand_1 - operand_2 << endl;
			cout << "Enter new values" << endl;
			break;
		case '*':
			cout << operand_1 * operand_2 << endl;
			cout << "Enter new values" << endl;
			break;
		case '/':
			if (operand_2 == 0)
			{
				cout << "You can't divide by 0" << endl;
				cout << "Enter new values" << endl;
			}
			else
			{
				cout << operand_1 / operand_2 << endl;
				cout << "Enter new values" << endl;
			}
			break;
		default:
			cout << "Enter a valid operation sign" << endl;
			cout << "Enter new values" << endl;
			break;
		}
		cin >> operand_1 >> operand_2 >> operation_sign;
	}
	cout << "The programme is completed" << endl;
	return 0;
}