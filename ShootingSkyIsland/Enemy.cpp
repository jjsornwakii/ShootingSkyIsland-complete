#include "Enemy.h"
#include "Player.h"



void Enemy::initEnimy(int i) {
	EnenyCharactor.loadFromFile("res/pic/AmoungUs2.png");
	EnenyCharactor2.loadFromFile("res/pic/Slime.png");
	EnenyCharactor3.loadFromFile("res/pic/bat.png");

	E[i].setEneny.setSize(sf::Vector2f(110.f, 150.f));
	E[i].setEneny.setTexture(&EnenyCharactor);

	
	E[i].EnemyState = true;
	
	//
	E[i].setEneny.setTexture(&EnenyCharactor);
	E[i].setEneny.setSize(sf::Vector2f(110.f, 150.f));


	EnenyTextureSize = EnenyCharactor.getSize();
	EnenyTextureSize.x /= 3;
	EnenyTextureSize.y /= 3;

	E[i].speed = 1;
	E[i].hpEnemy = 250;
	E[i].SelectE = 0;
	E[i].setEneny.setTextureRect(sf::IntRect(EnenyTextureSize.x * 1, EnenyTextureSize.y * 0, EnenyTextureSize.x, EnenyTextureSize.y));
}

void Enemy::randomEnemy(int rand, int i, float xhp,int level)
{
	if (level <= 2) {
		rand = 0;
	}

	else if (level <= 3&& rand > 1 ) {
		rand = 1;
	}

	if (rand == 0) {
		E[i].setEneny.setTexture(&EnenyCharactor);
		E[i].setEneny.setSize(sf::Vector2f(110.f, 150.f));
		

		EnenyTextureSize = EnenyCharactor.getSize();
		EnenyTextureSize.x /= 3;
		EnenyTextureSize.y /= 3;

		E[i].speed = 1;
		E[i].hpEnemy = 250*xhp;
		E[i].SelectE = 0;
		E[i].setEneny.setTextureRect(sf::IntRect(EnenyTextureSize.x * 1, EnenyTextureSize.y * 0, EnenyTextureSize.x, EnenyTextureSize.y));

	}
	else if (rand == 1) {
		E[i].setEneny.setTexture(&EnenyCharactor2);
		E[i].setEneny.setSize(sf::Vector2f(150.f, 150.f));
		

		EnenyTextureSize2 = EnenyCharactor2.getSize();
		EnenyTextureSize2.x /= 3;
		EnenyTextureSize2.y /= 3;

		E[i].speed = 0.5;
		E[i].hpEnemy = 900*xhp;
		E[i].SelectE = 1;
		E[i].setEneny.setTextureRect(sf::IntRect(EnenyTextureSize2.x * 1, EnenyTextureSize2.y * 0, EnenyTextureSize2.x, EnenyTextureSize2.y));

	}
	else if (rand == 2) {
		E[i].setEneny.setTexture(&EnenyCharactor3);
		E[i].setEneny.setSize(sf::Vector2f(150.f, 150.f));


		EnenyTextureSize3 = EnenyCharactor2.getSize();
		EnenyTextureSize3.x /= 3;
		EnenyTextureSize3.y /= 3;

		E[i].speed = 5;
		E[i].hpEnemy = 100 * xhp;
		E[i].SelectE = 2;
		E[i].setEneny.setTextureRect(sf::IntRect(EnenyTextureSize3.x * 1, EnenyTextureSize3.y * 0, EnenyTextureSize3.x, EnenyTextureSize3.y));
	}
	E[i].EnemyState = true;
	E[i].EnemyMoveState = true;
}

void Enemy::setSpawn(float X, float Y,int i) {

	E[i].setEneny.setPosition(X,Y);

}

void Enemy::EnemyMove(sf::Vector2f PlayerPos,int nEnemy,int i,int speedE) {
	
		if (E[i].EnemyState != false && E[i].EnemyMoveState != false) {
			
			if (E[i].setEneny.getPosition().y < PlayerPos.y) {
				E[i].setEneny.move(0.0f,  (E[i].speed + speedE));
				E[i].animationDir = 0;
			}
			if (E[i].setEneny.getPosition().y > PlayerPos.y) {
				E[i].setEneny.move(0.0f, -1 * (E[i].speed+speedE));
				E[i].animationDir = 0;
			}

			if (E[i].setEneny.getPosition().x < PlayerPos.x) {
				E[i].setEneny.move((E[i].speed + speedE), 0.f);

				E[i].animationDir = 1;

			}
			if (E[i].setEneny.getPosition().x > PlayerPos.x) {
				E[i].setEneny.move(-1 * (E[i].speed + speedE), 0.f);

				E[i].animationDir = 2;
			}
			

		}
	
}

void Enemy::EnemyAnimation(float deltaTime,int nEnemy) {
	if (bounchTime > 0.25) {
		
		for (int i = 0; i < nEnemy; i++) {
			if (E[i].EnemyState != false) {
				if (E[i].animationDir == 1) {
					E[i].current.x++;
					E[i].current.y = 2;
					
				}

				if (E[i].animationDir == 2) {
					E[i].current.x++;
					E[i].current.y = 1;
				}

				if (E[i].current.x == 3) {
					E[i].current.x = 0;
				}

				if(E[i].SelectE == 0)
					E[i].setEneny.setTextureRect(sf::IntRect(EnenyTextureSize.x * E[i].current.x, float(EnenyTextureSize.y) * float(E[i].current.y), EnenyTextureSize.x, EnenyTextureSize.y));
				
				else if(E[i].SelectE == 1)
					E[i].setEneny.setTextureRect(sf::IntRect(EnenyTextureSize2.x * E[i].current.x, EnenyTextureSize2.y * E[i].current.y, EnenyTextureSize2.x, EnenyTextureSize2.y));

				else if(E[i].SelectE == 2)
					E[i].setEneny.setTextureRect(sf::IntRect(EnenyTextureSize3.x * E[i].current.x, EnenyTextureSize3.y * E[i].current.y, EnenyTextureSize3.x, EnenyTextureSize3.y));
			}
		}
		bounchTime = EnemyClock.restart().asSeconds();
	}
	bounchTime = EnemyClock.getElapsedTime().asSeconds();
}

