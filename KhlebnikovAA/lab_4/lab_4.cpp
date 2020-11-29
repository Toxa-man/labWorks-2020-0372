#include <iostream>

int power(int a, int b) {
    int res=a;
    for (int i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

int fact(int b) {
    static int res = 1;
    if (b != 1) {
        res *= b;
        b--;
        fact(b);
    }
    return res;
}

double sqrt(int z) {
    double a=0, b=0;
    for (int i = 0; i < z; i++) {
        if (i * i == z) {
            return i;
        }
        else if(i*i>z){
            b = i;
            break;
        }
        else {
            a = i;
        }
    }
    for (double i = 0.1; i < 1; i+=0.1) {
        if ((a+i)*(a + i) > z) {
            b = (a + i-0.1);
            break;
        }
    }
    for (double i = 0.01; i < 1; i += 0.01) {
        if ((a + i) * (a + i) > z) {
            b = (a + i-0.01);
            break;
        }
    }
    return b;
}

void simple(int b) {
    int x = 2, y=0;
    for (x; x < b; x++) {
        if (b % x == 0) {
            y = 1;
        }
    }
    if (y == 0) {
        std::cout << "Число " << b << " является простым" << std::endl;
    }
    else {
        std::cout << "Число " << b << " не является простым" << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int a=3, b=5;
    std::cout << a << " в степени " << b << " = " << power(a, b) << std::endl;
    std::cout << b << "! " << " = " << fact(b) << std::endl;
    std::cout << "Корень из " << b << " = " << sqrt(b) << std::endl;
    simple(b);
    system("PAUSE");
    return 0;
}

