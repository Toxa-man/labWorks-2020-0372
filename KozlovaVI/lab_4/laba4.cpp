#include <iostream>
using namespace std;;
int vozv(int ch, int st) {
	if (st)
		return vozv(ch, --st) * ch;
	else return 1;
}
int stepen(int ch) {
	int st;
	cout << " Enter degree\n";
	cin >> st;
	return vozv(ch, st);
}
int factorial(int P) {
	if (P)
		return factorial(P - 1) * P;
	else return 1;
}
double koren(int ch) {
	if (ch < 0) { return 0; }
	double rez = 0;
	while (rez * rez <= ch) { rez++; }
	rez--;
	if (rez * rez == ch) { return rez; }
	rez *= 10; ch *= 100;
	while (rez * rez <= ch) { rez++; }
	rez--;
	if (rez * rez == ch) { return rez/10; }
	rez *= 10; ch *= 100;
	while (rez * rez <= ch) { rez++; }
	rez--;
	 return rez/100; 
}
bool prost(int ch) {
	if (ch >= 0 && ch < 4) {
		return true;
	}
	else {
		for (int i = 2; i < ch; i++) {
			if (ch % i == 0) {
				return false;
			}
		}
	return true;
	}
}
int todo(int ukazatel, int ch) {
	switch (ukazatel) {
	case 1:
		cout << stepen(ch);
		break;
	case 2:
		cout << factorial(ch);
		break;
	case 3:
		cout << koren(ch);
		break;
	case 4:
		cout << prost(ch);
		break;
	}
	if (ukazatel > 4|| ukazatel < 1) {
		cout << "ERROR";
	}
	return 0;
}
int main()
{
	int ch; int ukazatel;
	cout << "Enter number" << endl;
	cin >> ch;
	cout << "What to do?\n" << "Raise a number to a power - press 1\n" << "Find a factorial - press 2\n";
	cout << "Find the square root - press 3\n" << "Find out if a prime number - press 4\n";
	cin >> ukazatel;
	todo(ukazatel, ch);

	return 0;
}
