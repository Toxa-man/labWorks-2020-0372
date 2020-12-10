#include <cstdio>
#include <iostream>


// count factorial function
int fact(int n){
    int result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

// exponentiation function
long int exp(int n, int degree){
    int i = 0;
    long int result = 1;
    while (i < degree){
        result *= n;
        i++;
    }
    return result;
}

// counting square root with integer result or float result depending on input number
double squareRoot(long n){
    double i = 1;
    double k = 10000;
    while (true){
        if (i * i < n) i += k;
        else {
            if ((double)n - i * i < 0.000001 && i * i < (double)n + 0.000001) {
                return i;
            }
            i -= k;
            k /= 10;
        }
    }
}

// function that check is this number simple
void isNumberSimple(long n){
    if (n % 2 != 0) {
        bool f = true;
        for (int i = n / 2; i > 1; i--) {
            if (n % i == 0){
                f = false;
                std::cout << "Число " << n << " составное";
                break;
            }
        }
        if (f) std::cout << "Число " << n << " простое";
    } else std::cout << "Число " << n << " составное";
}


int main(){
    system("chcp 65001 > nul");

    std::cout << fact(6) << std::endl;
    std::cout << exp(6, 4) << std::endl;
    printf("%.12f", squareRoot(1337000000));
    std::cout << "\n";
    isNumberSimple(123121003);

    return 0;
}