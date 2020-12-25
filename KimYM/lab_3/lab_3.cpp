#include <iostream>
#include <Windows.h>

void sortirovka(int schetchik, char** slova) {
	char* m;
	for (int i = 0; i < schetchik; i++) {
		for (int k = i + 1; k < schetchik; k++) {
			m = slova[i];
			if (strlen(m) > strlen(slova[k])) {
				slova[i] = slova[k];
				slova[k] = m;
			}
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char stroka[501];
	std::cout << "Введите предложение: ";
	std::cin.getline(stroka, 501);
	int nomer = 1;
	for (int i = 0; i < strlen(stroka); i++) {
		if (stroka[i] == ' ') {
			nomer = nomer + 1;
		}
	}
	char** slova;
	int kolich = 0;
	int word_ind = 0;
	slova = new char* [nomer];
	for (int i = 0; i < nomer; i++) {
		slova[i] = new char[100];
	}
	for (int i = 0; i <= strlen(stroka); i++) {
		if (stroka[i] != ' ') {
			slova[word_ind][kolich] = stroka[i];
			kolich = kolich + 1;
		}
		else {
			slova[word_ind][kolich] = '\0';
			word_ind = word_ind + 1;
			kolich = 0;
		}
	}
	sortirovka(nomer, slova);
	std::cout << "Результат: ";
	for (int i = 0; i < nomer; i++) {
		std::cout << slova[i] << " ";
	}
}
