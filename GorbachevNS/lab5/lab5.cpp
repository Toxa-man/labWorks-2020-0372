#include <iostream>
#include <windows.h>

using namespace std;
int const N = 3;

void my_powmultiplications(double A[N][N], double B[N][N], double C[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}
void my_addition(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void my_subtraction(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] - B[i][j];
}
void my_cout(double C[N][N]) {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (j % 3 == 0) {
                cout << endl;
            }
            cout << C[i][j] << " ";
        }
}

int main()
{
    while (true) {
        int v;
        cout << "Selected action:\n 1)powmultiplications.\n 2)addition.\n 3)subtraction.\n ";
        cin >> v;
        enum choice { powmultiplications = 1, addition, subtraction};
        switch (v)
        {
        case(powmultiplications):
            int i, j, k;
            double A[N][N];
            double B[N][N];
            double C[N][N];
            cout << "Matrix A:\n";
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    cin >> A[i][j];
            cout << "Matrix B:\n";
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    cin >> B[i][j];
            my_powmultiplications(A, B, C);
            cout << "Matrix C=AB:\n";
            my_cout(C);
            break;
        case(addition):
            cout << "Matrix A:\n";
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    cin >> A[i][j];
            cout << "Matrix B:\n";
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    cin >> B[i][j];
            my_addition(A, B, C);
            cout << "Matrix C=A+B:\n";
            my_cout(C);
            break;
        case(subtraction):
            cout << "Matrix A:\n";
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    cin >> A[i][j];
            cout << "Matrix B:\n";
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    cin >> B[i][j];
            my_subtraction(A, B, C);
            cout << "Matrix C=A-B:\n";
            my_cout(C);
            break;
        default:
            system("cls");
            cout << "ERROR\n";
            break;
        }
        int i;
        Sleep(5000);
        system("cls");
        cout << "Reboot\n 1)yes\n 2)no\n";
        cin >> i;
        if (i != 1) {
            break;
        }
    }
}
