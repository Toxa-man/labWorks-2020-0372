#include <iostream>
using namespace std;

void sorting(int N, char** mas_slov) {
	char* p;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
          p = mas_slov[i];
			if (sizeof(p) > sizeof(mas_slov[j])) {

				mas_slov[i] = mas_slov[j];
				mas_slov[j] = p;
			}
		}
	}
}

int main() {
    char str[300];
	int N = 1;
	int kol_slov = 0;
	int index = 0;
	
	cout << "Enter the string: ";
	cin.getline(str, 300);
	
	for (int i = 0; i < sizeof(str); i++) {

		if (str[i] == ' ') {
			N = N + 1;
		}
	}

	char** mas_slov;
	mas_slov = new char* [N];
	for (int i = 0; i < N; i++) {

		mas_slov[i] = new char[100];
	}
	for (int i = 0; i <= sizeof(str); i++) {

		if (str[i] != ' ') {

			mas_slov[index][kol_slov] = str[i];
			kol_slov = kol_slov + 1;
		}
		else {
			mas_slov[index][kol_slov] = NULL;
			index = index + 1;
			kol_slov = 0;
		}
	}

	sorting(N, mas_slov);

	cout << "Sorting result output: ";
	for (int i = 0; i < N; i++) {

		cout << mas_slov[i] << " ";
	}
}