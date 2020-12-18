#include <iostream>

int getSum(char* word) {
    int sum = 0;
    for (int i = 0; i <= 20; i++) {
        if (word[i] == '\0') break;
        sum += (int)word[i];
    }
    return sum;
}

void doSort(char words[8][20], int right) {
    int left = 0;
    int flag = 1;
    while (left < right && flag>0) {
        flag = 0;
        for (int i = left; i < right; i++) {
            if (getSum(words[i]) > getSum(words[i + 1])) {
                std::swap(words[i], words[i + 1]);
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (getSum(words[i - 1]) < getSum(words[i])) {
                std::swap(words[i], words[i + 1]);
                flag = 1;
            }
        }
        left++;
    }
}

int main()
{
    char str[161];
    char words[8][20];
    int last_word_index = 0;

    std::cin.getline(str, 160);

    int n = 0;
    for (char i : str) {
        if (i == ' ') {
            words[last_word_index][n] = '\0';
            last_word_index += 1;
            n = 0;
        }
        else {
            if (i == '\0') {
                words[last_word_index][n] = '\0';
                break;
            }
            words[last_word_index][n] = i;
            n++;
        }
    }

    doSort(words, last_word_index);

    for (int i = 0; i <= last_word_index; i++) {
        int j = 0;
        while (words[i][j] != '\0') {
            std::cout << words[i][j];
            j++;
        }
        std::cout << " ";
    }

    return 0;
}
