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
    bool flag = true;
    int max, min;
    float avg = 0;

    int odd_index = 0;
    while (i < size){
        if (arr[i] % 2 != 0){
            if (flag){
                min = arr[i];
                max = arr[i];
                flag = false;
            }
            length += 1;
            odd[odd_index] = arr[i];
            avg += (float)arr[i];
            if (arr[i] < min){
                min = arr[i];
            }
            if (arr[i] > max){
                max = arr[i];
            }
            odd_index++;
        }
        i++;
    }

    avg = avg / (float)length;
    std::cout << "\n" << min << " " << max << " " << avg;

    return 0;
}
