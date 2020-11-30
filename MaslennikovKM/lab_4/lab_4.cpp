#include <iostream>

float number_in_degree(float number, int degree) {
	float result = 1;
	if (degree > 0) {
		for (int i = 0; i < degree; ++i) {
			result = result * number;
		}
	}
	if ((degree < 0) && (number != 0)) {

		for (int i = 0; i < abs(degree); ++i) {
			result = result * 1 / number;
		}
	}
	if ((degree == 0) && (number != 0)) {
		result = 1;
	}
	return result;
}
int factorial(int num_factorial) {
	int res_factorial = 1;
	for (int i = 1; i <= num_factorial; i++) {
		res_factorial = res_factorial * i;
	}
	return res_factorial;
}
float sqrt_(float num_sqrt) {
	float res_sqrt;
	if (num_sqrt == 0) {
		res_sqrt = 0;
	}
	float x_n = 1;
	int count_loops = 30;
	while (count_loops > 0 || res_sqrt != x_n) {
		res_sqrt = x_n;
		x_n = (res_sqrt + num_sqrt / res_sqrt) / 2;
		count_loops--;
	}
	return res_sqrt;
}
bool prime(int prime_num) {
	if ((factorial(prime_num - 1) + 1) % prime_num == 0) {
		return true;
	}
	else {
	}
	return false;
}

int main() {
	float number; int degree; int num_factorial; float num_sqrt; int num_for_prime;
	std::cout << " Enter a number: " << std::endl;
	std::cin >> number;
	std::cout << " Enter degree of number: " << std::endl;
	std::cin >> degree;
	if ((degree <= 0) && (number == 0)) {
		std::cout << "Not defined" << std::endl;
	}
	else {
		std::cout << "Result: " << number_in_degree(number, degree) << std::endl;
	}
	std::cout << "Enter a number for the factorial: " << std::endl;
	std::cin >> num_factorial;
	if (num_factorial <= 0) {
		std::cout << "num_factorial must be > 0" << std::endl;
	}
	else {
		std::cout << "Factorial: " << factorial(num_factorial) << std::endl;
	}
	std::cout << "Enter a number for the squarerooting: " << std::endl;
	std::cin >> num_sqrt;
	if (num_sqrt < 0) {
		std::cout << "You can't extract the square root of a negative number." << std::endl;
	}
	else {
		std::cout << "Squarerootin result: " << sqrt_(num_sqrt) << std::endl;
	}
	std::cout << "Enter a number to test it for a Prime number" << std::endl;
	std::cin >> num_for_prime;
	if (num_for_prime <= 0) {
		std::cout << "Number must be > 0" << std::endl;
	}
	else {
		if (prime(num_for_prime) == true) {
			std::cout << "The number entered is prime number." << std::endl;
		}
		else {
			std::cout << "The number entered is composite number." << std::endl;
		}
	}
	return 0;
}