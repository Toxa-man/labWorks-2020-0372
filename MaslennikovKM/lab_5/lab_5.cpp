#include <iostream>
#include <conio.h>

const int size = 3;
void plus(float matrix1[size][size], float matrix2[size][size], float res_matrix[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			res_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}
void minus(float matrix1[size][size], float matrix2[size][size], float res_matrix[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			res_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
}
void umnoj(float matrix1[size][size], float matrix2[size][size], float res_matrix[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			res_matrix[i][j] = 0;
			for (int m = 0; m < size; m++) {
				res_matrix[i][j] = res_matrix[i][j] + matrix1[i][m] * matrix2[m][j];
			}
		}
	}
}
void output(float res_matrix[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << res_matrix[i][j] << " ";
		}
		std::cout << std:: endl;
	}
}

int main() {
	char ch;
	float matrix1[size][size], matrix2[size][size], res_matrix[size][size];
	do {
		char button;
		std::cout << "Enter the first matrix:" << std::endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				std::cin >> matrix1[i][j];
			}
		}
		std::cout << std:: endl;
		std::cout << "Enter the second matrix:" << std::endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				std::cin >> matrix2[i][j];
			}
		}
			std::cout << std::endl;
		std:: cout << "What you want to do with the matrices, press one of the buttons 1-3:" << std::endl;
		std:: cout << "1) To add up the matrix" << std::endl;
		std:: cout << "2) Subtracting one matrix from another" << std::endl;
		std::cout << "3) Matrix multiplication" << std::endl;
		std::cin >> button;
		switch (button) {
		case '1':
			plus(matrix1, matrix2, res_matrix);
			std::cout << "Result: " << std::endl;
			output(res_matrix);
			break;
		case '2':
			minus(matrix1, matrix2, res_matrix);
			std::cout << "Result: " << std::endl;
			output(res_matrix);
			break;
		case '3':
			umnoj(matrix1, matrix2, res_matrix);
			std::cout << "Result: " << std::endl;
			output(res_matrix);
			break;
		}
		std:: cout << "Press esc, if you want exit or press any key to try again" << std:: endl;
		ch = _getch();
	} while (ch != 27);
	system("pause");
	return 0;
}