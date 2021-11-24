#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Background
{
public:
	sf::Texture backgroundText;
	sf::RectangleShape bg;

	sf::Texture Skybackground;
	sf::RectangleShape skybg;

	sf::Texture modelTexture;
	sf::RectangleShape model;
	int dir = 0;

	sf::Clock time;
	float getTime;

	sf::Texture MainModel;
	sf::RectangleShape mainModelbg;

	sf::Texture logoTexture;
	sf::RectangleShape Logo;

	sf::Text name;
	sf::Font F;

	sf::Texture cloudTexture[4];
	sf::RectangleShape cloud[2];


	void setBG();

	void randomCloud(int);
	void cloudMove();
	void drawCloud(sf::RenderWindow*);
	void animation(sf::RenderWindow* );
};

