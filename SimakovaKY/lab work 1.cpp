#include <iostream> 
#include <conio.h>
using namespace std;
char ch = _getch();
int main() {
	do {
		
		float  x;
		float  y;
		char sign;

		cin >> x >> sign >> y;
		switch (sign) {
		case '+':
			cout << "Result = " << x + y;
			break;
		case '-':
			cout << "Result = " << x - y;
			break;
		
		case '/':
			if (y == 0) {
				cout << " Can't be divided by 0 "; break;
			}
			 else {
				cout << "Result = " << x / y;
				break;}
		case '*':
			cout << "Result = " << x * y;
			break;
		default:
			cout << " Sign unrecognised " << endl;
		} 
	} while (ch != 27);
		return 0; 
	} 
