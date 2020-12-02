#include<time.h>
#include<iostream>
using namespace std;
int main() {

const int size = 9;
int odd = 0;
double summ = 0;
int array[size];
srand(time(NULL));

//заполняем рандомный массив

for (int i = 0; i < size; i++) {
array[i] = rand()%15 - 5;
if (abs(array[i]) % 2 == 1) {
odd++;
}
}

cout « "a random array: ";
for (int i = 0; i < size; i++) {
cout « array[i] « " ";
}
cout « endl;

int i = 0;
//сортировка вставками
while (i < size - 1) {
if (array[i] > array[i + 1]) {
int index = i + 1;
int element = array[i + 1];
while (index > 0 && array[index - 1] > element) {
array[index] = array[index - 1];
array[index - 1] = element;
index--;
}
}
i++;
}

i = 0;
cout « "sorted array: " ;
for (; i < size; i++) {
cout « array[i] « " ";
}
cout « endl;

//делаем массив из нечетных элементов

int array_odd[size];
int j = 0;
while (j < odd) {
for (int i = 0; i < size; i++) {
if (abs(array[i]) % 2 == 1) {
array_odd[j] = array[i];
summ = summ + array_odd[j];
j++;
}
}
}

cout « "second array: ";
for (int i = 0; i < odd; i++) {
cout « array_odd[i] « " ";
}

cout « endl;
cout « "mean: " « summ / odd « endl;
cout « "min element: " « array_odd[0] « endl;
cout « "max element: " « array_odd[odd - 1] « endl;

return 0;
}
