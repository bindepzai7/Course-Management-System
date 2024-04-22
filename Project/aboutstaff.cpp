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


void staffHome(Staff& userstaff) {
    //init mode
    userstaff.setmode(false);
    sf::RenderWindow window(sf::VideoMode(1470, 950), "Login window", sf::Style::Close);
    sf::Texture staffHomeTexture;
    staffHomeTexture.loadFromFile("Design UI/[Staff - 1] Home.jpg");
    staffHomeTexture.setSmooth(true);
    sf::Sprite s_staffHomeTexture;
    s_staffHomeTexture.setTexture(staffHomeTexture);
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


    //navigation bar current textbox
    OutputTextBox schoolyeartextbox(22, sf::Color(119, 106, 92), getCurrentSchoolyear());
    schoolyeartextbox.setfont(Palatino);
    schoolyeartextbox.setTextPosition(sf::Vector2f(181, 667));

    OutputTextBox semestertextbox(22, sf::Color(119, 106, 92), getCurrentSemester());
    semestertextbox.setfont(Palatino);
    semestertextbox.setTextPosition(sf::Vector2f(218, 702));

    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));

    //mode button
    Button editmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "EDIT", 20, Palatino);
    editmode.setposition(sf::Vector2f(46, 491));
    Button viewmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "VIEW", 20, Palatino);
    viewmode.setposition(sf::Vector2f(46, 538));

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
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                    }
                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1)) {
                window.close();
                staffmanageschoolyeardisplay(userstaff);
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffSemesterLobby(userstaff);
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff, getCurrentSchoolyear(), getCurrentSemester());
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                window.close();
                staffaddclasses(userstaff, getCurrentSchoolyear());
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5)) {
                window.close();
                staffaboutUs(userstaff);
                break;
            }

            //click mode
            if (editmode.isClick(event)) {
                editmode.setisClicked(true);
                viewmode.setisClicked(false);
                userstaff.setmode(true);
            }
            if (viewmode.isClick(event)) {
                viewmode.setisClicked(true);
                editmode.setisClicked(false);
                userstaff.setmode(false);
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
        }

        window.clear();
        window.draw(s_staffHomeTexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        logoutbut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
}

void staffviewprofile(sf::RenderWindow& window, Staff& userstaff) {
    sf::Texture staffViewProfiletexture;
    staffViewProfiletexture.loadFromFile("Design UI/[Staff - 2.1] Profile.jpg");
    staffViewProfiletexture.setSmooth(true);
    sf::Sprite s_staffViewProfiletexture;
    s_staffViewProfiletexture.setTexture(staffViewProfiletexture);
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

    //navigation bar current textbox
    OutputTextBox schoolyeartextbox(22, sf::Color(119, 106, 92), getCurrentSchoolyear());
    schoolyeartextbox.setfont(Palatino);
    schoolyeartextbox.setTextPosition(sf::Vector2f(181, 667));

    OutputTextBox semestertextbox(22, sf::Color(119, 106, 92), getCurrentSemester());
    semestertextbox.setfont(Palatino);
    semestertextbox.setTextPosition(sf::Vector2f(218, 702));

    //Staff ID textbox
    OutputTextBox ID(22, sf::Color::Black, userstaff.getStaffID());
    ID.setfont(Palatino);
    ID.setTextPosition(sf::Vector2f(700, 342));

    //Staff username textbox
    OutputTextBox username(22, sf::Color::Black, userstaff.getStaffID());
    username.setfont(Palatino);
    username.setTextPosition(sf::Vector2f(445, 481));

    //Staff fullname textbox
    OutputTextBox fullname(22, sf::Color::Black, userstaff.getLastname()+" "+userstaff.getFirstname());
    fullname.setfont(Palatino);
    fullname.setTextPosition(sf::Vector2f(445, 590));

    //Staff social ID textbox
    OutputTextBox socialID(22, sf::Color::Black, userstaff.getStaffSocialID());
    socialID.setfont(Palatino);
    socialID.setTextPosition(sf::Vector2f(445, 703));

    //Staff dob textbox
    OutputTextBox dob(22, sf::Color::Black, userstaff.getdob());
    dob.setfont(Palatino);
    dob.setTextPosition(sf::Vector2f(970, 590));

    //Staff gender textbox
    OutputTextBox gender(50, sf::Color(119, 106, 92), "*");
    gender.setfont(Palatino);
    int x = 1090;
    if (userstaff.getGender()) x += 172;   //if gender is female 
    gender.setTextPosition(sf::Vector2f(x, 464));

    //mode button
    Button editmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "EDIT", 20, Palatino);
    editmode.setposition(sf::Vector2f(46, 491));
    Button viewmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "VIEW", 20, Palatino);
    viewmode.setposition(sf::Vector2f(46, 538));

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
                        userstaff.~Staff();
                        window.close();
                        staffHome(userstaff);
                    }
                    if (x_coor > 1087 && x_coor < 1200 && y_coor> 370 && y_coor < 405) {
                        staffChangePassword(window, userstaff);
                        break;
                    }
                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1)) {
                window.close();
                staffmanageschoolyeardisplay(userstaff);
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffSemesterLobby(userstaff);
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff, getCurrentSchoolyear(), getCurrentSemester());
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                window.close();
                staffaddclasses(userstaff, getCurrentSchoolyear());
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5)) {
                window.close();
                staffaboutUs(userstaff);
                break;
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
            //click mode
            if (editmode.isClick(event)) {
                editmode.setisClicked(true);
                viewmode.setisClicked(false);
                userstaff.setmode(true);
            }
            if (viewmode.isClick(event)) {
                viewmode.setisClicked(true);
                editmode.setisClicked(false);
                userstaff.setmode(false);
            }
        }

        window.clear();
        window.draw(s_staffViewProfiletexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window); 
        ID.drawTextbox(window);
        fullname.drawTextbox(window);
        socialID.drawTextbox(window);
        dob.drawTextbox(window);
        gender.drawTextbox(window);
        username.drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        logoutbut.drawbutton(window);
        window.display();

    }
}

void staffChangePassword(sf::RenderWindow& window, Staff& userstaff) {
    sf::Texture staffChangePassword;
    staffChangePassword.loadFromFile("Design UI/[Staff - 2.2] Change Password.jpg");
    staffChangePassword.setSmooth(true);
    sf::Sprite s_staffChangePassword;
    s_staffChangePassword.setTexture(staffChangePassword);
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

    //navigation bar current textbox
    OutputTextBox schoolyeartextbox(22, sf::Color(119, 106, 92), getCurrentSchoolyear());
    schoolyeartextbox.setfont(Palatino);
    schoolyeartextbox.setTextPosition(sf::Vector2f(181, 667));

    OutputTextBox semestertextbox(22, sf::Color(119, 106, 92), getCurrentSemester());
    semestertextbox.setfont(Palatino);
    semestertextbox.setTextPosition(sf::Vector2f(218, 702));

    //mode button
    Button editmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "EDIT", 20, Palatino);
    editmode.setposition(sf::Vector2f(46, 491));
    Button viewmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "VIEW", 20, Palatino);
    viewmode.setposition(sf::Vector2f(46, 538));

    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));
    //input 3 types of password
    TextBox inputCurrentPassword(24, sf::Color::Black, false);
    inputCurrentPassword.setfont(Palatino);
    inputCurrentPassword.setTextPosition(sf::Vector2f(750, 420));
    inputCurrentPassword.setlimit(true, 24);

    TextBox inputNewPassword(24, sf::Color::Black, false);
    inputNewPassword.setfont(Palatino);
    inputNewPassword.setTextPosition(sf::Vector2f(750, 532));
    inputNewPassword.setlimit(true, 24);

    TextBox inputConfirmPassword(24, sf::Color::Black, false);
    inputConfirmPassword.setfont(Palatino);
    inputConfirmPassword.setTextPosition(sf::Vector2f(750, 644));
    inputConfirmPassword.setlimit(true, 24);
    OutputTextBox wrongaccount(16, sf::Color::Red, "password incorrect!\nPlease try again!");
    wrongaccount.setfont(Palatino);
    bool check = 0;

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
                        userstaff.~Staff();
                        window.close();
                        staffHome(userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                        break;
                    }
                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1)) {
                window.close();
                staffmanageschoolyeardisplay(userstaff);
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffSemesterLobby(userstaff);
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff, getCurrentSchoolyear(), getCurrentSemester());
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                window.close();
                staffaddclasses(userstaff, getCurrentSchoolyear());
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5)) {
                window.close();
                staffaboutUs(userstaff);
                break;
            }


            //click logout button
            if (logoutbut.isClick(event)) {
                chooseRole(window);
                break;
            }
            //click mode
            if (editmode.isClick(event)) {
                editmode.setisClicked(true);
                viewmode.setisClicked(false);
                userstaff.setmode(true);
            }
            if (viewmode.isClick(event)) {
                viewmode.setisClicked(true);
                editmode.setisClicked(false);
                userstaff.setmode(false);
            }
            //change color button when on cursor
            if (logoutbut.isonMousecursor(event)) {
                logoutbut.changecolor(sf::Color(192, 200, 184));
                logoutbut.changeTextColor(sf::Color::Black);
            }
            else {
                logoutbut.changecolor(sf::Color::Transparent);
                logoutbut.changeTextColor(sf::Color::Transparent);
            }

            //change password click
            if (inputCurrentPassword.isClick(event, 733, 413, 1164, 455)) {
                inputCurrentPassword.setselected(true);
                inputNewPassword.setselected(false);
                inputConfirmPassword.setselected(false);
                inputCurrentPassword.settextencode(true);
                inputNewPassword.settextencode(true);
                inputConfirmPassword.settextencode(true);
            }
            else if (inputNewPassword.isClick(event, 733, 525, 1164, 575)) {
                inputCurrentPassword.setselected(false);
                inputNewPassword.setselected(true);
                inputConfirmPassword.setselected(false);
                inputCurrentPassword.settextencode(true);
                inputNewPassword.settextencode(true);
                inputConfirmPassword.settextencode(true);
            }
            else if (inputConfirmPassword.isClick(event, 733, 636, 1164, 679)) {
                inputCurrentPassword.setselected(false);
                inputNewPassword.setselected(false);
                inputConfirmPassword.setselected(true);
                inputCurrentPassword.settextencode(true);
                inputNewPassword.settextencode(true);
                inputConfirmPassword.settextencode(true);
            }

            if (event.type == sf::Event::TextEntered) {
                if (inputCurrentPassword.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                        inputCurrentPassword.setselected(false);
                    }
                    else
                        inputCurrentPassword.typedText(event);
                }
                else if (inputNewPassword.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                        inputNewPassword.setselected(false);
                    }
                    else
                        inputNewPassword.typedText(event);
                }
                else if (inputConfirmPassword.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                        inputConfirmPassword.setselected(false);
                    }
                    else
                        inputConfirmPassword.typedText(event);
                }
            }
            //if change password is clicked
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 946 && x_coor < 1167 && y_coor > 730 && y_coor < 771) {
                        std::string staffID = userstaff.getStaffID();
                        std::string currentPassword = inputCurrentPassword.getText();
                        std::string newPassword = inputNewPassword.getText();
                        std::string confirmPassword = inputConfirmPassword.getText();
                        if (newPassword != confirmPassword) {
                            std::cout << "Wrong" << std::endl;
                            check = true;
                        }
                        else if (newPassword == currentPassword) {
                            std::cout << "wrong1" << std::endl;
                            check = true;
                            std::cout << check;
                        }
                        else {
                            LinkedList<User> userList = readUserFromCSV("Data/staffuser.csv");
                            if (check_login(userList, userstaff.getStaffID(), currentPassword)) {
                                changePassword(userList, userstaff.getStaffID(), newPassword);
                                updateUser2CSVfile("Data/staffuser.csv", userList);
                                announcement("change password sucessfully");
                            }
                            else {
                                std::cout << "wrong2" << std::endl;
                                std::cout << userstaff.getStaffID() << std::endl;
                                check = true;
                            }

                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(s_staffChangePassword);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        inputCurrentPassword.drawTextbox(window);
        inputNewPassword.drawTextbox(window);
        inputConfirmPassword.drawTextbox(window);
        if (check) {
            wrongaccount.setTextPosition(sf::Vector2f(750, 680));
            wrongaccount.drawTextbox(window);
        }
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();

    }
}

void staffaboutUs( Staff& userstaff) {
    sf::RenderWindow window(sf::VideoMode(1470, 950), "Login window", sf::Style::Close);
    sf::Texture AboutUstexture;
    AboutUstexture.loadFromFile("Design UI/[Staff - 7] About us.jpg");
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

    //navigation bar current textbox
    OutputTextBox schoolyeartextbox(22, sf::Color(119, 106, 92), getCurrentSchoolyear());
    schoolyeartextbox.setfont(Palatino);
    schoolyeartextbox.setTextPosition(sf::Vector2f(181, 667));

    OutputTextBox semestertextbox(22, sf::Color(119, 106, 92), getCurrentSemester());
    semestertextbox.setfont(Palatino);
    semestertextbox.setTextPosition(sf::Vector2f(218, 702));

    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));

    //mode button
    Button editmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "EDIT", 20, Palatino);
    editmode.setposition(sf::Vector2f(46, 491));
    Button viewmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "VIEW", 20, Palatino);
    viewmode.setposition(sf::Vector2f(46, 538));


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
                        userstaff.~Staff();
                        window.close();
                        staffHome(userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                    }
                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1)) {
                window.close();
                staffmanageschoolyeardisplay(userstaff);
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffSemesterLobby(userstaff);
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff, getCurrentSchoolyear(), getCurrentSemester());
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                window.close();
                staffaddclasses(userstaff, getCurrentSchoolyear());
                break;
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5)) {
                window.close();
                staffaboutUs(userstaff);
                break;
            }

            //click mode
            if (editmode.isClick(event)) {
                editmode.setisClicked(true);
                viewmode.setisClicked(false);
                userstaff.setmode(true);
            }
            if (viewmode.isClick(event)) {
                viewmode.setisClicked(true);
                editmode.setisClicked(false);
                userstaff.setmode(false);
            }


            //click logout button
            if (logoutbut.isClick(event)) { 
                userstaff.~Staff();
                chooseRole(window);
                break;
            }

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
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();

    }
}
