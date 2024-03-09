#include"displayfunction.h"
#include"textbox.h"
#include<iostream>
#include<SFML/Graphics.hpp>

void chooseRole(sf::RenderWindow& window)
{
    sf::Texture roletexture;
    roletexture.loadFromFile("App Design/[Design 1] Login 1.jpg");
    roletexture.setSmooth(true);
    sf::Sprite s_roletexture;
    s_roletexture.setTexture(roletexture);

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(s_roletexture);
        window.display();
    }
}