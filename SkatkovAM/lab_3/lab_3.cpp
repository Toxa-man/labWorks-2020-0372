#include <iostream>
#include <string.h>
const int arr_size=100;
class sentence_with_word {


public:


    void sortSentence(){
        while(end_index<=sentence_size){ // because size and last index are different things
            sortWord();
            newStartIndex();
            newEndIndex();
        }
    }
    sentence_with_word(char * sentence) {
        strcpy(this->sentence,sentence);
        sentence_size = length();
        newEndIndex();
    }

    void print(){
        std::cout<<sentence;
    }

private:

    int sentence_size;
    char sentence[arr_size];
    int start_index = 0;
    int end_index = 0;


    void sortWord(){
        for(int i=0; i < end_index-start_index; i++){
            for(int j=start_index; j < end_index;j++){
                if(sentence[j]>sentence[j+1]){
                    mySwap(j);
                }
            }
        }
    }


    void newEndIndex() {
       int i = end_index+2;
       while(sentence[i] != ' ' && sentence[i] != '\0'){
           i++;
       }
        end_index = i-1;// step back because on space.
    }

    void newStartIndex(){
        start_index=end_index+2; //Skip space
    }

    int length() {
        int i = 0;
        while (sentence[i] != '\0' && i < sentence_size-1) {
            i++;
        }
        return i-1;
    }
    void mySwap(int j){
        char im_helpful=sentence[j];
        sentence[j] = sentence[j+1];
        sentence[j+1] = im_helpful;
    }

};


int main() {

    char input_sentence[arr_size];
    std::cin.get(input_sentence, arr_size);
    sentence_with_word sentence(input_sentence);
    sentence.sortSentence();
    sentence.print();
    return 0;
}
