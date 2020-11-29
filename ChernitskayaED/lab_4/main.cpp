#include <iostream>
using namespace std;

double level(int a, int b) 
{
    double res = 1;
    for (int i = 0; i < abs(b); i++)
    {
        res *= a;
    }
    if (b <= 0)
    { 
        return 1 / res;
    }
    else 
    {
        return res;
    }  
    
}

int fact(int a) 
{
    int res = 1;
    for (int i = 1; i < a + 1; i++) {
        res = res * i;
    }
    return res;
}

double sqrt(int a)
{ 
    double b = 1;
    double t = 0; 
    if (a == 0)
    {
        return 0;
    }
    if (a < 0)
    {
        cout << "Не определен" << endl;
        return 0;
    }
        
    while (b != t)
    {
        t = b;
        b = (t + a / t) / 2.0;
    }
    return b;
    cout << b; 
}

bool simple(int a)
{
    bool flag = true;
    int t = 0;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            flag = false;
        }
    }
    if (flag) 
    {
        cout << a << " является простым числом " << endl;
    }
    else {
        cout << a <<" не является простым числом " << endl;
    }
    return 0;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int a = 7; 
    int b = -3;
    
    cout << "Число " << a << " в степени " << b << " = " << level(a, b) << endl;
    cout << "Факториал числа " << a << " = " << fact(a) << endl;
    cout << "Квадратный корень из числа " << a << " = " << sqrt(a) << endl;
    cout << simple(a) << endl;
    return 0;
}
