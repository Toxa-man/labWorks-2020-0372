#include <iostream>
#include <ctime>



const int row_amount=2;
const int column_amount=2;
int findElement(int * matrix1, int * matrix2, int u, int v);
enum answer{
    RANDOM,BYHANDS
};
void doAllThatThings(answer);

class matrix{
public:
    matrix(){
        std::cout<<"Type matrix "<<row_amount<<"x"<<column_amount<<std::endl;
        read();
    }
    matrix(int *matrix){
        set_arr(matrix);

    }
    matrix(int max){
        randomize(max);
    }
    void read(){
        for(int i=0;i<row_amount;i++){
            for(int j = 0;j<column_amount;j++){
                int element=0;
                std::cin>>element;
                arr[i][j] = element;
            }
        }
    }
    matrix operator+(matrix matrix){
        for(int i=0;i<row_amount;i++){
            for(int j = 0;j<column_amount;j++){
                matrix.arr[i][j]+=this->arr[i][j];
            }
        }
        return matrix;
    }

    matrix operator-(matrix matrix){
        for(int i=0;i<row_amount;i++){
            for(int j = 0;j<column_amount;j++){
                matrix.arr[i][j]=this->arr[i][j]-matrix.arr[i][j];
            }
        }
        return matrix;
    }



matrix operator* (matrix second_matrix) {
    matrix result(1);
    for(int i = 0;i<row_amount;i++){
        for(int j = 0;j<column_amount;j++){
            result.arr[i][j]=findElement(*arr,*second_matrix.arr,i,j);
        }
    }
    return result;
}
void print(){

    for (int i=0; i < row_amount; i++){
        std::cout<<" ";
        for(int j=0; j < column_amount; j++){
            std::cout<<arr[i][j]<< "\t";
        }
        std::cout<<"\n\n\n";
    }
    std::cout<<"\n\n";
}
private:

    int arr[row_amount][column_amount]={};

    void randomize(int max){
        for (int i=0; i < row_amount; i++){
            for(int j=0; j < column_amount; j++){

                arr[i][j]=(rand() % max)+1;
            }
        }

    }



    void set_arr(int *matrix){
        for (int i=0; i < row_amount; i++){
            for(int j=0; j < column_amount; j++){
                arr[i][j]=matrix[i * column_amount + j];
            }
        }

    }
};




answer dialog(){
    char answer;
    std::cout<<"do you want to type matrixes by self? Type Y or N"<<std::endl;
    while(1) {
        std::cin >> answer;
        switch (answer) {
            case 'Y' :
                return BYHANDS;
            case 'N'  :
                return RANDOM;
            default:
                std::cin.ignore(10000,'\n');
                std::cout << "It looks like wrong input. Try again"<<std::endl;
        }
    }
}

int main() {
    srand(time(0));
    answer answer;
    answer=dialog();
    doAllThatThings(answer);

    return 0;
}
int findElement(int * matrix1, int * matrix2, int u, int v){
    int sum=0;
    for(int i=0;i<row_amount;i++){
        sum+=matrix1[u*column_amount+i]*matrix2[v+column_amount*i];
    }
    return sum;
}
void doAllThatThings(answer answer){
    if(answer==RANDOM) {
        int max=0;
        std::cout<<"Tye max value, which will be max for each element\n";
        std::cin>>max;
        matrix matrix1(max);
        matrix matrix2(max);
        matrix1 * matrix2;
        std::cout << "A:\n";
        matrix1.print();
        std::cout << "B:\n";
        matrix2.print();
        std::cout << "A*B:\n";
        (matrix1 * matrix2).print();
        std::cout << "A+B:\n";
        (matrix1 + matrix2).print();
        std::cout << "A-B:\n";
        (matrix1 - matrix2).print();
    }else{
        matrix matrix1{};
        matrix matrix2{};
        matrix1 * matrix2;
        std::cout << "A:\n";
        matrix1.print();
        std::cout << "B:\n";
        matrix2.print();
        std::cout << "A*B:\n";
        (matrix1 * matrix2).print();
        std::cout << "A+B:\n";
        (matrix1 + matrix2).print();
        std::cout << "A-B:\n";
        (matrix1 - matrix2).print();


    }


}
