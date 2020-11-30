#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	const int num = 10;
	int arr[num], nechet[num];
	float summ = 0;
	int nech = 0;
	for (int i = 0; i < num; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << "\t";
		if (arr[i] % 2 != 0) {
			nechet[nech] = arr[i];
			nech++;
		}
	}
	int i = 1, kolich = 0;

	// Sort 
	while (i != num) {
		int j = 0;
		while (j < num) {
			if (arr[i] < arr[j])
			{
				swap(arr[i], arr[j]);
			}
			j++;
		}
		i++;
	}


	cout << endl;
	cout << "После сортировки: ";
	for (int i = 0; i < num; i++) {
		cout << arr[i] << "\t";	
	}
	int max = arr[0], min = arr[9];
	cout << endl;

	cout << "Второй массив: ";

	//max min middle
	for (int i = 0; i < nech; i++) {
		cout << nechet[i] << "\t";
		summ = summ + nechet[i];
		if (nechet[i] <= min) min = nechet[i];
		if (nechet[i] >= max) max = nechet[i];
		kolich++;
	}

	cout << endl;
	cout << "Среднее значение: " << summ / kolich << endl;
	cout << "Минимальный элемент: " << min << endl;
	cout << "Максимальный элемент: " << max;
}
