#include <iostream>
#include <string.h>

int our_number;
int degree;

long degree_of(int our_number, int degree) {
	long int new_number = 1;
	while (degree != 0) {
		new_number *= our_number;
		degree -= 1;
	}
	return new_number;
}

long int factorial(int our_number) {
	long int result = 1;
	for (int i = 1; i <= our_number; i++) {
		result *= i;
	}
	return result;
}

// We use the Geron's method
double root(int our_number) {
	double result = 0;
	int number_1 = 0, number_2 = 0;
	for (int i = 0; i <= our_number; i++) {
		if (i*i <= our_number)
			number_1 += 1;
	}
	number_2 = number_1 + 1;
	if (abs(our_number - number_1) < abs(our_number - number_1)) {
		result = (number_1 + (double(our_number / number_1))) / 2;
	}
	else
		result = (number_2 + (double(our_number / number_2))) / 2;
	return result;
}

std::string simple(int our_number) {
	std::string answer;
	int counter = 0;
	for (int i = 1; i <= our_number; i++) {
		if (our_number % i == 0)
			counter++;
	}
	if (counter > 2)
		answer = "is not  prime mumber";
	else
		answer = "is prime mumber";
	return answer;
}

int main()
{
	std::cout << "Enter your number" << std::endl;
	std::cin >> our_number;
	std::cout << "Enter degree of new number" << std::endl;
	std::cin >> degree;
	std::cout << "Your number to the " << degree << " power: " << degree_of(our_number, degree) << std::endl;
	std::cout << "Factorial of your number: " << factorial(our_number) << std::endl;
	std::cout << "Square root of your number: " << root(our_number) << std::endl;
	std::cout << "Your number " << simple(our_number) << std::endl;
	return 0;
}