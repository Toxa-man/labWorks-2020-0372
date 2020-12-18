#include <SFML/Graphics.hpp>
#include <ctime>
#include "gamepack.h"

int main()
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game pack");
	window.setFramerateLimit(60);

	sf::Font font;
	font.loadFromFile("fonts/arial.ttf");
	sf::Text snake("Snake", font);
	sf::Text tetris("Tetris", font);
	sf::Text tictactoes("Tic-Tac-Toe", font);

	snake.setCharacterSize(30);
	snake.setStyle(sf::Text::Bold);
	snake.setPosition(sf::Vector2f(300, 150));
	tetris.setCharacterSize(30);
	tetris.setStyle(sf::Text::Bold);
	tetris.setPosition(sf::Vector2f(300, 250));
	tictactoes.setCharacterSize(30);
	tictactoes.setStyle(sf::Text::Bold);
	tictactoes.setPosition(sf::Vector2f(300, 350));

	int menuNum;

	while (window.isOpen())
	{
		window.setTitle("Game pack");
		menuNum = 0;

		snake.setFillColor(sf::Color::White);
		tetris.setFillColor(sf::Color::White);
		tictactoes.setFillColor(sf::Color::White);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::IntRect(300, 150, 100, 35).contains(sf::Mouse::getPosition(window))) { snake.setFillColor(sf::Color::Magenta); menuNum = 1; }
		if (sf::IntRect(300, 250, 80, 35).contains(sf::Mouse::getPosition(window))) { tetris.setFillColor(sf::Color::Magenta); menuNum = 2; }
		if (sf::IntRect(300, 350, 190, 35).contains(sf::Mouse::getPosition(window))) { tictactoes.setFillColor(sf::Color::Magenta); menuNum = 3; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			switch (menuNum)
			{
			case 0:
				break;
			case 1:
				snakeGame(window);
				break;
			case 2:
				tetrisGame(window);
				break;
			case 3:
				tictactoesGame(window);
				break;
			}
		}

		window.clear();
		window.draw(snake);
		window.draw(tetris);
		window.draw(tictactoes);
		window.display();
	}
}