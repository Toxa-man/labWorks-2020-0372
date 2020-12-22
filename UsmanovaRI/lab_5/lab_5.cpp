#include<iostream>
#include <conio.h>
using namespace std;


void additiaddition(int** arr, int** arr2, int n, int m) {
	int** matrix_3 = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix_3[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix_3[i][j] = arr[i][j] + arr2[i][j];
		}
	}
	cout << "result:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix_3[i][j] << "\t";
		}
		cout << endl;
	}
	delete[]matrix_3;
}
void subtraction(int** arr, int** arr2, int n, int m) {
	int** matrix_3 = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix_3[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix_3[i][j] = arr[i][j] - arr2[i][j];
		}
	}
	cout << "result:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix_3[i][j] << "\t";
		}
		cout << endl;
	}
	delete[]matrix_3;
}
void multiplication(int** arr, int** arr2, int n, int m, int n1, int m2) {
	int** matrix_3 = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix_3[i] = new int[m2];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m2; j++) {
			matrix_3[i][j] = 0;
			for (int k = 0; k < m; k++) {
				matrix_3[i][j] += arr[i][k] * arr2[k][j];
			}
		}
	}
	cout << "result:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m2; j++) {
			cout << matrix_3[i][j] << "\t";
		}
		cout << endl;
	}
	delete[]matrix_3;
}
int main() {
	const int out = 27;
	int row_1, column_1, row_2, column_2;
	char sign;
	do { 
	cout << "enter the operation" << endl;
	cin >> sign;
	cout << "enter the size of  1 matrix" << endl;
	cin >> row_1 >> column_1;
	cout << "enter the size of  2 matrix" << endl;
	cin >> row_2 >> column_2;
	if (sign == '+' || sign == '-') {
		if (row_1 != row_2 || column_1 != column_2) {
			cout << "incompatible size of matrices\n";
			return 0;
		}

	}
	if (sign == '*') {
		if (column_1 != row_2) {
			cout << "incompatible size of matrices\n";
			return 0;
		}
	}
	int** matrix_1 = new int* [row_1];
	int** matrix_2 = new int* [row_2];
	cout << "enter to 1 matrix" << endl;
	for (int i = 0; i < row_1; i++) {
		matrix_1[i] = new int[column_1];
	}
	for (int i = 0; i < row_1; i++) {
		for (int j = 0; j < column_1; j++) {
			cin >> matrix_1[i][j];
		}
	}
	cout << "enter to 2 matrix" << endl;
	for (int i = 0; i < row_2; i++) {
		matrix_2[i] = new int[column_2];
	}
	for (int i = 0; i < row_2; i++) {
		for (int j = 0; j < column_2; j++) {
			cin >> matrix_2[i][j];
		}
	}
	cout << endl;
	switch (sign)
	{
	case '+':
		additiaddition(matrix_1, matrix_2, row_1, column_1);
		break;
	case '-':
		subtraction(matrix_1, matrix_2, row_1, column_1);
		break;
	case'*':
		multiplication(matrix_1, matrix_2, row_1, column_1, row_2, column_2);
		break;
	default:
		cout << "invalid operation" << endl;
		return 0;
		break;
	}
	cout << "Click 'Esc' to exit" << endl;
}
	while (_getch() != out);
	system("pause");
	return 0;

}
