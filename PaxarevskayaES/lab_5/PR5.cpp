#include <iostream>
#include <conio.h>

void multiplication(int** pmatrix1, int** pmatrix2, int** resultmatrix, int rows, int cols1, int cols2) {
	int sum_of_elements = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols2; j++) {
			for (int k = 0; k < cols1; k++) {
				sum_of_elements += pmatrix1[i][k] * pmatrix2[k][j];
			}
			resultmatrix[i][j] = sum_of_elements;
			sum_of_elements = 0;
		}
 	}
}

void sum(int **pmatrix1, int **pmatrix2, int **resultmatrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			resultmatrix[i][j] = pmatrix1[i][j] + pmatrix2[i][j];
}

void subtract(int** pmatrix1, int** pmatrix2, int** resultmatrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			resultmatrix[i][j] = pmatrix1[i][j] - pmatrix2[i][j];
}

char escape;
int main() {
	int rows1, cols1, rows2, cols2;
	char act;
	char escape;
	do {

		// we introduce matrices
		std::cout << "Enter the size of the first matrix." << std::endl;
		std::cout << "Number of lines: ";
		std::cin >> rows1;
		std::cout << "Number of columns: ";
		std::cin >> cols1;

		int** pmatrix1 = new int* [rows1];

		std::cout << "Enter the matrix line by line" << std::endl;
		for (int i = 0; i < rows1; i++) {
			pmatrix1[i] = new int[cols1];
			for (int j = 0; j < cols1; j++) 
				std::cin >> pmatrix1[i][j];
		}

		std::cout << "Enter the size of the second matrix." << std::endl;
		std::cout << "Number of lines: ";
		std::cin >> rows2;
		std::cout << "Number of columns: ";
		std::cin >> cols2;

		int** pmatrix2 = new int* [rows2];

		std::cout << "Enter the matrix line by line" << std::endl;
		for (int i = 0; i < rows2; i++) {
			pmatrix2[i] = new int[cols2];
			for (int j = 0; j < cols2; j++)
				std::cin >> pmatrix2[i][j];
		}

		// choose action
		std::cout << "Enter the number of the action you are interested in." << std::endl;
		std::cout << "Press 1 to multiply matrices" << std::endl;
		std::cout << "Press 2 to add  matrices" << std::endl;
		std::cout << "Press 3 to subtract  matrices" << std::endl;
		while (!(std::cin >> act) or not('0' < act and act <= '3')) {
			std::cout << "Wrong input" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}

		// create matrix-result
		int** resultmatrix = new int* [rows2];
		for (int i = 0; i < rows2; i++)
			resultmatrix[i] = new int[cols1];

		// action on a matrix
		switch (act) {
		case '1':
			if (rows2 != cols1)
				std::cout << "Action cannot be performed, try again" << std::endl;
			else {
					multiplication(pmatrix1, pmatrix2, resultmatrix, rows1, cols1, cols2);
				break;
		case '2':
			if (rows1 != rows2 or cols1 != cols2)
				std::cout << "Action cannot be performed, try again" << std::endl;
			else {
				sum(pmatrix1, pmatrix2, resultmatrix, rows1, cols1);
			}
			break;
		case '3':
			if (rows1 != rows2 or cols1 != cols2)
				std::cout << "Action cannot be performed, try again" << std::endl;
			else {
				subtract(pmatrix1, pmatrix2, resultmatrix, rows1, cols1);
			}
			break;
			}
		}

		// display the result
		std::cout << "Our result:" << std::endl;
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < cols2; j++)
				std::cout << resultmatrix[i][j] << "\t";
			std::cout << "\n";
		}

		// clearing the matrices
		for (int i = 0; i < rows1; i++) 
			delete[] pmatrix1[i];
		delete[] pmatrix1;

		for (int i = 0; i < rows2; i++) 
			delete[] pmatrix2[i];
		delete[] pmatrix2;

		for (int i = 0; i < rows2; i++) 
			delete[] resultmatrix[i];
		delete[] resultmatrix;

		std::cout << "Press esc to exit or any other key to continue" << std::endl;
		escape = _getch();
	} while (escape != 27);
	return 0;
}