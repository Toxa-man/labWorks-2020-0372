#include <iostream>
using namespace std;
int main() {
    const int size = 7;
    int arr[size];
    float sr_znach;
    int max, min;
    int per = 0;
    int i, j = 0;

   
    sr_znach = 0;
    for (int i = 0; i < size; i++) {

        arr[i] = rand();
        cout << arr[i] << ' ';
    }

    cout << endl;


    int x = 0;
   while (x < size) {
        per = arr[x];
        i = x - 1;
        while (i >= 0 && arr[i] > per) {
            arr[i + 1] = arr[i];
            i = i - 1;
            arr[i + 1] = per;
        }
        x++;
    }

   
    for (i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }

    max = arr[6];
    min = arr[0];
   
    cout << endl;
    
    int count = 0;
    int* arr2 = new int[j];
    j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            arr2[j] = arr[i];
            j++;
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << arr2[i] << ' ';
      }
    
   cout << endl;

    for (i = 0; i < size; i++) {
        sr_znach = sr_znach + arr[i];
    }
    sr_znach = sr_znach / size;
    cout << "Average value = " << sr_znach;

    cout << endl;

    cout << "Min = " << min << endl << "Max = " << max;

    system("pause");
}
