#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>
#include <conio.h>
#include "Enemy.h"
#include <SFML\Audio.hpp>

class Player:public Enemy
{
public:
	sf::RectangleShape player;
	sf::Texture charactorPlayer;
	sf::Vector2u TextureSize;
	sf::Clock playerClock,delayShoot;
	sf::Vector2f vec;

	// player status
	int weaponSelect = 0;
	float speed = 30;
	float vectorSpeed;
	float leng;
	float moveX, moveY;
	float hp = 3;
	float damage = 50;

	int currentX=0,currentY=0;
	bool switchAnimationState;
	int dirX=0;
	float getTime=0;
	float getTimeDelay = 0;

	sf::CircleShape aimPlayer;

	//bullet

	sf::Vector2f MousePositonWindow;
	sf::Vector2f playerCenter;
	int nBullet=0;


	struct Heart {
		sf::CircleShape bulletShape;
		bool state = false;
	};
	Heart HP[5];


	struct bullet {
		sf::CircleShape bulletShape;
		sf::Vector2f aimDir;
		sf::Vector2f aimDirNorm;
		sf::Vector2f currVelocity;
		float maxSpeed = 0.25;
		bool state=false;
	};
	bullet B[45];

public :
	void initPlayer(float posX,float posY);
	void HpPlayer();
	void PlayerControl();
	void PlayerAnimation(float deltaTime, sf::Sound*);
	void UpdateBullet(sf::Vector2f MousePos, int numBullet, float bulletSpeed, bool,sf::Sound*);

	

};
