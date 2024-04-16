#include"displayfunction.h"
#include"dropdownlist.h"
#include"Textbox.h"
#include"LinkedList.h"
#include"Staff.h"
#include "AdditionalStruct.h"
#include"Student.h"
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include<Windows.h>

void staffaddclasses(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear) {
    sf::Texture Staffaddclasstexture;
    Staffaddclasstexture.loadFromFile("Design UI/[Staff - 6.1] View classes.jpg");
    Staffaddclasstexture.setSmooth(true);
    sf::Sprite s_Staffaddclasstexture;
    s_Staffaddclasstexture.setTexture(Staffaddclasstexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> textstaffhomebutton;
    textstaffhomebutton.push_tail(" manage school year ");
    textstaffhomebutton.push_tail("  manage semester   ");
    textstaffhomebutton.push_tail("   manage course    ");
    textstaffhomebutton.push_tail("    manage class    ");
    textstaffhomebutton.push_tail("      about us      ");
    dropdownlist staffhomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), textstaffhomebutton, 30, Palatino);
    staffhomebuttonlist.setpostionlistbutton(30, 143, 0, 65);


    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));

    //school year current textbox
    OutputTextBox cur_schoolyeartextbox(28, sf::Color::Black, schoolyear);
    cur_schoolyeartextbox.setfont(Palatino);
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(1110, 357));

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
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        staffHome(window, userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                    }
                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1))
                staffmanageschoolyeardisplay(window, userstaff);
            if (staffhomebuttonlist.isClickedKOrder(event, 2))
                staffmanagesemesterdisplay(window, userstaff, getCurrentSchoolyear());
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window, userstaff, getCurrentSchoolyear(), getCurrentSemester());
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                staffaddclasses(window, userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5))
                staffaboutUs(window, userstaff);


            //click logout button
            if (logoutbut.isClick(event)) chooseRole(window);

            //change color button when on cursor
            if (logoutbut.isonMousecursor(event)) {
                logoutbut.changecolor(sf::Color(192, 200, 184));
                logoutbut.changeTextColor(sf::Color::Black);
            }
            else {
                logoutbut.changecolor(sf::Color::Transparent);
                logoutbut.changeTextColor(sf::Color::Transparent);
            }

            //click class button
            for (int i = 1; i <= classestext.sizeoflist(); i++) {
                if (classesbutton.isClickedKOrder(event, i)) {

                    staffmanageclass(window, userstaff, schoolyear, i);
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
                userstaff.writeClasstoFile(schoolyear, classestext2);
                staffaddclasses(window, userstaff, schoolyear);
            }
        }

        window.clear();
        window.draw(s_Staffaddclasstexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        classesbutton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        cur_schoolyeartextbox.drawTextbox(window);
        addclasstxtbox.drawTextbox(window);
        window.display();
    }
}

void staffmanageclass(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, int Korderbut) {
    const int limitnumsofbutton = 8;//limit of number of button that display in list 
    sf::Texture Coursetexture;
    Coursetexture.loadFromFile("Design UI/[Staff - 6.2] View Classes 2.jpg");
    Coursetexture.setSmooth(true);
    sf::Sprite s_Coursetexture;
    s_Coursetexture.setTexture(Coursetexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> textstaffhomebutton;
    textstaffhomebutton.push_tail(" manage school year ");
    textstaffhomebutton.push_tail("  manage semester   ");
    textstaffhomebutton.push_tail("   manage course    ");
    textstaffhomebutton.push_tail("    manage class    ");
    textstaffhomebutton.push_tail("      about us      ");
    dropdownlist staffhomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), textstaffhomebutton, 30, Palatino);
    staffhomebuttonlist.setpostionlistbutton(30, 143, 0, 65);


    //list of class at current schoolyear

    userstaff.readAllClassinSchoolYear(schoolyear);
    LinkedList<std::string> classestext = userstaff.getclassescode();
    dropdownlist classesbutton(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, classestext, 30, Palatino);
    classesbutton.setpostionlistbuttonwithlimit(475, 320, 0, 65, 310, 830, 500);

    sf::Vector2f Posofclasschosen = classesbutton.getpositionofKbut(Korderbut);
    std::string textofbutton = classesbutton.getKoderButtonText(Korderbut);
    Button classchosenbutton(sf::Color(192, 200, 184), sf::Vector2f(300, 50), false, sf::Color::Black, textofbutton, 30, Palatino);//Nen lay mau gi??
    classchosenbutton.setposition(sf::Vector2f(Posofclasschosen.x, Posofclasschosen.y));

    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));

    //add first year student button

    //view student in class button

    //init newposy of list classes button and class button chosen
    float newposy = 320;
    float newposyofclasschosen = Posofclasschosen.y;
    if (Korderbut > limitnumsofbutton)  newposyofclasschosen = newposyofclasschosen - 500.f;

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
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        staffHome(window, userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                    }
                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1))
                staffmanageschoolyeardisplay(window, userstaff);
            if (staffhomebuttonlist.isClickedKOrder(event, 2))
                staffmanagesemesterdisplay(window, userstaff, getCurrentSchoolyear());
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window, userstaff, getCurrentSchoolyear(), getCurrentSemester());
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                staffaddclasses(window, userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5))
                staffaboutUs(window, userstaff);

            //click class button
            for (int i = 1; i <= classestext.sizeoflist(); i++) {
                if (classesbutton.isClickedKOrder(event, i))
                    staffmanageclass(window, userstaff, schoolyear, i);

            }


            //wheel scrool
            if (event.type == event.MouseWheelScrolled) {
                newposy = newposy + event.mouseWheelScroll.delta * 10.0f;
                newposyofclasschosen = newposyofclasschosen + event.mouseWheelScroll.delta * 10.0f;
                classesbutton.setpostionlistbuttonwithlimit(475, newposy, 0, 65, 310, 830, 500);
                classchosenbutton.setpositiontwithbuttonlimit(Posofclasschosen.x, newposyofclasschosen, 310, 830, 500);

            }

            //click logout button
            if (logoutbut.isClick(event)) chooseRole(window);

            //change color button when on cursor
            if (logoutbut.isonMousecursor(event)) {
                logoutbut.changecolor(sf::Color(192, 200, 184));
                logoutbut.changeTextColor(sf::Color::Black);
            }
            else {
                logoutbut.changecolor(sf::Color::Transparent);
                logoutbut.changeTextColor(sf::Color::Transparent);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 910 and x_coor < 1385 and y_coor >390 and y_coor < 490) {
                        staffviewstudentinclass(window, userstaff, textofbutton);
                    }
                    if (x_coor > 910 and x_coor < 1385 and y_coor >545 and y_coor < 645) {
                        staffaddfirstyearstudent(window, userstaff, schoolyear, textofbutton);
                    }
                }
            }
        }

        window.clear();
        window.draw(s_Coursetexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        classesbutton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        classchosenbutton.drawbutton(window);
        logoutbut.drawbutton(window);
        window.display();
    }
}

void staffaddfirstyearstudent(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string addtoclass) {
    //inti class
    Class curclass(addtoclass);
    std::string studentID = "";
    Name name;
    bool studentGender = 1; // 0 is male, 1 is female
    Date birthDay;
    std::string socialID = "";

    curclass.loadStudentfromCSV("Data/" + schoolyear + "/" + addtoclass + ".csv");
    sf::Texture add1styearstudenttexture;
    add1styearstudenttexture.loadFromFile("Design UI/[Staff - 6.2.2] add 1st year students.jpg");
    add1styearstudenttexture.setSmooth(true);
    sf::Sprite s_add1styearstudenttexture;
    s_add1styearstudenttexture.setTexture(add1styearstudenttexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> textstaffhomebutton;
    textstaffhomebutton.push_tail(" manage school year ");
    textstaffhomebutton.push_tail("  manage semester   ");
    textstaffhomebutton.push_tail("   manage course    ");
    textstaffhomebutton.push_tail("    manage class    ");
    textstaffhomebutton.push_tail("      about us      ");
    dropdownlist staffhomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), textstaffhomebutton, 30, Palatino);
    staffhomebuttonlist.setpostionlistbutton(30, 143, 0, 65);


    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));

    //class current textbox
    OutputTextBox cur_classtextbox(28, sf::Color::Black, addtoclass);
    cur_classtextbox.setfont(Palatino);
    cur_classtextbox.setTextPosition(sf::Vector2f(1070.f, 216.f));

    //add student with information 
    TextBox addStudentID(24, sf::Color::Black, false);
    addStudentID.setfont(Palatino);
    addStudentID.setTextPosition(sf::Vector2f(450, 390));

    TextBox addFirstname(24, sf::Color::Black, false);
    addFirstname.setfont(Palatino);
    addFirstname.setTextPosition(sf::Vector2f(450, 497));

    TextBox addLastname(24, sf::Color::Black, false);
    addLastname.setfont(Palatino);
    addLastname.setTextPosition(sf::Vector2f(450, 604));

    OutputTextBox gender(52, sf::Color(119, 106, 92), "*");
    gender.setfont(Palatino);

    TextBox adddayofbirth(24, sf::Color::Black, false);
    adddayofbirth.setfont(Palatino);
    adddayofbirth.setTextPosition(sf::Vector2f(970, 497));

    TextBox addSocialID(24, sf::Color::Black, false);
    addSocialID.setfont(Palatino);
    addSocialID.setTextPosition(sf::Vector2f(970, 604));

    //button click to import file

    Button importbut(sf::Color(251, 244, 234, 50), sf::Vector2f(700, 145), false);
    importbut.setButposition(sf::Vector2f(680, 773));


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
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        staffHome(window, userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                    }
                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1))
                staffmanageschoolyeardisplay(window, userstaff);
            if (staffhomebuttonlist.isClickedKOrder(event, 2))
                staffmanagesemesterdisplay(window, userstaff, getCurrentSchoolyear());
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window, userstaff, getCurrentSchoolyear(), getCurrentSemester());
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                staffaddclasses(window, userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5))
                staffaboutUs(window, userstaff);


            //click logout button
            if (logoutbut.isClick(event)) chooseRole(window);

            //change color logout button when on cursor
            if (logoutbut.isonMousecursor(event)) {
                logoutbut.changecolor(sf::Color(192, 200, 184));
                logoutbut.changeTextColor(sf::Color::Black);
            }
            else {
                logoutbut.changecolor(sf::Color::Transparent);
                logoutbut.changeTextColor(sf::Color::Transparent);
            }


            //click to add student to class

            if (addStudentID.isClick(event, 450, 380, 815, 420)) {
                addStudentID.setselected(true);
                addFirstname.setselected(false);
                addLastname.setselected(false);
                adddayofbirth.setselected(false);
                addSocialID.setselected(false);
            }
            else if (addFirstname.isClick(event, 450, 487, 815, 527)) {
                addStudentID.setselected(false);
                addFirstname.setselected(true);
                addLastname.setselected(false);
                adddayofbirth.setselected(false);
                addSocialID.setselected(false);
            }
            else  if (addLastname.isClick(event, 450, 594, 815, 634)) {
                addStudentID.setselected(false);
                addFirstname.setselected(false);
                addLastname.setselected(true);
                adddayofbirth.setselected(false);
                addSocialID.setselected(false);
            }
            else if (adddayofbirth.isClick(event, 970, 487, 1335, 527)) {
                addStudentID.setselected(false);
                addFirstname.setselected(false);
                addLastname.setselected(false);
                adddayofbirth.setselected(true);
                addSocialID.setselected(false);
            }
            else if (addSocialID.isClick(event, 970, 594, 1335, 634)) {
                addStudentID.setselected(false);
                addFirstname.setselected(false);
                addLastname.setselected(false);
                adddayofbirth.setselected(false);
                addSocialID.setselected(true);
            }
            if (event.type == sf::Event::TextEntered) {
                if (addStudentID.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addStudentID.setselected(false);
                    else
                        addStudentID.typedText(event);
                }
                else if (addFirstname.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addFirstname.setselected(false);
                    else
                        addFirstname.typedText(event);
                }
                else if (addLastname.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addLastname.setselected(false);
                    else
                        addLastname.typedText(event);
                }
                else if (adddayofbirth.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        adddayofbirth.setselected(false);
                    else
                        adddayofbirth.typedText(event);
                }
                else if (addSocialID.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addSocialID.setselected(false);
                    else
                        addSocialID.typedText(event);
                }
            }
            //add student button is Press
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 1082 && x_coor < 1107 && y_coor>375 && y_coor < 400) {
                        gender.setTextPosition(sf::Vector2f(1085, 365));
                        studentGender = 0;
                    }
                    if (x_coor > 1251 && x_coor < 1276 && y_coor>375 && y_coor < 400) {
                        gender.setTextPosition(sf::Vector2f(1254, 365));
                        studentGender = 1;
                    }
                    if (x_coor > 1150 && x_coor < 1350 && y_coor>666 && y_coor < 706) {
                        std::cout << studentGender;
                        studentID = addStudentID.getText();
                        name.firstName = addFirstname.getText();
                        name.lastName = addLastname.getText();
                        std::string dayofbirth = adddayofbirth.getText();
                        int i = 0;
                        while (dayofbirth[i] != 47 && dayofbirth[i] != 45 && i < dayofbirth.size())
                            i++;
                        birthDay.day = std::stoi(dayofbirth.substr(0, i));
                        std::cout << birthDay.day;
                        int j = i + 1;
                        while (dayofbirth[j] != 47 && dayofbirth[j] != 45 && j < dayofbirth.size())
                            j++;
                        birthDay.month = std::stoi(dayofbirth.substr(i + 1, j - 1));
                        std::cout << birthDay.month;
                        birthDay.year = std::stoi(dayofbirth.substr(j + 1, dayofbirth.size() - 1));
                        std::cout << birthDay.year;
                        socialID = addSocialID.getText();
                        curclass.addStudent(Student(studentID, name, studentGender, birthDay, socialID));
                        curclass.saveStudent(schoolyear);
                    }
                }
            }

            //importfile is on mouse cursor
            if (importbut.isonMousecursor(event))
                importbut.changecolor(sf::Color(251, 244, 234, 128));
            else
                importbut.changecolor(sf::Color::Transparent);

            if (importbut.isClick(event)) {
                importbut.setisClicked(true);
                std::string filename = filenametoimport();
                curclass.loadStudentfromCSV(filename);
                curclass.saveStudent(schoolyear);
            }
            else importbut.setisClicked(false);
        }


        window.clear();
        window.draw(s_add1styearstudenttexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        cur_classtextbox.drawTextbox(window);
        addStudentID.drawTextbox(window);
        addFirstname.drawTextbox(window);
        addLastname.drawTextbox(window);
        gender.drawTextbox(window);
        adddayofbirth.drawTextbox(window);
        addSocialID.drawTextbox(window);
        importbut.drawbutton(window);
        window.display();
    }
}

std::string filenametoimport() {
    sf::RenderWindow window(sf::VideoMode(800, 300), "Enter Filename", sf::Style::Close);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    sf::RectangleShape framebut;
    framebut.setFillColor(sf::Color(239, 233, 222));
    framebut.setSize(sf::Vector2f(500, 50));
    framebut.setOutlineColor(sf::Color(255, 215, 0));
    framebut.setOutlineThickness(1.0f);
    framebut.setPosition(sf::Vector2f(200, 150));

    OutputTextBox tilte(32, sf::Color::Black, "Enter filename to import!");
    tilte.setfont(Palatino);
    tilte.setStyleBold();
    tilte.setTextPosition(sf::Vector2f(200, 30));

    OutputTextBox filenametxt(26, sf::Color::Black, "Filename: ");
    filenametxt.setfont(Palatino);
    filenametxt.setStyleBold();
    filenametxt.setTextPosition(sf::Vector2f(60, 100));

    TextBox enterfile(24, sf::Color::Black, false);
    enterfile.setfont(Palatino);
    enterfile.setTextPosition(sf::Vector2f(210, 170));

    Button enterbut(sf::Color(211, 212, 198), sf::Vector2f(120, 50), false, sf::Color::Black, "import", 28, Palatino);
    enterbut.setposition(sf::Vector2f(340, 230));

    std::string filename;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (enterfile.isClick(event, 200, 150, 700, 200)) {
                enterfile.setselected(true);
            }
            if (event.type == sf::Event::TextEntered) {
                if (enterfile.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        enterfile.setselected(false);
                    else
                        enterfile.typedText(event);
                }
            }
            if (enterbut.isonMousecursor(event)) enterbut.changecolor(sf::Color(192, 200, 184));
            else enterbut.changecolor(sf::Color(211, 212, 198));
            if (enterbut.isClick(event)) {
                filename = enterbut.getisClick();
                window.close();
            }
        }
        window.clear(sf::Color(251, 244, 234));
        window.draw(framebut);
        tilte.drawTextbox(window);
        filenametxt.drawTextbox(window);
        enterfile.drawTextbox(window);
        enterbut.drawbutton(window);
        window.display();
    }
    return filename;
}

void staffviewstudentinclass(sf::RenderWindow& window, Staff& userstaff, std::string classchosen) {
    sf::Texture AboutUstexture;
    AboutUstexture.loadFromFile("Design UI/[Staff - 6.2.1] View Students in Class.jpg");
    AboutUstexture.setSmooth(true);
    sf::Sprite s_AboutUstexture;
    s_AboutUstexture.setTexture(AboutUstexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> textstaffhomebutton;
    textstaffhomebutton.push_tail(" manage school year ");
    textstaffhomebutton.push_tail("  manage semester   ");
    textstaffhomebutton.push_tail("   manage course    ");
    textstaffhomebutton.push_tail("    manage class    ");
    textstaffhomebutton.push_tail("      about us      ");
    dropdownlist staffhomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), textstaffhomebutton, 30, Palatino);
    staffhomebuttonlist.setpostionlistbutton(30, 143, 0, 65);



    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        staffHome(window, userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                    }
                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1))
                staffmanageschoolyeardisplay(window, userstaff);
            if (staffhomebuttonlist.isClickedKOrder(event, 2))
                staffmanagesemesterdisplay(window, userstaff, getCurrentSchoolyear());
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window, userstaff, getCurrentSchoolyear(), getCurrentSemester());
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                staffaddclasses(window, userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5))
                staffaboutUs(window, userstaff);


            //click logout button
            if (logoutbut.isClick(event)) chooseRole(window);

            //change color button when on cursor
            if (logoutbut.isonMousecursor(event)) {
                logoutbut.changecolor(sf::Color(192, 200, 184));
                logoutbut.changeTextColor(sf::Color::Black);
            }
            else {
                logoutbut.changecolor(sf::Color::Transparent);
                logoutbut.changeTextColor(sf::Color::Transparent);
            }
        }

        window.clear();
        window.draw(s_AboutUstexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        window.display();

    }
}