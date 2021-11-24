#include "item.h"

void item::initItem() {

	medicTexture.loadFromFile("res/pic/madic.png");
	
	for (int i = 0; i < 5; i++) {
		
		med[i].medic.setSize(sf::Vector2f(50.f, 50.f));
		med[i].medic.setTexture(&medicTexture);
		sf::Vector2u medicSize = medicTexture.getSize();
		med[i].medic.setTextureRect(sf::IntRect(0, 0, medicSize.x, medicSize.y));
		med[i].itemState = false;
	}
	
	crystalTexture.loadFromFile("res/pic/crystal.png");
	
	for (int i = 0; i < 2; i++) {
		
		crys[i].crystal.setSize(sf::Vector2f(50.f, 50.f));
		crys[i].crystal.setTexture(&crystalTexture);
		sf::Vector2u crystalSize = crystalTexture.getSize();
		crys[i].crystal.setTextureRect(sf::IntRect(0, 0, crystalSize.x, crystalSize.y));
		crys[i].itemState = false;
	}

	bombTexture.loadFromFile("res/pic/bomb.png");
	BOOMTexture.loadFromFile("res/pic/BOOM.png");
	for (int i = 0; i < 3;i++) {
		bom[i].bomb.setSize(sf::Vector2f(90.f,50.f));
		bom[i].bomb.setTexture(&bombTexture);
		bombSize = bombTexture.getSize();
		bom[i].bomb.setTextureRect(sf::IntRect(0,0,bombSize.x/2,bombSize.y));

		bom[i].BOOM.setSize(sf::Vector2f(20.f,20.f));
		bom[i].BOOM.setTexture(&BOOMTexture);
		BOOMSize = BOOMTexture.getSize();
		bom[i].BOOM.setTextureRect(sf::IntRect(0, 0, BOOMSize.x / 4, BOOMSize.y));

		bom[i].itemState = false;
	}
	
	//
	TextureWeaponUp.loadFromFile("res/pic/weaponUp.png");
	TextureWSize = TextureWeaponUp.getSize();
	weaponUp.WeaponU.setTexture(&TextureWeaponUp);
	weaponUp.WeaponU.setSize(sf::Vector2f(50.f,50.f));
	weaponUp.WeaponU.setTextureRect(sf::IntRect(0,0, TextureWSize.x, TextureWSize.y));
	weaponUp.itemState = false;
	weaponUp.itemState = false;

}


void item::animationItem() {
	for (int i = 0; i < 4; i++) {
		if (bom[i].itemState == true && bom[i].planState == true) {
			bom[i].getTime = bom[i].bombCl.getElapsedTime().asSeconds();
			//std::cout << i << std::endl;
		
			if (bom[i].getTime >= 1) {
				//std::cout << "Hello" << std::endl;
				bom[i].getTime = bom[i].bombCl.restart().asSeconds();
				//bom[i].currentX =!bom[i].currentX;
				bom[i].bomb.setTextureRect(sf::IntRect(0, 0, bombSize.x / 2 * bom[i].currentX, bombSize.y));

			}
		}
	}
}


void item::randomItem(int n,sf::Vector2f Pos) {
	
	
		if (n >= 0 && n<=2 ) {
			for (int i = 0; i < 5; i++) {
				if (med[i].itemState == false) {
					med[i].itemState = true;
					med[i].medic.setPosition(Pos);
					break;
				}
			}
		}
		else if (n >= 3 && n <= 4) {
			for (int i = 0; i < 2 ; i++) {
				if (crys[i].itemState == false) {
					crys[i].itemState = true;
					crys[i].crystal.setPosition(Pos);
					break;
				}
			}
		}
		else if (n >= 5 && n <= 6) {
			for (int i = 0; i < 3; i++) {
				if (bom[i].itemState == false && bom[i].getItemState == false) {
					bom[i].itemState = true;
					bom[i].bomb.setPosition(Pos);
					break;
				}
			}
		}
		else if(n==-1){
			if (weaponUp.itemState == false) {
				weaponUp.itemState = true;
				weaponUp.WeaponU.setPosition(Pos);
				//std::cout << "JJJJJJ";
			}
		}
}

void item::planBomb(sf::Vector2f pos) {
	
	for (int i = 0; i < 3; i++) {
		if (bom[i].getItemState == true && bom[i].planState == false) {
			bom[i].itemState = true;
			bom[i].bomb.setPosition(pos);
			bom[i].planState = true;
			break;
		}
	}
}

void item::BOOMBAYAH(int i , sf::Vector2f pos) {
	
	float x = 200.f * (bom[i].currentXboom + 1);
	float y = 205.f * (bom[i].currentXboom + 1);

	bom[i].BOOM.setSize(sf::Vector2f( x , y ));
	bom[i].BOOM.setTextureRect(sf::IntRect(BOOMSize.x / 4 * (bom[i].currentXboom + 1), 0, BOOMSize.x / 4, BOOMSize.y));
	sf::Vector2f posDelta = { (x / 2) - bom[i].bomb.getSize().x/2 , ( y / 2 ) - bom[i].bomb.getSize().y / 2 };
	bom[i].BOOM.setPosition(pos- posDelta);

	bom[i].currentXboom++;

	if (bom[i].currentXboom == 4) {
		
		bom[i].bomb.setTextureRect(sf::IntRect(0, 0, bombSize.x / 2, bombSize.y));

		bom[i].currentXboom = 0;
		bom[i].itemState = false;
		bom[i].getItemState = false;
		bom[i].planState = false;
		bom[i].BombActivate = false;
	}
}

void item::BombAnimation() {
	for (int i = 0; i < 3; i++) {
		if (bom[i].planState == true) {
			if (bom[i].getTime >= 1) {
				bom[i].currentX = !bom[i].currentX;
				bom[i].bomb.setTextureRect(sf::IntRect(bombSize.x / 2 * bom[i].currentX, 0, bombSize.x / 2, bombSize.y));
				bom[i].getTime = bom[i].bombCl.restart().asSeconds();
			}
			bom[i].getTime = bom[i].bombCl.getElapsedTime().asSeconds();
		}
	}
	
}