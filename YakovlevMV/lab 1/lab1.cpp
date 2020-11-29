#include <iostream>
#include <conio.h>

using namespace std;

int main()

{
	float first_oper, second_oper;
	char znak, ch;
	setlocale(LC_ALL, "Rus");
	do {
		cout << "Введите выражение: " << endl;
		cin >> first_oper;
		cin >> second_oper;
		if (cin.good() == true) {
			cin >> znak;
			if (znak != '+' && znak != '-' && znak != '/' && znak != '*') {
				cout << "error! write the correct operator! Press Enter" << endl;
			}
			else {
				switch (znak) {
				case '+': {
					cout << first_oper + second_oper << endl;
					break;
				}
				case '-': {
					cout << first_oper - second_oper << endl;
					break;
				}
				case '/':
					if (second_oper != 0) {
						cout << first_oper / second_oper << endl; break;
					}
					else if (second_oper == 0) {
						cout << "error! second operator cannot be zero! Press Enter" << endl; 
						break;
					}
				case '*': {
					cout << first_oper * second_oper << endl;
					break;
				}
				default: {
					cout << "error! write the correct operator! Press Enter" << endl;
					break;
				}
				}
			}
		}
		else {
			cout << "Write the correct operator! Press Enter" << endl;

			cin.ignore(32767, '/n');
			cin.clear();
			break;
		}
		ch = _getch();
	} while (ch != 27);
}
