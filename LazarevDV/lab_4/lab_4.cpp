#include <iostream>
#include <conio.h>


using namespace std;

float power() {
    float number, counter = 1; //number число вводимое в степень, pow сама степень, counter счетчик
    int pow;
    cout << "Введите число и степень через пробел: ";
    cin >> number >> pow;
    if (pow < 0) {
        for (int i = 0; i < abs(pow); i++) {
            counter = counter / number;
        } 
    }
    else {
        for (int i = 0; i < abs(pow); i++) {
            counter *= number;
        }
    }
    if (abs(pow) == 3) {
        cout << number << " В " << pow << "-ей степени равно: " << counter;
    }
    else {
        cout << number << " В " << pow << "-ой степени равно: " << counter;
    }
    cout << endl;
    return number;
}

int fact() {
    int number, counter = 1; //number край факториала, counter счетчик
    cout << "Введите число для нахождения факториала: ";
    cin >> number;
    for (int i = 1; i < number + 1; i++) {
        counter *= i;
    }
    cout << "Факториал равен: " << counter;
    cout << endl;
    return number;
}

float square() {
    float number, temp = 0, counter = 1; //number число для нахождения корня, counter счетчик
    cout << "Введите число для его квадратного корня: ";
    cin >> number;
    if (number <= 0) {
        if (number == 0) {
            cout << "Корень нуля равен 0\n";
        }
        if (number < 0) {
            cout << "Невозможно найти корень отрицательного числа, попробуйте еще раз!\n";
        }
    }
    else {
        while (counter != temp) {
            temp = counter;
            counter = (temp + number / temp) / 2.0;
        }
        cout << "Корень " << number << " равен: " << counter;
        cout << endl;
    }
    return number;
}

int simplicity() {
    int number; //number число для проверки на простоту 
    bool flag; 
    cout << "Введите число для проверки на простоту: ";
    cin >> number;
    if (number <= 0)
        cout << "Вы ввели '0' или отрицательное число, попробуйте еще раз!\n"; 
    else
    {
        flag = true;
        for (int i = 2; i <= sqrt(number) + 1; i++) {
            if (number % i == 0)
                flag = false;
        }
        
        if (number == 1)
            flag = false;
        if (number == 2)
            flag = true;
        if (flag)
            cout << "Число " << number << " простое\n";
        else
            cout << "Число " << number << " не простое\n";
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char func_cheker, check;
    
    cout << "Добро пожаловать в продвинутый калькулятор Дениса Лазарева!\n";
    
    do {
        cout << "1. Для возведения числа в степень введите '1'\n2. Для нахождения факториала числа введите '2'\n";
        //Разделил на 2 cout'a чтобы выглядело красиво и не расстягивалось на несколько мониторов
        cout << "3. Для нахождения квадратного корня числа введите '3'\n4. Для проверки числа на просоту введите '4': "; 
        cin >> func_cheker;
        switch (func_cheker) {
            case '1': power(); break;
            case '2': fact(); break;
            case '3': square(); break;
            case '4': simplicity(); break;
            default: cout << "Вы выбрали несуществующий вариант попробуйте еще раз!\n"; break;  
        }
        cout << "Нажмите Enter для продолжения или Esc для выхода из программы\n";
        check = _getch();
    } while (check != 27);
    
    system("pause");
    return 0;
}
