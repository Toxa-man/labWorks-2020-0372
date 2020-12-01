#include <iostream>
#include <ctime>


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
    int result;
    double approximately_res;
    int i = 1;
    double k = 0.1;  // reducing coefficient to get an approximately result
    double j;
    bool f = true;  // flag
    while (true){
        if (i * i == n){  // if square root of n is integer
            result = i;
            return (double)result;
        } else {
            if (i * i > n){  // if square root of n is float
                if (f){  // first assign j with flag
                    j = (double)i;  // assign last got "i" to j
                    f = false;
                }
                if (j * j > (double )n) j -= k;
                else if (j * j < (double )n) j += k;
                if ((double )n - j * j < 0.01 && j * j <= (double)n) {  // 0.01 is measurement error
                    approximately_res = j;
                    return approximately_res;
                } else if (j * j < (double )n) {
                    j += k;
                    k /= 10;
                }
            } else {
                i++;
            }
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
    std::cout << squareRoot(13370000) << std::endl;
    isNumberSimple(123121000);

    return 0;
}