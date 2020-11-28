#include <iostream>
#include <cstdlib>
#include <ctime>

const int size = 10;

void sort(int* arr){
    int left = 0, right = size - 1;
    while (left < right){
        int i = 0;
        while (i < right) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
            i++;
        }
        right--;
        i = right;
        while (i > left){
            if (arr[i] < arr[i - 1]){
                std::swap(arr[i], arr[i - 1]);
            }
            i--;
        }
        left++;
    }
}

int main() {
    srand(time(0));
    int arr[size];

    for (int & i : arr){
        i = rand();
    }

    sort(arr);
    
    int i = 0;
    while (i < size){
        std::cout << arr[i] << " ";
        i++;
    }

    int odd[size];
    i = 0;
    int length = 0;
    int max = arr[0], min = arr[0];
    float avg = 0;

    while (i < size){
        if (arr[i] % 2 != 0){
            length += 1;
            odd[i] = arr[i];
            avg += arr[i];
            if (arr[i] < min){
                min = arr[i];
            }
            if (arr[i] > max){
                max = arr[i];
            }
        }
        i++;
    }

    avg = avg / (float)length;
    i = 0;
    std::cout << "\n" << min << " " << max << " " << avg;

    return 0;
}
