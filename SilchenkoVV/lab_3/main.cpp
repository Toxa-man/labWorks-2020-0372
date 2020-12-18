#include <iostream>


int codesSum(char* word){
    int sum = 0;
    for (int i = 0; i <= 30; i++){
        if (word[i] == '\0') break;
        sum += (int)word[i];
    }
    return sum;
}

void sort(char words[10][30], int right){
    int left = 0;
    while (left < right){
        int i = 0;
        while (i < right) {
            if (codesSum(words[i]) > codesSum(words[i + 1])) {
                std::swap(words[i], words[i + 1]);
            }
            i++;
        }
        right--;
        i = right;
        while (i > left){
            if (codesSum(words[i]) < codesSum(words[i - 1])){
                std::swap(words[i], words[i - 1]);
            }
            i--;
        }
        left++;
    }
}

int main()
{
    char str[301];
    char words[10][30];
    int last_word_index = 0;

    std::cin.getline(str, 300);

    int n = 0;
    for (char i : str){
        if (i == ' '){
            words[last_word_index][n] = '\0';
            last_word_index += 1;
            n = 0;
        } else {
            if (i == '\0'){
                words[last_word_index][n] = '\0';
                break;
            }
            words[last_word_index][n] = i;
            n++;
        }
    }

    sort(words, last_word_index);

    for (int i = 0; i <= last_word_index; i++){
        int j = 0;
        while (words[i][j] != '\0') {
            std::cout << words[i][j];
            j++;
        }
        std::cout << " ";
    }

    return 0;
}
