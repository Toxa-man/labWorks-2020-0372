#include <iostream> 
#include <conio.h>
using namespace std;
char ch = _getch();
int main() {
	cout << "Enter expression: first number +,-,*,/ second number  " << endl;
	do {
		
		float  num1, num2, result;
		char sign;
		
		cin >> num1 >> sign >> num2;
		switch (sign) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result =  num1 - num2;
			break;
		
		case '/':
			if (num2 == 0) {
				cout << " Can't be divided by 0 "; break;
			}
			 else {
				result = num1 / num2;
				break;}
		case '*':
			result = num1 * num2;
			break;
		default:
			cout << " Sign unrecognised " << endl;
		} 
		cout << "Result= " << result;
	} while (ch != 32);
		return 0; 
	} 
