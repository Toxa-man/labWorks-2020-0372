

#include <iostream>
#include <cmath>
using namespace std;

float factorial(float n) {
	if (n > 0) {
		int result = 1, i = 0;
		result *= i;
		return result;
	}
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
}
float Sqrt(int k) {
	if (k > 0) {
	return sqrt(k);
	}
	if (k == 0) {
		return 0;
	}
	if (k < 0) {
		cout << "Error" << endl;
	}
	
}

bool Prime(int c){
	if (c > 1) {
		for (int i = 2; i < c; i++) 
			if (c % i == 0)
				return false;
		return true;
	}
	else 
		return false;			
}

int main(){
	//1
	cout << "Raising the number 'a' to the power 'b'. Enter 'a' then 'b'. " << endl;
	float a;
	int b;
	cin >> a >> b;
	cout << pow(a, b) << endl;

	//2
	cout << "Enter the number to calculate the factorial. " << endl;
	float n;
	cin >> n;
	cout << factorial(n) << endl;

	//3
	cout << "Enter the number to calculate the root of this number. " << endl;
	int k;
	cin >> k;
	cout << Sqrt(k) << endl;

	//4
	cout << "Enter the number you want to check prime number or not. " << endl;
	int c;
	cin >> c;
	if (Prime(c) == true) {
		cout << "Yes";
	}
	else
		cout << "No";
	
}
