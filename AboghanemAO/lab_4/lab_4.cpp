#include <iostream>
#include <math.h> 


double power(int num, int to_power) {
	double answer = 1;
	if (to_power == 0) { return 1; }
	for (int i = 0; i < abs(to_power); i++) {
		answer *= num;
	}
	if (to_power > 0) { return answer; }
	else{ return 1/answer;}
}


 int factorial(int num) {
	if (num == 0) { return 1; }
	if (num < 0) { return -1; }
	int answer = 1;
	for (int i = 1; i <= num ; i++) {
		answer *= i;
	}
	return answer;
}


double square_root(int num) {
	if (num == 0) return 0;
	if (num < 0) return -1;
	double answer = 0 ;
	double temp = 1;				

	while (answer != temp) {
		answer = temp;
		temp = (answer + num / answer) / 2;
	}
	return answer;
}


bool prime(int num) {
	if (num <= 1) return "Not Prime";

	for (int i = 2; i < num; i++) {
		if (num % i == 0) { return false; }
	}
	return true;
}

int main() {
	int test1[5] = {1,0,25,9,4};
	int test2[5] = {10,2,1,0,-2};
	int test3[5] = { 2,4,3,9,7 };
	double test1_poowr_test2[5] = {1,0,25,1,0.0625};
	int factorial_test2[5] = {3.6288E+6,2,1,1,-1};
	double Square_root_test1[5] = {1,0,5,3,2};
	bool prime_test3[5] = { true,false,true, false,true };



	std::cout << "------Exponentiation------\n" ;
	for (int i = 0; i < 5 ;i++ )
	{
		std::cout << test1[i] << '^' << test2[i] <<" = " << test1_poowr_test2[i] <<" ";
		if (power(test1[i], test2[i]) == test1_poowr_test2[i]) { std::cout << "True\n"; }
		else { std::cout << "False\n"; }
	}
	

	std::cout << "\n------Factorial------\n";
	for (int i = 0; i < 5;i++)
	{
		std::cout << test2[i] << "! = " << factorial_test2[i] << " ";
		if (factorial(test2[i]) == factorial_test2[i]) { std::cout << "True\n"; }
		else { std::cout << "False\n"; }
	}
	

	std::cout << "\n------Square root------\n";
	for (int i = 0; i < 5;i++)
	{
		std::cout << test1[i] << "^ 0.5 = " << Square_root_test1[i] << " ";
		if (square_root(test1[i]) == Square_root_test1[i]) { std::cout << "True\n"; }
		else { std::cout << "False\n"; }
	}

	

	std::cout << "\n------Prime------" << std::endl;
	for (int i = 0; i < 5;i++)
	{
		std::cout << test3[i] << " is " << prime_test3[i] << " ";
		if (prime(test3[i]) == prime_test3[i] ){ std::cout << "True\n"; }
		else { std::cout << "False\n"; }
	}
	

	system("pause");
	return 0;
}