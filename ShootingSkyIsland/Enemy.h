#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>
#include <conio.h>

class Enemy
{

public:
	
	sf::Texture EnenyCharactor;
	sf::Texture EnenyCharactor2;
	sf::Texture EnenyCharactor3;

	sf::Vector2u EnenyTextureSize;
	sf::Vector2u EnenyTextureSize2;
	sf::Vector2u EnenyTextureSize3;
	sf::Vector2f vec;

	int i = 0;
	int EnemyNumber=20;

	sf::Clock EnemyClock;
	float bounchTime = 0;
	struct enemy
	{
		sf::RectangleShape setEneny;
		sf::Vector2f position;
		sf::Vector2f vec;
		sf::Vector2u current;
		

		//staus
		int animationDir = 0;
		bool animationstate = 0;
		float speed = 1;
		float vectorSpeed;
		float leng;
		
		int SelectE;

		float hpEnemy = 250.0f;
		bool EnemyState =false;
		bool EnemyMoveState = false;
	};

	enemy E[5];

	void initEnimy(int i);
	void randomEnemy(int rand,int i, float, int);
	void setSpawn(float x,float y,int i);
	void EnemyMove(sf::Vector2f PlayerPos,int nEnemy,int i, int speedE);
	void EnemyAnimation(float deltaTime,int nEnemy);

};

