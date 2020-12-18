#include "gamepack.h"
#include <Windows.h>
#include <conio.h>

int snakeX, snakeY;
int fruitX, fruitY;
int score;
int tailX[255];
int tailY[255];
bool isFilled[16][16];
bool gameOver;
enum eDir { STOP = 0, UP, LEFT, RIGHT, DOWN };
eDir dir;

void setup()
{
	do
	{
		score = 0;
		snakeX = rand() % 16;
		snakeY = rand() % 16;
		fruitX = rand() % 16;
		fruitY = rand() % 16;
		gameOver = false;
		dir = STOP;
	} while (snakeX == fruitX && snakeY == fruitY);
}

void snakeGame(sf::RenderWindow& window)
{
	window.setTitle("Snake");

	sf::CircleShape body(11);
	body.setFillColor(sf::Color::Green);
	body.setOutlineColor(sf::Color::Black);
	body.setOutlineThickness(1.3);
	sf::CircleShape head(12);
	head.setFillColor(sf::Color::Magenta);
	head.setOutlineColor(sf::Color::Black);
	head.setOutlineThickness(1.3);
	sf::RectangleShape fruit(sf::Vector2f(20, 20));
	fruit.setFillColor(sf::Color::Red);
	fruit.setOutlineColor(sf::Color::Black);
	fruit.setOutlineThickness(1.2);

	setup();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}


		//    inputs    /////////////////////////////////////////////////////////////////////////////////////////////////


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (dir != DOWN)
				dir = UP;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (dir != RIGHT)
				dir = LEFT;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (dir != UP)
				dir = DOWN;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (dir != LEFT)
				dir = RIGHT;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			setup();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			break;
		}


		//    logics    /////////////////////////////////////////////////////////////////////////////////////////////////

		if (snakeX == fruitX && snakeY == fruitY)
		{
			score++;
			fruitX = rand() % 16;
			fruitY = rand() % 16;
		}

		std::string scorestr = "Score is ";
		scorestr += std::to_string(score);
		sf::Font font;
		font.loadFromFile("fonts/arial.ttf");
		sf::Text scoretext((std::string)scorestr, font);
		scoretext.setCharacterSize(30);
		scoretext.setPosition(330, 50);
		scoretext.setFillColor(sf::Color::White);

		if (score > 0)
		{
			for (int i = score; i >= 0; i--)
			{
				tailX[i] = tailX[i - 1];
				tailY[i] = tailY[i - 1];
				isFilled[tailX[i]][tailY[i]] = true;
			}
			tailX[0] = snakeX;
			tailY[0] = snakeY;
		}

		switch (dir)
		{
		case UP:
			snakeY--;
			break;
		case LEFT:
			snakeX--;
			break;
		case RIGHT:
			snakeX++;
			break;
		case DOWN:
			snakeY++;
			break;
		}

		if (isFilled[fruitX][fruitY])
		{
			fruitX = rand() % 16;
			fruitY = rand() % 16;
		}

		if (isFilled[snakeX][snakeY])
			setup();

		if (snakeX <= -1 || snakeX >= 16 || snakeY <= -1 || snakeY >= 16)
			setup();

		//    draw    ///////////////////////////////////////////////////////////////////////////////////////////////////

		window.clear();

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				sf::RectangleShape block(sf::Vector2f(30, 30));
				block.setFillColor(sf::Color::White);
				block.setOutlineColor(sf::Color::Blue);
				block.setOutlineThickness(1.f);
				block.setPosition(160 + i * 30, 100 + j * 30);
				window.draw(block);
				isFilled[i][j] = false;
			}
		}

		fruit.setPosition(165 + fruitX * 30, 105 + fruitY * 30);
		window.draw(fruit);

		head.setPosition(162.5 + snakeX * 30, 102.5 + snakeY * 30);
		window.draw(head);

		for (int i = 0; i < score; i++)
		{
			body.setPosition(162.6 + tailX[i] * 30, 102.6 + tailY[i] * 30);
			window.draw(body);
		}

		window.draw(scoretext);

		window.display();
		Sleep(100);
	}
}