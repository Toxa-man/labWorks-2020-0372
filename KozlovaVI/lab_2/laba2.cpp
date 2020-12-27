#include <iostream>
#include <ctime>
using namespace std;
int push(int Mass[], int size) {
    for (int i = 0; i < size; i++) {
        Mass[i] = rand() % 78 - 17;
    }
}
int sort(int Mass[], int size) {
    int i = 1;
    while (i < size) {
        int j = i;
        while (j > 0 && Mass[j - 1] > Mass[j]) {
            int swap = Mass[j];
            Mass[j] = Mass[j - 1];
            Mass[j - 1] = swap;
            j--;
        }
        i++;
    }
}
int out(int Mass[], int size) {
    for (int i = 0; i < size; i++) {
        cout << Mass[i] << " ";
    }
    cout << endl;
}
int main()
{
    srand(time(NULL));
   int const size = 10;
    int Mass[size];

    push(Mass, size);

    sort(Mass, size);

    out(Mass, size);
    
    
    int New[size]; int sizik = 0;
    for (int i = 0; i < size; i++) {
        if (Mass[i] % 2 != 0) {
            New[sizik] = Mass[i];
            sizik++;
        }
    }

  
    out(New, sizik);

    int min = New[0];
    int max = New[0];
    int sredn = 0;
    for (int i = 0; i < sizik; i++) {
        if (min > New[i]) min = New[i];
        if (max < New[i]) max = New[i];
        sredn = sredn + New[i];
    }
    sredn = sredn / sizik;
    cout << sredn << endl;
    cout << min << endl;
    cout << max << endl;
    return 0;
}

