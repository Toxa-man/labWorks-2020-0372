#include <iostream>
#include <conio.h>


void sum(int **matrix1, int **matrix2, int **result, int rows, int columns){
    for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++) result[i][j] = matrix1[i][j] + matrix2[i][j];
}

// difference
void diff(int **matrix1, int **matrix2, int **result, int rows, int columns){
    for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++) result[i][j] = matrix1[i][j] - matrix2[i][j];
}


void multiplication(int **matrix1, int **matrix2, int **result, int rows, int columns2, int columns1) {
    int row_sum;
    for (int i = 0; i < rows; i++) {
        for (int column = 0; column < columns2; column++){
            row_sum = 0;
            for (int j = 0; j < columns1; j++) row_sum += matrix1[i][j] * matrix2[j][column];
            result[i][column] = row_sum;
        }
    }
}


int main() {
    int rows1, rows2, columns1, columns2;
    char exit_char;

    do {
        std::cout << "Enter first matrix rows count:";
        std::cin >> rows1;
        std::cout << "Enter first matrix columns count:";
        std::cin >> columns1;

        int **matrix1 = new int* [rows1];

        std::cout << "Enter first matrix:\n";
        for (int i = 0; i < rows1; i++){
            matrix1[i] = new int [columns1];
            for (int j = 0; j < columns1; j++) std::cin >> matrix1[i][j];
        }

        std::cout << "Enter second matrix rows count:";
        std::cin >> rows2;
        std::cout << "Enter second matrix columns count:";
        std::cin >> columns2;

        int **matrix2 = new int* [rows2];

        std::cout << "Enter second matrix:\n";
        for (int i = 0; i < rows2; i++){
            matrix2[i] = new int [columns2];
            for (int j = 0; j < columns2; j++) std::cin >> matrix2[i][j];
        }

        int action;
        std::cout << "Select desired action:\n";
        std::cout << "1) Matrix addition.\n";
        std::cout << "2) Matrix multiplication.\n";
        std::cout << "3) Matrix difference.\n";
        std::cout << ">";

        while (!(std::cin >> action) or not (0 < action and action <= 3)){
            std::cout << "Wrong input\n" << std::endl;
            std::cout << "Select desired action:\n";
            std::cout << "1) Matrix addition.\n";
            std::cout << "2) Matrix multiplication.\n";
            std::cout << "3) Matrix difference.\n";
            std::cout << ">";
            std::cin.clear();
            std::cin.ignore();
        }

        int **result = new int* [rows1];
        for (int i = 0; i < rows1; i++) result[i] = new int [columns2];

        switch (action) {
            case 1:
                if (rows1 == rows2 and columns1 == columns2) sum(matrix1, matrix2, result, rows1, columns1);
                else std::cout << "You can sum only equal size matrices";
                break;
            case 2:
                if (rows2 == columns1) multiplication(matrix1, matrix2, result, rows1, columns2, columns1);
                break;
            case 3:
                if (rows1 == rows2 and columns1 == columns2) sum(matrix1, matrix2, result, rows1, columns1);
                else std::cout << "You can get difference only equal size matrices";
                diff(matrix1, matrix2, result, rows1, columns1);
                break;

        }

        for (int i = 0; i < rows1; i++) delete [] matrix1[i];
        delete [] matrix1;

        for (int i = 0; i < rows2; i++) delete [] matrix2[i];
        delete [] matrix2;

        for (int i = 0; i < rows1; i++){
            for (int j = 0; j < columns2; j++) std:: cout << result[i][j] << " ";
            std::cout << '\n';
        }

        for (int i = 0; i < rows1; i++) delete [] result[i];
        delete [] result;

        std::cout << "Press ESC to exit program\n";
        exit_char = _getch();
    } while (exit_char != 27);
    return 0;
}