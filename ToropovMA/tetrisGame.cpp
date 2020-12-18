#include "gamepack.h"
#include <Windows.h>

int total_score, lines_destroyed;
int check;

int tetraminoX[4] = { 0 }, tetraminoY[4] = { 0 };
int map[10][22];

sf::Color colorPicker(short figure_type)
{
	switch (figure_type)
	{
	case 0:
		return (sf::Color::Cyan);
		break;
	case 1:
		return (sf::Color::Green);
		break;
	case 2:
		return (sf::Color::Red);
		break;
	case 3:
		return (sf::Color::Magenta);
		break;
	case 4:
		return (sf::Color::Yellow);
		break;
	case 5:
		return (sf::Color(252, 123, 3));
		break;
	case 6:
		return (sf::Color::Blue);
		break;
	}
	return sf::Color::White;
}

bool horizontalCheck()
{
	for (int i = 0; i < 4; i++)
	{
		if (tetraminoX[i] < 0 || tetraminoX[i] > 9)
			return 0;
		else if (map[tetraminoX[i]][tetraminoY[i]] != 7)
			return 0;
	}
	return 1;
}

bool verticalCheck()
{
	for (int i = 0; i < 4; i++)
	{
		if (tetraminoY[i] >= 22)
			return 0;
		else if (map[tetraminoX[i]][tetraminoY[i]] != 7)//>= 0 && map[tetraminoX[i]][tetraminoY[i]] < 7)
			return 0;
	}
	return 1;
}

void tetrisCheck()
{
	check = 0;
	for (int i = 21; i > 0; i--)
	{
		if (map[0][i] != 7 && map[3][i] != 7 && map[6][i] != 7 && map[8][i] != 7 && 
			map[1][i] != 7 && map[4][i] != 7 && map[7][i] != 7 && map[9][i] != 7 && 
			map[2][i] != 7 && map[5][i] != 7)
		{
			check++;
			lines_destroyed++;
			for (int j = 0; j < 10; j++)
			{
				for (int k = i; k > 0; k--)
				{
					map[j][k] = map[j][k - 1];
				}
			}
			i--;
		}
	}
	switch (check)
	{
	case 0:
		break;
	case 1:
		total_score += 100;
		break;
	case 2:
		total_score += 300;
		break;
	case 3:
		total_score += 700;
		break;
	case 4:
		total_score += 1200;
		break;
	}
}

void gameOver(sf::RenderWindow& window, sf::Font font)
{
	window.clear();
	sf::Text game_over("Game Over", font);
	game_over.setCharacterSize(40);
	game_over.setFillColor(sf::Color::White);
	game_over.setPosition(300, 220);
	window.draw(game_over);
	window.display();
	Sleep(666);
}

void tetrisGame(sf::RenderWindow& window)
{
	sf::RectangleShape tetramino(sf::Vector2f(24, 24));
	tetramino.setFillColor(sf::Color::Red);
	tetramino.setOutlineColor(sf::Color::Black);
	tetramino.setOutlineThickness(1.2);

	sf::Font font;
	font.loadFromFile("fonts/arial.ttf");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			map[i][j] = 7;
		}
	}

	total_score = 0;
	lines_destroyed = 0;

	short prevX[4] = { 0 };
	short prevY[4] = { 0 };
	int figure_type = 7;

	const short tilesize = 25;
	unsigned short ntime = 300;

	int figures[7][4] =
	{
		1,3,5,7, // I
		0,2,3,5, // S
		1,3,2,4, // Z
		1,3,2,5, // T
		0,1,3,5, // L
		1,3,5,4, // J
		0,1,2,3, // O
	};

	bool new_figure = true;
	bool rotate = false;

	sf::Clock timerX;
	sf::Clock timerY;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
				if (figure_type != 6)
					if (event.key.code == sf::Keyboard::W)
						rotate = true;
		}

		std::string score_str = "Score: ";
		score_str += std::to_string(total_score);
		std::string lines_str = "Lines destroyed: ";
		lines_str += std::to_string(lines_destroyed);

		sf::Text score_text(score_str, font);
		score_text.setPosition(15, 25);
		score_text.setCharacterSize(22);
		sf::Text lines_text(lines_str, font);
		lines_text.setPosition(15, 75);
		lines_text.setCharacterSize(22);

		short dx = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			break;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			dx--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			dx++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { ntime = 50; } else { ntime = 300; }

		if (new_figure)
		{
			figure_type = rand() % 7;
			tetramino.setFillColor(colorPicker(figure_type));
			new_figure = false;
			for (int i = 0; i < 4; i++)
			{
				tetraminoX[i] = 4 + figures[figure_type][i] % 2;
				tetraminoY[i] = figures[figure_type][i] / 2;
			}
		}

		if (timerX.getElapsedTime().asMilliseconds() >= 50)
			for (int i = 0; i < 4; i++)
			{
				prevX[i] = tetraminoX[i];
				prevY[i] = tetraminoY[i];
				tetraminoX[i] += dx;
				timerX.restart();
			}

		if (!horizontalCheck())
		{
			for (int i = 0; i < 4; i++)
				tetraminoX[i] = prevX[i];
		}

		if (rotate)
		{
			int pointX = tetraminoX[1];
			int pointY = tetraminoY[1];
			for (int i = 0; i < 4; i++)
			{
				prevX[i] = tetraminoX[i];
				prevY[i] = tetraminoY[i];
				int x = tetraminoY[i] - pointY;
				int y = tetraminoX[i] - pointX;
				tetraminoX[i] = pointX - x;
				tetraminoY[i] = pointY + y;
			}
			rotate = false;
		}

		if (!horizontalCheck())
		{
			for (int i = 0; i < 4; i++)
			{
				tetraminoX[i] = prevX[i];
				tetraminoY[i] = prevY[i];
			}
		}

		if (timerY.getElapsedTime().asMilliseconds() >= ntime)
		{
			for (int i = 0; i < 4; i++)
			{
				prevY[i] = tetraminoY[i];
				tetraminoY[i]++;
				timerY.restart();
			}
		}

		if (!verticalCheck())
		{
			for (int i = 0; i < 4; i++)
				tetraminoY[i] = prevY[i];
			new_figure = true;
			for (int i = 0; i < 4; i++)
				map[tetraminoX[i]][tetraminoY[i]] = figure_type;
		}

		if (map[4][0] != 7 || map[5][0] != 7)
		{
			gameOver(window, font);
			tetrisGame(window);
			break;
		}

		tetrisCheck();

		window.clear();

		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 22; y++)
			{
				sf::RectangleShape tile(sf::Vector2f(25, 25));
				tile.setFillColor(sf::Color::White);
				tile.setPosition(275 + x * tilesize, 50 + y * tilesize);
				window.draw(tile);
				if (map[x][y] >= 0 && map[x][y] < 7)
				{
					sf::RectangleShape tetraminops(sf::Vector2f(24, 24));
					tetraminops.setFillColor(colorPicker(map[x][y]));
					tetraminops.setOutlineColor(sf::Color::Black);
					tetraminops.setOutlineThickness(1.2);
					tetraminops.setPosition(275 + x * tilesize, 50 + y * tilesize);
					window.draw(tetraminops);
				}
			}
		}

		window.draw(score_text);
		window.draw(lines_text);

		for (int i = 0; i < 4; i++)
		{
			tetramino.setPosition(275 + tetraminoX[i] * tilesize, 50 + tetraminoY[i] * tilesize);
			window.draw(tetramino);
		}

		window.display();
	}
}