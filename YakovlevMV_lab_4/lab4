#include <iostream>

using namespace std;

float stepen(float x, int n) {
    float c = 1;
    for (int i = 1; i <= n; i++) {
        c = c * x;
        
    }
    return c;
}

long double fact(int x)
{
    if (x < 0) return 0; 
    if (x == 0) return 1; 
    else return x * fact(x - 1); 
}

double my_sqrt(int x) {
    int pr_besk = 0;
    double res, k = 1;
    if (x == 0) return 0;
    if (x < 0) return -1;
    while (pr_besk < 10 || res != k) {
        res = k;
        k = (res + x / res) / 2;
        pr_besk++;
    }
    return res;
}

bool prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main()
{
    float x;
    int n;
    cout << "Write number: " << endl;
    cin >> x;
    cout << "Write degree of number: " << endl;
    cin >> n;
    cout << x << " to " << n << " degree is " << stepen(x, n) << endl;
    cout << "factorial of " << x << " is " << fact(x) << endl;
    cout << "square root of " << x << " is " << my_sqrt(x) << endl;
    if (prime(x)) cout << "Prime number";
    else cout << "non prime number";
}
