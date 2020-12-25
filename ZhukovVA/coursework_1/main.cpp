#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include "nlohmann/json.h"

//Colors
#define fblue	0x0001
#define fgreen	0x0002
#define fred	0x0004
#define fint	0x0008
#define bblue	0x0010
#define bgreen	0x0020
#define bred	0x0040
#define bint	0x0080

using std::cout;
using std::cin;
using std::string;
using std::vector;
using json = nlohmann::json;

//Starting board
string BOARD[8][8] = { {"  ", "-P", "  ", "-P", "  ", "-P", "  ", "-P"},
						{"-P", "  ", "-P", "  ", "-P", "  ", "-P", "  "},
						{"  ", "-P", "  ", "-P", "  ", "-P", "  ", "-P"},
						{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
						{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
						{"+P", "  ", "+P", "  ", "+P", "  ", "+P", "  "},
						{"  ", "+P", "  ", "+P", "  ", "+P", "  ", "+P"},
						{"+P", "  ", "+P", "  ", "+P", "  ", "+P", "  "} };

//For terminal color and cursor manipulation
HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE); //Get the console output handle
COORD cursorPosition; //For cursor coords storing

void gotoXY(int x, int y) {
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(terminal, cursorPosition);
}

//Delete the board
void clearBoard() {
	for (int i = 0; i < 45; i++) {
		for (int j = 1; j < 27; j++) {
			gotoXY(i, j); cout << " ";
		}
	}
}

//Print cell of the board
void printCell(int x, int y, char value, bool checkerColor, bool cellColor) {
	if (not cellColor) {
		SetConsoleTextAttribute(terminal, bred | bgreen | bblue);
		for (int i = 0; i < 3; i++) {
			gotoXY(x, y + i); cout << "     ";
		}
	}
	else {
		SetConsoleTextAttribute(terminal, bint | checkerColor * (fint | fred | fgreen | fblue));
		gotoXY(x, y); cout << "     ";
		gotoXY(x, y + 1); cout << "  " << value << "  ";
		gotoXY(x, y + 2); cout << "     ";
	}
	SetConsoleTextAttribute(terminal, fblue | fgreen | fred);
}

//Print the board
void printBoard(string board[8][8]) {
	clearBoard();
	//Print the board
	for (int i = 0; i < 64; i++) {
		printCell((i%8 + 1)*5, 1 + 3*(i/8), board[i/8][i%8][1], not bool((board[i/8][i%8][0] - 43)/2), ((i/8%2) * not bool(i%2)) + (((i + 8)/8%2) * bool(i%2)));
	}

	for (int i = 0; i < 8; i++) {
		gotoXY(2, 2 + 3 * i);
		cout << 8 - i;
		gotoXY(7 + 5 * i, 26);
		cout << (char)('A' + i);
	}
}

//Print other game elements
void printGameElements() {
	gotoXY(46, 1); cout << "****** Score ******";
	gotoXY(46, 2); cout << "* White  | Black  *";
	gotoXY(46, 3); cout << "*        |        *";
	gotoXY(46, 4); cout << "*        |        *";
	gotoXY(46, 5); cout << "*        |        *";
	gotoXY(46, 6); cout << "*******************";

	gotoXY(46, 7); cout << "****** Moves ******";
	for (int i = 8; i < 32; i++) {
		gotoXY(46, i); cout << "*                 *";
	}
	gotoXY(46, 32); cout << "*******************";

	gotoXY(5, 28); cout << "***** Commands *****";
	gotoXY(5, 29); cout << "* exit - To exit   *";
	gotoXY(5, 30); cout << "* draw - To draw   *";
	gotoXY(5, 31); cout << "* rsgn - To resign *";
	gotoXY(5, 32); cout << "********************";

	gotoXY(27, 28); cout << "*** Make move ***";
	gotoXY(27, 29); cout << "*               *";
	gotoXY(27, 30); cout << "*               *";
	gotoXY(27, 31); cout << "*               *";
	gotoXY(27, 32); cout << "*****************";
}

void updateMovesField(vector<string> moves) {
	if ((moves.size() - 1) % 24 == 0) {
		gotoXY(46, 7); cout << "****** Moves ******";
		for (int i = 8; i < 32; i++) {
			gotoXY(46, i); cout << "*                 *";
		}
		gotoXY(46, 32); cout << "*******************";
	}

	for (int i = 24*((int)moves.size()/24); i < (int)moves.size() % 24 + 24*(moves.size() / 24); i++) {
		gotoXY(47, 8 + i%24); cout << i + 1 << ". " << moves[i];
	}
}

void updateScoreField(float score[2]) {
	gotoXY(50, 4); cout << "  ";
	gotoXY(50, 4); cout << score[1];
	gotoXY(59, 4); cout << "  ";
	gotoXY(59, 4); cout << score[0];
}

bool checkMove(vector<int> move, string board[8][8], bool side, int checkers[2], bool &beated) {
	//Verify format and limits
	for (int element: move) {
		if (element > 7 || element < 0)
			return false;
	}

	//Verify if the selected cell contains appropriate checker
	if (board[ move[0] ][ move[1] ] == "  " || \
		board[ move[2] ][ move[3] ] != "  " || \
		(side + (board[ move[0] ][ move[1] ][0] == '+') == 1))
		return false;

	//Make king
	if (((move[2] == 0 && side) || (move[2] == 7 && not side)) && \
		board[ move[0] ][ move[1] ][1] != 'D')
		board[ move[0] ][ move[1] ][1] = 'D';

	//Make move
	if (board[ move[0] ][ move[1] ][1] == 'D') {
		//King moves
		vector<vector<int>> cells;
		int rivalCounter = 0;
		int colChange = (move[1] < move[3]) - (move[1] > move[3]),
			rowChange = -(move[0] < move[2]) + (move[0] > move[2]);

		//Check whether the move is correct
		if (not (abs(move[3] - move[1]) == abs(move[2] - move[0])))
			return false;

		//Find all possible moves for the king to beat
		for (int i = move[0] - rowChange, j = move[1] + colChange; j != (move[3] - (move[1] > move[3])); i -= rowChange, j += colChange) {
			if (board[i][j][0] == (not side * 45 + side * 43))
				return false; //If found own checker, stop (the move is prohibited)

			if (board[i][j][0] == (side * 45 + not side * 43) && ++rivalCounter > 1 )
				return false; //If found more than 1 rival checker, stop

			cells.push_back({ i, j });
		}

		for (auto element: cells) {
			if (board[element[0]][element[1]][0] == (side * 45 + not side * 43)) {
				board[element[0]][element[1]] = "  "; //Remove rival checker
				checkers[not side]--; //Decrease rival checkers count
				beated = true; //For multiple beats
			}
		}

	} else {
		//Standard checker beat: 
		//1. Whether the move is correct
		//3. Whether you beat the right color
		if (abs(move[3] - move[1]) == 2 && abs(move[2] - move[0]) == 2 && \
			board[ (move[0] + move[2]) / 2 ][ (move[1] + move[3]) / 2 ][0] == (side * 45 + not side * 43)) {

			board[(move[0] + move[2]) / 2][ (move[1] + move[3]) / 2] = "  "; //Remove rival checker
			checkers[not side]--; //Decrease rival checkers count
			beated = true; //For series of beats
			return true;
		}

		//Verify validity of the checker move
		if (not (abs(move[3] - move[1]) == 1 && abs(move[2] - move[0]) == 1))
			return false;
	}

	return true;
}

void findNextBeat(string move, vector<string>& moves, string board[8][8], bool side, int checkers[2]) {
	vector<int> prevPos = { move[0] - 97, 56 - move[1] }; //For multiple king beats
	vector<int> currPos = { move[2] - 97, 56 - move[3] };

	if (board[56 - move[3]][move[2] - 97][1] == 'P') {
		//Multiple beats for standard checkers
		while (true) {
			vector<vector<int>> availMoves;

			for (int i = -1; i <= 1; i += 2) {
				for (int j = -1; j <= 1; j += 2) {
					if (currPos[1] + 2 * i < 8 && currPos[1] + 2 * i >= 0 && currPos[0] + 2 * j >= 0 && currPos[0] + 2 * j < 8) {
						if (board[currPos[1] + i][currPos[0] + j][0] == (side * 45 + not side * 43) && \
							board[currPos[1] + 2 * i][currPos[0] + 2 * j] == "  ") {
							//Next checker coords + rival checker coords to empty its cell
							availMoves.push_back({ currPos[1] + 2 * i, currPos[0] + 2 * j, currPos[1] + i, currPos[0] + j });
						}
					}
				}
			}

			//Print interactive menu if found available moves
			if (availMoves.size() > 0) {
				bool running = true;
				int menuItem = 0, bias = 0;

				printBoard(board);
				gotoXY(33, 30);
				cout << "    ";
				gotoXY(33, 29);
				cout << "->";

				while (running) {
					for (int i = 0; i < (int)availMoves.size(); i++) {
						gotoXY(35, 29 + i); cout << char(availMoves[i][1] + 97) << 8 - availMoves[i][0];
					}

					switch (_getch()) {
					case 72: //Up key
						if (menuItem == 0) continue;
						gotoXY(33, 29 + bias--); cout << "  ";
						gotoXY(33, 29 + bias); cout << "->";
						menuItem--;
						continue;

					case 80: //Down key
						if (menuItem == availMoves.size() - 1) continue;
						gotoXY(33, 29 + bias++); cout << "  ";
						gotoXY(33, 29 + bias); cout << "->";
						menuItem++;
						continue;

					case 13: //Enter
						running = false;
					}
				}

				swap(board[ currPos[1] ][ currPos[0] ], board[ availMoves[menuItem][0] ][ availMoves[menuItem][1] ]);
				currPos = { availMoves[menuItem][1], availMoves[menuItem][0] }; //Reset current position
				board[ availMoves[menuItem][2] ][ availMoves[menuItem][3] ] = "  "; //Remove rival checker
				moves.back() = moves.back() + ':' + char(currPos[0] + 97) + char(56 - currPos[1]);

				if (((currPos[1] == 0 && side) || (currPos[1] == 7 && not side)) && \
					board[currPos[1]][currPos[0]][1] != 'D')
					board[currPos[1]][currPos[0]][1] = 'D';

				checkers[not side]--; //Decrease rival checkers count

				for (int i = 29; i < 32; i++) { //Empty the menu
					gotoXY(33, i); cout << "      ";
				}
			}
			else {
				break;
			}
		}
	} else {
		//Multiple beats for king checkers
		while (true) {
			vector<vector<int>> availMoves;
			vector<int> rival;
			string nextMove;

			//Up-Right
			if (not (prevPos[1] < currPos[1] && prevPos[0] > currPos[0])) {
				for (int i = currPos[0] + 1, j = currPos[1] - 1; i < 8 && j > -1; i++, j--) {
					if (board[j][i][0] == (not side * 45 + side * 43)) break; //If find own checker, stop
					if (board[j][i][0] == (side * 45 + not side * 43)) { //Find the closest rival checker
						if (board[j - 1][i + 1] == "  ") { //Check next cell after the cell with rival checker to move to
							rival = { j, i };
							for (++i, --j; i < 8 && j > -1; i++, j--) { //Go further and gather available cells to move (beat)
								if (board[j][i] == "  ") {
									availMoves.push_back({ j, i, rival[0], rival[1] });
								}
								else {
									break; //If found not empty cell then stop
								}
							}
						}
						break; //If this suppossedly empty cell is not so then stop
					}
				}
			}

			//Down-Right
			if (not (prevPos[1] > currPos[1] && prevPos[0] > currPos[0])) {
				for (int i = currPos[0] + 1, j = currPos[1] + 1; i < 8 && j < 8; i++, j++) {
					if (board[j][i][0] == (not side * 45 + side * 43)) break;
					if (board[j][i][0] == (side * 45 + not side * 43)) {
						if (board[j + 1][i + 1] == "  ") {
							rival = { j, i };
							for (++i, ++j; i < 8 && j < 8; i++, j++) {
								if (board[j][i] == "  ") {
									availMoves.push_back({ j, i, rival[0], rival[1] });
								}
								else {
									break;
								}
							}
						}
						break;
					}
				}
			}

			//Down-Left
			if (not (prevPos[1] > currPos[1] && prevPos[0] < currPos[0])) {
				for (int i = currPos[0] - 1, j = currPos[1] + 1; i > -1 && j < 8; i--, j++) {
					if (board[j][i][0] == (not side * 45 + side * 43)) break;
					if (board[j][i][0] == (side * 45 + not side * 43)) {
						if (board[j + 1][i - 1] == "  ") {
							rival = { j, i };
							for (--i, ++j; i > -1 && j < 8; i--, j++) {
								if (board[j][i] == "  ") {
									availMoves.push_back({ j, i, rival[0], rival[1] });
								}
								else {
									break;
								}
							}
						}
						break;
					}
				}
			}

			//Up-Left
			if (not (prevPos[1] < currPos[1] && prevPos[0] < currPos[0])) {
				for (int i = currPos[0] - 1, j = currPos[1] - 1; i > -1 && j > -1; i--, j--) {
					if (board[j][i][0] == (not side * 45 + side * 43)) break;
					if (board[j][i][0] == (side * 45 + not side * 43)) {
						if (board[j - 1][i - 1] == "  ") {
							rival = { j, i };
							for (--i, --j; i > -1 && j > -1; i--, j--) {
								if (board[j][i] == "  ") {
									availMoves.push_back({ j, i, rival[0], rival[1] });
								}
								else {
									break;
								}
							}
						}
						break;
					}
				}
			}
			
			if (availMoves.size() > 0) {
				printBoard(board);
				gotoXY(33, 30);
				cout << "    ";
				gotoXY(33, 30);
				cin >> nextMove;

				for (auto element : availMoves) {
					if (nextMove[0] - 97 == element[1] && 56 - nextMove[1] == element[0]) {
						swap(board[ currPos[1] ][ currPos[0] ], board[ element[0] ][ element[1] ]);
						board[ element[2] ][ element[3] ] = "  "; //Remove rival checker
						prevPos = { currPos[0], currPos[1] }; //Reset previous position
						currPos = { element[1], element[0] }; //Reset current position
						moves.back() = moves.back() + ':' + char(element[1] + 97) + char(56 - element[0]);
						checkers[not side]--; //Decrease rival checkers count
					}
				}
			} else {
				break;
			}
		}
	}
}

bool gameProcess(string players[2], float score[2], int &draws) {
	vector<string> moves;
	vector<int> move;
	int checkers[2] = { 12, 12 }; //Black, White
	bool side = 1, //0 - black, 1 - white
		 draw = false,
		 beated = false;
	string action;
	string board[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = BOARD[i][j];
		}
	}

	//Print starting score and moves
	updateScoreField(score);

	while (true) {
		gotoXY(33, 30);
		cout << "       ";
		gotoXY(33, 30);
		cin >> action;

		if (action.length() != 4) continue;

		//Commands handler
		if (action == "exit") {
			return false;
		}
		else if (action == "draw") {
			gotoXY(29, 30);
			cout << "Draw? (y/n)   ";
			gotoXY(41, 30);
			switch (_getch()) {
			case 110:
				continue;
			case 121:
				score[0] += 0.5;
				score[1] += 0.5;
				draw = true;
				draws++;
			}
		}
		else if (action == "rsgn") {
			checkers[side] = 0;
		} else {
			move = { 56 - action[1], action[0] - 97, 56 - action[3], action[2] - 97};
			//Check move availability and correctness
			if (not checkMove(move, board, side, checkers, beated)) {
				continue;
			}

			swap(board[ move[0] ][ move[1] ], board[ move[2] ][ move[3] ]);
			moves.push_back(action.substr(0, 2) + ':' + action.substr(2, 2));

			//Multiple beats
			if (beated) {
				findNextBeat(action, moves, board, side, checkers);
				beated = false;
			}
			side = not side; //Change the side

			printBoard(board);
			updateMovesField(moves);
		}

		//If one of the side have zero checker, change score and print the winner
		if (checkers[0] * checkers[1] == 0) {
			clearBoard();
			gotoXY(9, 10); cout << "------- Game over -------";
			gotoXY(21 - players[not side].length()/2, 12);
			cout << players[not side];
			gotoXY(14, 13); cout << "is victorious!";

			score[not side]++;
		}

		if (checkers[0] * checkers[1] == 0 or draw) {
			//Draw handler
			if (draw) {
				clearBoard();
				gotoXY(20, 15);
				cout << "DRAW!";
			}
			updateScoreField(score);

			gotoXY(5, 17);
			cout << "Press <Enter> to play another game";
			gotoXY(5, 18);
			cout << "        Or <ESC> to exit";

			switch (_getch()) {
			case 13:
				return true;
			case 27:
				return false;
			}
		}
	}
}

void saveGameToFile(string players[2], float score[2], int draws, int games) {
	json stats;
	std::ifstream statsFileIn("stats.txt");
	if (not statsFileIn.is_open()) {
		std::ofstream o("stats.txt");
	} else {
		statsFileIn >> stats;
	}

	for (int i = 0; i < 2; i++) {
		if (stats["players"][players[i]] == nullptr) {
			stats["players"][players[i]]["all_wins"] = 0;
			stats["players"][players[i]]["all_loses"] = 0;
			stats["players"][players[i]]["games_count"] = 0;
		}

		stats["players"][players[i]]["all_wins"] = int(stats["players"][players[i]]["all_wins"] + score[i] - 0.5 * draws);
		stats["players"][players[i]]["all_loses"] = int(stats["players"][players[i]]["all_loses"] + score[1 - i] - 0.5 * draws);
		stats["players"][players[i]]["games_count"] = stats["players"][players[i]]["games_count"] + games;
	}

	std::ofstream statsFileOut("stats.txt");
	statsFileOut << std::setw(4) << stats;
	statsFileOut.close();
}

void newGame() {
	string Player1, Player2;
	string players[2] = { Player1, Player2 }; //Black, White
	float score[2] = { 0, 0 }; //Black, White
	int games = 0, draws = 0, defX = 8;
	bool continueGame;

	gotoXY(9, 12); cout << "------------------- New Game -----------------";
	gotoXY(9, 13); cout << "| White's player name: |                     |";
	gotoXY(9, 14); cout << "|----------------------|---------------------|";
	gotoXY(9, 15); cout << "| Black's player name: |                     |";
	gotoXY(9, 16); cout << "----------------------------------------------";

	while (players[1].length() < 1) {
		gotoXY(34, 13); cout << "                   ";
		gotoXY(34, 13); cin >> players[1];
	}

	while (players[0].length() < 1) {
		gotoXY(34, 15); cout << "                   ";
		gotoXY(34, 15); cin >> players[0];
		if (players[0] == players[1]) {
			players[0] = "";
		}
	}

	system("CLS");
	do {
		printBoard(BOARD);
		printGameElements();
		continueGame = gameProcess(players, score, draws);
		games++;
	} while (continueGame);

	saveGameToFile(players, score, draws, games);
}

void showStats() {
	json stats;
	int i = 0;
	std::ifstream statsFileIn("stats.txt");
	if (not statsFileIn.is_open()) {
		gotoXY(15, 10); cout << "--- Not found any played game ---";
	}
	else {
		statsFileIn >> stats;
		gotoXY(24, 10); cout << "--- Statistics ---";
		gotoXY(7, 12); cout << "----------------------------------------------------";
		gotoXY(7, 13); cout << "|    Player    |   Games   |   Wins   |   Loses    |";
		gotoXY(7, 14); cout << "----------------------------------------------------";

		for (auto player : stats["players"].items()) {
			gotoXY(7, 15 + 2 * i); cout << "|              |           |          |            |";
			gotoXY(7, 16 + 2 * i); cout << "----------------------------------------------------";
			gotoXY(15 - player.key().length()/2, 15 + 2*i); cout << player.key();;
			gotoXY(28, 15 + 2 * i); cout << player.value()["games_count"];
			gotoXY(39, 15 + 2 * i); cout << player.value()["all_wins"];
			gotoXY(51, 15 + 2 * i++); cout << player.value()["all_loses"];
		}
	}
	_getch();
}

//Game menu
void menu() {
	int menuItem, bias;
	int score[2] = { 12, 12 };
	bool running;

menu:
	menuItem = 1;
	bias = 2;
	running = true;

	system("CLS");
	gotoXY(20, 14); cout << "->";
	while (running) {
		gotoXY(18, 12); cout << "------ Main Menu ------";
		gotoXY(22, 14); cout << "1. New Game";
		gotoXY(22, 15); cout << "2. Show statistics";
		gotoXY(22, 16); cout << "3. Exit";

		switch (_getch()) {
		case 72: //Up key
			if (menuItem == 1) continue;
			gotoXY(20, 12 + bias--); cout << "  ";
			gotoXY(20, 12 + bias); cout << "->";
			menuItem--;
			continue;

		case 80: //Down key
			if (menuItem == 3) continue;
			gotoXY(20, 12 + bias++); cout << "  ";
			gotoXY(20, 12 + bias); cout << "->";
			menuItem++;
			continue;

		case 13: //Enter
			running = false;
		}
	}

	system("CLS");
	switch (menuItem) {
	case 1:
		newGame();
		break;
	case 2:
		showStats();
		break;
	case 3:
		exit(0);
	}
	goto menu;
}

int main() {
	//Set terminal size
	HWND console = GetConsoleWindow(); //Get window handle used by the console
	MoveWindow(console, 100, 150, 560, 570, TRUE); //HWND, X, Y, Width, Height, repaint window

	menu();
	return 0;
}