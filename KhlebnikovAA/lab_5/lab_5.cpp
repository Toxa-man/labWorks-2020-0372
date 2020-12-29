#include <iostream>
#include <ctime>

const int size = 3;

void cout_matrix(int matrix3[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix3[i][j] << " ";

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void sum(int matrix[size][size], int matrix2[size][size], int matrix3[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix3[i][j] = matrix2[i][j] + matrix[i][j];

        }

    }
    cout_matrix(matrix3);
}

void multip(int matrix[size][size], int matrix2[size][size], int matrix3[size][size]) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix3[i][j] = 0;
            for (int t = 0; t < size; t++) {
                matrix3[i][j] += matrix[i][t] * matrix2[t][j];
            }
        }
    }
    cout_matrix(matrix3);
}

void subtr(int matrix[size][size], int matrix2[size][size], int matrix3[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix3[i][j] = matrix[i][j] - matrix2[i][j];

        }

    }
    cout_matrix(matrix3);
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int matrix[size][size], matrix2[size][size], matrix3[size][size];
    int command=1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }

    }
    std::cout << "Первая матрица: " << std::endl; 
    cout_matrix(matrix);
    std::cout << "Вторая матрица: " << std::endl;
    cout_matrix(matrix2);
    while (command != 0) {
        std::cout << "Что сделать: \n1) Умножить матрицы. \n2) Сложить матрицы. \n3) Вычесть матрицы. \n0) ВЫйти." << std::endl << std::endl;
        std::cin >> command;
        std::cout << std::endl;
        switch (command) {
        case 1: //умножение
            multip(matrix, matrix2, matrix3); break;
        case 2: //сложение
            sum(matrix, matrix2, matrix3); break;
        case size: //вычитание
            subtr(matrix, matrix2, matrix3); break;
        }
    }
}
