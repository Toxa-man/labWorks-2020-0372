#include <iostream>

using namespace std;

int main() {
	float num1, num2;
	char op;

	while (true) {
		cout << "Type two numbers and an operator in this format 'num num op': ";
		cin >> num1 >> num2 >> op;

		switch (op) {
		case '+':
			cout << "Result: " << num1 + num2 << endl;
			break;
		case '-':
			cout << "Result: " << num1 - num2 << endl;
			break;
		case '*':
			cout << "Result: " << num1 * num2 << endl;
			break;
		case '/':
			if (!num2) {
				cout << "Error: Dividing by zero!" << endl;
			}
			else {
				cout << "Result: " << num1 / num2 << endl;
			}
			break;
		default:
			cout << "The operator does not exist!\n" << endl;
			continue;
		}
		break;
	}

	system("pause");
	return 0;
}