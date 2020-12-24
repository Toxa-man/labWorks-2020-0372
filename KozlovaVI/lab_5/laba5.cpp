#include <iostream>
using namespace std;;
int proizv(int M1[4][4], int M2[4][4]) {
    int M[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            M[i][j] = M1[i][0] * M2[0][j] + M1[i][1] * M2[1][j] + M1[i][2] * M2[2][j] + M1[i][3] * M2[3][j];
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
int summ(int M1[4][4], int M2[4][4]) {
    int M[4][4];
    for (int i=0; i<4; i++){
        for (int j = 0; j < 4; j++) {
            M[i][j] = M1[i][j] + M2[i][j];
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
int razn(int M1[4][4], int M2[4][4]) {
    int M[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            M[i][j] = M1[i][j] - M2[i][j];
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
int todo(int ukaz, int M1[4][4], int M2[4][4]) {
    switch (ukaz) {
    case 1:
        proizv(M1, M2);
        break;
    case 2:
        summ(M1, M2);
        break;
    case 3:
        razn(M1, M2);
        break;
        return 0;
    }
}
int main()
{
    int M1[4][4];
    int M2[4][4];
    cout << "Put numbers\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> M1[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> M2[i][j];
        }
    }
    int x = 1;
    while (x != 0) {
        cout << "That to do\n" << "Multiply - press 1\n" << "Addition - press 2\n" << "Difference - press 3\n";
        int ukaz;
        cin >> ukaz;
        todo(ukaz, M1, M2);
        cout << "Press random number to continied\n" << "Or 0 to exit\n";
        cin >> x;
    }
    return 0;
}