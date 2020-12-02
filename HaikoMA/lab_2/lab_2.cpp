#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
srand(time(NULL));
setlocale(LC_ALL, "Rus");
const int N = 15;
int mass[N], nechet[N];
float summ = 0;
int nech = 0;
for (int i = 0; i < N; i++) {
mass[i] = rand() % 100;
cout « mass[i] « "\t";
if (mass[i] % 2 != 0) {
nechet[nech] = mass[i];
nech++;
}
}
int i = 1, k = 0;
while (i != N) {
int j = 0;
while (j < N) {
if (mass[i] < mass[j])
{
swap(mass[i], mass[j]);
}
j++;
}
i++;
}


cout « endl;
cout « "После сортировки: ";
for (int i = 0; i < N; i++) {
cout « mass[i] « "\t";
}
int max = mass[0], min = mass[14];
cout « endl;

cout « "Второй массив: ";
for (int i = 0; i < nech; i++) {
cout « nechet[i] « "\t";
summ = summ + nechet[i];
if (nechet[i] <= min) min = nechet[i];
if (nechet[i] >= max) max = nechet[i];
k++;
}

cout « endl;
cout « "Среднее значение: " « summ / k « endl;
cout « "Минимальный элемент: " « min « endl;
cout « "Максимальный элемент: " « max;
}
