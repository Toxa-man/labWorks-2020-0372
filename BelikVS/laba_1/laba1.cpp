#include <iostream>
using namespace std;



double Plus(double x, double y) {
	return x + y;
}
double Minus(double x, double y) {
	return x - y;
}
double Divide(double x, double y) {
	if (y == 0) {
		cout << "Error! Divide by 0!"<<endl;
		return 0;
	}
	return x / y;
}
double Multiply(double x, double y) {
	return x * y;
}


int main()
{
	double number1, number2;
	char symbol;
	bool exit = 0;

	do {

		cout << "Enter two numbers:" << endl;
		cin >> number1 >> number2;
		cout << "Enter a maths symbol:" << endl;
		cin >> symbol;

		switch (symbol)
		{
		case '+':
			cout <<"Answer: "<< Plus(number1, number2) << endl;
			break;
		case '-':
			cout << "Answer: "<< Minus(number1, number2) << endl;
			break;
		case '/':
			cout << "Answer: "<< Divide(number1, number2) << endl;
			break;
		case '*':
			cout << "Answer: " << Multiply(number1, number2) << endl;
			break;
		default:
			cout << "Sorry I don't know this maths operation, please enter +,-,*,/";
			break;
		}
		cout << "Enter 0 if you want try other numbers or 1 to exit"<< endl;
		cin >> exit;
	} while (exit != 1);


	return 0;
}
