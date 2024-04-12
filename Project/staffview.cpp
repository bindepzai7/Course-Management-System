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
                if (schoolyears.isClickedKOrder(event, i)) {
                    /*std::string textofbutton=schoolyears.getKoderButtonText(i);
                    std::cout << textofbutton;*/
                    //std::cout << schoolyears.getpositionofKbut(i).y;
                    std::cout << i;
                    staffmanageschoolyear2display(window, userstaff, i);
                }
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

void staffmanageschoolyear2display(sf::RenderWindow& window, Staff& userstaff, int Korderofbut) {
    const int limitnumsofbutton = 8;//limit of number of button that display wiht schoolyear 
    sf::Texture Schoolyeartexture;
    Schoolyeartexture.loadFromFile("Design UI/[Staff] school year 2.jpg");
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

    //userstaff.readAllSchoolyear();
    LinkedList<std::string> schoolyearstext = userstaff.getschoolyearstext();
    dropdownlist schoolyears(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, schoolyearstext, 30, Palatino);
    schoolyears.setpostionlistbuttonwithlimit(475, 320, 0, 65, 310, 830, 500);

    sf::Vector2f Posofschoolyearclicked = schoolyears.getpositionofKbut(Korderofbut);
    std::cout << Posofschoolyearclicked.y;
    std::string textofbutton = schoolyears.getKoderButtonText(Korderofbut);

    Button schoolyearclickbutton(sf::Color(192, 200, 184), sf::Vector2f(300, 50), false, sf::Color::Black, textofbutton, 30, Palatino);//Nen lay mau gi??
    schoolyearclickbutton.setposition(sf::Vector2f(Posofschoolyearclicked.x, Posofschoolyearclicked.y));
   
     //init newposy of list school years button
    float newposy = 320;
    float newposyofschoolyearclicked = Posofschoolyearclicked.y;
    if (Korderofbut > limitnumsofbutton)  newposyofschoolyearclicked = newposyofschoolyearclicked - 500.f;

    //view semester butotn


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
                if (schoolyears.isClickedKOrder(event, i)) {
                    staffmanageschoolyear2display(window, userstaff, i);
                }
            }


            //wheel scrool
            if (event.type == event.MouseWheelScrolled) {
                newposy = newposy + event.mouseWheelScroll.delta * 10.0f;
                newposyofschoolyearclicked = newposyofschoolyearclicked + event.mouseWheelScroll.delta * 10.0f;
                schoolyears.setpostionlistbuttonwithlimit(475, newposy, 0, 65, 310, 830, 500);
                schoolyearclickbutton.setpositiontwithbuttonlimit(Posofschoolyearclicked.x, newposyofschoolyearclicked, 310, 830, 500);
            }


            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 910 and x_coor < 1385 and y_coor >390 and y_coor < 490) {
                        staffaddclasses(window, userstaff, textofbutton);
                    }
                    if (x_coor > 910 and x_coor < 1385 and y_coor >545 and y_coor < 645) {

                    }
                }
            }

        }
        //add school button is Press
       
        window.clear();
        window.draw(s_Schoolyeartexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        schoolyears.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        schoolyearclickbutton.drawbutton(window);
        //addfirstyearbutton.drawbutton(window);
        window.display();
    }
}

void staffaddclasses(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear) {
    sf::Texture Staffhometexture;
    Staffhometexture.loadFromFile("Design UI/[Staff] add classes.jpg");
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
    dropdownlist staffhomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color(239, 233, 222), textstaffhomebutton, 24, Palatino);
    staffhomebuttonlist.setpostionlistbutton(30, 140, 0, 60);
    //school year current textbox

    OutputTextBox cur_schoolyeartextbox(28, sf::Color::Black, schoolyear);
    cur_schoolyeartextbox.setfont(Palatino);
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(1040.f, 362.f));

    //list of class at current schoolyear

    userstaff.readAllClassinSchoolYear(schoolyear);
    LinkedList<std::string> classestext = userstaff.getclassescode();
    dropdownlist classesbutton(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, classestext, 30, Palatino);
    classesbutton.setpostionlistbuttonwithlimit(475, 320, 0, 65, 310, 830, 500);

    TextBox addclasstxtbox(24, sf::Color::Black, false);
    addclasstxtbox.setfont(Palatino);
    addclasstxtbox.setTextPosition(sf::Vector2f(950, 515));
     //init newposy of list classes button
    float newposy = 320;

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

            //click class button
            for (int i = 1; i <= classestext.sizeoflist(); i++) {
                if (classesbutton.isClickedKOrder(event, i)) { 
                    std::cout << i;
                }
            }


            //wheel scrool
            if (event.type == event.MouseWheelScrolled) {
                newposy = newposy + event.mouseWheelScroll.delta * 10.0f;
                classesbutton.setpostionlistbuttonwithlimit(475, newposy, 0, 65, 310, 830, 500);
            }


            if (addclasstxtbox.isClick(event, 950, 505, 1350, 545)) {
                addclasstxtbox.setselected(true);
            }
            if (event.type == sf::Event::TextEntered) {
                if (addclasstxtbox.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addclasstxtbox.setselected(false);
                    else
                        addclasstxtbox.typedText(event);
                }
            }
        }
        //add class button is Press
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            int x_coor = event.mouseButton.x;
            int y_coor = event.mouseButton.y;
            if (x_coor > 1150 && x_coor < 1350 && y_coor>575 && y_coor < 615) {
                std::cout << "c";
                std::string newschoolyeartext = addclasstxtbox.getText();
                userstaff.addClassforNewSchoolYear(Class(newschoolyeartext));
                LinkedList<std::string> classestext2 = userstaff.getclassescode();
                userstaff.writeClasstoFile(schoolyear,classestext2);
                staffaddclasses(window, userstaff, schoolyear);
            }
        }

        window.clear();
        window.draw(s_Staffhometexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        classesbutton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        cur_schoolyeartextbox.drawTextbox(window);
        addclasstxtbox.drawTextbox(window);
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