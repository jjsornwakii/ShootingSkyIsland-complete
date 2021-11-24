#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

class UI
{
public:

	/// Main Menu
	sf::Texture mainButton;
	
	sf::RectangleShape PlayButton;
	
	sf::RectangleShape ScoreButton;
	
	sf::RectangleShape ExitButton;
	
	sf::RectangleShape quitButton;

	sf::Vector2u buttonSize;



	/// PlayerStatus
	sf::RectangleShape HP;
	float HPplayer = 100;

	sf::RectangleShape SCORE[6];
	sf::Vector2u Ssize;
	sf::Texture Number;
	int s[6];
	int score;

	// clock
	sf::Text timer;
	sf::Text stack1;
	sf::Text stack2;
	
	sf::RectangleShape clockUI;
	sf::Texture clockTexture;
	sf::String T;

	sf::Font F;

	struct BACKUP {
		int score=0;

		std::string buName;
		std::string buScore;
		
		

		sf::Text N;
		sf::Text S;
	};

	BACKUP backup[500];
	//
	int LineNumber=0;


	sf::Text number;
	void HPinit();
	void SCOREinit();
	void CLOCKinit();

	void SCOREchange(int);
	void HPchange(float);

	void initButton();

	void sortScore(std::string str);
	void getbuScore();
	void showTopScore(sf::RenderWindow*);
	void updateTime(float, int, sf::RenderWindow*);
	
};

