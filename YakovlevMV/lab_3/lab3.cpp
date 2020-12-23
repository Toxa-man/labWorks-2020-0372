#include <iostream>

using namespace std;

void sort(char**, int);

int main() {
	char sent[100];
	cout << "Enter your sentence (max 100 symbols): " << endl;
	cin.getline(sent, 100);
	int last_index = 0, word_num = 1, letter_count = 0, word_ind = 0;
	for (int i = 0; i < (int)strlen(sent); i++)  if (sent[i] == ' ') word_num++;
	char** words;
	words = new char* [word_num];
	for (int i = 0; i < word_num; i++) words[i] = new char[100];
	for (int i = 0; i <= (int)strlen(sent); i++) {
		if (sent[i] != ' ') {
			words[word_ind][letter_count] = sent[i];
			letter_count++;
		}
		else {
			words[word_ind][letter_count] = '\0';
			word_ind++;
			letter_count = 0;
		}
	}
	sort(words, word_num);
	cout << "Sorted string: " << endl;
	for (int i = 0; i < word_num; i++) cout << words[i] << " ";
	cout << endl;
}


void sort(char** words, int words_counter) {
	char* t;
	for (int i = 0; i < words_counter; i++) {
		for (int j = i + 1; j < words_counter; j++) {
			t = words[i];
			if ((int)strlen(t) > (int)strlen(words[j])) {
				words[i] = words[j];
				words[j] = t;
			}
		}
	}
}
