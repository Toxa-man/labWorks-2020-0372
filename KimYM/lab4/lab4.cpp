#include <iostream>
#include <Windows.h>
#include <conio.h>

    int stepeni(int proisv, int stepen) {
    int num = 1;
    for (int i = 0; i < stepen; i++) {
        num = num * proisv;
    }
    return num;
    }

    int faktoriali(int faktorial) {
    long int fakt = 1;
    int dopchislo = 1;
    for (int i = 0; i < faktorial; i++) {
        fakt = fakt * dopchislo;
        dopchislo = dopchislo + 1;
    }
    return fakt;
    }

    double coren(int chislo_one) {
    int ostatok = chislo_one;
    int k = 0;
    double coren;
    while (ostatok > 0) {
        k++;
        ostatok = chislo_one - k * k;
    }
    double ostatok_1 = ostatok;
    double k_one = k;
    coren = k_one + ostatok_1 / (k_one * 2);
    return coren;
    }

    bool prostoe(int zifra) {
        if (zifra > 1) {
            for (int i = 2; i < zifra; i++)
                if (zifra % i == 0)
                    return 0;
            return 1;
        }
        else
            return 0;
    }

    int main()
    {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char ch;
    do {
        std::cout << "Введите число\n";
        int chislo;
        std::cin >> chislo;
        std::cout << "Введите степень\n";
        int stepen;
        std::cin >> stepen;

        std::cout << stepen << "-я " << "степень числа " << chislo << " равна ";
        std::cout << stepeni(chislo, stepen) << std::endl;

        std::cout << "Факториал числа " << chislo << " равен ";
        std::cout << faktoriali(chislo) << std::endl;

        std::cout << "Квадратный корень из числа " << chislo << " равен ";
        std::cout << coren(chislo) << std::endl;

        if (prostoe(chislo) == 1) {
            std::cout << "Число " << chislo << " является простым" << std::endl;
            std::cout << std::endl;
        }
        else {
            std::cout << "Число " << chislo << " не является простым" << std::endl;
            std::cout << std::endl;
        }
        ch = _getch();
    } while (ch != 27);
    }
