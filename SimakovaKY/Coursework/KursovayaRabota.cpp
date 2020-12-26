#include <iostream>
#include <conio.h>
using namespace std;

void coordinat_vect(int x0, int y0, int z0, int x, int y, int z) {
	cout << "Координаты вектора равны:" << ' ' << x - x0 << ' ' << y - y0 << ' ' << z - z0 << endl;
}

void dlina_vect(int x0, int y0, int z0, int x, int y, int z) {
	int length;
	length = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0) + (z - z0) * (z - z0));
	cout << "Длина вектора равна:" << ' ' << length;
}

void summ_vect(int x1, int y1, int z1, int x2, int y2, int z2) {

	cout << "Вектор суммы (" << x1 << ' ' << y1 << ' ' << z1 << ") и (" << x2 << ' ' << y2 << ' ' << z2 << ") равен (" << x1 + x2 << ' ' << y1 + y2 << ' ' << z1 + z2 << ")" << endl;
}

void minus_vect(int x1, int y1, int z1, int x2, int y2, int z2) {

	cout << "Вектор разности (" << x1 << ' ' << y1 << ' ' << z1 << ") и (" << x2 << ' ' << y2 << ' ' << z2 << ") равен (" << x1 - x2 << ' ' << y1 - y2 << ' ' << z1 - z2 << ")" << endl;
}

void umn_vect(int x0, int y0, int z0, int n) {
	cout << "Введите координаты вектора: " << endl;
	cin >> x0 >> y0 >> z0;
	cout << "Введите число, на которое хотите умножить вектор: " << endl;
	cin >> n;
	cout << "Вектор (" << x0 << ' ' << y0 << ' ' << z0 << "), умноженный на " << n << " равен вектору (" << x0 * n << ' ' << y0 * n << ' ' << z0 * n << ")" << endl;
}

void vect(int x0, int y0, int z0, int x, int y, int z, int x1, int x2, int y1, int y2, int z1, int z2, int n) {
	cout << "Выберите действие (введите число): " << endl << "1 - Нахождение координат вектора" << endl << "2 - Нахождение длины вектора" << endl << "3 - Сложение векторов" << endl << "4 - Вычитание векторов" << endl << "5 - Умножение вектора на число" << endl;
	char signn;
	cin >> signn;

	if ((signn == '1') || (signn == '2')) {
		cout << "Введите координаты начала вектора: " << endl;
		cin >> x0 >> y0 >> z0;
		cout << "Введите координаты конца вектора: " << endl;
		cin >> x >> y >> z;

		switch (signn) {

		case '1':
			coordinat_vect(x0, y0, z0, x, y, z);
			break;
		case '2':
			dlina_vect(x0, y0, z0, x, y, z);
			break;
		}
	}


	if ((signn == '3') || (signn == '4')) {
		cout << "Введите координаты первого вектора: " << endl;
		cin >> x1 >> y1 >> z1;
		cout << "Введите координаты второго вектора: " << endl;
		cin >> x2 >> y2 >> z2;

		switch (signn) {

		case '3':
			summ_vect(x1, y1, z1, x2, y2, z2);
			break;

		case '4':
			minus_vect(x1, y1, z1, x2, y2, z2);
			break;
		}
	}

	switch (signn) {
	case '5':
		umn_vect(x0, y0, z0, n);
		break;
		cout << endl;
	}
}

void summ_matrix(int** Matrix1, int** Matrix2, int** Matrix_result, int n1, int m1, int n2, int m2) {
	cout << "Исходная матрица = ";

	if ((n1 == n2) && (m1 == m2)) {

		Matrix_result = new int* [n1];
		for (int i = 0; i < n1; i++) {
			Matrix_result[i] = new int[m1];
			for (int j = 0; j < m1; j++) {
				Matrix_result[i][j] = 0;
				Matrix_result[i][j] = Matrix1[i][j] + Matrix2[i][j];
				cout << Matrix_result[i][j] << ' ';
			}
		}
	}
	else {
		cout << "Матрицы разных размеров!";
	}



}

void minus_matrix(int** Matrix1, int** Matrix2, int** Matrix_result, int n1, int m1, int n2, int m2) {
	cout << "Исходная матрица = ";
	if ((n1 == n2) && (m1 == m2)) {
		Matrix_result = new int* [n1];
		for (int i = 0; i < n1; i++) {
			Matrix_result[i] = new int[m1];
			for (int j = 0; j < m1; j++) {
				Matrix_result[i][j] = 0;
				Matrix_result[i][j] = Matrix1[i][j] - Matrix2[i][j];
				cout << Matrix_result[i][j] << ' ';
			}
		}

	}
	else {
		cout << "Матрицы разных размеров!";

	}


}

void umn_matrix(int** Matrix1, int** Matrix2, int** Matrix_result, int n1, int m1, int m2, int n2) {
	cout << "Исходная матрица = ";
	if (m1 = n2) {
		Matrix_result = new int* [n1];
		for (int i = 0; i < n1; i++) {
			Matrix_result[i] = new int[m2];
			for (int j = 0; j < m2; j++) {
				Matrix_result[i][j] = 0;
				for (int k = 0; k < m1; k++) {
					Matrix_result[i][j] = Matrix_result[i][j] + (Matrix1[i][k] * Matrix2[k][j]);

				}
			}
		}
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m2; j++)
				cout << Matrix_result[i][j] << " ";
		}
	}
	else {
		cout << "Умножение невозможно! Проверьте размер матриц.";
	}

}

void transpor_matrix(int** Matrix1, int n1, int m1) {
	cout << "Исходная матрица = ";
	for (int i = 0; i < n1; ++i) {
		for (int j = i; j < m1; ++j)
		{
			int t = Matrix1[i][j];
			Matrix1[i][j] = Matrix1[j][i];
			Matrix1[j][i] = t;
		}
	}
	for (int i = 0; i < m1; ++i)
		for (int j = 0; j < n1; ++j)
		{
			cout << Matrix1[i][j] << ' ';
		}
}


void umn_na_chislo(int** Matrix1, int n1, int m1) {
	cout << "Введите число, на которое будет умножена матрица:  ";
	int chislo;
	cin >> chislo;
	cout << "Исходная матрица = ";
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {

			Matrix1[i][j] = Matrix1[i][j] * chislo;
			cout << Matrix1[i][j] << ' ';
		}
	}

}


void Matrix(int** Matrix1, int** Matrix2, int** Matrix_result, int n1, int m1, int n2, int m2) {
	cout << "выберите действие (введите число): " << endl << "1 - сложение матриц" << endl << "2 - вычитание матриц" << endl << "3 - перемножение матриц" << endl << "4 - транспонирование матрицы" << endl << "5 - умножение матрицы на число" << endl;
	char sign1;
	cin >> sign1;

	if ((sign1 == '4') || (sign1 == '5')) {
		cout << "Введите число строк и столбцов матрицы: " << endl;
		cin >> n1 >> m1;

		cout << "Введите матрицу:" << endl;
		Matrix1 = new int* [n1];
		for (int i = 0; i < n1; i++) {
			Matrix1[i] = new int[m1];
			for (int j = 0; j < m1; j++) {
				cin >> Matrix1[i][j];
			}
		}

		switch (sign1) {

		case '4':
			transpor_matrix(Matrix1, n1, m1);
			break;

		case '5':
			umn_na_chislo(Matrix1, n1, m1);
			break;
		}
	}
	else {

		cout << "Введите число строк и столбцов первой матрицы: " << endl;
		cin >> n1 >> m1;

		cout << "Введите матрицу:" << endl;
		Matrix1 = new int* [n1];
		for (int i = 0; i < n1; i++) {
			Matrix1[i] = new int[m1];
			for (int j = 0; j < m1; j++) {
				cin >> Matrix1[i][j];
			}
		}


		cout << "Введите число строк и столбцов второй матрицы: " << endl;
		cin >> n2 >> m2;

		cout << "Введите матрицу:" << endl;
		Matrix2 = new int* [n2];
		for (int i = 0; i < n2; i++) {
			Matrix2[i] = new int[m2];
			for (int j = 0; j < m2; j++) {
				cin >> Matrix2[i][j];
			}
		}


		switch (sign1) {

		case '1':
			summ_matrix(Matrix1, Matrix2, Matrix_result, n1, m1, n2, m2);
			break;

		case '2':
			minus_matrix(Matrix1, Matrix2, Matrix_result, n1, m1, n2, m2);
			break;

		case '3':
			umn_matrix(Matrix1, Matrix2, Matrix_result, n1, m1, m2, n2);
			break;
		}

		cout << endl;
	}

	delete[] Matrix1;
	delete[] Matrix2;

}

typedef struct Complex {
	double Re;
	double Im;

} Z;

Z summation(Z Z1, Z Z2) {
	Z summ;
	summ.Re = Z1.Re + Z2.Re;
	summ.Im = Z1.Im + Z2.Im;
	return summ;
}

Z subtract(Z Z1, Z Z2) {
	Z subt;
	subt.Re = Z1.Re - Z2.Re;
	subt.Im = Z1.Im - Z2.Im;
	return subt;
}

Z multiply(Z Z1, Z Z2) {
	Z mult;
	mult.Re = (Z1.Re * Z2.Re) - (Z1.Im * Z2.Im);
	mult.Im = (Z1.Im * Z2.Re) + (Z2.Im * Z1.Re);
	return mult;
}

Z divide(Z Z1, Z Z2) {
	Z divi;
	divi.Re = (Z1.Re * Z2.Re + Z1.Im * Z2.Im) / (pow(Z2.Re, 2) + pow(Z2.Im, 2));
	divi.Im = (Z1.Im * Z2.Re - Z2.Im * Z1.Re) / (pow(Z2.Re, 2) + pow(Z2.Im, 2));
	return divi;
}


Z Stepen_chisla(Z Z1, int chislo) {
	Z stepen;
	stepen.Re = (Z1.Re * Z1.Re) - (Z1.Im * Z1.Im);
	stepen.Im = (Z1.Im * Z1.Re) + (Z1.Im * Z1.Re);
	return stepen;
}

void comlex_chisla(Z com1, Z com2) {

	cout << "Выберите действие с комплексными числами (введите цифру): " << endl << "1 - сложение" << endl << "2 - вычитание" << endl << "3 - умножение" << endl << "4 - деление" << endl << "5 - возведение в степень" << endl << "6 - модуль числа" << endl << "7 - аргумент числа" << endl << "8 - тригонометрическая форма числа" << endl << "9 - показательная форма числа " << endl;
	char sign2;
	cin >> sign2;
	if ((sign2 == '1') || (sign2 == '2') || (sign2 == '3') || (sign2 == '4')) {

		cout << "Введите первое комплексное число. Первая цифра отвечает за реальную часть комплексного числа, " << endl << "вторая за мнимую, i писать не нужно (пример ввода: 11 67): " << endl;
		cin >> com1.Re;
		cin >> com1.Im;
		cout << "Введите второе комплексное число. Первая цифра отвечает за реальную часть комплексного числа, " << endl << "вторая за мнимую, i писать не нужно (пример ввода: 35 28): " << endl;
		cin >> com2.Re;
		cin >> com2.Im;


		switch (sign2) {

		case '1':

			Z summ = summation(com1, com2);

			if (summ.Im > 0) {
				cout << "Сумма двух комплексных чисел равна " << summ.Re << "+" << summ.Im << "i" << endl;
			}
			else {
				cout << "Сумма двух комплексных чисел равна " << summ.Re << summ.Im << "i" << endl;
			}
			break;

		case '2':

			Z subt = subtract(com1, com2);

			if (subt.Im > 0) {
				cout << "Разность двух комплексных чисел равна " << subt.Re << "+" << subt.Im << "i" << endl;
			}
			else {
				cout << "Разность двух комплексных чисел равна " << subt.Re << subt.Im << "i" << endl;
			}
			break;

		case '3':
			Z mult = multiply(com1, com2);

			if (mult.Im > 0) {
				cout << "Призведение двух комплексных чисел равна " << mult.Re << "+" << mult.Im << "i" << endl;
			}
			else {
				cout << "Произведение двух комплексных чисел равна " << mult.Re << mult.Im << "i" << endl;
			}
			break;

		case '4':

			Z divi = divide(com1, com2);

			if (divi.Im > 0) {
				cout << "Частное двух комплексных чисел равна " << divi.Re << "+" << divi.Im << "i" << endl;
			}
			else {
				cout << "Частное двух комплексных чисел равна " << divi.Re << divi.Im << "i" << endl;
			}
			break;
		}
	}
	else {

		cout << "Введите комплексное число. Первое число отвечает за реальную часть комплексного числа, " << endl << "второе за мнимую, i писать не нужно (пример ввода: 13 17): " << endl;


		switch (sign2) {
			float Arg, Modul, Stepen;
			float real, mnim;

		case '5':

			cin >> real >> mnim;
			int chislo;
			cout << "В какую степень возвести число?" << endl;
			cin >> chislo;
			Modul = sqrt((real * real) + (mnim * mnim));
			Arg = atan(mnim / real);
			cout << "Введенное комплексное число в степени " << chislo << " равна " << pow(Modul, chislo) << "*(" << cos(chislo * Arg) << "+i*" << sin(chislo * Arg) << ")" << endl;

			break;


		case '6':
			cin >> real >> mnim;
			Modul = sqrt((real * real) + (mnim * mnim));
			cout << "Модуль введенного комплексного числа равен " << Modul << endl;
			break;

		case '7':
			cin >> real >> mnim;
			Arg = atan(mnim / real);
			cout << "Аргумен введенного комплексного числа равен " << Arg << endl;
			break;

		case '8':
			cin >> real >> mnim;
			Modul = sqrt((real * real) + (mnim * mnim));
			Arg = atan(mnim / real);
			cout << "Введенное комплексное число в тригонометрической форме равно " << Modul << "*(cos(" << Arg << ") + i*sin(" << Arg << "))" << endl;
			break;

		case '9':
			cin >> real >> mnim;
			Modul = sqrt((real * real) + (mnim * mnim));
			Arg = atan(mnim / real);
			cout << "Введенное комплексное число в показательной форме равно " << Modul << "*exp(i*" << Arg << ")" << endl;
			break;
		}

	}
}

int main() {

	setlocale(LC_ALL, "Russian");
	int escape;
	int x0 = 0, y0 = 0, z0 = 0, x = 0, y = 0, z = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0, n = 0, n1 = 0, m1 = 0, n2 = 0, m2 = 0, t = 0;
	int** Matrix1 = NULL, ** Matrix2 = NULL, ** Matrix_result = NULL;
	double modul = 0;

	cout << "Для продолжения - пробел." << endl;


	do {
		cout << "Вывести калькулятор для (введите соответствующую цифру): " << endl << "1 - векторов" << endl << "2 - матриц" << endl << "3 - комплексных чисел" << endl;

		char sign;
		cin >> sign;
		Z com1 = {}, com2 = {};
		switch (sign) {

		case '1':
			vect(x0, y0, z0, x, y, z, x1, x2, y1, y2, z1, z2, n);
			break;

		case '2':
			Matrix(Matrix1, Matrix2, Matrix_result, n1, m1, n2, m2);
			break;

		case '3':

			comlex_chisla(com1, com2);
			break;
		}
		cout << endl << endl;
		cout << "Для выхода из программы нажмите клавишу 'Escape'. " << endl;
		escape = _getch();
		cout << endl;
	} while (escape != 27);

	return 0;
}