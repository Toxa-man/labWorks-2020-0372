#include <iostream>

float func_degree()
{
    float num1, num2;
    int degree;
    std::cout << "Enter it number and degree :" << std::endl;
    std::cin >> num1 >> degree;
    num2 = num1;
    for (int i = 0; i < degree - 1; i++)
        num1 = num1 * num2;
    std::cout << num1;
    return num1;
}

int func_factorial()
{
    int Num1, Num2 = 1;
    std::cout << "Write N and I will find factorial:";
    std::cin >> Num1;
    while (Num1 > 0)
    {
        Num2 = Num2 * Num1;
        Num1--;
    }
    std::cout << Num2;
    return Num2;
}

double func_root()
{
    double Num1, Num2 = 1, t = 0;
    std::cout << "Write N and I will cout the root:" << std::endl;
    std::cin >> Num1;
    if (Num1 == 0)
        return 0;
    if (Num1 < 0)
        return -1;
    while (Num2 != t)
    {
        t = Num2;
        Num2 = (t + Num1 / t) / 2.0;

    }
    std::cout << Num2;
    return Num2;
}

bool func_simplicity()
{
    std::cout << "Write N:";
    int Num, h = 0;
    std::cin >> Num;
    if (Num <= 0)
        return -1;
    for (int i = 1; i <= Num; i++)
    {
        if (Num % i == 0)
            h++;

    }
    if (h == 2 && Num != 1)
        return true;
    if (h != 2 && Num != 1)
        return false;
    if (Num == 1)
        return true;
    
}

int main()
{
    std::cout << "What do you want to do" << std::endl;
    std::cout << " If you want :" << std::endl;
    std::cout << "N^M then click it {1}" << std::endl;
    std::cout << "N! then click it {2}" << std::endl;
    std::cout << "sqrt(N) then click it {3}" << std::endl;
    std::cout << "Check the numbers for simplicity then click it {4}" << std::endl;
    char CHOICE;
    std::cin >> CHOICE;
    switch (CHOICE)
    {
    case '1':
        func_degree();
        break;
    case '2':
        func_factorial();
        break;
    case '3':
        func_root();
        break;
    case '4':
        std::cout <<func_simplicity();
        break;
    default:
        break;

    }

}
