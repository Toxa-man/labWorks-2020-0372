#include <iostream>
#include <conio.h>
#include <ctime>

void sum(int** matrix_1, int** matrix_2, int** matrix_X, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		matrix_X[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			matrix_X[i][j] = matrix_1[i][j] + matrix_2[i][j];
			std::cout << matrix_X[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

void min(int** matrix_1, int** matrix_2, int** matrix_X, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		matrix_X[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			matrix_X[i][j] = matrix_1[i][j] + matrix_2[i][j];
			std::cout << matrix_X[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

void multi(int** matrix_1, int** matrix_2, int** matrix_X, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		matrix_X[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			matrix_X[i][j] = matrix_1[i][j] + matrix_2[i][j];
			std::cout << matrix_X[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

int main()
{
	srand(time(0));
	char keycheck;
	do
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		system("cls");
		int rows = 0, columns = 0;
		std::cout << "Enter number of rows and columns:\n";
		std::cin >> rows >> columns;
		std::cout << '\n';

		int** matrix_X = new int* [rows]();

		int** matrix_1 = new int* [rows]();
		for (int i = 0; i < rows; i++)
		{
			matrix_1[i] = new int[columns];
			for (int j = 0; j < columns; j++)
			{
				matrix_1[i][j] = rand() % 100;
				std::cout << matrix_1[i][j] << '\t';
			}
			std::cout << '\n';
		}

		std::cout << '\n';

		int** matrix_2 = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix_2[i] = new int[columns]();
			for (int j = 0; j < columns; j++)
			{
				matrix_2[i][j] = rand() % 100;
				std::cout << matrix_2[i][j] << '\t';
			}
			std::cout << '\n';
		}

		std::cout << '\n';

		char act;
		std::cout << "Choose (+, -, *): ";
		std::cin >> act;
		std::cout << '\n';

		switch (act)
		{
		case '+':
			sum(matrix_1, matrix_2, matrix_X, rows, columns);
			break;
		case '-':
			min(matrix_1, matrix_2, matrix_X, rows, columns);
			break;
		case '*':
			multi(matrix_1, matrix_2, matrix_X, rows, columns);
			break;
		}

		for (int i = 0; i < rows; i++)
			delete[] matrix_1[i];
		delete[] matrix_1;
		for (int i = 0; i < rows; i++)
			delete[] matrix_2[i];
		delete[] matrix_2;
		for (int i = 0; i < rows; i++)
			delete[] matrix_X[i];
		delete[] matrix_X;

		std::cout << "\nPress ESC to end.\nPress any button to continue\n";
		keycheck = _getch();
	} while (keycheck != 27);
}
