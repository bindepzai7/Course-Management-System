#include"displayfunction.h"
#include"dropdownlist.h"
#include"Textbox.h"
#include"LinkedList.h"
#include"Staff.h"
#include"Student.h"
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>


void staffhome(sf::RenderWindow &window, LinkedList<User>& userlist,Staff &userstaff) {

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
    staffhomebuttonlist.setpostionlistbutton(30, 140, 0, 60);
    //list of button for new

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (staffhomebuttonlist.isClickedKOrder(event, 1)){
                window.close();
                staffmanageschoolyeardisplay(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffmanagesemesterdisplay(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4))
                abousUs(window);
        }

        window.clear();
        window.draw(s_Staffhometexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146),sf::Color(239, 233, 222));
        window.display();
    }
}
void staffmanageschoolyeardisplay(Staff &userstaff) {
    sf::RenderWindow window(sf::VideoMode(1470, 950), "Login window", sf::Style::Close);
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
    staffhomebuttonlist.setpostionlistbutton(30, 140, 0, 60);

    userstaff.readAllSchoolyear();
    LinkedList<std::string> schoolyearstext = userstaff.getschoolyearstext();
    dropdownlist schoolyears(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, schoolyearstext, 30, Palatino);
    schoolyears.setpostionlistbuttonwithlimit(475, 320, 0, 65,310,830,500);


    TextBox addschoolyearbox(24, sf::Color::Black, false);
    addschoolyearbox.setfont(Palatino);
   // std::cout << schoolyearstext.sizeoflist();

    //init newposy of list school years button
    float newposy = 320;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            //menu button
            if (staffhomebuttonlist.isClickedKOrder(event, 1)) {
                window.close();
                staffmanageschoolyeardisplay(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffmanagesemesterdisplay(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4))
                abousUs(window);
            //list of year button
            for (int i = 1; i <= schoolyearstext.sizeoflist(); i++) {
                if (schoolyears.isClickedKOrder(event, i))
                std::cout << schoolyears.getKoderButtonText(i);
            }


            if (addschoolyearbox.isClick(event, 940, 505, 1350, 545)) {
                addschoolyearbox.setselected(true);
            }
            if (event.type == sf::Event::TextEntered) {
                if (addschoolyearbox.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                    {
                        addschoolyearbox.setselected(false);

                    }
                    else
                    {
                        addschoolyearbox.typedText(event);
                    }
                }
            }


            //wheel scrool
            if (event.type == event.MouseWheelScrolled) {
                newposy = newposy + event.mouseWheelScroll.delta * 10.0f;
                schoolyears.setpostionlistbuttonwithlimit(475, newposy, 0, 65, 310,830, 500);
            }

        }
        //add school button is Press
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                int x_coor = event.mouseButton.x;
                int y_coor = event.mouseButton.y;
                if (x_coor > 1150 && x_coor < 1350 && y_coor>575 && y_coor < 615) {
                    std::cout << "c";
                    std::string newschoolyeartext = addschoolyearbox.getText();
                    int newstartyear = std::stoi(newschoolyeartext.substr(0, 4));
                    int newsendyear = std::stoi(newschoolyeartext.substr(5, 8));
                    userstaff.addNewSchoolyear(SchoolYear(newstartyear, newsendyear));
                    window.close();
                    LinkedList<std::string> schoolyearstext2 = userstaff.getschoolyearstext();
                    userstaff.writeSchoolyear2file(schoolyearstext2);
                    staffmanageschoolyeardisplay(userstaff);
                }
        }
        window.clear();
        window.draw(s_Schoolyeartexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        schoolyears.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        addschoolyearbox.setTextPosition(sf::Vector2f(950, 515));
        addschoolyearbox.drawTextbox(window);
        window.display();
    }
}
void staffmanagesemesterdisplay( Staff &userstaff) {
    sf::RenderWindow window(sf::VideoMode(1470, 950), "Login window", sf::Style::Close);
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
    staffhomebuttonlist.setpostionlistbutton(30, 140, 0, 60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (staffhomebuttonlist.isClickedKOrder(event, 1)) {
                window.close();
                staffmanageschoolyeardisplay(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffmanagesemesterdisplay(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4))
                abousUs(window);
        }

        window.clear();
        window.draw(s_Semestertexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        
        window.display();
    }
}
void staffmanagecourse(Staff &userstaff) {
    sf::RenderWindow window(sf::VideoMode(1470, 950), "Login window", sf::Style::Close);
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
    staffhomebuttonlist.setpostionlistbutton(30, 140, 0, 60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (staffhomebuttonlist.isClickedKOrder(event, 1)) {
                window.close();
                staffmanageschoolyeardisplay(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffmanagesemesterdisplay(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4))
                abousUs(window);
        }

        window.clear();
        window.draw(s_Coursetexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        window.display();
    }
}