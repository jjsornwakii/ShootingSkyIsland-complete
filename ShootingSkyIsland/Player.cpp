#include "Player.h"


void Player::initPlayer(float posX,float posY) {
	charactorPlayer.loadFromFile("res/pic/Player2.png");
	player.setSize(sf::Vector2f(110.f, 150.f));
	player.setTexture(&charactorPlayer);

	TextureSize = charactorPlayer.getSize();
	TextureSize.x /= 3;
	TextureSize.y /= 3;

	player.setTextureRect(sf::IntRect(TextureSize.x * currentX , TextureSize.y * currentY, TextureSize.x , TextureSize.y));
	player.setPosition(posX, posY);

    aimPlayer.setRadius(1.0f);
    aimPlayer.setFillColor(sf::Color::Red);
    
}

void Player::PlayerControl()
{
   
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        
        vec.x = 0;
        vec.y = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            if (player.getPosition().y > 0.0f) {
                moveY -= 1;
                vec.y += 1;
            }
            currentY = 0;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            if (player.getPosition().y < 780) {
                moveY += 1;
                vec.y -= 1;
            }
            currentY = 0;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            if (player.getPosition().x > 120.0f) {
                moveX -= 1;
                vec.x += 1;
            }
            currentY = 1;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            if (player.getPosition().x < 1680.0f) {
                moveX += 1;
                vec.x -= 1;
            }
            currentY = 2;

        }

        float V = ((abs(moveX) + abs(moveY))/(float)2) ;
        leng = sqrt(vec.x * vec.x + vec.y * vec.y);
        if (leng != 0) {
            vectorSpeed = abs(V / leng);
        }

        player.move(moveX * (1- vectorSpeed) * .2f * speed, moveY * (1 - vectorSpeed) * .2f * speed);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            //aimPlayer.setPosition(player.getPosition().x, player.getPosition().y);
            //std::cout << aimPlayer.getPosition().x << " " << aimPlayer.getPosition().y << std::endl;
        }

        moveX = 0;
        moveY = 0;
        leng = 0;
        vectorSpeed = 1;
        switchAnimationState = 1;

    }
       
}

void Player::PlayerAnimation(float deltaTime,sf::Sound* w) {

    if (switchAnimationState == 1) {
        w->setLoop(true);
        w->setVolume(100);
        getTime = playerClock.getElapsedTime().asSeconds();
        if (deltaTime < getTime) {
            w->play();
            getTime = playerClock.restart().asSeconds();

            if (currentX >= 2) {
                dirX = 1;
            }
            if (currentX <= 0) {
                dirX = 0;
            }
            if (dirX == 0) {
                currentX++;
            }
            else {
                currentX--;
            }
            
        }
        
    }

    player.setTextureRect(sf::IntRect(TextureSize.x * currentX, TextureSize.y * currentY, TextureSize.x, TextureSize.y));
    
    if (switchAnimationState == false) {
        w->setVolume(0);
        w->setLoop(false);
        player.setTextureRect(sf::IntRect(TextureSize.x * 1, TextureSize.y * 0, TextureSize.x, TextureSize.y));
        getTime = playerClock.restart().asSeconds();
    }
    switchAnimationState = false;
}




void Player::UpdateBullet(sf::Vector2f MousePos, int numBullet,float bulletSpeed,bool godMode, sf::Sound* m) {
        
    if (getTimeDelay >= 100.0f) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            for (int j = 0; j < numBullet; j++) {
                //std::cout << "Y" << std::endl;  
                    if (B[j].state == false) {
                        
                        
                        m->play();
                        getTimeDelay = delayShoot.restart().asMilliseconds();
                        B[j].currVelocity = B[j].aimDirNorm;
                        B[j].bulletShape.setPosition(playerCenter);
                        B[j].state = true;
                        break;
                    }
                    else {
                        
                    }
                    
            }

            if (sf::Mouse::getPosition().x > player.getPosition().x)
                currentY = 2;
            else
                currentY = 1;

            player.setTextureRect(sf::IntRect(TextureSize.x * currentX, TextureSize.y * currentY, TextureSize.x, TextureSize.y));

        }
            
    }getTimeDelay = delayShoot.getElapsedTime().asMilliseconds();

        for (int j = 0; j < numBullet; j++) {
            if (B[j].state == true)
                B[j].bulletShape.move(B[j].currVelocity.x * (B[j].maxSpeed* bulletSpeed), B[j].currVelocity.y * (B[j].maxSpeed* bulletSpeed));
        }


        //get bullet Direction
        for (int j = 0; j < numBullet; j++) {

            B[j].bulletShape.setRadius(10.0f);
            if(godMode == false)
                B[j].bulletShape.setFillColor(sf::Color::Red);
            
            else
                B[j].bulletShape.setFillColor(sf::Color::Yellow);

            playerCenter = sf::Vector2f(player.getPosition().x + player.getSize().x / 2, player.getPosition().y + player.getSize().y / 2);
            MousePositonWindow = MousePos;
            if (weaponSelect==0) {
                
                //aimPlayer.setPosition(player.getPosition().x + (player.getSize().x / 6.0f), player.getPosition().y + (player.getSize().y / 6.0f));

                //playerCenter = sf::Vector2f(aimPlayer.getPosition().x + aimPlayer.getRadius(), aimPlayer.getPosition().y + aimPlayer.getRadius());
                
                
                B[j].aimDir = MousePositonWindow - playerCenter;
                B[j].aimDirNorm = B[j].aimDir / sqrt(B[j].aimDir.x * B[j].aimDir.x + B[j].aimDir.y * B[j].aimDir.y);
            }


        }

        
        for (int j = 0; j < numBullet; j++) {

            // out display
            if ((B[j].bulletShape.getPosition().x <= 0 || B[j].bulletShape.getPosition().x >= 1920 ||
                B[j].bulletShape.getPosition().y <= 0 || B[j].bulletShape.getPosition().y >= 1080)
                && B[j].state == true) {
                B[j].currVelocity.x = 0;
                B[j].currVelocity.y = 0;
                B[j].state = false;
            }

            // bullet collision
            
        }
}



/*(B[j].bulletShape.getPosition().x >= enemyPosX && B[j].bulletShape.getPosition().x <= enemyPosX + sizeEnemyX &&
    B[j].bulletShape.getPosition().y >= enemyPosY && B[j].bulletShape.getPosition().y <= enemyPosY + sizeEnemyY) && B[j].state == true

    

void Player::HpPlayer(int k,int n) {
    for (int i=0; i <= n; i++) {

    }
}
*/

