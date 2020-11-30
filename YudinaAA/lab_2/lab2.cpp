#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(nullptr));
	const int size = 10;
	int arr[size];

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 200 + (-100);
	}
	cout << "array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int j, temporary;
	int i = 0;
		while (i < size)  {
			j = 0;
			while (j < size - 1)  {
				if (arr[j + 1] > arr[j]) {
					temporary = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temporary;
				}
				j++;
			}
			i++;
		}
		cout << "sorted array: ";
	for (int j = 0; j < size; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;

	cout << "odd array: ";
	int sum = 0;
	int size2 = 0;
	for (int j = 0; j < size; j++) {
		if ((arr[j] % 2) != 0) {
			cout << arr[j] << " ";
			sum = sum + arr[j];
			size2++;
		}
	}
    cout << endl;

	cout << "average: ";
	double average = (double)sum / size2;
	cout << average;
	cout << endl;

	cout << "minimum: " << arr[size2-1] << endl;
	cout << "maximum: " << arr[0];
	return 0;
}
