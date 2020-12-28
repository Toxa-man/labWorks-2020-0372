#include<iostream>
using namespace std;
int main()
{
    const int N = 10;
    int arr[N], a, i, j, arr_n[N], min = 10, max = -10, k = 0;
    float sum = 0;
    cout << "Original array:" << endl;
    for (i = 0; i < N; i++)
    {
        arr[i] = rand() % 21 - 10;
        cout << arr[i] << ' ';
    }
    cout << endl;
    i = 0;
    j = 0;
    while (i < N)
    {
        while (j < N - 1 - i)
        {
            if (arr[j] > arr[j + 1])
            {
                a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
            }
            j++;
        }
        i++;
        j = 0;
    }
    cout << "The resulting array:" << endl;
    for (i = 0; i < N; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    for (i = 0; i < N; i++)
    {
        if (arr[i] % 2 != 0)
        {
            arr_n[k] = arr[i];
            k++;
        }
    }
    cout << "Array with odd numbers:" << endl;
    for (i = 0; i < k; i++)
    {
        cout << arr_n[i] << ' ';
        sum += arr_n[i];
        if (arr_n[i] < min)
        {
            min = arr_n[i];
        }
        if (arr_n[i] > max)
        {
            max = arr_n[i];
        }
    }
    cout << endl;
    cout << "Average = " << sum / k << endl;
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
    return 0;
}
