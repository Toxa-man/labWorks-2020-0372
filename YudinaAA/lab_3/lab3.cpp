#include <iostream>

using namespace std;

void sort(char** words, int counter) {
	char* buff;
	for (int i=0; i < counter; i++)
		for (int j = i + 1; j < counter; j++) {
			buff = words[i];
			if (strlen(words[j]) < strlen(buff)) {
				words[i] = words[j];
				words[j] = buff;
			}
		}
}

int main() {
	char words[256]; 
	cout << "enter your string: ";
	gets_s(words); 

	int counter = 1;
	for (int i = 0; i < strlen(words); i++) {
		if (words[i] == ' ')
			counter += 1;
	}

	int order = 0, let_amount = 0;
	char** words_new = new char* [counter];
	for (int i = 0; i < counter; ++i) {
		words_new[i] = new char[256];
	}
	for (int i = 0; i <= strlen(words); ++i) {
		if (words[i] != ' ') {
			words_new[order][let_amount] = words[i];
			let_amount++;
		}
		if (words[i] == ' ') {
			words_new[order][let_amount] = '\0';
			order++;
			let_amount = 0;
		}
	}

	sort(words_new, counter);

	cout << "result: ";
	for (int i = 0; i < counter; i++)
		cout << words_new[i] << " ";

	return 0;
}
