#ifndef klasa_h
#define klasa_h
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
#include <time.h>

class Snake
{
public:
	
	int scoreInt;
	int theBestScore;
	int speed;
	int movex;
	int movey;
	bool eaten;
	bool end;
	sf::RectangleShape apple;
	std::vector<sf::RectangleShape> body;
	Snake();
	void draw(sf::RenderWindow& window);
	void move();
	void direction(sf::Event event);
	void create_apple();
	void get_point();
	void colision();
	void writing(int startX, int startY, int scale, std::string inscription);
	std::vector<sf::RectangleShape> signs;
	void creatingUpMargin();
	void bestScore();
};

#endif
