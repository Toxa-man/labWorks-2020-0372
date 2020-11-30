#include <iostream> 
using namespace std;

double power(int number, int power)
{
	double answer = 1;
	if (power == 0) { return 1; }
	for (int i = 0; i < abs( power); i++) {
		answer *= number;
	}
	if ( power > 0) { return answer; }
	else { return 1 / answer; }
}


int factorial(int number)
{
	if (number == 0) { return 1; }
	if (number < 0) { return -1; }
	int answer = 1;
	for (int i = 1; i <= number; i++)
	{
		answer *= i;
	}
	return answer;
}


double square_root(int number)
{
	if (number == 0) return 0;
	if (number < 0) return -1;
	double answer = 0;
	double temp = 1;

	while (answer != temp)
	{
		answer = temp;
		temp = (answer + number / answer) / 2;
	}
	return answer;
}


bool prime(int number) 
{
	for (int i = 2; i <= square_root(number); i++)
		if (number % i == 0)
			return false;
	return true;
}
int main()
{
	cout << power (2, 8) << "\n";
	cout << factorial(9) << "\n";
	cout << square_root(64) << "\n";
	cout << prime(9) << "\n";
	system("pause");
	return 0;
}