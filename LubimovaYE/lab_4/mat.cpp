#include<iostream>
#include<string>
using namespace std;
void power(int a, int b)
{
    int x = 1;
    for (int i = 0; i < b; i++)
    {
        x *= a;
    }
    cout << a << '^' << b << " = " << x << endl;
}
void fact(int a)
{
    int x = 1;
    for (int i = 2; i <= a; i++)
    {
        x *= i;
    }
    cout << x << endl;
}
void root(int a)
{
    float x = 1;
    while (x * x < a)
    {
        x++;
    }
    x--;
    cout << x + (a - x * x) / (2 * x) << endl;
}
void prime(int a)
{
    int k = 0;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            k++;
        }
    }
    if (k)
    {
        cout << "Difficult" << endl;
    }
    else
    {
        cout << "Simple" << endl;
    }
}
int main()
{
    int a, b, x = 1;
    cout << "Power" << endl;
    cin >> a >> b;
    power(a, b);
    cout << "Factorial:" << endl;
    cin >> a;
    fact(a);
    cout << "Root" << endl;
    cin >> a;
    root(a);
    cout << "Prime" << endl;
    cin >> a;
    prime(a);
    return 0;

}
