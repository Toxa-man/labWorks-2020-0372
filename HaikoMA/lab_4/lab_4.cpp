#include <iostream>

using namespace std;

float my_power(float number, int pow);

long double factorial(int number);

double my_sqrt(int number);

bool my_prime(int number);

int main()
{
float number;
int pow;
cout « "Write number: " « endl;
cin » number;
cout « "Power of number: " « endl;
cin » pow;
cout « number « " in " « pow « " = " « my_power(number, pow) « endl;
cout « "factorial " « number « " = " « factorial(number) « endl;
cout « "square root " « number « " = " « my_sqrt(number) « endl;
if (my_prime(number)) cout « "it is a prime number";
else cout « "not a prime number";
}

float my_power(float number, int pow) {
float c = 1;
for (int i = 1; i <= pow; i++) {
c = c * number;

}
return c;
}

long double factorial(int number)
{
if (number < 0) return 0;
if (number == 0) return 1;
else return number * factorial(number - 1);
}

double my_sqrt(int number) {
int inf_lim = 0;
double res, k = 1;
if (number == 0) return 0;
if (number < 0) return -1;
while (inf_lim < 10 || res != k) {
res = k;
k = (res + number / res) / 2;
inf_lim++;
}
return res;
}

bool my_prime(int number) {
if (number <= 1) return 0;
for (int i = 2; i < number; i++) {
if (number % i == 0) return 0;
}
return 1;
}
