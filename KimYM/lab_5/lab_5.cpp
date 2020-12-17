#include <iostream>
#include <Windows.h>
#include <conio.h>

const int razmer = 3;
void summa(int matrica1[razmer][razmer], int matrica2[razmer][razmer], int rezultat[razmer][razmer]) {
    for (int i = 0; i < razmer; i++) {
        for (int j = 0; j < razmer; j++) {
            rezultat[i][j] = matrica1[i][j] + matrica2[i][j];
        }
    }
}

void raznost(int matrica1[razmer][razmer], int matrica2[razmer][razmer], int rezultat[razmer][razmer]) {
    for (int i = 0; i < razmer; i++) {
        for (int j = 0; j < razmer; j++) {
            rezultat[i][j] = matrica1[i][j] - matrica2[i][j];
        }
    }
}

void proizv(int matrica1[razmer][razmer], int matrica2[razmer][razmer], int rezultat[razmer][razmer]) {
    for (int i = 0; i < razmer; i++) {
        for (int j = 0; j < razmer; j++) {
            rezultat[i][j] = 0;
            for (int k = 0; k < razmer; k++) {
                rezultat[i][j] += matrica1[i][j] * matrica2[i][j];
            }
        }
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char vihod;
    const int local_razmer = 3;
    int matrica1[local_razmer][local_razmer];
    int matrica2[local_razmer][local_razmer];
    int rezultat[local_razmer][local_razmer];
    do {

        char action;
        std::cout << "Введите первую матрицу: " << std::endl;
        for (int i = 0; i < local_razmer; i++) {
            for (int j = 0; j < local_razmer; j++) {
                std::cin >> matrica1[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Введите вторую матрицу: " << std::endl;
        for (int i = 0; i < local_razmer; i++) {
            for (int j = 0; j < local_razmer; j++) {
                std::cin >> matrica2[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Первая матрица: " << std::endl;
        for (int i = 0; i < local_razmer; i++) {
            for (int j = 0; j < local_razmer; j++) {
                std::cout << matrica1[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Вторая матрица: " << std::endl;
        for (int i = 0; i < local_razmer; i++) {
            for (int j = 0; j < local_razmer; j++) {
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
            for (int i = 0; i < local_razmer; i++) {
                for (int j = 0; j < local_razmer; j++) {
                    std::cout << rezultat[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            break;
        case '-':
            raznost(matrica1, matrica2, rezultat);
            std::cout << "В результате вычитания получилось:" << std::endl;
            for (int i = 0; i < local_razmer; i++) {
                for (int j = 0; j < local_razmer; j++) {
                    std::cout << rezultat[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            break;
        case '*':
            proizv(matrica1, matrica2, rezultat);
            std::cout << "В результате умножения получилось: " << std::endl;
            for (int i = 0; i < local_razmer; i++) {
                for (int j = 0; j < local_razmer; j++) {
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
