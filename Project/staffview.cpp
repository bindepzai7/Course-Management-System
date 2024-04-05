#include"displayfunction.h"
#include"dropdownlist.h"
#include"LinkedList.h"
#include"Staff.h"
#include"Student.h"
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>


void staffhome(sf::RenderWindow &window) {
    sf::Texture Staffhometexture;
    Staffhometexture.loadFromFile("Design UI/[Staff] Home.jpg");
    Staffhometexture.setSmooth(true);
    sf::Sprite s_Staffhometexture;
    s_Staffhometexture.setTexture(Staffhometexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");
    //list of button manage
    LinkedList<std::string> textstaffhomebutton;
    textstaffhomebutton.push_tail("manage school year");
    textstaffhomebutton.push_tail("manage semester");
    textstaffhomebutton.push_tail("manage course");
    textstaffhomebutton.push_tail("about us");
    dropdownlist staffhomebuttonlist(sf::Color(168, 158,146), sf::Vector2f(300, 50), false,sf::Color(239,233,222),textstaffhomebutton,24,Palatino);
    //list of button for new

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (staffhomebuttonlist.isClickedKOrder(event, 1))
                staffmanageschoolyeardisplay(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 2))
                staffmanagesemesterdisplay(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 4))
                abousUs(window);
        }

        window.clear();
        window.draw(s_Staffhometexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, 30, 140, 0, 60, sf::Color(168, 158, 146),sf::Color(239, 233, 222));
        window.display();
    }
}
void staffmanageschoolyeardisplay(sf::RenderWindow& window) {
    sf::Texture Schoolyeartexture;
    Schoolyeartexture.loadFromFile("Design UI/[Staff] school year.jpg");
    Schoolyeartexture.setSmooth(true);
    sf::Sprite s_Schoolyeartexture;
    s_Schoolyeartexture.setTexture(Schoolyeartexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");
    LinkedList<std::string> textstaffhomebutton;
    textstaffhomebutton.push_tail("manage school year");
    textstaffhomebutton.push_tail("manage semester");
    textstaffhomebutton.push_tail("manage course");
    textstaffhomebutton.push_tail("about us");
    dropdownlist staffhomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color(239, 233, 222), textstaffhomebutton, 24, Palatino);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (staffhomebuttonlist.isClickedKOrder(event, 1))
                staffmanageschoolyeardisplay(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 2))
                staffmanagesemesterdisplay(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 4))
                abousUs(window);
        }

        window.clear();
        window.draw(s_Schoolyeartexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, 30, 140, 0, 60, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        window.display();
    }
}
void staffmanagesemesterdisplay(sf::RenderWindow& window) {
    sf::Texture Semestertexture;
    Semestertexture.loadFromFile("Design UI/[Staff] semester.jpg");
    Semestertexture.setSmooth(true);
    sf::Sprite s_Semestertexture;
    s_Semestertexture.setTexture(Semestertexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");
    LinkedList<std::string> textstaffhomebutton;
    textstaffhomebutton.push_tail("manage school year");
    textstaffhomebutton.push_tail("manage semester");
    textstaffhomebutton.push_tail("manage course");
    textstaffhomebutton.push_tail("about us");
    dropdownlist staffhomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color(239, 233, 222), textstaffhomebutton, 24, Palatino);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (staffhomebuttonlist.isClickedKOrder(event, 1))
                staffmanageschoolyeardisplay(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 2))
                staffmanagesemesterdisplay(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 4))
                abousUs(window);
        }

        window.clear();
        window.draw(s_Semestertexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, 30, 140, 0, 60, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        window.display();
    }
}
void staffmanagecourse(sf::RenderWindow& window) {
    sf::Texture Coursetexture;
    Coursetexture.loadFromFile("Design UI/[Staff] course.jpg");
    Coursetexture.setSmooth(true);
    sf::Sprite s_Coursetexture;
    s_Coursetexture.setTexture(Coursetexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");
    LinkedList<std::string> textstaffhomebutton;
    textstaffhomebutton.push_tail("manage school year");
    textstaffhomebutton.push_tail("manage semester");
    textstaffhomebutton.push_tail("manage course");
    textstaffhomebutton.push_tail("about us");
    dropdownlist staffhomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color(239, 233, 222), textstaffhomebutton, 24, Palatino);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (staffhomebuttonlist.isClickedKOrder(event, 1))
                staffmanageschoolyeardisplay(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 2))
                staffmanagesemesterdisplay(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window);
            if (staffhomebuttonlist.isClickedKOrder(event, 4))
                abousUs(window);
        }

        window.clear();
        window.draw(s_Coursetexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, 30, 140, 0, 60, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        window.display();
    }
}