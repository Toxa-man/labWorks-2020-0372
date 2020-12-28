#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int const N = 100;
    char word[N][N];
    int i = 0, x = 0, y = 0;
    cout << "¬ведите предложение, которое оканчиваетс€ точкой" << endl;
    while (word[i][strlen(word[i]) - 1] != '.')
    {
        ++i;
        cin >> word[i];
        cin.clear();
    }
    word[i][strlen(word[i]) - 1] = '\0';
    word[i][strlen(word[i]) + 1] = -52;
    for (int k = 0; k < i; k++)
    {
        for (int j = 1; j < i - k; ++j)
        {
            for (int l = 0; l < strlen(word[j]); l++)
            {
                x += word[j][l];
            }
            for (int d = 0; d < strlen(word[j + 1]); d++)
            {
                y += word[j + 1][d];
            }
            if (x > y)
            {
                swap(word[j], word[j + 1]);
            }
            x = 0;
            y = 0;
        }
    }
    for (int j = 1; j <= i; ++j)
    {
        cout << word[j] << ' ';
    }
    system("pause");
}
