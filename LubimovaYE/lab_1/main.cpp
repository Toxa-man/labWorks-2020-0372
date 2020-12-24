#include
using namespace std;

int main()
{

	float operand_1, operand_2, res;
	bool flag = 0;
	char operation_sign;
	cout << "Enter 2 numbers and an action sign(+,-,*,/)" << endl;
	cout << "To exit the program, enter '0' three times" << endl;
	cin >> operand_1 >> operand_2 >> operation_sign;
	while (!(operand_1 == 0 && operand_2 == 0 && operation_sign == '0'))
	{
		switch (operation_sign)
		{
		case '+':
			res = operand_1 + operand_2;
			break;
		case '-':
			res = operand_1 - operand_2;
			break;
		case '*':
			res = operand_1 * operand_2;
			break;
		case '/':
			if (operand_2 == 0)
			{
				flag = 1;
				cout << "You can't divide by 0" << endl;
			}
			else
			{
				res = operand_1 / operand_2;
			}
			break;
		default:
			cout << "Enter a valid operation sign" << endl;
			flag = 1;
			break;
		}
		if (flag != 1)
		{
			cout << res << endl;
		}
		res = 0;
		flag = 0;
		cout << "Enter new values" << endl;
		cin >> operand_1 >> operand_2 >> operation_sign;
	}
	cout << "The programme is completed" << endl;
	return 0;
}