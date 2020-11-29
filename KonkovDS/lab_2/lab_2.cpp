#include <iostream>
#include <time.h>

const int size(10);//размер массива
void vivod(int arr[size]) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

int main() {
	srand(time(nullptr));
	setlocale(LC_ALL, "Russian");
	int array1[size];
	for (int i = 0; i < size; i++) {
		array1[i] = rand() % 20 - 10;	
	}
	std::cout << "Исходный массив: ";
	vivod(array1);
	//начинаем сортировку моим способом
	int i,schet = 1; //счетчик проходов по массиву
	while (schet <= (size - 1)) {
		i = 0;
		while (i < (size - schet)) {
			if (array1[i] > array1[i + 1]){
				std::swap(array1[i], array1[i + 1]);
			}
			i++;
		}
		schet++;
	}
	std::cout << "После сортировки: ";
	vivod(array1);
	std::cout << "Второй массив: ";
	int array2[size];
	schet = 0;
	for (int i = 0; i < size; i++) {
		if (abs(array1[i] % 2) == 1){
			array2[schet] = array1[i];
			std::cout << array2[schet] << ' '; 
			schet++;
		}
	}
	std::cout << std::endl;
	int min = array1[0], max = array1[0];
	double  srednee = array1[0];
	for (int i = 1; i < size; i++) {
		srednee += array1[i];
		if (array1[i] < min){
			min = array1[i];
		}
		if (array1[i] > max) {
			max = array1[i];
		}
	}
	srednee /= size;
	std::cout << "Среднее значение :" << srednee << std::endl << "Минимальный элемент:" << min << std::endl << "Максимальный элемент:" << max << std::endl;
	system("pause");
	return 0;
}
