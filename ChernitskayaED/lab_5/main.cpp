#include <iostream>
#include <conio.h>
using namespace std;

const int s = 3;

void addition(int matrix_1[s][s], int matrix_2[s][s], int matrix_3[s][s])
{
	{
		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++)
				matrix_3[i][j] = matrix_1[i][j] + matrix_2[i][j];
	}
}
void multiplication(int matrix_1[s][s], int matrix_2[s][s], int matrix_3[s][s]) 
{
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++) 
		{
			matrix_3[i][j] = 0;
			for (int m = 0; m < s; m++)
				matrix_3[i][j] += matrix_1[i][j] * matrix_2[i][j];
		}
}
void subtraction(int matrix_1[s][s], int matrix_2[s][s], int matrix_3[s][s])
{
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			matrix_3[i][j] = matrix_1[i][j] - matrix_2[i][j];
}
void result(int matrix_3[s][s])
{
	cout << "Result: " << endl;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << matrix_3[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	char ch;
	int matrix_1[s][s], matrix_2[s][s], matrix_3[s][s];
	do {

		cout << "Enter the elements of the first matrix:" << endl;
		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++)
			{
				cout << "Element number " << i + 1 << "," << j + 1 << " = ";
				cin >> matrix_1[i][j];
			}
		cout << "Enter the elements of the second matrix:" << endl;
		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++)
			{
				cout << "Element number " << i + 1 << "," << j + 1 << " = ";
				cin >> matrix_2[i][j];
			}

		char sing;
		cout << "Choose operation with matrix: " << endl;
		cin >> sing;
		switch (sing)
		{
		case'+':
			addition(matrix_1, matrix_2, matrix_3);
			result(matrix_3);
			break;
		case'-':
			subtraction(matrix_1, matrix_2, matrix_3);
			result(matrix_3);
			break;
		case'*':
			multiplication(matrix_1, matrix_2, matrix_3);
			result(matrix_3);
			break;
		default: cout << "Wrong type" << endl;
			break;
			
		} 
		cout << "Press esc if you're finished" << endl;
		ch = _getch();
	} while (ch != 27);
	return 0;
}
