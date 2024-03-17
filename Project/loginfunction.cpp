#include"displayfunction.h"
#include"textbox.h"
#include<iostream>
#include<SFML/Graphics.hpp>

void chooseRole(sf::RenderWindow& window)
{
    
    sf::Texture roletexture;
    roletexture.loadFromFile("Design UI/Login 1.jpg");
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
        if (event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                bool role;//0 is student, 1 is teacher
                int x_coor = event.mouseButton.x;
                int y_coor = event.mouseButton.y;
                if (y_coor > 625 && y_coor < 690)
                {
                    if (x_coor > 40 && x_coor < 165) {
                        role = 0;
                        loginWindow(window, role);//if enter student button move to login window with student role
                    }
                    else if (x_coor > 232 && x_coor < 347) {
                        role = 1;
                        loginWindow(window, role);
                    }
                }
            }
        }
        window.display();
    }
}

void loginWindow(sf::RenderWindow& window, bool role)
{
    account acc;
    sf::Texture loginscreen;
    loginscreen.loadFromFile("Design UI/Login 2.jpg");
    loginscreen.setSmooth(true);
    sf::Sprite s_loginscreen;
    s_loginscreen.setTexture(loginscreen);
    sf::Font rokkitfont;
    rokkitfont.loadFromFile("Font/Rokkitt-VariableFont.ttf");
    TextBox username(30, sf::Color::Black, false);
    username.setfont(rokkitfont);
    username.setlimit(true, 20);
    TextBox password(30, sf::Color::Black, false);
    password.setfont(rokkitfont);
    password.setlimit(true, 20);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                int x_coor = event.mouseButton.x;
                int y_coor = event.mouseButton.y;
                if (x_coor > 60 && x_coor < 360)
                {
                    //choose username input box
                    if (y_coor > 505 && y_coor < 590) {
                        if (password.isselectedbox() == true)
                        {
                            password.setselected(false);
                            acc.isselectedpassword = false;
                        }
                        password.settextencode(true);
                        username.setselected(true);
                        acc.isselectedusername = true;
                    }
                    else if (y_coor > 645 && y_coor < 730) {
                        if (username.isselectedbox() == true) {
                            acc.isselectedusername = false;
                            username.setselected(false);
                        }
                        password.settextencode(true);
                        password.setselected(true);
                        acc.isselectedpassword = true;
                    }
                }
            }
        }
        if (event.type == sf::Event::TextEntered){
            if (acc.isselectedusername == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    username.setselected(false);
                    acc.isselectedusername = false;
                }
                else
                {
                    username.typedText(event);
                }
            }
            else if (acc.isselectedpassword == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    password.setselected(false);
                    acc.isselectedpassword = false;
                    password.settextencode(true);
                }
                else
                {
                    password.typedText(event);
                }
            }
        }
        }
        window.clear();
        window.draw(s_loginscreen);
        username.setTextPosition(sf::Vector2f(60, 530));
        username.drawTextbox(window);
        password.setTextPosition(sf::Vector2f(60, 670));
        password.drawTextbox(window);
        window.display();
    }
}