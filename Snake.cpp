#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <windows.h>
#include <WinUser.h>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <fstream>
#include"klasa.h"


int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	sf::RenderWindow  window(sf::VideoMode(450, 600, 32), "Snake");

	stop:
	Snake* snake = new Snake;

	while (true)
	{
		window.clear(sf::Color::White);

		sf::Event event;
		
		window.pollEvent(event);

		if (event.type == sf::Event::Closed||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
			break;
		}

		snake->draw(window);

		snake->move();

		snake->direction(event);

		snake->create_apple();

		snake->get_point();

		snake->colision();

		if (snake->end == true)
		{
			delete snake;
			goto stop;
		}

		window.display();
	}
	return 0;
}