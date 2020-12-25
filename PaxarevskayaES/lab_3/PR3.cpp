#include <iostream>
#include <cstring>

int const size = 377, w_size_1 = 25, w_size_2 = 15;

// The function counts the number of letters in a word
int i_find_sum(char* word) {
    int sum = 0;
    for (int i = 0; i <= w_size_2; i++) {
        if (word[i] == '\0') 
            break;
        sum += int(word[i]);
    }
    return sum;
}

// The function sorts words with shaker-sort
void sorting(char(*words)[w_size_2], int right) {
    int left = 0;
    while (left < right) {
        int i = 0;
        while (i < right) {
            if (i_find_sum(words[i]) > i_find_sum(words[i + 1])) {
                std::swap(words[i], words[i + 1]);
            }
            i++;
        }
        right--;
        i = right;
        while (i > left) {
            if (i_find_sum(words[i]) < i_find_sum(words[i - 1])) {
                std::swap(words[i], words[i - 1]);
            }
            i--;
        }
        left++;
    }
}

int main()
{
    char str[size];
    char words[w_size_1][w_size_2];
    int last_index = 0;

    std::cout << "Enter your sentence : " << std::endl;
    std::cin.getline(str, 377);

    // Splitting a string into words
    int detector = 0;
    for (char i: str) {
        if (i == ' ') {
            words[last_index][detector] = '\0';
            last_index += 1;
            detector = 0;
        }
        else {
            if (i == '\0') {
                words[last_index][detector] = '\0';
                break;
            }
            words[last_index][detector] = i;
            detector++;
        }
    }

    //Apply the function
    sorting(words, last_index);

    // Displaying the result
    std::cout << "Our result: " << std::endl;
    for (int i = 0; i <= last_index; i++) {
        int j = 0;
        while (words[i][j] != '\0') {
            std::cout << words[i][j];
            j++;
        }
        std::cout << " ";
    }

    return 0;
}