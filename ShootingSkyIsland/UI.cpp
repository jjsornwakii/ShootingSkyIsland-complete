#include "UI.h"

void UI::HPinit() {
	HPplayer = 100;
	HP.setFillColor(sf::Color{ 50,200,100,255 });
	HP.setSize(sf::Vector2f(500, 30));
	HP.setPosition(10, 10);
}

void UI::initButton() {

	mainButton.loadFromFile("res/pic/menuButton.png");
	buttonSize = mainButton.getSize();


	PlayButton.setTexture(&mainButton);
	PlayButton.setSize(sf::Vector2f(400,195));
	PlayButton.setTextureRect(sf::IntRect(0, 0, buttonSize.x , buttonSize.y/3));
	PlayButton.setPosition(200,400);


	ScoreButton.setTexture(&mainButton);
	ScoreButton.setSize(sf::Vector2f(400, 195));
	ScoreButton.setTextureRect(sf::IntRect(0, buttonSize.y/3, buttonSize.x, buttonSize.y / 3));	//(sf::IntRect(0, buttonSize.y, buttonSize.x, buttonSize.y/3))
	ScoreButton.setPosition(200, 600);

	ExitButton.setTexture(&mainButton);
	ExitButton.setSize(sf::Vector2f(400, 195));
	ExitButton.setTextureRect(sf::IntRect(0, buttonSize.y*2/3, buttonSize.x, buttonSize.y/3));
	ExitButton.setPosition(200,  800);

	quitButton.setTexture(&mainButton);
	quitButton.setSize(sf::Vector2f(200, 95));
	quitButton.setTextureRect(sf::IntRect(0, buttonSize.y * 2 / 3, buttonSize.x, buttonSize.y / 3));
	quitButton.setPosition(800, 450);

}

void UI::SCOREinit() {
	score = 0;
	Number.loadFromFile("res/pic/number.png");
	Ssize = Number.getSize();
	for (int i = 0; i < 6; i++) {
		SCORE[i].setPosition(1850 - (60 * i), 10);
		SCORE[i].setSize(sf::Vector2f(40, 60));
		SCORE[i].setTexture(&Number);
		SCORE[i].setTextureRect(sf::IntRect(0, 0, Ssize.x / 10, Ssize.y));
	}
}

void UI::CLOCKinit() {
	clockTexture.loadFromFile("res/pic/clock.png");
	sf::Vector2u size = clockTexture.getSize();

	clockUI.setTexture(&clockTexture);
	clockUI.setSize(sf::Vector2f(500,500));
	clockUI.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	clockUI.setPosition(1500, 100);

	
	F.loadFromFile("res/font/MyFont.ttf");

	stack1.setFont(F);
	stack2.setFont(F);
	timer.setFont(F);

	timer.setPosition(1700, 180);
	stack1.setPosition(1730, 470);
	stack2.setPosition(1800, 470);

	stack1.setCharacterSize(50);
	stack1.setFillColor(sf::Color::Black);
	stack1.setStyle(sf::Text::Bold);
	stack1.setString("10");

	stack2.setCharacterSize(50);
	stack2.setFillColor(sf::Color::Black);
	stack2.setStyle(sf::Text::Bold);
	stack2.setString("/ 20");

	timer.setCharacterSize(100);
	timer.setFillColor(sf::Color::Black);
	timer.setStyle(sf::Text::Bold);
}

void UI::updateTime(float t,int i, sf::RenderWindow* window) {
	
	

	int deltaTime = 0;
	deltaTime = 60 - t;
	auto str = std::to_string(deltaTime);
	T = str;
	timer.setString(T);
	
	str = std::to_string(i);
	T = str;
	stack1.setString(T);

	window->draw(stack1);
	window->draw(stack2);
	window->draw(timer);
}

void UI::SCOREchange(int sc) {
	int add=0;

	if (sc == 0)
		add = 25;

	else if (sc == 1)
		add = 125;

	else if (sc == 2)
		add = 75;

	score += add;
	


	for (int i = 0; i < 6; i++) {
		s[i] = (score / int(pow(10, i)) % 10);
		SCORE[i].setTextureRect(sf::IntRect(Ssize.x / 10 * s[i] , 0, Ssize.x / 10, Ssize.y));
		//std::cout << s[i] << std::endl;
	}
}

void UI::HPchange(float change) {

	HPplayer += change;

	if (HPplayer > 100)
		HPplayer = 100;

	if (HPplayer > 75) {
		HP.setFillColor(sf::Color{ 50,200,100,255 });
	}
	else if (HPplayer > 50) {
		HP.setFillColor(sf::Color::Green);
	}
	else if (HPplayer > 25) {
		HP.setFillColor(sf::Color{ 250,100,10,255 });
	}
	else if (HPplayer >= 0) {
		HP.setFillColor(sf::Color::Red);
	}

	HP.setSize(sf::Vector2f(HPplayer*500/100, 30));
}

void UI::getbuScore() {
	
	std::ifstream f;
	f.open("score.txt", std::ios::in);
	std::string str;
	int i=0;
	int j = 0;
	int s = 0;
	//std::cout << "----READ----" << std::endl;
	while (f >> str) {
		
		//std::cout << str << std::endl;
		if (i % 2 == 0) {
			backup[j].buName = str;
		}
		else {
			backup[j].score = 0;			/// BUG HERE
			backup[j].buScore = str;

			int len = backup[j].buScore.length();
			
			
			for (int k = 0; k < len; k++) {
				if (s == 0) {
					backup[j].score += backup[j].buScore[k] - 48;
					//std::cout << backup[j].buScore[k] ;
					s = 1;
				}
				else {
					backup[j].score *= 10;
					backup[j].score += backup[j].buScore[k] - 48;
					//std::cout << backup[j].buScore[k];
				}
			}
			
			
			
			
			j++;
		}
		s = 0;
		str = "\0";
		i++;
		//std::cout <<"i" << i << std::endl;
	}
	
	f.close();
	LineNumber = j;
	
	//std::cout<< LineNumber << std::endl;
}



void UI::sortScore(std::string str) {
	//std::cout << "------Before Sort-------" << std::endl;


	backup[LineNumber].score = score;
	backup[LineNumber].buName = str;

	for (int i=0; i <= LineNumber; i++) {
		
		for (int j=0; j < LineNumber; j++) {

			if (backup[j].buName != "\0" ) {
				
				if (backup[j].score < backup[j + 1].score) {
					
					int tempS = backup[j + 1].score;
					backup[j + 1].score = backup[j].score;
					backup[j].score = tempS;

					std::string tempStr;
					tempStr = backup[j + 1].buScore;
					backup[j + 1].buScore = backup[j].buScore;
					backup[j].buScore = tempStr;

					std::string tempN = backup[j + 1].buName;
					backup[j + 1].buName = backup[j].buName;
					backup[j].buName = tempN;

				}
				
			}
		}
	}



	//std::cout << "----------------" << std::endl;
	//std::cout << "sort" << std::endl;
	std::ofstream myScore;
	myScore.open("score.txt");
	if (myScore.is_open()) {
		for (int j = 0; j <= 10; j++) {
			if (backup[j].buName != "\0") {

				myScore << backup[j].buName << std::endl;
				myScore << backup[j].score << "\r";

				//std::cout << backup[j].buName << " ";
				//std::cout << backup[j].score << std::endl;
			}
			
		}
	}
	myScore.close();
}

void UI::showTopScore(sf::RenderWindow* window)
{
	sf::Font font;
	font.loadFromFile("res/font/MyFont.ttf");
	sf::Text Banner;
	Banner.setFont(font);
	Banner.setPosition(700, 0);
	Banner.setString("TOP 10 SCORE !");
	Banner.setCharacterSize(70);
	Banner.setFillColor(sf::Color::Yellow);
	Banner.setStyle(sf::Text::Bold);

	

	window->draw(Banner);

	for (int i = 0; i < 10; i++) {
		backup[i].N.setFont(font);
		backup[i].N.setCharacterSize(70);
		backup[i].N.setFillColor(sf::Color::Yellow);
		backup[i].N.setString(backup[i].buName);

		backup[i].S.setFont(font);
		backup[i].S.setCharacterSize(70);
		backup[i].S.setFillColor(sf::Color::Yellow);
		backup[i].S.setString(backup[i].buScore);

		number.setFont(font);
		number.setCharacterSize(70);
		number.setFillColor(sf::Color::Yellow);
		
	}

	for (int i = 0; i < 10; i++) {

		if (i != 9) {
			
			number.setString(char(i + '0' + 1));
		}
		else
		{
			number.setString("10");
		}
		number.setPosition(300, 200 + (i * 80));
		window->draw(number);

		backup[i].N.setPosition(500, 200+(i*80));
		window->draw(backup[i].N);

		backup[i].S.setPosition(1300, 200 + (i * 80));
		window->draw(backup[i].S);

	}


}
