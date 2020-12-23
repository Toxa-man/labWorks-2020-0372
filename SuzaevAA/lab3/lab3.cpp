#include <iostream>
#include <cstring>

const int Razmer_String = 50;
int main() {
    int Number_Words = 1;
    char String[Razmer_String] = { 0 };
    char Number_Words1[Razmer_String][Razmer_String] = { 0 };
	std::cin.getline(String, Razmer_String);
    for (int couter = 0; couter < (int)strlen(String); ++couter){
        if (String[couter] == ' ')
            Number_Words++;
    }
    int massive_number_of_letters[12][2] = { 0 };
    int counter1 = 0;
    int counter2 = 0;
    for (int counter = 0; counter < Number_Words ; counter++){
        counter1 = 0;
        while (String[counter2] != ' ' && counter2 < (int)strlen(String)){
        Number_Words1[counter][counter1]=String[counter2];
        counter1++;
        counter2++;
        }
        massive_number_of_letters[counter][0] = counter1;
        massive_number_of_letters[counter][1] = counter;
        counter2++;
    }
    for (int couterA = 0; couterA < Number_Words; couterA++){
        for (int couterB = 1; couterB < Number_Words; couterB++){
            if (massive_number_of_letters[couterB - 1][0] > massive_number_of_letters[couterB][0]){
                int konteiner1 = massive_number_of_letters[couterB - 1][0];
                massive_number_of_letters[couterB - 1][0] = massive_number_of_letters[couterB][0];
                massive_number_of_letters[couterB][0] = konteiner1;
                int konteiner2 = massive_number_of_letters[couterB - 1][1];
                massive_number_of_letters[couterB - 1][1] = massive_number_of_letters[couterB][1];
                massive_number_of_letters[couterB][1] = konteiner2;
            }
        }
    }
    counter1 = -1;
    for (int counterA = 0; counterA <= Number_Words; counterA++){
        counter1++;
        for (int counterB = 0; counterB < massive_number_of_letters[counterA][0]; counterB++){
            String[counter1]=Number_Words1[massive_number_of_letters[counterA][1]][counterB];
            counter1++;
        }
        String[counter1] = ' ';    
    }
    std::cout << String;
    }
