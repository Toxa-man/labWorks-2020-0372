#include <iostream>


void str_sort(char** numbers_of_words, int words_count) {
	char* temp;
	for (int i = 0; i < words_count; ++i) {
		temp = numbers_of_words[i];
		for (int j = i + 1; j < words_count; ++j) {
			if (strlen(numbers_of_words[j]) < strlen(temp)) {
				numbers_of_words[i] = numbers_of_words[j];
				numbers_of_words[j] = temp;
			}
		}
	}
}

int main() {
	char str[200]; int word_count=1, index = 0, count_letters = 0;
	std::cin.getline(str, 200);
	for (int i = 0; i <= strlen(str); ++i) {
		if (str[i] == ' ') {
			++word_count;
		}
	}
	char** word = new char* [word_count];
	for (int i = 0; i < word_count; ++i) {
		word[i] = new char[200];
	}
	for (int i = 0; i <= strlen(str); ++i) {
		if (str[i] != ' ') {
			word[index][count_letters] = str[i];
			++count_letters;
		}
		if (str[i] == ' ') {
			word[index][count_letters] = '\0';
			++index;
			count_letters = 0;
		}
	}
	str_sort(word, word_count);
	for (int i = 0; i < word_count; ++i) {
		std::cout << word[i] << " ";
	}
	for (int i = 0; i < word_count; ++i) {
		delete[] word[i];
	}
	return 0;
}