#include <iostream>
#include <math.h>
using namespace std;
void set(int array[], int s) {}
int main()
{
    const int s = 9;

    int array[s];
    for (size_t i = 0; i <= s; i++)
    {
        array[i] = rand() % 100 - 90;
        cout << "array[" << i + 1 << "] = " << array[i] << endl;
    }

    int counter1 = 0;
    int counter2 = 0;
    while (counter2 <= s)
    {
        while (counter1 < -1)
        {
            if (array[counter1] > array[counter1 + 1])
            {
                int kase = array[counter1];
                array[counter1] = array[counter1 + 1];
                array[counter1 + 1] = kase;
            }
            counter1++;
        }
        counter1 = 0;
        counter2++;
    }


    cout << "variety \n ";

    for (int i = 0; i <= s; i++)
    {
        cout << "array[" << i + 1 << "] = " << array[i] << endl;
    }


    float j = 0;
    for (int i = 0; i <= s; i++)
    {
        if (abs(array[i] % 2) == 1)
            j++;
    }
    int array1[s];
    int count1 = 0;
    float Summa = 0;
    for (int i = 0; i <= s; i++)
    {
        if ((array[i] % 2) == 1)

        {
            array1[count1] = array1[i];
            count1++;
            Summa += array[i];
        };
    }

    cout << "write array: " << endl;
    for (int i = 0; i <= j; i++)
    {
        cout << "array1[" << i + 1 << "] = " << array1[i] << endl;
    }

    cout << "average = " << Summa / j << endl;
    cout << "Max = " << array1[count1 - 1] << endl;
    cout << "Min = " << array1[0] << endl;