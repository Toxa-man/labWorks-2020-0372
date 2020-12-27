#include<iostream>
using namespace std;

//возведение в степень
	int degree(int number, int power)
	{
		int stepen = 1;
		if (power == 0) {
			return 1;
		}
		for (int i = 1; i <= power; i++) {
			stepen = stepen * number;
		}
		return stepen;
	}

	//факториал числа
	int factorial(int number) {
		long int factorial = 1;
		for (int i = 1; i <= number; i++) {
			factorial = factorial * i;
		}
		return factorial;
	}

	//вычисление квадратного корня
	double sqrt(int number) {
		int i = 0;
		int ostatok = number;
		double sqrt;
		while (ostatok > 0) {
			i++;
			ostatok = number - i * i;
		}
		double ostatok_1 = ostatok,i_1 = i;
		sqrt = i_1 + ostatok_1 / (i_1 * 2);
		return sqrt;
	}

	//определие простоты числа
	string simple(int number) {
		bool simpl = true;
		if (number == 1) {
			return "the number is simple";
			}
		for (int i = 2; i <= number/2; i++) {
			if (number % i == 0) {
				simpl = false;
			}
			if (simpl) {
				return "the number is simple";
			}
			else {
				return "the number is not simple";
			}
		}
	}
	int main(){
		int number_1, number_2;
		cout << "Enter the number and exponent" << endl;
	
		cin >> number_1 >> number_2;
		cout << "number " <<  number_1 << " to the power of " << number_2 << " = " << degree(number_1, number_2) << endl;
		cout << "factorial of " << number_1 << " = " << factorial(number_1) << endl;
		cout << "square root of a " << number_1 << " = " << sqrt(number_1) << endl;
		cout << simple(number_1);
	return 0;
}
