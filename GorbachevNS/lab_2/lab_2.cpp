#include <iostream>
#include <ctime>

using namespace std;

void Bubble(int* arr, int size)
{
    int i(0), j, tmp;
    do {
        j = 0;
        do {
            if (arr[j + 1] < arr[j])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
            j++;
        } while (j < size - 1);
        i++;
    } while (i < size);
}
int main()
{
    const int size(9);
    int arr[size];
    int i, c(0);
    srand(time(0));
    for (i = 0; i < size; i++) {
        arr[i] = -50 + rand() % 100 + 1;
    }
    cout << "Original array: " ;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl <<"After sorting: " ;
    Bubble(arr, size);
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl <<"Second array:" ;
    int arr2[size];
    for (i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            arr2[i] = arr[i];
        }
        else {
            arr2[i] = 0;
        }
    }
    for (i = 0; i < size; i++) {
        if (arr2[i] != 0)
            cout << arr2[i] << " ";
    }
   
    cout << endl << "Minimal element: " << arr[0] << endl;
    cout << "Maximal element: " << arr[size - 1] << endl;
    cout << "Average: ";
    for (i = 0; i < size; i++) {
        c += arr[i];
    }
    cout << (double)c / size;
}
