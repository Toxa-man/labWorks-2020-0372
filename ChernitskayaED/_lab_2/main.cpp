#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int kolvo;
	cout << "Введите диапазон рандомных чисел: ";
	cin >> kolvo;
	const int size = 9;
	int arr[size];
	cout << "Исходный массив: ";
	for (int i = 0; i < size; i++){
	
		arr[i] = 1 + rand() % kolvo;
		cout << arr[i] << " ";
	}
	
	int t = 0;
	bool end = false;
	cout << endl << "Отсортированный массив: ";
	do{
		end = true;
		for (int i = 0; i < size-1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				end = false;
			}
		}
	
	}while (end != true);
	
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " " ;
	}
	
	int nechet = 0;                
	for ( int i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0)
		{
			nechet = nechet + 1;
		}
	}
	
	                
	int *arr2 = new int[nechet];
	int suma = 0;
	int j = 0;
	for (int i = 0; i < size; i++) 
	{
		if (arr[i] % 2 != 0)
		{
			arr2[j] = arr[i];
			j++;
			suma = suma + arr[i];
			
		}
	}
	int maxi = arr2[nechet-1];
	int mini = arr2[0];
	
	double average = (double)suma / nechet;

	cout << endl << "Нечетные значения: ";
	for (int j = 0; j < nechet; j++)
	{
		cout << arr2[j] << " ";
	}
	
	cout << endl << "Среднее значение: ~ " << average;
	cout << endl << "Максимальное значение: " << maxi;
	cout << endl << "Минимальное значение: " << mini << endl;
	 
	system("pause");
	return 0; 
}
