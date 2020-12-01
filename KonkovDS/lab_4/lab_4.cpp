#include <iostream>
long double stepen(void);
long int factor(void);
long double coren(void);
bool prostota(void);

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите номер нужной операции:" << std::endl;
    std::cout << "1)a^n" << std::endl << "2)a!" << std::endl << "3)корень из a" << std::endl << "4)проверка на простоту" << std::endl;
    int nomer;
    std::cin >> nomer;
    switch (nomer)
    {
    case 1:
        std::cout << "Введите a и n:" << std::endl;
        std::cout << "Результат " << stepen() << std::endl;
        break;
    case 2:
        std::cout << "Введите a:" << std::endl;
        std::cout << "Результат " << factor() << std::endl;
        break;
    case 3:
        std::cout << "Введите a:" << std::endl;
        std::cout << "Результат " << coren() << std::endl;
        break;
    case 4:
        std::cout << "Введите a:" << std::endl;
        if (prostota()) {
            std::cout << "Результат-является" << std::endl;
        }
        else { std::cout << "Результат-не является" << std::endl; }
        break;
    default:
        std::cout << "Там только 4 пунтка, теперь перезапускай" << std::endl;//yt ienb f kz;m cgfnm
        break;
    }
}
long double stepen(void) {
    int stepen;
    long double chislo, rez = 1;
    std::cin >> chislo >> stepen;
    if (stepen > 0) {
        for (int i = 1; i <= stepen; i++) {
            rez *= chislo;
        }
    }
    else {
        for (int i = 0; i > stepen; i--) {
            rez /= chislo;
        }
    }
    return rez;
}
long int factor(void) {
    int chislo, rez = 1;
    std::cin >> chislo;
    if (chislo < 13) {
        for (int i = 2; i <= chislo; i++) {
            rez *= i;
        }
        return rez;
    }
    else {
        std::cout << "Результат слишком велик поэтому программа даст вам ";
        return 666;
    }
}
//Итерационный аналитический алгоритм
long double coren(void) {
    long int chislo;
    std::cin >> chislo;
    if (chislo < 0) {
        std::cout << "НЕТ КОРНЯ У ОТРИЦАТЕЛЬНОГО ЧИСЛА ";
        return 666;
    }
    else {
        if (chislo == 0) {
            return 0;
        }
        else {
            long double rez;
            rez = chislo;
            for (int i = 1; i < 10; i++) {
                rez = 0.5 * (rez + chislo / rez);
            }
            return rez;
        }
    }
}
//просто мой метод который тупо проверяет
bool prostota(void) {
    long int chislo;
    std::cin >> chislo;
    switch (chislo) {
    case 1: return false;
        break;
    case 2: return true;
        break;
    default:
        if (chislo > 0){
            for (long int i = 2; i <= (chislo / 2); i++)
                if (chislo % i == 0)
                    return false;
        return true;
        }
            else{
            return false;
            }
    }
}
