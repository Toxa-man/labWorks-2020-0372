#include <iostream>

double power(float num1, float num2)
{
	if (num2 > 0)
	{
		int bruh = num1;
		for (int i = 0; i < num2 - 1; i++)
			num1 *= bruh;
		return num1;
	}
	if (num2 == 0)
		return 1;
	if (num2 < 0)
	{

	}
}

int factorial(int n)
{
	int x = 1;
	if (n > 0)
	{
		for (int i = n; i > 1; i--)
		{
			x *= i;
		}
		return x;
	}
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
}

// CTRL+C & CTRL+V -- http://www.codenet.ru/progr/alg/sqrt.php
float squareRoot(int n)
{
	float rslt = n;
	float div = n;
	if (n <= 0)
		return 0;
	while (true)
	{
		div = (n / div + div) / 2;
		if (rslt > div)
			rslt = div;
		else
			return rslt;
	}
}

bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	float num1, num2;
	std::cout << "Well, x to the power of y (enter x and y)\n";
	std::cin >> num1 >> num2;
	std::cout << power(num1, num2) << '\n';


	int n;
	std::cout << "Well, factorial of x (enter x)\n";
	std::cin >> n;
	std::cout << factorial(n) << '\n';


	std::cout << "Well, square root of x (enter x)\n";
	std::cin >> n;
	std::cout << squareRoot(n) << '\n';


	std::cout << "Well, u wanna know if x is prime? (enter x)\n";
	std::cin >> n;
	if (isPrime(n))
		std::cout << "Yeap, it's prime\n";
	else
		std::cout << "No, it's not a prime number\n";
}
