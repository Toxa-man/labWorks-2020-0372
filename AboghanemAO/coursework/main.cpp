/* Выполнили: 
Мохамед .А.А 
Абуганем.А.У  */



#include <iostream>



void out(std::string* spot) {

    std::cout << "     |     |     \n";
    std::cout << spot[0] << "|" << spot[1] << "|" << spot[2] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << spot[3] << "|" << spot[4] << "|" << spot[5] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << spot[6] << "|" << spot[7] << "|" << spot[8] << "\n";
    std::cout << "     |     |     \n";
}




char didwin(bool* isx, bool* iso) {
    if ((isx[0] && isx[1] && isx[2]) || (isx[3] && isx[4] && isx[5]) || (isx[6] && isx[7] && isx[8]) || 
        (isx[0] && isx[3] && isx[6]) || (isx[4] && isx[1] && isx[7]) || (isx[2] && isx[5] && isx[8]) || 
        (isx[0] && isx[4] && isx[8]) || (isx[6] && isx[2] && isx[4])){
        return 'x';
    }
    if ((iso[0] && iso[1] && iso[2]) || (iso[3] && iso[4] && iso[5]) || (iso[6] && iso[7] && iso[8]) || 
        (iso[0] && iso[3] && iso[6]) || (iso[4] && iso[1] && iso[7]) || (iso[2] && iso[5] && iso[8]) || 
        (iso[0] && iso[4] && iso[8]) || (iso[6] && iso[2] && iso[4])){
        return 'o';
    }
    return ' ';
}


int main() {
    std::string spot[9]{ "  1  " , "  2  " , "  3  ", "  4  " , "  5  " ,"  6  " , "  7  " , "  8  " , "  9  " };
    out(spot);
    int x, o;
    bool isx[9] = { false,false,false,false,false,false,false,false,false }, iso[9]{ false,false,false,false,false,false,false,false,false };
    char winer;
    int turn = 0;
    int player1 = 0, player2 = 0;


    while (player1 != 3 && player2 != 3) {
        while (turn < 9) {
            std::cout << "player 1 :";
            std::cin >> x;
            turn++;
            if (turn == 9) { break; }
            for (int i = 1; i <= 9; i++) {
                if (x == i) {
                    spot[i - 1] = "  X  ";
                    isx[i - 1] = true;
                }
            }
            out(spot);
            winer = didwin(isx, iso);
            if (winer == 'x' || winer == 'o') { break; }


            std::cout << "player 2 :";
            std::cin >> o;
            turn++;
            for (int i = 1; i <= 9; i++) {
                if (o == i) {
                    spot[i - 1] = "  O  ";
                    iso[i - 1] = true;
                }
            }
            out(spot);

            winer = didwin(isx, iso);
            if (winer == 'x' || winer == 'o') { break; }
        }

        if (winer == 'x') { std::cout << "player1 won the round \n"; player1++; }
        else if (winer == 'o') { std::cout << "player2 won the round \n";player2++; }
        else { std::cout << "draw \n"; }

        std::cout << "player 1 won " << player1 << " rounds and player 2 won " << player2 << " rounds\n";
        turn = 0;
        winer = ' ';
        spot[0] = "  1  ";spot[1] = "  2  ";spot[2] = "  3  ";spot[3] = "  4  ";spot[4] = "  5  ";spot[5] = "  6  ";spot[6] = "  7  ";spot[7] = "  8  ";spot[8] = "  9  ";
        for (int i = 0; i < 9; i++) { isx[i] = false; iso[i] = false; }
        out(spot);


    }
    std::cout << "===============================\nGAME OVER\n";
    if (player1 == 3) { std::cout << "player1 won the game\n"; }
    if (player2 == 3) { std::cout << "player2 won the game\n"; }
    return 0;
}
