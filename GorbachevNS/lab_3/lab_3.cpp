#include <iostream>
using namespace std;

void my_move(char**, int);

int main() {
	char str[500];

	cout << "Entered string:\n";
	cin.getline(str, 100);


	int words_counter = 1;
	for (int i = 0; i < (int)strlen(str); i++) {
		if (str[i] == ' ') {
			words_counter++;
		}
	}

	char** words;
	words = new char* [words_counter];
	for (int i = 0; i < words_counter; i++) {
		words[i] = new char[100];

	}
	int word = 0;
	int letter = 0;
	for (int i = 0; i <= (int)strlen(str); i++) {
		if (str[i] != ' ') {
			words[word][letter] = str[i];
			letter++;
		}
		else {
			words[word][letter] = '\0';
			word++;
			letter = 0;
		}
	}


	my_move(words, words_counter);
	cout << "Sorted string:\n";
	for (int i = 0; i < words_counter; i++) {
		cout << words[i] << " ";
	}
	cout << endl;

}
void my_move(char** words, int words_counter)

{
	char* temp;
	for (int i = 0; i < words_counter; i++) {
		for (int j = i + 1; j < words_counter; j++) {
			temp = words[i];
			if ((int)strlen(temp) > (int)strlen(words[j])) {
				words[i] = words[j];
				words[j] = temp;
			}
		}
	}
}
