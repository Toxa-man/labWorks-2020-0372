#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fcntl.h>
#include <io.h>
#include <vector>
#include <cmath>
#include <algorithm>

//Colors
#define fblue	0x0001
#define fgreen	0x0002
#define fred	0x0004
#define fint	0x0008
#define bblue	0x0010
#define bgreen	0x0020
#define bred	0x0040
#define bint	0x0080

//Starting board
std::string BOARD[8][8] = { {"  ", "-P", "  ", "-P", "  ", "-P", "  ", "-P"},
							{"-P", "  ", "-P", "  ", "-P", "  ", "-P", "  "},
							{"  ", "-P", "  ", "-P", "  ", "-P", "  ", "-P"},
							{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
							{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
							{"+P", "  ", "+P", "  ", "+P", "  ", "+P", "  "},
							{"  ", "+P", "  ", "+P", "  ", "+P", "  ", "+P"},
							{"+P", "  ", "+P", "  ", "+P", "  ", "+P", "  "} };

//Player
struct Player {
	std::string name;
	bool color; //0 - black, 1 - white
	int wins = 0;
	int loses = 0;
};

//Starting coordinates constants and variables for the board
const int _defBoardX = 5, _defBoardY = 1;
int defBoardX = _defBoardX, defBoardY = _defBoardY;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //For terminal colors manipulation

//Goto parameters
HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPosition;

void printBoard(std::string board[8][8]);

void gotoXY(int x, int y)
{
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(terminal, cursorPosition);
}

//Delete the board
void clearBoard() {
	for (int i = 0; i < 45; i++) {
		for (int j = 1; j < 27; j++) {
			gotoXY(i, j); std::cout << " ";
		}
	}
}

//Print cell of the board
void printCell(int x, int y, char value, bool checkerColor, bool cellColor) {
	if (not cellColor) {
		SetConsoleTextAttribute(color, bred | bgreen | bblue);
		for (int i = 0; i < 3; i++) {
			gotoXY(x, y + i); std::cout << "     ";
		}
	}
	else {
		SetConsoleTextAttribute(color, bint | checkerColor * (fint | fred | fgreen | fblue));
		gotoXY(x, y); std::cout << "     ";
		gotoXY(x, y + 1); std::cout << "  " << value << "  ";
		gotoXY(x, y + 2); std::cout << "     ";
	}
	SetConsoleTextAttribute(color, fblue | fgreen | fred);
}

//Print the board
void printBoard(std::string board[8][8]) {
	clearBoard();
	//Print the board
	for (int i = 0; i < 64; i++) {
		printCell((i%8 + 1)*5, 1 + 3*(i/8), board[i/8][i%8][1], not bool((board[i/8][i%8][0] - 43)/2), ((i/8%2) * not bool(i%2)) + (((i + 8)/8%2) * bool(i%2)));
	}
	defBoardX = _defBoardX;
	defBoardY = _defBoardY;

	for (int i = 0; i < 8; i++) {
		gotoXY(defBoardX - 3, defBoardY + 1 + 3 * i);
		std::cout << 8 - i;
		gotoXY(defBoardX + 2 + 5 * i, defBoardY + 25);
		std::cout << (char)('A' + i);
	}
}

//Print other game elements
void printGameElements() {
	gotoXY(46, 1); std::cout << "****** Score ******";
	gotoXY(46, 2); std::cout << "* White  | Black  *";
	gotoXY(46, 3); std::cout << "*        |        *";
	gotoXY(46, 4); std::cout << "*        |        *";
	gotoXY(46, 5); std::cout << "*        |        *";
	gotoXY(46, 6); std::cout << "*******************";

	gotoXY(46, 7); std::cout << "****** Moves ******";
	for (int i = 8; i < 32; i++) {
		gotoXY(46, i); std::cout << "*        |        *";
	}
	gotoXY(46, 32); std::cout << "*******************";

	gotoXY(5, 28); std::cout << "***** Keywords *****";
	gotoXY(5, 29); std::cout << "* exit - To exit   *";
	gotoXY(5, 30); std::cout << "* draw - To draw   *";
	gotoXY(5, 31); std::cout << "* rsgn - To resign *";
	gotoXY(5, 32); std::cout << "********************";

	gotoXY(27, 28); std::cout << "*** Make move ***";
	gotoXY(27, 29); std::cout << "*               *";
	gotoXY(27, 30); std::cout << "*               *";
	gotoXY(27, 31); std::cout << "*               *";
	gotoXY(27, 32); std::cout << "*****************";
}

void updateMovesField(std::vector<std::string> moves) {
	if (moves.size() % 49 <= 24) {
		for (int i = 0; i < moves.size() % 25; i++) {
			gotoXY(47, 8 + i); std::cout << i + 1 << ". " << moves[i];
		}
	} else if (moves.size() % 49 <= 48) {
		for (int i = 25; i < moves.size() + 1; i++) {
			gotoXY(57, 8 + i - 25); std::cout << i << ". " << moves[i - 1];
		}
	}
}

void updateScoreField(float score[2]) {
	gotoXY(50, 4); std::cout << "  ";
	gotoXY(50, 4); std::cout << score[1];
	gotoXY(59, 4); std::cout << "  ";
	gotoXY(59, 4); std::cout << score[0];
}

bool checkMove(std::string move, std::string board[8][8], bool side, int checkers[2], bool &beated) {
	//Verify format
	if (not (isalpha(move[0]) && isalpha(move[2]) && isdigit(move[1]) && isdigit(move[3])))
		return false;

	//Verify letters and digits
	if (not ((96 < move[0] and move[0] < 105) && (96 < move[2] and move[2] < 105) && \
		((48 < move[1] and move[1] < 57) && (48 < move[3] and move[3] < 57))))
		return false;

	//Verify if the selected cell contains appropriate checker
	if (board[56 - move[1]][move[0] - 97] == "  " || \
		board[56 - move[3]][move[2] - 97] != "  " || \
		(side + (board[56 - move[1]][move[0] - 97][0] == '+') == 0))
		return false;

	//Make king
	if (board[56 - move[1]][move[0] - 97][1] != 'D' && move[3] == '8') {
		board[56 - move[1]][move[0] - 97][1] = 'D';
	}

	if (board[56 - move[1]][move[0] - 97][1] == 'D') {
		std::vector<std::vector<int>> cells;
		int sum = 0;

		if (not (std::abs(move[2] - move[0]) == std::abs(move[3] - move[1])))
			return false;

		//King beat
		if (move[0] < move[2] && move[1] < move[3]) {
			//+-
			for (int i = move[0] - 97 + 1, j = 56 - move[1] - 1; i < move[2] - 97; i++, j--) {
				cells.push_back({ j, i });
			}
		} else if (move[0] < move[2] && move[1] > move[3]) {
			//++
			for (int i = move[0] - 97 + 1, j = 56 - move[1] + 1; i < move[2] - 97; i++, j++) {
				cells.push_back({ j, i });
			}
		} else if (move[0] > move[2] && move[1] > move[3]) {
			//-+
			for (int i = move[0] - 97 - 1, j = 56 - move[1] + 1; i > move[2] - 97; i--, j++) {
				cells.push_back({ j, i });
			}
		} else if (move[0] > move[2] && move[1] < move[3]) {
			//--
			for (int i = move[0] - 97 - 1, j = 56 - move[1] - 1; i > move[2] - 97 + 1; i--, j--) {
				cells.push_back({ j, i });
			}
		}

		for (int i = 0; i < cells.size(); i++) {
			if (BOARD[cells[i][0]][cells[i][1]][0] == (not side * 45 + side * 43))
				return 0;
			if (BOARD[cells[i][0]][cells[i][1]] != "  ")
				sum++;
		}

		checkers[0] -= side * sum;
		checkers[1] -= not side * sum;
	} else {
		//Standart checker beat: 
		//1. Whether the move is correct
		//3. Whether you beat the right color
		if (std::abs(move[2] - move[0]) == 2 && std::abs(move[3] - move[1]) == 2 && \
			board[7 - ((move[1] + move[3] - 98)) / 2][(move[0] + move[2] - 194) / 2][0] == (side * 45 + not side * 43)) {

			board[7 - ((move[1] + move[3] - 98)) / 2][(move[0] + move[2] - 194) / 2] = "  ";
			checkers[0] -= side;
			checkers[1] -= not side;
			beated = true;
			return true;
		}

		//Verify validity of the checker move
		if (not (std::abs(move[2] - move[0]) == 1 && std::abs(move[3] - move[1]) == 1))
			return false;
	}

	return true;
}

void findAvailableBeats(std::string move, std::vector<std::string> moves, std::string board[8][8], bool side, int checkers[2]) {
	std::vector<int> currPos = { move[2] - 97, 56 - move[3] };

	while (true) {
		std::vector<std::vector<int>> availMoves;

		for (int i = -1; i <= 1; i += 2) {
			for (int j = -1; j <= 1; j += 2) {
				if (currPos[1] + 2 * i <= 8 && currPos[1] + 2 * i >= 0 && currPos[0] + 2 * j >= 0 && currPos[0] + 2 * j <= 8) {
					if (board[currPos[1] + i][currPos[0] + j][0] == (side * 45 + not side * 43) && \
						board[currPos[1] + 2 * i][currPos[0] + 2 * j] == "  ") {
						availMoves.push_back({ currPos[1] + 2 * i, currPos[0] + 2 * j, currPos[1] + i, currPos[0] + j });
					}
				}
			}
		}

		if (availMoves.size() > 0) {
			bool running = true;
			int menuItem = 0, bias = 0;

			printBoard(board);
			gotoXY(33, 30);
			std::cout << "    ";
			gotoXY(33, 29);
			std::cout << "->";

			while (running) {
				for (int i = 0; i < availMoves.size(); i++) {
					gotoXY(35, 29 + i); std::cout << char(availMoves[i][1] + 97) << 8 - availMoves[i][0];
				}

				switch (_getch()) {
				case 72: //Up key
					if (menuItem == 0) continue;
					gotoXY(33, 29 + bias--); std::cout << "  ";
					gotoXY(33, 29 + bias); std::cout << "->";
					menuItem--;
					continue;

				case 80: //Down key
					if (menuItem == availMoves.size() - 1) continue;
					gotoXY(33, 29 + bias++); std::cout << "  ";
					gotoXY(33, 29 + bias); std::cout << "->";
					menuItem++;
					continue;

				case 13: //Enter
					running = false;
				}
			}

			std::swap(board[currPos[1]][currPos[0]], board[availMoves[menuItem][0]][availMoves[menuItem][1]]);
			currPos = { availMoves[menuItem][1], availMoves[menuItem][0] };
			board[availMoves[menuItem][2]][availMoves[menuItem][3]] = "  ";
			checkers[not side]--;

			for (int i = 29; i < 32; i++) {
				gotoXY(33, i); std::cout << "      ";
			}
		} else {
			break;
		}
	}
}

void whoWon(bool side, Player players[2]) {
	clearBoard();
	gotoXY(9, 10); std::cout << "####### Game over #######";
	gotoXY(21 - players[not side].name.length()/2, 12);
	std::cout << players[not side].name;
	gotoXY(14, 13); std::cout << "is victorious!";
	gotoXY(9, 15); std::cout << "#########################";
}

bool gameProcess(Player players[2], float score[2]) {
	std::vector<std::string> moves;
	std::string move;
	bool side = 1; //0 - black, 1 - white
	int checkers[2] = { 12, 12 }; //Black, White
	bool draw = false;
	bool beated = false;
	std::string board[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = BOARD[i][j];
		}
	}

	//Print starting score and moves
	updateMovesField(moves);
	updateScoreField(score);

	while (true) {
		gotoXY(33, 30);
		std::cout << "    ";
		gotoXY(33, 30);
		std::cin >> move;

		if (move == "exit") {
			return false;
		}
		else if (move == "draw") {
			gotoXY(29, 30);
			std::cout << "Draw? (y/n)   ";
			gotoXY(41, 30);
			switch (_getch()) {
			case 110:
				continue;
			case 121:
				score[0] += 0.5;
				score[1] += 0.5;
				draw = true;
			}
		}
		else if (move == "rsgn") {
			checkers[side] = 0;
		} else {
			if (not checkMove(move, board, side, checkers, beated)) {
				continue;
			}

			std::swap(board[7 - (move[1] - 49)][move[0] - 97], board[7 - (move[3] - 49)][move[2] - 97]);
			moves.push_back(move);

			//Multiple beats
			if (beated) {
				findAvailableBeats(move, moves, board, side, checkers);
				beated = false;
			}
			side = not side;

			printBoard(board);
			updateMovesField(moves);
		}

		if (checkers[0] * checkers[1] == 0) {
			whoWon(not side, players);
			score[not side]++;
		}
		if (checkers[0] * checkers[1] == 0 or draw) {
			if (draw) {
				clearBoard();
				gotoXY(20, 15);
				std::cout << "DRAW!";
			}
			updateScoreField(score);

			gotoXY(5, 17);
			std::cout << "Press <Enter> to play another game";
			gotoXY(5, 18);
			std::cout << "        Or <ESC> to exit";

			switch (_getch()) {
			case 13:
				return true;
			case 27:
				return false;
			}
		}
	}
}

void newGame() {
	Player Player1, Player2;
	Player players[2] = { Player1, Player2 };
	float score[2] = { 0, 0 };
	int games = 0;
	int defX = 8;
	bool continueGame;

	gotoXY(defX, 12); std::cout << "#################### New Game ###################";
	gotoXY(defX, 13); std::cout << "## White's player name: |                      ##";
	gotoXY(defX, 14); std::cout << "##----------------------|----------------------##";
	gotoXY(defX, 15); std::cout << "## Black's player name: |                      ##";
	gotoXY(defX, 16); std::cout << "#################################################";

	while (players[0].name.length() < 3) {
		gotoXY(defX + 26, 13); std::cout << " ";
		gotoXY(defX + 26, 13); std::cin >> players[0].name;
	}
	players[0].color = 1;

	while (players[1].name.length() < 3) {
		gotoXY(defX + 26, 15); std::cout << " ";
		gotoXY(defX + 26, 15); std::cin >> players[1].name;
	}
	players[1].color = 0;

	system("CLS");
	do {
		printBoard(BOARD);
		printGameElements();
		continueGame = gameProcess(players, score);
		games++;
	} while (continueGame);
}

//Game menu
void menu() {
	int defX = 22, bias = 2;
	int score[2] = { 12, 12 };

menu:
	int menuItem = 1;
	bool running = true;

	system("CLS");
	gotoXY(defX - 2, 14); std::cout << "->";
	while (running) {
		gotoXY(defX, 12); std::cout << "#### Main Menu ####\n";
		gotoXY(defX, 14); std::cout << "1. New Game\n";
		gotoXY(defX, 15); std::cout << "2. Exit\n";
		gotoXY(defX, 19); std::cout << "###################\n";

		switch (_getch()) {
		case 72: //Up key
			if (menuItem == 1) continue;
			gotoXY(defX - 2, 12 + bias--); std::cout << "  ";
			gotoXY(defX - 2, 12 + bias); std::cout << "->";
			menuItem--;
			continue;

		case 80: //Down key
			if (menuItem == 2) continue;
			gotoXY(defX - 2, 12 + bias++); std::cout << "  ";
			gotoXY(defX - 2, 12 + bias); std::cout << "->";
			menuItem++;
			continue;

		case 13: //Enter
			running = false;
		}
	}

	switch (menuItem) {
	case 1:
		system("CLS");
		newGame();
		break;

	case 2:
		exit(0);
	}
	goto menu;
}



int main() {
	//Set terminal size
	HWND console = GetConsoleWindow();
	RECT window;
	GetWindowRect(console, &window);
	MoveWindow(console, 100, 150, 560, 570, TRUE);

	menu();
	return 0;
}