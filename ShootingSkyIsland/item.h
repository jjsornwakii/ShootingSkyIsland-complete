#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class item
{

public:
	
	sf::Clock CrystalDelay;
	float CryTime=0;

	bool CrystalActivate;

	struct Medic {
		sf::RectangleShape medic;
		sf::Vector2u TextureSize1;
		bool itemState;
		
	};
	sf::Texture medicTexture;
	Medic med[5];



	struct Crystal {
		sf::RectangleShape crystal;
		sf::Vector2u TextureSize2;
		bool itemState;
		
	};
	sf::Texture crystalTexture;
	Crystal crys[2];



	struct Bomb {
		sf::RectangleShape bomb;
		sf::Vector2u TextureSize;

		bool itemState;
		bool getItemState;
		bool planState;
		bool BombActivate;
		
		sf::Clock BOOMTime;
		sf::RectangleShape BOOM;
		sf::Vector2u BOOMTextureSize;
		int currentXboom;
		float BOOMgetTime=0;


		sf::Clock bombCl;
		float getTime = 0;
		int currentX = 0;


		
	};
	int nBomb = 0;
	sf::Texture bombTexture;
	sf::Vector2u bombSize = bombTexture.getSize();

	sf::Texture BOOMTexture;
	sf::Vector2u BOOMSize = BOOMTexture.getSize();


	float delayBomb = 5;
	sf::Clock BombUseDelayTime;

	Bomb bom[3];
	
	struct WeaponUpgrade
	{
		sf::RectangleShape WeaponU;
		sf::Clock clock;
		float T = 0;
		bool activate;
		bool itemState;
	};

	WeaponUpgrade weaponUp;
	sf::Vector2u TextureWSize;
	sf::Texture TextureWeaponUp;
	int selectItem;
	
	



	void initItem();
	void randomItem(int n, sf::Vector2f Pos);
	void animationItem();
	
	///////////////////////////// use the bomb

	void planBomb( sf::Vector2f pos);
	void BombAnimation();
	void BOOMBAYAH(int , sf::Vector2f );
};

