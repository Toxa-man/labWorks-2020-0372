#include <iostream>
#include <time.h>

const int SIZE = 10;

//Selection sort algorithm
void sort(int* arr) {
	int i = 0;
	while (i < SIZE) {
		int j = i + 1;
		while (j < SIZE) {
			int temp = arr[j];
			if (arr[i] > temp) {
				arr[j] = arr[i];
				arr[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int main() {
	int oddsCount = 0;
	int firstArray[SIZE];

	srand(time(NULL));						//Update seed

	std::cout << "First Array: ";
	for (int i = 0; i < SIZE; i++) {
		firstArray[i] = rand() % 100 - 50;	//From -50 to 49
		std::cout << firstArray[i] << " ";
		if (firstArray[i] % 2 != 0) {
			oddsCount++;					//Count odd numbers
		}
	}

	sort(firstArray);						//Sort the array

	int secondArray[SIZE];
	int	index = 0,
		sum = 0;

	for (int i = 0; i < SIZE; i++) {
		if (firstArray[i] % 2 != 0) {
			secondArray[index++] = firstArray[i];		//Fill the second array with odd numbers
		}
	}

	//Print out arrays
	std::cout << "\nFirst Array (after sorting): ";
	for (int i = 0; i < SIZE; i++) {
		std::cout << firstArray[i] << " ";
	}

	std::cout << "\nSecond Array: ";
	for (int i = 0; i < oddsCount; i++) {
		std::cout << secondArray[i] << " ";
		sum += secondArray[i];
	}

	//Print out maximum, minimum and average values from the secondArray
	std::cout << "\nMinimum: " << secondArray[0] << "\n" << "Maximum: " << secondArray[oddsCount-1] << "\n" << "Average: " << (float)sum / oddsCount << std::endl;

	system("pause");
	return 0;
}