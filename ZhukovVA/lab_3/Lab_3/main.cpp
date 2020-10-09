#include <iostream>

int getCodesSum(char* word) {
	int sum = 0;
	for (int i = 0; i < (int)strlen(word); i++) {
		sum += int(word[i]);
	}
	return sum;
}

void sortByCodes(char** words, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			char* temp = words[i];
			if (getCodesSum(temp) > getCodesSum(words[j])) {
				words[i] = words[j];
				words[j] = temp;
			}
		}
	}
}

int main() {
	char text[100];
	int size = 1, word = 0, letter = 0;

	std::cout << "Type your sentence (100 symbols max): ";
	std::cin.getline(text, 100);

	//Get split array size
	for (int i = 0; i < (int)strlen(text); i++) {
		if (text[i] == ' ') {
			size++;
		}
	}

	//Create char array of char arrays to store splitted string
	char** split = new char* [size];
	for (int i = 0; i < size; i++) {
		split[i] = new char[100];
	}

	//Split the string
	for (int i = 0; i < (int)strlen(text) + 1; i++) {
		if (text[i] != ' ') {
			split[word][letter++] = text[i];
		}
		else {
			split[word][letter] = '\0';
			word++;
			letter = 0;
		}
	}

	sortByCodes(split, size);		//Sort words by its codes sums with selection algorithm

	//Print out result string
	std::cout << "Result string: ";
	for (int i = 0; i < size; i++) {
		std::cout << split[i] << " ";
	}

	std::cout << std::endl;

	system("pause");
	return 0;
}