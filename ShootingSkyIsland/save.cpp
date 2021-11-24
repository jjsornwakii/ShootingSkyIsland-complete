
/*
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>


using namespace std;
using namespace sf;







int man()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Shooting Sky Island!", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(150.0f, 150.0f));

    sf::Texture charactorPlayer;
    charactorPlayer.loadFromFile("res/pic/C2.png");
    player.setTexture(&charactorPlayer);

    sf::RectangleShape gun(sf::Vector2f(80.0f, 50.0f));
    sf::Texture Gun;
    Gun.loadFromFile("res/pic/gun.png");
    gun.setTexture(&Gun);

    sf::RectangleShape bullet(sf::Vector2f(80.0f, 50.0f));
    sf::Texture Bullet;
    Bullet.loadFromFile("res/pic/bull.png");
    bullet.setTexture(&Bullet);


    struct BULLET {
        float X;
        float Xp;
        float Y;
        float Yp;
        float M;
    };
    BULLET b;



    sf::Clock clock, clockTest;
    float deltaTime = 0.0f;
    int currentX = 0, currentY = 0;
    int posX = 0;
    int switchAnimationState = 0;
    int BulletState = 0, bulletPos;
    float testtime = 0;

    sf::Vector2u Tsize = charactorPlayer.getSize();
    Tsize.x /= 3;
    Tsize.y /= 3;

    Vector2u Gunsize = Gun.getSize();
    Vector2u Bulletsize = Bullet.getSize();



    player.setTextureRect(sf::IntRect(Tsize.x * currentX, Tsize.y * currentY, Tsize.x, Tsize.y));
    gun.setTextureRect(sf::IntRect(0, 0, Gunsize.x, Gunsize.y));
    bullet.setTextureRect(IntRect(0, 0, Bulletsize.x, Bulletsize.y));

    player.setPosition(200, 300);
    gun.setPosition(250, 380);

    while (window.isOpen()) {
        window.clear();
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

        //sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
        //printf("%d\n", pixelPos);

        sf::Event EVNT;
        while (window.pollEvent(EVNT)) {


            switch (EVNT.type) {
            case sf::Event::Closed: window.close(); break;

            case sf::Event::Resized: std::cout << EVNT.size.width << "     " << EVNT.size.height << std::endl;
            }
        }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            if (player.getPosition().y > 0.0f) {
                player.move(0.0f, -0.1f);
                gun.move(0.0f, -0.1f);
            }
            currentY = 0;
            switchAnimationState = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            if (player.getPosition().y < 860) {
                player.move(0.0f, 0.1f);
                gun.move(0.0f, 0.1f);
            }
            currentY = 0;
            switchAnimationState = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            if (player.getPosition().x > 0.0f) {
                player.move(-0.1f, 0.0f);
                gun.move(-0.1f, 0.0f);
            }
            currentY = 1;
            switchAnimationState = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            if (player.getPosition().x < 1780.0f) {
                player.move(0.1f, 0.0f);
                gun.move(0.1f, 0.0f);
            }
            currentY = 2;
            switchAnimationState = 1;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && BulletState != 1) {
            BulletState = 1;

            b.M = (player.getPosition().y - Mouse::getPosition().y) / (player.getPosition().x - Mouse::getPosition().x);
            b.X = player.getPosition().x;
            b.Xp = player.getPosition().x;
            b.Y = player.getPosition().y;
            b.Yp = player.getPosition().y;

            if (Mouse::getPosition().x > player.getPosition().x + (Tsize.x)) {
                bullet.setPosition(player.getPosition().x + 30.0f, player.getPosition().y + 50.0f);
                bulletPos = 1;
            }

            else {
                bullet.setPosition(player.getPosition().x + 30.0f, player.getPosition().y + 50.0f);
                bulletPos = 2;
            }
        }

        if (BulletState == 1) {
            if (testtime >= 0.001f) {
                testtime = clockTest.restart().asSeconds();

                bullet.setPosition(b.X, b.Y);
                b.X = b.X - 1.0f;
                b.Y = (b.M) * (b.X - b.Xp) + b.Yp;


            }
            testtime = clockTest.getElapsedTime().asSeconds();
            window.draw(bullet);

            if (b.X < 0 || b.X > 1700 || b.Y < 0 || b.Y > 1080) {
                BulletState = 0;
            }
        }


        if (switchAnimationState == 1) {
            if (deltaTime >= 0.25) {
                deltaTime = clock.restart().asSeconds();
                //player.setTextureRect(sf::IntRect(Tsize.x * currentX, 0, Tsize.x , Tsize.y));
                player.setTextureRect(sf::IntRect(Tsize.x * currentX, Tsize.y * currentY, Tsize.x, Tsize.y));
                //printf("%f", deltaTime);

                if (currentX >= 2) {
                    posX = 1;
                }
                if (currentX <= 0) {
                    posX = 0;
                }
                if (posX == 0) {
                    currentX++;
                }
                else {
                    currentX--;
                }

            }
            deltaTime = clock.getElapsedTime().asSeconds();
        }


        if (switchAnimationState == 0) {
            currentY = 0;
            player.setTextureRect(sf::IntRect(Tsize.x * currentX, Tsize.y * currentY, Tsize.x, Tsize.y));
        }
        switchAnimationState = 0;



        window.draw(player);
        window.draw(gun);
        window.display();



    }
    return 0;
}
*/