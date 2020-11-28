#include <stdio.h>
#include <iostream>
using namespace std;
int  step;
long double res;
double num;
bool sostavnoe;


int stepen(int a, int n){
    int res = 1;
    for(int i =0; i<n; i++){
        res=res*a;
    }
    return res;
}

int factor(int a){
    long long int res = 1;
    for(int i =2; i<(a+1); i++){
        res=res*i;
    }
    return res;
}

double koren(double a){
    double left = 0;//левая граница
    double right = 9999999; //правая граница
    double mid;//середина
    double p = 0.000001;//точность вычислений

    while (right - left > p){ 
        mid = left + (right - left)/2;//ищем середину
        if (mid*mid > a) {
            right = mid;
        }
        else 
            left = mid; 
        }
    return left;         
}

bool prosto_li(int a){
    double kor=koren(a);//корень искомого числа
    int i = 2;//делитель
    bool sost = false;//проверка составное ли число

    while ((i<=kor)&&(sost==false)){
        if(a % i == 0){
            sost=true;
        }
        else {
            i++;
        }
    }
    return sost;
}

int main()
{
    cout << "Enter number:";
    cin >> num;
    cout << "Enter degree of number:";
    cin >> step;

    res=stepen(num, step);
    cout<< num << "^" << step << " = " << res<<endl;

    res=factor(num);
    cout<< num << "!" << " = " << res<<endl;

    res=koren(num);
    cout<< "sqrt(" << num << ")" << " = " << res<<endl;

    sostavnoe=prosto_li(num);
    cout<< "Is it a simple number?"<<endl;;
    if(sostavnoe == true){
        cout << "No" << endl;
    }
    else if(sostavnoe == false) {
        cout << "Yes" << endl;
    }

    system("pause");
	return 0;
    }