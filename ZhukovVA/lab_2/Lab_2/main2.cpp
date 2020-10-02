
#include <iostream>

const int SIZE = 10;

void sort(int* arr) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			int temp = *(arr + j);
			if (*(arr + i) > temp) {
				*(arr + j) = *(arr + i);
				*(arr + i) = temp;
			}
		}
	}
}

int main() {
	int firstArray[SIZE] = {};

	for (int i = 0; i < SIZE; i++) {
		firstArray[i] = rand() % 100 - 50; //From -50 to 49
	}

	sort(firstArray);

	int secondArray[SIZE],
		min = firstArray[0],
		max = firstArray[0],
		sum = 0;

	for (int i = 0; i < SIZE; i++) {
		if (min > firstArray[i]) { min = firstArray[i]; }
		if (max < firstArray[i]) { max = firstArray[i]; }

		secondArray[i] = firstArray[i];
		sum += i;
	}

	for (int i = SIZE - 1; i > -1; i--) {
		if (secondArray[i] % 2 == 0) {
			delete& secondArray[i];
		}
	}

	std::cout << "First Array: ";
	for (int i : firstArray) { std::cout << i << " "; }

	std::cout << "\nSecond Array: ";
	for (int i : secondArray) { std::cout << i << " "; }

	std::cout << "\nMinimum: " << min << "\n" << "Maximum: " << max << "\n" << "Average: " << (float)sum / SIZE << std::endl;



	system("pause");
	return 0;
}