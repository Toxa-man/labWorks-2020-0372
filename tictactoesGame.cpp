#include "gamepack.h"
#include <Windows.h>

void tictactoesGame(sf::RenderWindow& window)
{
	window.setTitle("Tic-tac-toes");
	Sleep(100);

	sf::Texture tCircle;
	tCircle.loadFromFile("images/circle.png");
	sf::Sprite circle(tCircle);
	circle.setScale(0.0625, 0.0625);

	sf::Texture tCross;
	tCross.loadFromFile("images/cross.png");
	sf::Sprite cross(tCross);
	cross.setScale(0.2, 0.204);

	sf::Font font;
	font.loadFromFile("fonts/arial.ttf");
	sf::Text cross_win("Cross have won!", font);
	cross_win.setOutlineThickness(1.3);
	cross_win.setCharacterSize(36);
	cross_win.setPosition(250, 300);
	sf::Text circle_win("Circle have won!", font);
	circle_win.setOutlineThickness(1.3);
	circle_win.setCharacterSize(36);
	circle_win.setPosition(250, 300);

	int isFilled[3][3] = { 0 };
	int countFilled = 0;
	bool turn_switch = 1;
	bool gameOver = false;

	while (window.isOpen())
	{
		int tileNum1 = -1, tileNum2 = -1;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			break;
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (isFilled[0][0] == 1 && isFilled[1][1] == 1 && isFilled[2][2] == 1 || 
					isFilled[0][0] == 2 && isFilled[1][1] == 2 && isFilled[2][2] == 2 || 
					isFilled[2][0] == 1 && isFilled[1][1] == 1 && isFilled[0][2] == 1 || 
					isFilled[2][0] == 2 && isFilled[1][1] == 2 && isFilled[0][2] == 2 || 
					isFilled[0][j] == 1 && isFilled[1][j] == 1 && isFilled[2][j] == 1 || 
					isFilled[0][j] == 2 && isFilled[1][j] == 2 && isFilled[2][j] == 2 || 
					isFilled[i][0] == 1 && isFilled[i][1] == 1 && isFilled[i][2] == 1 || 
					isFilled[i][0] == 2 && isFilled[i][1] == 2 && isFilled[i][2] == 2)
				{
					window.clear();
					if (countFilled % 2 == 0)
						window.draw(circle_win);
					else if (countFilled % 2 == 1)
						window.draw(cross_win);
					window.display();
					Sleep(300);
					gameOver = true;
				}
			}
		}

		if (gameOver)
			break;

		if (countFilled == 9)
		{
			sf::Text draw("Draw!", font);
			draw.setCharacterSize(36);
			draw.setPosition(350, 300);
			window.clear();
			window.draw(draw);
			window.display();
			Sleep(300);
			break;
		}

		window.clear();

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				sf::RectangleShape tile(sf::Vector2f(100, 100));
				tile.setFillColor(sf::Color::White);
				tile.setOutlineColor(sf::Color::Black);
				tile.setOutlineThickness(1.2);
				tile.setPosition(250 + i * 100, 150 + j * 100);
				if (sf::IntRect(540 + i * 100, 265 + j * 100, 100, 100).contains(sf::Mouse::getPosition()))
				{
					tile.setFillColor(sf::Color(111, 111, 111));
					tileNum1 = i;
					tileNum2 = j;
				}
				window.draw(tile);
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (tileNum1 >= 0 && tileNum1 < 3 && tileNum2 >= 0 && tileNum2 < 3)
			{
				switch (turn_switch)
				{
				case 0:
					if (isFilled[tileNum1][tileNum2] == 0)
					{
						isFilled[tileNum1][tileNum2] = 1;
						countFilled++;
						turn_switch = 1;
					}
					break;
				case 1:
					if (isFilled[tileNum1][tileNum2] == 0)
					{
						isFilled[tileNum1][tileNum2] = 2;
						countFilled++;
						turn_switch = 0;
					}
					break;
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (isFilled[i][j] == 1)
				{
					circle.setPosition(250 + i * 100, 150 + j * 100);
					window.draw(circle);
				}
				if (isFilled[i][j] == 2)
				{
					cross.setPosition(250 + i * 100, 150 + j * 100);
					window.draw(cross);
				}
			}
		}
		
		window.display();
	}
}