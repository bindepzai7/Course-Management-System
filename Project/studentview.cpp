#include"displayfunction.h"
#include"textbox.h"
#include"LinkedList.h"
#include"Student.h"
#include"Staff.h"
#include<iostream>
#include<SFML/Graphics.hpp>

void studenthome(sf::RenderWindow &window) {
    sf::Texture Studenthometexture;
    Studenthometexture.loadFromFile("Design UI/[Student] Home.jpg");
    Studenthometexture.setSmooth(true);
    sf::Sprite s_Studenthometexture;
    s_Studenthometexture.setTexture(Studenthometexture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(s_Studenthometexture);
        window.display();
    }
}