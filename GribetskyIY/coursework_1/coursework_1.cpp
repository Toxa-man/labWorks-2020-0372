#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
using namespace std;

class student{//Класс студент
    public:
        string fio;
        int age;
        int group;
};

student add_student (int number, student arr[]){//Добавление студента в БД
    cout <<"Name: "<<endl;
    cin>>arr[number].fio;
    cout <<"Age: "<<endl;
    cin>>arr[number].age;
    cout <<"Group: "<<endl;
    cin>>arr[number].group;
    return arr[number];
}

void restore_student(int number, ifstream& f_read, student arr[]){//Распаковываем БД из файла в массив
    
    if(!f_read.is_open()){
            cout <<"File incorrect"<<endl;
        }
    else if(f_read.peek() != EOF){
            f_read>>arr[number].fio;
            f_read>>arr[number].age;
            f_read>>arr[number].group;
        }
}

void out_student (int number, student arr[]){//Вывод студентов на консоль
    cout <<"Student #"<< number <<endl;
    cout <<"Name:  "<< arr[number].fio <<endl;
    cout <<"Age:   "<< arr[number].age << endl;
    cout <<"Group: "<< arr[number].group << endl;
}

void write_student (int number, ofstream& f_write, student arr[]){//Запись БД в файл
    
    if(!f_write.is_open()){
        cout <<"File incorrect"<<endl;
    }
    else{
        f_write << arr[number].fio <<endl;
        f_write << arr[number].age<<endl;
        f_write << arr[number].group <<endl;
        f_write <<endl;
    }
    cout << "New entry made!"<<endl;
}

void del_student(int number, int count, student arr[]){//Удаление студентов
    arr[number].fio="0";

    for (int i=number; i<count; i++){
        if(arr[i].fio=="0"){
            swap(arr[i],arr[i+1]);
        }
    }
    cout <<"Student deleted successfully!"<<endl;
}

int main()
{
    int const n=30;
    student arr[n];//Массив объектов класса студент
    char ex_key;//esc
    int action;//Действие
    int count;//Кол-во студентов БД
    int temp_count;//Кол-во студентов, которых хотят добавить в данный момент
    string data_path = "data_base.txt";//Файл для записи БД
    ofstream f_write;
    ifstream f_read;

    f_read.open(data_path);//Распаковываем БД из файла в массив

        if(!f_read.is_open()){
            cout <<"File incorrect"<<endl;
        }
        else{
            f_read >> count;
        }
        
        if (count != 0){ 
            for(int i=0; i<count; i++){        
                restore_student(i, f_read, arr);
            }
        }
            
    f_read.close();
    
    bool correct_oper;//проверка на правильность введенно операции
    do{
        system("cls");
        do{//выбор действия

            cout << "Possible actions: "<<endl;
            cout << "Add students:      [1]"<<endl;
            cout << "Write database:    [2]"<<endl;
            cout << "Delete students:   [3]"<<endl;
            cout << "Out database:      [4]"<<endl;
            cout << "Exit:              [5]"<<endl;
            cout << "Choose an action:"<<endl;
            cin >> action;
            correct_oper = true;

            switch (action)
            {

            case 1://Добавить студента
                cout <<"How many students do you want to add?"<<endl;
                cin>>temp_count;
                for(int i=count; i<(count+temp_count); i++){
                    arr[i]=add_student(i, arr);
                }
                count=count+temp_count;
                cout <<"Don't forget to save your changes to the database!"<<endl;
                break;

            case 2://Записать БД
                cout << "Open file..."<<endl;
                f_write.open(data_path);
                f_write <<count<<endl;
                    for(int i=0; i<count; i++){        
                        write_student(i, f_write, arr);
                    }
                f_write.close();
                cout << "Database was successfully updated!"<<endl;
                break;

            case 3://Вывести БД
                int temp_del;//номер удаляемого студента
                cout << "Which student do you want to remove (number)?"<<endl;
                cin >> temp_del;
                del_student(temp_del, count, arr);
                cout <<"Don't forget to save your changes to the database!"<<endl;
                count--;
                break;

            case 4://Вывести БД
                    for(int i=0; i<count; i++){        
                        out_student(i, arr);
                    }
                break;
            
            case 5://Выход
                system("pause");
                return 0;

            default:
                cout <<"Choose correct operation!";
                break;
            }

        }while(!correct_oper);

        cout << "Press esc to exit...\n";
        cout << "Press any key to go back to the main menu...\n";
        ex_key = _getch();

    }while(ex_key != 27);

    system("pause");
    return 0;
}    