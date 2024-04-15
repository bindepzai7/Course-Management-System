#include"displayfunction.h"
#include"textbox.h"
#include"LinkedList.h"
#include"Student.h"
#include"Staff.h"
#include"ReadCSVfile.h"
#include"User.h"
#include"Button.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include<Windows.h>

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
                if (y_coor > 550 && y_coor < 610)
                {
                    if (x_coor > 30 && x_coor < 140) {
                        role = 0;
                        loginWindow(window, role);//if enter student button move to login window with student role
                    }
                    else if (x_coor > 190 && x_coor < 300) {
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
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");
    TextBox username(20, sf::Color::Black, false);
    username.setfont(Palatino);
    username.setlimit(true, 24);
    TextBox password(24, sf::Color::Black, false);
    password.setfont(Palatino);
    password.setlimit(true, 24);
    OutputTextBox wrongaccount(16, sf::Color::Red, "Username or password incorrect!\nPlease try again!");
    wrongaccount.setfont(Palatino);
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
                if (x_coor > 50 && x_coor < 300)
                {
                    //choose username input box
                    if (y_coor > 380 && y_coor < 455) {
                        if (password.isselectedbox() == true)
                        {
                            password.setselected(false);
                            acc.isselectedpassword = false;
                        }
                        password.settextencode(true);
                        username.setselected(true);
                        acc.isselectedusername = true;
                    }
                    else if (y_coor > 500 && y_coor < 575) {
                        if (username.isselectedbox() == true) {
                            acc.isselectedusername = false;
                            username.setselected(false);
                        }
                        password.settextencode(true);
                        password.setselected(true);
                        acc.isselectedpassword = true;
                    }
                }
                if (x_coor > 45 && x_coor < 85 && y_coor>50 && y_coor < 90) {
                    Sleep(200);
                    chooseRole(window);
                }
                if (x_coor > 90 && x_coor < 270 && y_coor>640 && y_coor < 695) {
                        if (role == 0) {
                            LinkedList<User> userlist = readUserFromCSV("Data/studentuser.csv");
                            if (check_login(userlist, username.getText(), password.getText())) {
                                acc.iswrongaccount = false;
                                Student studentuser;
                                studenthome(window, studentuser);
                            }
                            else
                                acc.iswrongaccount = true;
                        }
                        else {
                            LinkedList<User> userlist = readUserFromCSV("Data/staffuser.csv");
                            if (check_login(userlist, username.getText(), password.getText())) {
                                acc.iswrongaccount = false;
                                LinkedList<Staff> Stafflist;
                                Staff userstaff;
                                //getDataStafffromlist(Stafflist, username.getText(), userstaff);
                                staffhome(window, userstaff);
                            }
                            else
                                acc.iswrongaccount = true;
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
        if (acc.iswrongaccount == true) {
            wrongaccount.setTextPosition(sf::Vector2f(45, 590));
            wrongaccount.drawTextbox(window);
        }
        username.setTextPosition(sf::Vector2f(60, 405));
        username.drawTextbox(window);
        password.setTextPosition(sf::Vector2f(60, 535));
        password.drawTextbox(window);
        window.display();
    }
}
