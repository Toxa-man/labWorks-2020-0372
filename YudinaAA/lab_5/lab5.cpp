#include <iostream>
#include <conio.h>

using namespace std;

const int n = 3;

void multiplication(int matrix1[n][n], int matrix2[n][n], int matrix3[n][n]) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			matrix3[i][j] = 0;
			for (int m = 0; m < n; m++)
				matrix3[i][j] += matrix1[i][j] * matrix2[i][j];
		}
}

void addition(int matrix1[n][n], int matrix2[n][n], int matrix3[n][n]) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
}

void subtraction(int matrix1[n][n], int matrix2[n][n], int matrix3[n][n]) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
}

void print(int matrix3[n][n]) {
	cout << "result:" << endl;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix3[i][j] << " ";
		}
		cout << endl;
	}
}

	int main() {
		int operation, matrix1[n][n], matrix2[n][n], matrix3[n][n];
		char ch;

		do {
			cout << "enter first matix:" << endl;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					cout << "element " << i+1 << "," << j+1 << " = ";
					cin >> matrix1[i][j];
				}
			cout << "enter second matix:" << endl;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					cout << "element " << i+1 << "," << j+1 << " = ";
					cin >> matrix2[i][j];
				}

			cout << "choose operation:" << endl;
			cout << "press 1 to multiply" << endl;
			cout << "press 2 to add" << endl;
			cout << "press 3 to subtract" << endl;
			cin >> operation;

			switch (operation) {
			case(1):
				multiplication(matrix1, matrix2, matrix3);
				print(matrix3);
				break;
			case(2):
				addition(matrix1, matrix2, matrix3);
				print(matrix3);
				break;
			case(3):
				subtraction(matrix1, matrix2, matrix3);
				print(matrix3);
				break;
			default:
				cout << "wrong type!" << endl;
			}

			cout << "press esc if you are finished" << endl;
		ch = _getch();
} while (ch != 27);
return 0;
}
