
#include <iostream>
using namespace std;
int main()
{
	float number1, number2;
	char sign;
	cout << "Enter two numbers and a sign"<< endl;
	cin >> number1 >> number2 >> sign;
	
	while (true)
	{
		switch (sign)
		{
		case '+':
			cout << number1 + number2 << endl;
			cout << "Enter new values" << endl;
			break;
		case '-':
			cout << number1 - number2<< endl;
			cout << "Enter new values" << endl;
			break;
		case '*':
			cout << number1 * number2<< endl;
			cout << "Enter new values" << endl;
			break;
		case '/':
			if (number2 == 0)
			{
				cout << "can not be divisible by 0" << endl;
				cout << "Enter new values" << endl;
			}
			else
			{
				cout << number1 / number2<<endl;
				cout << "Enter new values" << endl;
			}
			break;
		default:
			cout << "Enter a valid operation sign" << endl;
			cout << "Enter new values" << endl;
			break;
		}
		cout << "Exit the program?" << endl;
		string answer;
		cin >> answer;
		if (answer == "yes") {
			cout << "The programme is completed" << endl;
			return 0;
		}
		else {
			cin >> number1 >> number2 >> sign;
		}
	}
	return 0;
}

