#include"displayfunction.h"
#include"dropdownlist.h"
#include"Textbox.h"
#include"LinkedList.h"
#include"Student.h"
#include"Staff.h"
#include<string>
#include<Windows.h>
#include<iostream>
#include<SFML/Graphics.hpp>

void studenthome(sf::RenderWindow &window,Student&studentuser) {
    sf::Texture Studenthometexture;
    Studenthometexture.loadFromFile("Design UI/[Student - 1] Home.jpg");
    Studenthometexture.setSmooth(true);
    sf::Sprite s_Studenthometexture;
    s_Studenthometexture.setTexture(Studenthometexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> studenttexthomebutton;
    studenttexthomebutton.push_tail("my profile");
    studenttexthomebutton.push_tail("change password");
    studenttexthomebutton.push_tail("my courses");
    studenttexthomebutton.push_tail("my scoreboard");
    studenttexthomebutton.push_tail("about us");
    dropdownlist studenthomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), studenttexthomebutton, 30, Palatino);
    studenthomebuttonlist.setpostionlistbutton(30, 143, 0, 95);


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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        studentprofileview(window, studentuser);
                    }
                }
            }
            if (studenthomebuttonlist.isClickedKOrder(event, 1))
                studentprofileview(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 2))
                studentChangePassword(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 3))
                studentCourse(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentScoreboard(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);

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
        window.draw(s_Studenthometexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }

}

void studentprofileview(sf::RenderWindow& window, Student& studentuser) {
    sf::Texture studentprofileviewtexture;
    studentprofileviewtexture.loadFromFile("Design UI/[Student - 2] Profile.jpg");
    studentprofileviewtexture.setSmooth(true);
    sf::Sprite s_studentprofileviewtexture;
    s_studentprofileviewtexture.setTexture(studentprofileviewtexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> studenttexthomebutton;
    studenttexthomebutton.push_tail("my profile");
    studenttexthomebutton.push_tail("change password");
    studenttexthomebutton.push_tail("my courses");
    studenttexthomebutton.push_tail("my scoreboard");
    studenttexthomebutton.push_tail("about us");
    dropdownlist studenthomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), studenttexthomebutton, 30, Palatino);
    studenthomebuttonlist.setpostionlistbutton(30, 143, 0, 95);


    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));


    //Student ID textbox
    OutputTextBox ID(22, sf::Color::Black, "Bo ID vao day");
    ID.setfont(Palatino);
    ID.setTextPosition(sf::Vector2f(700, 342));

    //Student username textbox
    OutputTextBox username(22, sf::Color::Black, "Bo Username vao day");
    username.setfont(Palatino);
    username.setTextPosition(sf::Vector2f(445, 481));

    //Student fullname textbox
    OutputTextBox fullname(22, sf::Color::Black, "Bo Fullname vao day");
    fullname.setfont(Palatino);
    fullname.setTextPosition(sf::Vector2f(445, 590));

    //Student class textbox
    OutputTextBox className(22, sf::Color::Black, "Bo Class vao day");
    className.setfont(Palatino);
    className.setTextPosition(sf::Vector2f(445, 701));

    //Student dob textbox
    OutputTextBox dob(22, sf::Color::Black, "Bo day of birth vao day");
    dob.setfont(Palatino);
    dob.setTextPosition(sf::Vector2f(970, 590));

    //Student gender textbox
    OutputTextBox gender(50, sf::Color(119, 106, 92), "*");
    gender.setfont(Palatino);
    int x = 1090;
    if (1) x += 172;   //if gender is female 
    gender.setTextPosition(sf::Vector2f(x, 464));

    //Student social ID textbox
    OutputTextBox socialID(22, sf::Color::Black, "Bo social ID vao day");
    socialID.setfont(Palatino);
    socialID.setTextPosition(sf::Vector2f(970, 701));

    //navigation bar current textbox
    OutputTextBox schoolyeartextbox(22, sf::Color(119, 106, 92), getCurrentSchoolyear());
    schoolyeartextbox.setfont(Palatino);
    schoolyeartextbox.setTextPosition(sf::Vector2f(181, 667));

    OutputTextBox semestertextbox(22, sf::Color(119, 106, 92), getCurrentSemester());
    semestertextbox.setfont(Palatino);
    semestertextbox.setTextPosition(sf::Vector2f(218, 702));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        studenthome(window, studentuser);
                    }
                    if (x_coor > 1087 && x_coor < 1200 && y_coor> 370 && y_coor < 405) {
                        studentChangePassword(window, studentuser);
                    }
                }
            }
            if (studenthomebuttonlist.isClickedKOrder(event, 1))
                studentprofileview(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 2))
                studentChangePassword(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 3))
                studentCourse(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentScoreboard(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);


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
        window.draw(s_studentprofileviewtexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        ID.drawTextbox(window);
        fullname.drawTextbox(window);
        socialID.drawTextbox(window);
        className.drawTextbox(window);
        dob.drawTextbox(window);
        gender.drawTextbox(window);
        username.drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
}

void studentChangePassword(sf::RenderWindow& window, Student& studentuser) {
    sf::Texture studentChangePasswordTexture;
    studentChangePasswordTexture.loadFromFile("Design UI/[Student - 3] Change Password.jpg");
    studentChangePasswordTexture.setSmooth(true);
    sf::Sprite s_studentChangePasswordTexture;
    s_studentChangePasswordTexture.setTexture(studentChangePasswordTexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> studenttexthomebutton;
    studenttexthomebutton.push_tail("my profile");
    studenttexthomebutton.push_tail("change password");
    studenttexthomebutton.push_tail("my courses");
    studenttexthomebutton.push_tail("my scoreboard");
    studenttexthomebutton.push_tail("about us");
    dropdownlist studenthomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), studenttexthomebutton, 30, Palatino);
    studenthomebuttonlist.setpostionlistbutton(30, 143, 0, 95);

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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        studenthome(window, studentuser);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        studentprofileview(window, studentuser);
                    }
                }
            }
            if (studenthomebuttonlist.isClickedKOrder(event, 1))
                studentprofileview(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 2))
                studentChangePassword(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 3))
                studentCourse(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentScoreboard(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);

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
        window.draw(s_studentChangePasswordTexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }

 }

void studentCourse(sf::RenderWindow& window, Student& studentuser, std::string schoolyear, std::string semester) {
    sf::Texture studentCourseTexture;
    studentCourseTexture.loadFromFile("Design UI/[Student - 4] My Course.jpg");
    studentCourseTexture.setSmooth(true);
    sf::Sprite s_studentCourseTexture;
    s_studentCourseTexture.setTexture(studentCourseTexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> studenttexthomebutton;
    studenttexthomebutton.push_tail("my profile");
    studenttexthomebutton.push_tail("change password");
    studenttexthomebutton.push_tail("my courses");
    studenttexthomebutton.push_tail("my scoreboard");
    studenttexthomebutton.push_tail("about us");
    dropdownlist studenthomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), studenttexthomebutton, 30, Palatino);
    studenthomebuttonlist.setpostionlistbutton(30, 143, 0, 95);

    ///navigation bar current textbox
    OutputTextBox schoolyeartextbox(22, sf::Color(119, 106, 92), getCurrentSchoolyear());
    schoolyeartextbox.setfont(Palatino);
    schoolyeartextbox.setTextPosition(sf::Vector2f(181, 667));

    OutputTextBox semestertextbox(22, sf::Color(119, 106, 92), getCurrentSemester());
    semestertextbox.setfont(Palatino);
    semestertextbox.setTextPosition(sf::Vector2f(218, 702));

    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));


    //school year current textbox
    OutputTextBox cur_schoolyeartextbox(28, sf::Color::Black, schoolyear);
    cur_schoolyeartextbox.setfont(Palatino);
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(1160, 180));

    //semester current textbox
    OutputTextBox cur_semestertextbox(28, sf::Color::Black, semester);
    cur_semestertextbox.setfont(Palatino);
    cur_semestertextbox.setTextPosition(sf::Vector2f(1215, 250));

    //input 3 types of password
    TextBox inputCurrentPassword(24, sf::Color::Black, false);
    inputCurrentPassword.setfont(Palatino);
    inputCurrentPassword.setTextPosition(sf::Vector2f(750, 420));

    TextBox inputNewPassword(24, sf::Color::Black, false);
    inputNewPassword.setfont(Palatino);
    inputNewPassword.setTextPosition(sf::Vector2f(750, 532));

    TextBox inputConfirmPassword(24, sf::Color::Black, false);
    inputConfirmPassword.setfont(Palatino);
    inputConfirmPassword.setTextPosition(sf::Vector2f(750, 644));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        studenthome(window, studentuser);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        studentprofileview(window, studentuser);
                    }
                }
            }
            if (studenthomebuttonlist.isClickedKOrder(event, 1))
                studentprofileview(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 2))
                studentChangePassword(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 3))
                studentCourse(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentScoreboard(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);

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

            //change password click
            if (inputCurrentPassword.isClick(event, 733, 413, 1164, 455)) {
                inputCurrentPassword.setselected(true);
                inputNewPassword.setselected(false);
                inputConfirmPassword.setselected(false);
            }
            else if (inputNewPassword.isClick(event, 733, 525, 1164, 575)) {
                inputCurrentPassword.setselected(false);
                inputNewPassword.setselected(true);
                inputConfirmPassword.setselected(false);
            }
            else if (inputConfirmPassword.isClick(event, 733, 636, 1164, 679)) {
                inputCurrentPassword.setselected(false);
                inputNewPassword.setselected(false);
                inputConfirmPassword.setselected(true);
            }

            if (event.type == sf::Event::TextEntered) {
                if (inputCurrentPassword.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        inputCurrentPassword.setselected(false);
                    else
                        inputCurrentPassword.typedText(event);
                }
                else if (inputNewPassword.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        inputNewPassword.setselected(false);
                    else
                        inputNewPassword.typedText(event);
                }
                else if (inputConfirmPassword.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        inputConfirmPassword.setselected(false);
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
                        std::string studentID = studentuser.studentID;
                        std::string currentPassword = string_hashing(inputCurrentPassword.getText());
                        std::string newPassword = string_hashing(inputNewPassword.getText());
                        std::string confirmPassword = string_hashing(inputConfirmPassword.getText());
                        if (newPassword != confirmPassword) {
                            std::cout << "Wrong" << std::endl;
                        }
                        else if (newPassword == currentPassword) {
                            std::cout << "wrong" << std::endl;
                        }
                        else {
                            LinkedList<User> userList = readUserFromCSV("Data/studentuser.csv");
                            if (check_login(userList, studentuser.studentID, currentPassword)) {
                                changePassword(userList, studentuser.studentID, newPassword);
                                updateUser2CSVfile("Data/studentuser.csv", userList);
                            }
                            else {
                                std::cout << "wrong" << std::endl;
                            }

                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(s_studentCourseTexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        cur_schoolyeartextbox.drawTextbox(window);
        cur_semestertextbox.drawTextbox(window);
        inputCurrentPassword.drawTextbox(window);
        inputNewPassword.drawTextbox(window);
        inputConfirmPassword.drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }

}

void studentScoreboard(sf::RenderWindow& window, Student& studentuser, std::string schoolyear, std::string semester) {
    sf::Texture studentScoreboardTexture;
    studentScoreboardTexture.loadFromFile("Design UI/[Student - 5] My Scoreboard.jpg");
    studentScoreboardTexture.setSmooth(true);
    sf::Sprite s_studentScoreboardTexture;
    s_studentScoreboardTexture.setTexture(studentScoreboardTexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> studenttexthomebutton;
    studenttexthomebutton.push_tail("my profile");
    studenttexthomebutton.push_tail("change password");
    studenttexthomebutton.push_tail("my courses");
    studenttexthomebutton.push_tail("my scoreboard");
    studenttexthomebutton.push_tail("about us");
    dropdownlist studenthomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), studenttexthomebutton, 30, Palatino);
    studenthomebuttonlist.setpostionlistbutton(30, 143, 0, 95);


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


    //school year current textbox
    OutputTextBox cur_schoolyeartextbox(28, sf::Color::Black, schoolyear);
    cur_schoolyeartextbox.setfont(Palatino);
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(1160, 180));

    //semester current textbox
    OutputTextBox cur_semestertextbox(28, sf::Color::Black, semester);
    cur_semestertextbox.setfont(Palatino);
    cur_semestertextbox.setTextPosition(sf::Vector2f(1215, 250));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        studenthome(window, studentuser);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        studentprofileview(window, studentuser);
                    }
                }
            }
            if (studenthomebuttonlist.isClickedKOrder(event, 1))
                studentprofileview(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 2))
                studentChangePassword(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 3))
                studentCourse(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentScoreboard(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);

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
        window.draw(s_studentScoreboardTexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        cur_schoolyeartextbox.drawTextbox(window);
        cur_semestertextbox.drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
}

void studentAboutUs(sf::RenderWindow& window, Student& studentuser) {
    sf::Texture studentAboutUsTexture;
    studentAboutUsTexture.loadFromFile("Design UI/[Student - 6] About us.jpg");
    studentAboutUsTexture.setSmooth(true);
    sf::Sprite s_studentAboutUsTexture;
    s_studentAboutUsTexture.setTexture(studentAboutUsTexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    //list of button manage
    LinkedList<std::string> studenttexthomebutton;
    studenttexthomebutton.push_tail("my profile");
    studenttexthomebutton.push_tail("change password");
    studenttexthomebutton.push_tail("my courses");
    studenttexthomebutton.push_tail("my scoreboard");
    studenttexthomebutton.push_tail("about us");
    dropdownlist studenthomebuttonlist(sf::Color(168, 158, 146), sf::Vector2f(280, 53), false, sf::Color(239, 233, 222), studenttexthomebutton, 30, Palatino);
    studenthomebuttonlist.setpostionlistbutton(30, 143, 0, 95);

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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        studenthome(window, studentuser);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        studentprofileview(window, studentuser);
                    }
                }
            }
            if (studenthomebuttonlist.isClickedKOrder(event, 1))
                studentprofileview(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 2))
                studentChangePassword(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 3))
                studentCourse(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentScoreboard(window, studentuser, getCurrentSchoolyear(), getCurrentSemester());
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);

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
        window.draw(s_studentAboutUsTexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }

}