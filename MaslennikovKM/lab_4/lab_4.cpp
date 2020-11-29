#include <iostream>

float number_in_degree(float number, int degree) {
	float result = 1;
	if ((degree <= 0) && (number == 0)) {
		std::cout << "Not defined" << std::endl;
		return 0;
	}
	if (degree > 0) {
		for (int i = 0; i < degree; ++i) {
			result = result * number;
		}
	}
	if ((degree < 0) && (number!=0)) {

		for (int i = 0; i < abs(degree); ++i) {
			result = result * 1/number;
		}
	}
	if ((degree == 0) && (number !=0)) {
		result = 1;
	}
	std::cout << "Result: " << result << std::endl;
	return 0;
}
int factorial(int num_factorial) {
	int res_factorial = 1;
	if (num_factorial <= 0) {
		std::cout << "num_factorial must be > 0";
		return 0;
	}
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
	if (num_sqrt < 0) {
		std::cout << "You can't extract the square root of a negative number." << std::endl;
		return 0;
	}
	float x_n = 1;
	int count_loops = 30;
	while (count_loops > 0 || res_sqrt != x_n) {
		res_sqrt = x_n;
		x_n = (res_sqrt + num_sqrt / res_sqrt) / 2;
		count_loops--;
	}
	std::cout << "Squarerootin result: " << res_sqrt << std::endl;
	return 0;
}
int prime(int prime_num) {
	if (prime_num <= 0) {
		std::cout << "Number must be > 0" << std::endl;
		return 0;
	}
	if ((factorial(prime_num - 1) + 1) % prime_num == 0) {
		std::cout << "The number entered is a Prime number." << std::endl;
	}
	else {
		std::cout << "The number entered is composite number." << std::endl;
	}
	return 0;
}

int main() {
	float number; int degree; int num_factorial; float num_sqrt; int num_for_prime;
	std::cout << " Enter a number: " << std:: endl;
	std::cin >> number;
	std::cout << " Enter degree of number: " << std::endl;
	std::cin >> degree;
	number_in_degree(number, degree);
	std::cout << "Enter a number for the factorial: " << std::endl;
	std::cin >> num_factorial;
	std::cout << "Factorial of number: " << factorial(num_factorial) << std::endl;
	std::cout << "Enter a number for the squarerooting: " << std::endl;
	std::cin >> num_sqrt;
	sqrt_(num_sqrt);
	std::cout << "Enter a number to test it for a Prime number" << std::endl;
	std::cin >> num_for_prime;
	prime(num_for_prime);
	return 0;
}