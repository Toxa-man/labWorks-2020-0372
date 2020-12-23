#include <stdio.h>
#include <iostream>
using namespace std;
int const n = 15;
int const m = 30;
char str[m] = {'S','o','m','e',' ','r','a','n','d','o','m',' ','w','o','r','d','s',' ','h','e','r','e'};
char word_matr[n][n];//массив отдельных слов

int main()
{
    int num [n];//массив сумм кодов

    int simv=0;//кол-во символов
    int words = 1;//кол-во слов
    while (str[simv]!='\0'){//подсчет слов
        simv++;
        if(str[simv]==' '){
            words++;
        }
    }


    int j=0; int d=0;
    for(int i=0; i<words; i++){//заполняем двумерный массив отдельными словами
        d=0;
        while(str[j]!=' '){
            word_matr[i][d]=str[j];
            num[i]= num[i]+(int)(str[j]);//считаем сумму кодов
            j++;
            d++;
            if(str[j]=='\0'){
                break;
            }
        }
        j++;
    }

    for (int i = 0; i<words; i++){//переставляем слова в порядке увеличения суммы кодов
        for (int a = 0; a<(words-1); a++){
            if(num[a]>num[a+1]){
                swap(num[a],num[a+1]);
                for(int k=0; k<n; k++){
                    swap(word_matr[a][k],word_matr[a+1][k]);
                }
            }   
        }
    }

    cout<<"Input: "<<str<<endl;
    cout<<"Output: ";
    for(int i=0; i<words; i++){//вывод двумерного массива
        cout<<word_matr[i];
        cout<<" ";
    }
    cout<<endl;
    system("pause");
	return 0;
}