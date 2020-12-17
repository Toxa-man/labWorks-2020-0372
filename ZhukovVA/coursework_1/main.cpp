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
std::string BOARD[10][8] = { {"  ", "-P", "  ", "-P", "  ", "-P", "  ", "-P"},
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

void printBoard(std::string board[10][8]);

void gotoXY(int x, int y)
{
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(terminal, cursorPosition);
}

void clear() {
	system("CLS");
}

//Print one row started with white color
void printFromWhiteLine(std::string values[8]) {
	int bDefBoardY = defBoardY;
	int bDefBoardX = defBoardX;
	for (int i = 0; i < 4; i++) {
		SetConsoleTextAttribute(color, bred | bgreen | bblue);
		gotoXY(defBoardX + 10 * i, defBoardY);
		std::cout << "     ";
		SetConsoleTextAttribute(color, bint);
		gotoXY(defBoardX + 5 + 10 * i, defBoardY);
		std::cout << "     ";
	}
	std::cout << std::endl;
	defBoardY++;

	for (int i = 0; i < 4; i++) {
		if (values[i * 2][0] == '-') {
			SetConsoleTextAttribute(color, bred | bgreen | bblue);
		}
		else {
			SetConsoleTextAttribute(color, bred | bgreen | bblue | fint | fred | fgreen | fblue);
		}
		gotoXY(defBoardX + 10 * i, defBoardY);
		std::cout << "  " << values[i * 2][1] << "  ";
		if (values[i * 2 + 1][0] == '-') {
			SetConsoleTextAttribute(color, bint);
		}
		else {
			SetConsoleTextAttribute(color, bint | fint | fred | fgreen | fblue);
		}
		gotoXY(defBoardX + 5 + 10 * i, defBoardY);
		std::cout << "  " << values[i * 2 + 1][1] << "  ";
	}
	std::cout << std::endl;
	defBoardY++;

	for (int i = 0; i < 4; i++) {
		SetConsoleTextAttribute(color, bred | bgreen | bblue);
		gotoXY(defBoardX + 10 * i, defBoardY);
		std::cout << "     ";
		SetConsoleTextAttribute(color, bint);
		gotoXY(defBoardX + 5 + 10 * i, defBoardY);
		std::cout << "     ";
	}
	std::cout << std::endl;
	defBoardY++;
}

//Print one row started with black color
void printFromBlackLine(std::string values[8]) {
	for (int i = 0; i < 4; i++) {
		SetConsoleTextAttribute(color, bint);
		gotoXY(defBoardX + 10 * i, defBoardY);
		std::cout << "     ";
		SetConsoleTextAttribute(color, bred | bgreen | bblue);
		gotoXY(defBoardX + 5 + 10 * i, defBoardY);
		std::cout << "     ";
	}
	std::cout << std::endl;
	defBoardY++;

	for (int i = 0; i < 4; i++) {
		if (values[i * 2][0] == '-') {
			SetConsoleTextAttribute(color, bint);
		}
		else {
			SetConsoleTextAttribute(color, bint | fint | fred | fgreen | fblue);
		}
		gotoXY(defBoardX + 10 * i, defBoardY);
		std::cout << "  " << values[i * 2][1] << "  ";
		if (values[i * 2 + 1][0] == '-') {
			SetConsoleTextAttribute(color, bred | bgreen | bblue);
		}
		else {
			SetConsoleTextAttribute(color, bred | bgreen | bblue | fint | fred | fgreen | fblue);
		}
		std::cout << "  " << values[i * 2 + 1][1] << "  ";
	}
	std::cout << std::endl;
	defBoardY++;

	for (int i = 0; i < 4; i++) {
		SetConsoleTextAttribute(color, bint);
		gotoXY(defBoardX + 10 * i, defBoardY);
		std::cout << "     ";
		SetConsoleTextAttribute(color, bred | bgreen | bblue);
		gotoXY(defBoardX + 5 + 10 * i, defBoardY);
		std::cout << "     ";
	}
	std::cout << std::endl;
	defBoardY++;

	SetConsoleTextAttribute(color, fblue | fgreen | fred); //Reset style
}

void updateGameField(std::vector<std::string> moves, int score[2]) {
	for (int i = 0; i < moves.size(); i++) {
		gotoXY(47, 8 + i); std::cout << i + 1 << ". " << moves[i];
	}

	gotoXY(50, 4);
	std::cout << "  ";
	gotoXY(50, 4);
	std::cout << 12 - score[1];
	gotoXY(58, 4);
	std::cout << "  ";
	gotoXY(58, 4);
	std::cout << 12 - score[0];
}

bool checkMove(std::string move, std::string board[10][8], bool side, int score[2]) {
	//Verify format
	if (not (isalpha(move[0]) && \
		isalpha(move[2]) && \
		isdigit(move[1]) && \
		isdigit(move[3])))
		return false;

	//Verify letters and digits
	if (not ((96 < move[0] and move[0] < 105) && (96 < move[2] and move[2] < 105) && \
		((0 < move[1] - 48 and move[1] - 48 < 9) && (0 < move[3] - 48 and move[3] - 48 < 9))))
		return false;

	//Verify validity of the checker
	if (board[7 - (move[1] - 49)][move[0] - 97] == "  " || \
		(side + (board[7 - (move[1] - 49)][move[0] - 97][0] == '+') == 1))
		return false;

	//Beat
	if (board[7 - ((move[1] + move[3] - 98)) / 2][(move[0] + move[2] - 194) / 2][0] == (side * 45 + not side * 43) && \
		std::abs(move[2] - move[0]) == 2 && std::abs(move[3] - move[1]) == 2) {

		board[7 - ((move[1] + move[3] - 98)) / 2][(move[0] + move[2] - 194) / 2] = "  ";
		score[0] -= side;
		score[1] -= not side;
		return true;
	}

	//Verify validity of the move
	if (not (board[7 - (move[3] - 49)][move[2] - 97] == "  " && \
		std::abs(move[2] - move[0]) == 1 && \
		std::abs(move[3] - move[1]) == 1))
		return false;

	return true;
}

void whoWon(int side, Player players[2]) {
	gotoXY(22, 15);
	if (side) {
		std::cout << players[0].name;
	}
	else {
		std::cout << players[1].name;
	}
	std::cout << " is victorious!\n";
}

void gameProcess(Player players[2]) {
	std::vector<std::string> moves;
	std::string move;
	bool side = 1; //0 - black, 1 - white
	int score[2] = { 12, 12 }; //Black, White
	std::string board[10][8];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = BOARD[i][j];
		}
	}

	updateGameField(moves, score); //Print starting score and moves

	while (true) {
		gotoXY(30, 30);
		std::cout << "            ";
		gotoXY(33, 30);
		std::cin >> move;

		if (move == "exit") {
			exit(0);
		}
		else if (move == "draw") {

		}
		else if (move == "rsgn") {

		}
		else {
			if (not checkMove(move, board, side, score)) {
				continue;
			}

			std::swap(board[7 - (move[1] - 49)][move[0] - 97], board[7 - (move[3] - 49)][move[2] - 97]);
			moves.push_back(move);
			side = not side;

			printBoard(board);
			updateGameField(moves, score);
		}

		if (score[0] * score[1] == 0) {
			whoWon(not side, players);
			_getch();
			break;
		}
	}
}

//Print the board
void printBoard(std::string board[10][8]) {
	clear();
	for (int i = 0; i < 4; i++) {
		printFromWhiteLine(board[i * 2]);
		printFromBlackLine(board[i * 2 + 1]);
	}
	defBoardX = _defBoardX;
	defBoardY = _defBoardY;

	for (int i = 0; i < 8; i++) {
		gotoXY(defBoardX - 3, defBoardY + 1 + 3 * i);
		std::cout << 8 - i;
		gotoXY(defBoardX + 2 + 5 * i, defBoardY + 25);
		std::cout << (char)('A' + i);
	}

	gotoXY(46, 1); std::cout << "***** Score *****";
	gotoXY(46, 2); std::cout << "* White | Black *";
	gotoXY(46, 3); std::cout << "*       |       *";
	gotoXY(46, 4); std::cout << "*       |       *";
	gotoXY(46, 5); std::cout << "*       |       *";
	gotoXY(46, 6); std::cout << "*****************";

	gotoXY(46, 7); std::cout << "***** Moves *****";
	for (int i = 8; i < 32; i++) {
		gotoXY(46, i); std::cout << "*       |       *";
	}
	gotoXY(46, 32); std::cout << "*****************";

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

void newGame() {
	Player Player1, Player2;
	Player players[2] = { Player1, Player2 };
	int games = 0;
	int defX = 8;

	clear();
	gotoXY(defX, 12); std::cout << "#################### New Game ###################";
	gotoXY(defX, 13); std::cout << "## White's player name: |                      ##";
	gotoXY(defX, 14); std::cout << "##----------------------|----------------------##";
	gotoXY(defX, 15); std::cout << "## Black's player name: |                      ##";
	gotoXY(defX, 16); std::cout << "##----------------------|----------------------##";
	gotoXY(defX, 17); std::cout << "## Games count:         |                      ##";
	gotoXY(defX, 18); std::cout << "#################################################";

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

	while (games < 1) {
		gotoXY(defX + 26, 17); std::cout << " ";
		gotoXY(defX + 26, 17); std::cin >> games;
	}

	printBoard(BOARD);
	gameProcess(players);
}

//Game menu
void menu() {
	int defX = 22, bias = 2;
	int score[2] = { 12, 12 };

menu:
	int menuItem = 1;
	bool running = true;

	clear();
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
	MoveWindow(console, 100, 150, 550, 570, TRUE);

	menu();
	return 0;
}