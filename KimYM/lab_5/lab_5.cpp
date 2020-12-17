#include <iostream>
#include <Windows.h>
#include <conio.h>

const int size = 3;
void summa(int matrica1[size][size], int matrica2[size][size], int rezultat[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            rezultat[i][j] = matrica1[i][j] + matrica2[i][j];
        }
    }
}

void raznost(int matrica1[size][size], int matrica2[size][size], int rezultat[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            rezultat[i][j] = matrica1[i][j] - matrica2[i][j];
        }
    }
}

void proizv(int matrica1[size][size], int matrica2[size][size], int rezultat[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            rezultat[i][j] = 0;
            for (int k = 0; k < size; k++) {
                rezultat[i][j] += matrica1[i][j] * matrica2[i][j];
            }
        }
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char vihod;
    int matrica1[size][size];
    int matrica2[size][size];
    int rezultat[size][size];
    do {

        char action;
        std::cout << "Введите первую матрицу: " << std::endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cin >> matrica1[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Введите вторую матрицу: " << std::endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cin >> matrica2[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Первая матрица: " << std::endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << matrica1[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Вторая матрица: " << std::endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << matrica2[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Выберите действие: +, - или *" << std::endl;
        std::cin >> action;
        switch (action) {
        case '+':
            summa(matrica1, matrica2, rezultat);
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    std::cout << rezultat[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            break;
        case '-':
            raznost(matrica1, matrica2, rezultat);
            std::cout << "В результате вычитания получилось:" << std::endl;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    std::cout << rezultat[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            break;
        case '*':
            proizv(matrica1, matrica2, rezultat);
            std::cout << "В результате умножения получилось: " << std::endl;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    std::cout << rezultat[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            break;
        default: std::cout << "Введено неверное действие, начните сначала" << std::endl;
            break;
        }
        std::cout << "Press F to pay respects" << std::endl;
        vihod = _getch();
    } while (vihod != 70);
}
