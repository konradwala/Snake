#include"klasa.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <memory>

int randomInt(int min, int max)
{
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };

	return d(e);
}

Snake::Snake()
{
	score = 0;
	movex = 0;
	movey = -1;
	speed = 60;
	eaten = true;
	end = false;

	for (int i = 0; i < 3; i++)
	{
		sf::RectangleShape segment(sf::Vector2f(30,30));
		segment.setPosition(210 , 300+ i * 30);
		segment.setFillColor(sf::Color::Black);
		body.push_back(segment);
	}

	apple.setSize(sf::Vector2f(30,30));
	apple.setFillColor(sf::Color::Red);
}

void Snake::draw(sf::RenderWindow& window)
{
	window.draw(apple);
	for (int i = 0; i < body.size(); i++)
		window.draw(body[i]);
	
}

void Snake::move()
{
	

	if (speed == 60)
	{
		for (int i = body.size()-1; i > 0; i--)
		{
			body[i].setPosition(body[i-1].getPosition().x, body[i-1].getPosition().y);
		}
		body[0].move(movex * 30, movey * 30);
		speed = 0;
	
	}
	speed++;

	if (body[0].getPosition().x == 450)
		body[0].move(-450, 0);
	if (body[0].getPosition().x == -30)
		body[0].move(450, 0);
	if (body[0].getPosition().y == 600)
		body[0].move(0, -600);
	if (body[0].getPosition().y == -30)
		body[0].move(0, 600);
}

void Snake::direction(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && movey == 0)
	{
		movey = -1;
		movex = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && movey == 0)
	{
		movey = 1;
		movex = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && movex == 0)
	{
		movex = -1;
		movey = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && movex == 0)
	{
		movex = 1;
		movey = 0;
	}

}

void Snake::create_apple()
{
	if (eaten == true)
	{
		apple.setPosition(randomInt(0, 14) * 30, randomInt(0, 19) * 30);
		eaten = false;
	}
}

void Snake::get_point()
{
	for (int i = 0; i < body.size(); i++)
	{
		if (body[i].getPosition() == apple.getPosition())
		{
			score++;
			eaten = true;
			sf::RectangleShape add(sf::Vector2f(30, 30));
			add.setFillColor(sf::Color::Black);
			add.setPosition(-60, -60);
			body.push_back(add);
			//std::cout << "Score: " << score << std::endl;
		}

	}
	
}

void Snake::colision()
{
	for (int i = 2; i < body.size(); i++)
	{
		if (body[0].getPosition() == body[i].getPosition())
		{
			end = true;
			//std::cout << "Game over!" << std::endl;
		}
			
	}
}


