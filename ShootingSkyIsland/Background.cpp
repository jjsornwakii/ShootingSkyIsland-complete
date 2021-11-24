#include "Background.h"

void Background::setBG() {
	backgroundText.loadFromFile("res/pic/bg2.png");
	bg.setSize(sf::Vector2f(1920,1080));
	bg.setTexture(&backgroundText);
	
	Skybackground.loadFromFile("res/pic/sky2.png");
	skybg.setSize(sf::Vector2f(1920, 1080));
	skybg.setTexture(&Skybackground);

	modelTexture.loadFromFile("res/pic/model.png");
	sf::Vector2u size = modelTexture.getSize();
	model.setSize(sf::Vector2f(size));
	model.setTexture(&modelTexture);
	model.setPosition(70,100);

	MainModel.loadFromFile("res/pic/bgmain.png");
	sf::Vector2u size1 = MainModel.getSize();

	mainModelbg.setSize(sf::Vector2f(size1));
	mainModelbg.setTexture(&MainModel);
	mainModelbg.setPosition(900, 379);

	logoTexture.loadFromFile("res/pic/logo.png");
	sf::Vector2u size2 = logoTexture.getSize();

	Logo.setSize(sf::Vector2f(size2));
	Logo.setTexture(&logoTexture);
	Logo.setPosition(15, 20);

	F.loadFromFile("res/font/MyFont.ttf");
	name.setFillColor(sf::Color::Magenta);
	name.setCharacterSize(40);
	name.setString("Siwakorn Suriya\n     64010850");
	name.setPosition(1600, 10);
	name.setFont(F);

	cloudTexture[0].loadFromFile("res/pic/Cloud1.png");
	cloudTexture[1].loadFromFile("res/pic/Cloud2.png");
	cloudTexture[2].loadFromFile("res/pic/Cloud3.png");
	cloudTexture[3].loadFromFile("res/pic/Cloud4.png");

	cloud[0].setPosition(2000,0);
	cloud[1].setPosition(2000,0);

	cloud[0].setSize(sf::Vector2f(500,250));
	cloud[1].setSize(sf::Vector2f(600, 200));
}

void Background::animation(sf::RenderWindow* window) {
	
	getTime = time.getElapsedTime().asMilliseconds();
	if (getTime >= 1500) {
		getTime = time.restart().asMilliseconds();
		dir = !dir;
	}

	if (int(getTime)%5==0) {
		if (dir == 0)
			model.move(0, -.1f*30);

		if (dir == 1)
			model.move(0, .1f*30);
	}
	window->draw(model);
}

void Background::randomCloud(int rand) {
	for (int i = 0; i < 2; i++) {
		if (cloud[i].getPosition().x>=1920) {
			//std::cout << "out";
			cloud[i].setPosition(-700,rand % 500);
			cloud[i].setTexture(&cloudTexture[rand % 4]);
		}
	}
}

void Background::cloudMove() {
	cloud[0].move( 0.1f*30 , 0);
	cloud[1].move(0.25f*30, 0);
}

void Background::drawCloud(sf::RenderWindow* window) {
	window->draw(cloud[0]);
	window->draw(cloud[1]);
}