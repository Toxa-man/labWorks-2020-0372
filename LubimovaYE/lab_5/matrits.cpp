#include <iostream>
#include <conio.h>
using namespace std;
const int N = 3;
void sum(int arrA[N][N], int arrB[N][N])
{
    int arrC[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
    cout << "Массив C:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arrC[i][j] << ' ';
        }
        cout << endl;
    }
}
void min(int arrA[N][N], int arrB[N][N])
{
    int arrC[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
    cout << "Массив C:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arrC[i][j] << ' ';
        }
        cout << endl;
    }
}
void mult(int arrA[N][N], int arrB[N][N])
{
    int arrC[N][N], a = 0, b = 0, c = 0;;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                b = arrA[i][k];
                c = arrB[k][j];
                a += (arrA[i][k] * arrB[k][j]);

            }
            arrC[i][j] = a;
            a = 0;
        }
    }
    cout << "Массив C:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arrC[i][j] << ' ';
        }
        cout << endl;
    }
}
int main(int argc, char* argv[])
{
    const int KEY_ESC = 27;
    setlocale(LC_ALL, "RUS");
    char x;
    int arrA[N][N], arrB[N][N];
    cout << "Нажмите любую клавишу, чтобы продолжить, для выхода из программы нажмите ESC" << endl;
    while (_getch() != KEY_ESC)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arrA[i][j] = rand() % 21 - 10;
                arrB[i][j] = rand() % 21 - 10;
            }
        }
        cout << "Массив A:" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << arrA[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "Массив B:" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << arrB[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "Выберите действие + - *" << endl;
        cin >> x;
        switch (x)
        {
        case '+':
            sum(arrA, arrB);
            break;
        case '-':
            min(arrA, arrB);
            break;
        case '*':
            mult(arrA, arrB);
            break;
        default:
            cout << "Неверное действие" << endl;
            break;
        }
        cout << "Нажмите любую клавишу, чтобы продолжить, для выхода из программы нажмите ESC" << endl;
    }
    system("pause");
    return 0;
}