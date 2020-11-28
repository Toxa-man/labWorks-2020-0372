#include <iostream>
#include <stdio.h>
#include <ctime>
#include <conio.h>
using namespace std;
char ch;
const int n = 20;
int matr_1 [n][n];//1-я матрица
int matr_2 [n][n];//2-я матрица
int res [n][n];//результат действия
int n_1;//строки 1-ой матрицы 
int m_1;//столбцы 1-ой матрицы  
int n_2;//строки 2-ой матрицы 
int m_2;//столбцы 2-ой матрицы 
int oper;//действие над матрицами
bool correct;//проверка на правильность размеров

void summ_or_razn (int mat_1[n][n], int mat_2[n][n], int itog [n][n]){//сумма и разность
    if((n_1==n_2)&&(m_1==m_2))
    {
        if(oper==1){
            for(int i = 0; i<n_1 ; i++){
                for(int j = 0; j<m_1 ; j++){
                    itog[i][j] = mat_1[i][j] + mat_2[i][j];
                }
            }
        }
        else if(oper==2){
            for(int i = 0; i<n_1 ; i++){
                for(int j = 0; j<m_1 ; j++){
                    itog[i][j] = mat_1[i][j] - mat_2[i][j];
                }
            }
        }

    }

    else
    {
        cout<<"Impossible to calculate! Wrong size!";
        correct = false;
    }
}

void proizved (int mat_1[n][n], int mat_2[n][n], int itog [n][n]){//произведение
    if(n_1==m_2)
    {
        for(int i = 0; i<n_2 ; i++){//строка
                for(int j = 0; j<m_1 ; j++){//столбец
                    itog[i][j]=0;
                    for(int k=0; k<m_1; k++)//идем по строке и столбцу
                    itog[i][j] += (mat_1[i][k] * mat_2[k][j]);        
                }
        }
    }
    else
    {
        cout<<"Impossible to calculate! Wrong size!";
        correct = false;
    }

}


int main()
{
    do{
    correct = true;

    cout << "Select the size of the 1st matrix:\n";//ввод размеров 1-й матрицы
    cout << "Strings:\n";
    cin>>n_1;
    cout << "Columns:\n";
    cin>>m_1;

    cout << "Select the size of the 2nd matrix:\n";//ввод размеров 2-й матрицы
    cout << "Strings:\n";
    cin>>n_2;
    cout << "Columns:\n";
    cin>>m_2;

    srand(time(NULL));

    for(int i = 0; i<n_1 ; i++){//заполнение 1-й матрицы
        for(int j = 0; j<m_1 ; j++){
            matr_1[i][j]=rand() % 10;

        }
    
    }
    cout<<endl;
    for(int i = 0; i<n_2 ; i++){//заполнение 2-й матрицы
        for(int j = 0; j<m_2 ; j++){
            matr_2[i][j]=rand() % 10;

        }
    
    }
    cout << "1st matrix:\n";
    for(int i = 0; i<n_1 ; i++){//вывод 1-й матрицы
        for(int j = 0; j<m_1 ; j++){
           cout << matr_1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout << "2st matrix:\n";
    for(int i = 0; i<n_2 ; i++){//вывод 2-й матрицы
        for(int j = 0; j<m_2 ; j++){
           cout << matr_2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    bool correct_oper;//проверка на правильность введенно операции

    do{//выбор действия

    cout << "Possible actions: "<<endl;
    cout << " '+': 1"<<endl;
    cout << " '-': 2"<<endl;
    cout << " '*': 3"<<endl;
    cout << "Choose an action:"<<endl;

    cin >> oper;
    correct_oper = true;

    switch (oper)
    {
        case 1://сложение
            summ_or_razn(matr_1, matr_2, res);
            break;
        case 2://вычитание
            summ_or_razn(matr_1, matr_2, res);
            break;
        case 3://умножение
            proizved(matr_1, matr_2, res);
            break;
    
        default:
            cout << "There is no such operation!\n";
            correct_oper = false;
            break;
    }
        cout <<endl;
    }while(!correct_oper);
    
    if(correct == true){
        for(int i = 0; i<n_1 ; i++){//вывод результата
            for(int j = 0; j<m_1 ; j++){
            cout << res[i][j]<<" ";
            }
            cout<<endl;
    }
    }
    
    cout << "Press esc to exit...\n";
	cout << "Press any key to restart program...\n";
    ch = _getch();

    }while(ch != 27);


    system("pause");
	return 0;
    
}
