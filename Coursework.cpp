#include<iostream>
#include<cmath>
using namespace std;

void Promahi(long double*& arr, int &size, double* promahi) {
	// проверка на промахи
	long double* new_arr = new long double[size];
	
	for (int i = 0; i < size; i++) {
		
		if (arr[size - 1] - arr[size - 2] > promahi[size] * (arr[size - 1] - arr[0])) {
			arr[size - 1] = 0;
		}
           new_arr[i] = arr[i];
	}

	delete[] arr;
	arr = new_arr;
}

double pogreshnost(long double *arr, int size, long double sr, double* student, double pr) {

	//подсчет полной погрешности

	long double SKO = 0;
	for (int i = 0; i < size; i++) {
		SKO = SKO + pow((arr[i] - sr), 2);
	}
	SKO = sqrt(SKO / (size * (size - 1)));
	return sqrt(pow(student[size] * SKO, 2) + pow(pr, 2));


}

int main() {

	setlocale(0, "");

	int size;
	double pribor_pgr;
	cout << "Введите размер выборки" << endl;
	cin >> size;
	cout << "Введите приборную погрешность" << endl;
	cin >> pribor_pgr;

	 long double* viborka = new long double[size];

	//коэффициенты
	double student[11] = { 0, 0, 12.7, 4.3, 3.2, 2.8, 2.6, 2.4, 2.4, 2.3, 2.3 };
	double promahi[11] = { 0, 0, 0.93, 0.94, 0.76, 0.54, 0.54, 0.71, 0.71, 0.41, 0.41 };

	//ввод выборки

	cout << "Ведите " << size << " чисел" << endl;
	for (int i = 0; i < size; i++) {	
		cin >> viborka[i];
	}
	

	//сортировка выборки

    int i = 0;
	while (i < size - 1) {
		if (viborka[i] > viborka[i + 1]) {
			int index = i + 1;
			double element = viborka[i + 1];
			while (index > 0 && viborka[index - 1] > element) {
				viborka[index] = viborka[index - 1];
				viborka[index - 1] = element;
				index--;
			}
		}
		i++;
	}


	Promahi(viborka, size, promahi);


	//подсчет среднего значения

	long double srednee = 0;
	for (int i = 0; i < size; i++) {
		if (viborka[i] == 0) {
			size--;
		}
	}

	for (int i = 0; i < size; i++) {
	  srednee = srednee + viborka[i] / size;
	}
	cout << endl;

	cout << "Результат: " <<srednee << " +- " << pogreshnost(viborka, size, srednee, student, pribor_pgr);

	delete[]viborka;

		return 0;
	}
