#include <iostream> 
#include <conio.h>
using namespace std;

int main() {
	cout << "Enter expression: first number +,-,*,/ second number  " << endl;
	char ch; 
	do {
		
		float  num1, num2, result;
		char sign;

		cin >> num1 >> sign >> num2;
		switch (sign) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;

		case '/':
			if (num2 == 0) {
				cout << " Can't be divided by 0 "; break;
			}
			else {
				result = num1 / num2;
				break;
			}
		case '*':
			result = num1 * num2;
			break;
		default:
			cout << " Sign unrecognised " << endl;
		}
		cout << "Result= " << result << endl;
		cout << "To exit the program press Esc. To continue - space." << endl;
		ch = _getch();
	} while (ch != 27);
	return 0;
}