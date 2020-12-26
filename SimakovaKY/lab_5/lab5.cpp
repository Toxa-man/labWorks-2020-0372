#include <iostream>
#include <conio.h>
using namespace std;

void summ(int** M_result, int** M1, int** M2, int n, int m) {
	
	M_result = new int* [n];
	for (int i = 0; i < n; i++) {
		M_result[i] = new int[m];
		for (int j = 0; j < m; j++) {
			
			M_result[i][j] = M1[i][j] + M2[i][j];
			cout << M_result[i][j] << " ";
		}
	}
}

void min(int** M_result, int** M1, int** M2, int n, int m) {
	
	M_result = new int* [n];
	for (int i = 0; i < n; i++) {
		M_result[i] = new int[n];
		for (int j = 0; j < m; j++) {
			
			M_result[i][j] = M1[i][j] - M2[i][j];
			cout << M_result[i][j] << " ";
		}
	}
}
void umn(int** M_result, int** M1, int** M2, int n, int m) {
	
	if (n = m) {
		M_result = new int* [n];
		for (int i = 0; i < n; i++) {
			M_result[i] = new int[n];
			for (int j = 0; j < m; j++) {
				
				M_result[i][j] = M1[i][j] - M2[i][j];
				cout << M_result[i][j] << " ";
			}
		}
	}
	else {
		cout << "Matrices of different sizes!";
	}
}

int main() {
	char ch;
	int** M1 = 0,** M2 = 0,** M_result = 0;
    int n, m;

	do {
		
		cout << "Enter the number of rows and columns in matrices: " << endl;
		cin >> n >> m;

		cout << "Input matrix 1: " << endl;
		M1 = new int* [n];
		for (int i = 0; i < n; i++) {
			M1[i] = new int[m];
			for (int j = 0; j < m; j++) {
				cin >> M1[i][j];
			}
		}

		cout << "Input matrix 2: " << endl;
		M2 = new int* [n];
		for (int i = 0; i < n; i++) {
			M2[i] = new int[m];
			for (int j = 0; j < m; j++) {
				cin >> M2[i][j];
			}
		}

		int sign;
		cout << "Enter a sign describing the action on matrices ( +, -, *) ";
		cin >> sign;

		switch (sign) {

		case '+' :

			cout << "Matrix = ";
			summ(M1, M2, M_result, n, m);
			break;

		case '-':

			cout << "Matrix = ";
			min(M1, M2, M_result, n, m);
			break;

		case '*':

			cout << "Matrix = ";
			umn(M1, M2, M_result, n, m);
			break;

		}

		delete[] M1;
		delete[] M2;
		delete[] M_result;

		cout << "To exit the program press Esc. To continue - space." << endl;
     ch = _getch();
	} while (ch != 27);
	return 0;
}