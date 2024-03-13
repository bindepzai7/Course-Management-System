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
        if (event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                bool role;//0 is student, 1 is teacher
                int x_coor = event.mouseButton.x;
                int y_coor = event.mouseButton.y;
                if (y_coor > 865 && y_coor < 935)
                {
                    if (x_coor > 517 && x_coor < 757) {
                        role = 0;
                        loginWindow(window, role);//if enter student button move to login window with student role
                    }
                    else if (x_coor > 970 && y_coor < 1210) {
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
    loginscreen.loadFromFile("App Design/[Design 1] Login 2.jpg");
    loginscreen.setSmooth(true);
    sf::Sprite s_loginscreen;
    s_loginscreen.setTexture(loginscreen);
    sf::Font rokkitfont;
    rokkitfont.loadFromFile("Font/Rokkitt-VariableFont.ttf");
    TextBox username(30, sf::Color::White, false);
    username.setfont(rokkitfont);
    TextBox password(30, sf::Color::White, false);
    password.setfont(rokkitfont);
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
                if (x_coor > 490 && x_coor < 1230)
                {
                    //choose username input box
                    if (y_coor > 545 && y_coor < 625) {
                        if (password.isselectedbox() == true)
                        {
                            password.setselected(false);
                            acc.isselectedpassword = false;
                        }
                        username.setselected(true);
                        acc.isselectedusername = true;
                    }
                    else if (y_coor > 675 && y_coor < 755) {
                        if (username.isselectedbox() == true) {

                            acc.isselectedusername = false;
                            username.setselected(false);
                        }
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
        username.setTextPosition(sf::Vector2f(500, 570));
        username.drawTextbox(window);
        password.setTextPosition(sf::Vector2f(500, 700));
        password.drawTextbox(window);
        window.display();
    }
}