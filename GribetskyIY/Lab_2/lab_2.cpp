#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;
const int n = 10;
const int m = 10;
int array1 [n];
int array2[m];
int i, j, t, maxx, minn, sr;

int main()
{
	cout << "Initial array:\n";
	srand(time(NULL));//Заполнение массива
	for (i = 0; i < n; i++) 
	{
		array1[i] = rand() % 100 + 1;
		cout << array1[i] << " ";
    }
	cout << " \n";
	cout << "  \n";

	i = 0;//Сортировка массива
	while (i<(n)) {
		j = 0;
		while (j<(n-1)) {
			if (array1[j] > array1[j + 1]) {
				t = array1[j + 1];
				array1[j + 1] = array1[j];
				array1[j] = t;
			}
			j++;
		}
		i++;
	}

	cout << "Sorted array:\n";//Вывод отсортированного массива
	for (i = 0; i < n; i++)
	{
		cout << array1[i] << " ";
	}
	cout << " \n";


	j = 0;//Нахождения массива из нечетных элементов первого
	minn = 101; maxx = -1; sr = 0;
	for (i = 0; i < n; i++) 
	{
		if (array1[i] % 2 == 1) {
			array2[j] = array1[i];
			sr = sr + array2[j];
			if (array2[j] > maxx) {//Находим максимум
				maxx = array2[j];
			}
			if (array2[j] < minn) {//Находим минимум
				minn = array2[j];
			}
			j++;
		}
	}
	sr = sr / j;//Находим среднее
	cout << " \n";

	cout << "Array of odd elements:\n";//Вывод массива нечетных элементов
	for (i = 0; i < m; i++)
	{
		if (array2[i] != 0) {
			cout << array2[i] << " ";
		}
	}
	cout << " \n";
	cout << " \n";
	cout << "Max: " << maxx << endl;
	cout << "Min: " << minn << endl;
	cout << "Average: " << sr << endl;
}
