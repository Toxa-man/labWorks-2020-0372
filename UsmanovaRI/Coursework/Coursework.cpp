#include<iostream>
#include<cmath>
#include "exprtk.hpp"
using namespace std;

void Promahi(long double*& arr, int size, double* promahi) {
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

double pogreshnost(long double* arr, int size, long double sr, double* student, double pr) {

	//подсчет полной погрешности

	long double SKO = 0;

	for (int i = 0; i < size; i++) {
		SKO = SKO + pow((arr[i] - sr), 2);
	}
	SKO = sqrt(SKO / (size * (size - 1)));
	return sqrt(pow(student[size] * SKO, 2) + pow(pr, 2));


}

//работа с формулой


//формула с одной переменной
template <typename T>
double trig_function(std::string str, double arg)
{
	typedef exprtk::symbol_table<T> symbol_table_t;
	typedef exprtk::expression<T> expression_t;
	typedef exprtk::parser<T> parser_t;

	const std::string expression_string = str;


	T x;

	symbol_table_t symbol_table;
	symbol_table.add_variable("x", x);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	x = T(arg);

	const T result = expression.value();
	return result;

}

//с двумя переменными
template <typename T>
double trig_function(std::string str, double arg, double arg2)
{
	typedef exprtk::symbol_table<T> symbol_table_t;
	typedef exprtk::expression<T>     expression_t;
	typedef exprtk::parser<T>             parser_t;

	const std::string expression_string = str;


	T x;
	T y;

	symbol_table_t symbol_table;
	symbol_table.add_variable("x", x);
	symbol_table.add_variable("y", y);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	x = T(arg);
	y = T(arg2);
	const T result = expression.value();
	return result;

}
//с тремя переменными
template <typename T>
double trig_function(std::string str, double arg, double arg2, double arg3)
{
	typedef exprtk::symbol_table<T> symbol_table_t;
	typedef exprtk::expression<T>     expression_t;
	typedef exprtk::parser<T>             parser_t;

	const std::string expression_string = str;


	T x;
	T y;
	T z;

	symbol_table_t symbol_table;
	symbol_table.add_variable("x", x);
	symbol_table.add_variable("y", y);
	symbol_table.add_variable("z", z);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	x = T(arg);
	y = T(arg2);
	z = T(arg3);
	const T result = expression.value();
	return result;

}



int main() {

	setlocale(0, "");

	//коэффициенты
	double student[11] = { 0, 0, 12.7, 4.3, 3.2, 2.8, 2.6, 2.4, 2.4, 2.3, 2.3 };
	double promahi[11] = { 0, 0, 0.93, 0.94, 0.76, 0.54, 0.54, 0.71, 0.71, 0.41, 0.41 };

    bool metod;
	cout << "Для выбора метода обработки погрешностей прямых измерений нажмите \"0\", для косвенных \"1\"." << endl;
	cin >> metod;

    int variable;
	int var;

	if (metod) {
		cout << "Введите количество переменных (максимально 3) " << endl;
		cin >> variable;
		var = variable;
		cout << "Вводите выборки в порядке x, y, z" << endl;
	}
	else {
		variable = 0;
	}

	double* sr_variables = new double[variable];
	double* pgr_variables = new double[variable];
	

	do {

		int size;
		double pribor_pgr;
		cout << "Введите размер выборки" << endl;
		cin >> size;
		cout << "Введите приборную погрешность" << endl;
		cin >> pribor_pgr;

		long double* viborka = new long double[size];


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
		sr_variables[variable - 1] = srednee;
		pgr_variables[variable - 1] = pogreshnost(viborka, size, srednee, student, pribor_pgr);
		if (!metod) {
			cout << "Результат: " << srednee << " +- " << pogreshnost(viborka, size, srednee, student, pribor_pgr);
			delete[]viborka;
			return 0;
		}
		variable--;
	} while (variable > 0);
	cout << endl;
	string formula;
	cout << "Введите формулу используя переменные x, y, z" << endl;
	cin >> formula;
	double result;
	double result_pogreshnost = 0;
	double dx = 0.0001;
	//найдем погрешность используя частные производные

	switch (var)
	{
		
	case 3: result = trig_function<double>(formula, sr_variables[2], sr_variables[1], sr_variables[0]);
		
		for (int i = 0; i < var; i++) {
			sr_variables[2 - i] += dx;
			result_pogreshnost += pow(pgr_variables[i] * ((trig_function<double>(formula, sr_variables[2], sr_variables[1], sr_variables[0]) - result) / dx), 2);
		}
		break;
	case 2: result = trig_function<double>(formula, sr_variables[1], sr_variables[0]);

		for (int i = 0; i < var; i++) {
			sr_variables[1 - i] += dx;
			result_pogreshnost += pow(pgr_variables[i] * ((trig_function<double>(formula, sr_variables[1], sr_variables[0]) - result) / dx), 2);
		}
		break;
	case 1: result = trig_function<double>(formula, sr_variables[0]);

		for (int i = 0; i < var; i++) {
			sr_variables[i] += dx;
			result_pogreshnost += pow(pgr_variables[i] * ((trig_function<double>(formula, sr_variables[0]) - result) / dx), 2);
		}
		break;
	}

	result_pogreshnost = sqrt(result_pogreshnost);

	cout << " Результат: " << result << " +- " << result_pogreshnost;
	delete[] sr_variables;
	delete[] pgr_variables;
	

	return 0;
}
