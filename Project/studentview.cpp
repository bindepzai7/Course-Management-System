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

void studenthome(sf::RenderWindow& window, Student& studentuser) {
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
                studentChooseOption(window, studentuser, 0);
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentChooseOption(window, studentuser, 1);
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
    OutputTextBox ID(22, sf::Color::Black, studentuser.studentID);
    ID.setfont(Palatino);
    ID.setTextPosition(sf::Vector2f(700, 342));

    //Student username textbox
    OutputTextBox username(22, sf::Color::Black, studentuser.studentID);
    username.setfont(Palatino);
    username.setTextPosition(sf::Vector2f(445, 481));

    //Student fullname textbox
    OutputTextBox fullname(22, sf::Color::Black, studentuser.name.lastName + " " + studentuser.name.firstName);
    fullname.setfont(Palatino);
    fullname.setTextPosition(sf::Vector2f(445, 590));


    //Student dob textbox
    OutputTextBox dob(22, sf::Color::Black, studentuser.birthDay.getDate());
    dob.setfont(Palatino);
    dob.setTextPosition(sf::Vector2f(970, 590));

    //Student gender textbox
    OutputTextBox gender(50, sf::Color(119, 106, 92), "*");
    gender.setfont(Palatino);
    int x = 1090;
    if (studentuser.studentGender) x += 172;   //if gender is female 
    gender.setTextPosition(sf::Vector2f(x, 464));

    //Student social ID textbox
    OutputTextBox socialID(22, sf::Color::Black, studentuser.socialID);
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
                studentChooseOption(window, studentuser, 0);
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentChooseOption(window, studentuser, 1);
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
                studentChooseOption(window, studentuser, 0);
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentChooseOption(window, studentuser, 1);
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
                        std::string studentID = studentuser.studentID;
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
                            LinkedList<User> userList = readUserFromCSV("Data/studentuser.csv");
                            if (check_login(userList, studentuser.studentID, currentPassword)) {
                                changePassword(userList, studentuser.studentID, newPassword);
                                inputNewPassword.setText("");
                                inputConfirmPassword.setText("");
                                inputCurrentPassword.setText("");
                                updateUser2CSVfile("Data/studentuser.csv", userList);
                                announcement("change password sucessfully");
                            }
                            else {
                                std::cout << "wrong2" << std::endl;
                                std::cout << studentuser.studentID << std::endl;
                                check = true;
                            }

                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(s_studentChangePasswordTexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        inputCurrentPassword.drawTextbox(window);
        inputNewPassword.drawTextbox(window);
        inputConfirmPassword.drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        if (check) {
            wrongaccount.setTextPosition(sf::Vector2f(750, 680));
            wrongaccount.drawTextbox(window);
        }
        inputCurrentPassword.drawTextbox(window);
        inputNewPassword.drawTextbox(window);
        inputConfirmPassword.drawTextbox(window);
        window.display();
    }

}
void studentChooseOption(sf::RenderWindow& window, Student& studentuser, int viewType) {
    sf::Texture StudentChooseOptionTexture;
    StudentChooseOptionTexture.loadFromFile("Design UI/[Student - 4] choosing to view.jpg");
    StudentChooseOptionTexture.setSmooth(true);
    sf::Sprite s_StudentChooseOptionTexture;
    s_StudentChooseOptionTexture.setTexture(StudentChooseOptionTexture);
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

    //CODE HERE

    LinkedList<std::string> schoolyearstext;
    std::string tmp = "20" + studentuser.studentID.substr(0, 2);
    int Kyear = std::stoi(tmp);
    while (Kyear <= std::stoi(getCurrentSchoolyear().substr(0, 4))) {
        schoolyearstext.addNodeInAscending(std::to_string(Kyear) + "-" + std::to_string(Kyear + 1));
        Kyear++;
    }
    dropdownlist schoolyears(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, schoolyearstext, 30, Palatino);
    schoolyears.setpostionlistbutton(475, 320, 0, 65);
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
                studentChooseOption(window, studentuser, 0);
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentChooseOption(window, studentuser, 1);
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
            for (int i = 1; i <= schoolyearstext.sizeoflist(); i++) {
                if (schoolyears.isClickedKOrder(event, i)) {
                    studentChooseOption2(window, studentuser, viewType, i);
                }
            }

        }

        window.clear();
        window.draw(s_StudentChooseOptionTexture);
        logoutbut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        schoolyears.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        window.display();
    }
}

void studentChooseOption2(sf::RenderWindow& window, Student& studentuser, int viewType,int Korderbut) {
    sf::Texture StudentChooseOptionTexture;
    StudentChooseOptionTexture.loadFromFile("Design UI/[Student - 4] choosing to view.jpg");
    StudentChooseOptionTexture.setSmooth(true);
    sf::Sprite s_StudentChooseOptionTexture;
    s_StudentChooseOptionTexture.setTexture(StudentChooseOptionTexture);
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

    //CODE HERE
    //////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////
    
    LinkedList<std::string> schoolyearstext;
    std::string tmp ="20"+ studentuser.studentID.substr(0, 2);
    int Kyear = std::stoi(tmp);
    while (Kyear <= std::stoi(getCurrentSchoolyear().substr(0, 4)) and Kyear<Kyear+8) {
              schoolyearstext.addNodeInAscending(std::to_string(Kyear) + "-" + std::to_string(Kyear + 1));
        Kyear++;
    }
    dropdownlist schoolyears(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, schoolyearstext, 30, Palatino);
    schoolyears.setpostionlistbutton(475, 320, 0, 65);
    sf::Vector2f Posofschoolyearclicked = schoolyears.getpositionofKbut(Korderbut);
    std::string textofbutton = schoolyears.getKoderButtonText(Korderbut);
    Button schoolyearclickbutton(sf::Color(192, 200, 184), sf::Vector2f(300, 50), false, sf::Color::Black, textofbutton, 30, Palatino);//Nen lay mau gi??
    schoolyearclickbutton.setposition(sf::Vector2f(Posofschoolyearclicked.x, Posofschoolyearclicked.y));
    int startyear = std::stoi(textofbutton.substr(0, 4));
    int endyear = std::stoi(textofbutton.substr(5, 8));
    int numbersemester = -1;
    SchoolYear schoolyearchosen(startyear, endyear);
    schoolyearchosen.loadSemesterListFromSemesterList();
    int n = schoolyearchosen.getnumberofsemeseter();
    Button* semesterbut = new Button[n];
    for (int i = 0; i < n; i++) {
        semesterbut[i].changecolor(sf::Color(192, 200, 184, 100));
        semesterbut[i].changesize(sf::Vector2f(55, 55));
        semesterbut[i].setButposition(sf::Vector2f(1093 + i * 100.0f, 454));
    }
    Button semesterbutchosen(sf::Color::Transparent, sf::Vector2f(56, 56), false);
    semesterbutchosen.setButposition(sf::Vector2f(1093, 455));

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
                    if (numbersemester > 0 and x_coor > 910 and x_coor < 1385 and y_coor >545 and y_coor < 645) {
                        //staffscoreboard    /////////////////////////////// 
                        std::cout << semesterbutchosen.getText();
                        if (viewType == 0) studentCourse(window, studentuser, textofbutton, std::to_string(numbersemester));
                        if(viewType==1) studentScoreboard(window, studentuser, textofbutton, std::to_string(numbersemester));
                    }
                }
            }
            if (studenthomebuttonlist.isClickedKOrder(event, 1))
                studentprofileview(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 2))
                studentChangePassword(window, studentuser);
            if (studenthomebuttonlist.isClickedKOrder(event, 3))
                studentChooseOption(window, studentuser, 0);
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentChooseOption(window, studentuser, 1);
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);

            //click logout button
            if (logoutbut.isClick(event)) {
                studentuser.~Student();
                chooseRole(window);
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
            for (int i = 1; i <= schoolyearstext.sizeoflist(); i++) {
                for (int i = 1; i <= schoolyearstext.sizeoflist(); i++) {
                    if (schoolyearclickbutton.isClick(event))
                        studentChooseOption(window,studentuser,viewType);
                    if (schoolyears.isClickedKOrder(event, i)) {
                        studentChooseOption2(window, studentuser,viewType,i);
                    }

                }
            }
            for (int i = 0; i < n; i++) {
                if (semesterbut[i].isClick(event)) {
                    if (semesterbut[i].getisClick() == false) {
                        semesterbut[i].setisClicked(true);
                        semesterbutchosen.setButposition(semesterbut[i].getpositionofbutton());
                        semesterbutchosen.changecolor(sf::Color(250, 128, 114, 50));
                        semesterbutchosen.setoutlinecolor(sf::Color(250, 128, 114));
                        numbersemester = i + 1;
                    }
                    else {
                        semesterbut[i].setisClicked(false);
                        semesterbutchosen.changecolor(sf::Color::Transparent);
                        semesterbutchosen.setoutlinecolor(sf::Color::Transparent);
                        numbersemester = -1;
                    }
                }
                if (semesterbut[i].isonMousecursor(event)) {
                    semesterbut[i].changecolor(sf::Color(186, 158, 146, 100));
                }
                else
                    semesterbut[i].changecolor(sf::Color(192, 200, 184, 100));
            }
        }

        window.clear();
        window.draw(s_StudentChooseOptionTexture);
        logoutbut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        schoolyears.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        schoolyearclickbutton.drawbutton(window);
        for (int i = 0; i < n; i++)
            semesterbut[i].drawbutton(window);
        semesterbutchosen.drawbutton(window);
        window.display();
    }
    delete[] semesterbut;
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

    Semester curSemester(semester);
    curSemester.loadCourseListFromFileCourseList(schoolyear);
    Node<Course>* courseList = curSemester.courseList.head;
    Node<Course>* cur = curSemester.courseList.head;

    int n = 0;
    while (courseList) {
        courseList->data.loadStudentsFromCsvFileStaffUpload("Data/" + schoolyear + "/" + semester + "/studentOfEachCourse/" + courseList->data.courseID + ".csv");

        if (courseList->data.findIfStudentIsInThisCourse(studentuser.studentID)) {
            curSemester.loadCourseListFromFileCourseList(schoolyear);
            n++;
        }
        courseList = courseList->next;
    }

    TextBox** studentTextBox = new TextBox * [n];

    float Posx[6] = { 380,470,577,900,975,1230 };
    float Posy = 385;
    float distance = 60;
    float Posylimabove = 365;
    float Posylimunder = 810;
    float jumpsize = 500;
    int numberofbutton = 8;
    for (int i = 0; i < n; i++)
    {
        studentTextBox[i] = new TextBox[6];
        for (int j = 0; j < 6; j++)
        {
            studentTextBox[i][j].setsize(17);
            studentTextBox[i][j].setColor(sf::Color::Black);
            studentTextBox[i][j].setselected(false);
            studentTextBox[i][j].setfont(Palatino);
            studentTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);
        }

        studentTextBox[i][0].setText(std::to_string(i + 1)); // Assuming you want to set index 0 to an index value
        studentTextBox[i][1].setText(cur->data.courseID);
        studentTextBox[i][2].setText(cur->data.courseName);

        studentTextBox[i][4].setText(cur->data.getTeacherName());
        studentTextBox[i][3].setText(std::to_string(cur->data.credits));
        studentTextBox[i][5].setText(cur->data.getSession());
        cur = cur->next;
    }
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
                studentChooseOption(window, studentuser, 0);
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentChooseOption(window, studentuser, 1);
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);

            //click logout button
            if (logoutbut.isClick(event)) {
                studentuser.~Student();
                chooseRole(window);
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
        window.draw(s_studentCourseTexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        cur_schoolyeartextbox.drawTextbox(window);
        cur_semestertextbox.drawTextbox(window);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++)
                studentTextBox[i][j].drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
    for (int i = 0; i < n; i++)
        delete[] studentTextBox[i];
    delete[] studentTextBox;

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
    semestertextbox.setTextPosition(sf::Vector2f(218, 700));


    //school year current textbox
    OutputTextBox cur_schoolyeartextbox(28, sf::Color::Black, schoolyear);
    cur_schoolyeartextbox.setfont(Palatino);
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(945, 168));

    //semester current textbox
    OutputTextBox cur_semestertextbox(28, sf::Color::Black, semester);
    cur_semestertextbox.setfont(Palatino);
    cur_semestertextbox.setTextPosition(sf::Vector2f(1322, 168));

    float Posx[7] = { 380,472,585,945,1110,1250,1390 };
    float Posy = 385;
    float Posylimabove = 200;
    float Posylimunder = 860;
    float jumpsize = 1000;
    int numberofbutton = 4;
    float distance = 60;

    //find how many course this student learn
    Semester curSemester(semester);
    curSemester.loadCourseListFromFileCourseList(schoolyear);
    Node<Course>* courseList = curSemester.courseList.head;
    Node<Course>* cur = curSemester.courseList.head;


    int n = 0;
    while (courseList) {
        courseList->data.loadStudentsFromCsvFileStaffUpload("Data/" + schoolyear + "/" + semester + "/scoreOfEachCourse/" + courseList->data.courseID + ".csv");

        if (courseList->data.findIfStudentIsInThisCourse(studentuser.studentID)) {
            n++;
        }
        courseList = courseList->next;
    }
    std::cout << n << std::endl;
    //find score
    TextBox** scoreboards = new TextBox * [n];
    Course::Student* scorestudent = new Course::Student[n];
    std::string* courseid = new std::string[n];
    std::string* coursename = new std::string[n];
    courseList = curSemester.courseList.head;

    n = 0;
    while (courseList) {
        if (courseList->data.findIfStudentIsInThisCourse(studentuser.studentID)) {
            courseList->data.loadScoreFromCsvScoresFile(schoolyear, semester);
            courseList->data.findAStudentOfThisCourse(studentuser.studentID, scorestudent[n]);
            courseid[n] = courseList->data.courseID;
            coursename[n] = courseList->data.courseName;
            n++;
        }
        courseList = courseList->next;
    }

    std::cout << scorestudent[0].getStudentID();
    for (int i = 0; i < n; i++) {
        scoreboards[i] = new TextBox[7];
        for (int j = 0; j < 7; j++) {
            scoreboards[i][j].setsize(17);
            scoreboards[i][j].setColor(sf::Color::Black);
            scoreboards[i][j].setfont(Palatino);
            scoreboards[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);
        }
        std::cout << courseid[i];
        scoreboards[i][0].setText(std::to_string(i + 1));
        scoreboards[i][1].setText(cur->data.courseID);
        scoreboards[i][2].setText(coursename[i]);
        scoreboards[i][3].setText(scorestudent[i].midScore);
        scoreboards[i][4].setText(scorestudent[i].finScore);
        scoreboards[i][5].setText(scorestudent[i].otherScore);
        scoreboards[i][6].setText(scorestudent[i].totalScore);
        cur = cur->next;
    }
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += std::stof(scorestudent[i].totalScore);
    }
    float semGPA = sum / n;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << semGPA;
    std::string seGPA = oss.str();
    OutputTextBox semesterGPA(25, sf::Color(119, 106, 92), seGPA);
    semesterGPA.setfont(Palatino);
    semesterGPA.setTextPosition(sf::Vector2f(1017, 250));
    //overall GPA
    OutputTextBox overallGPA(25, sf::Color(119, 106, 92), calculateOverall(studentuser.studentID));
    overallGPA.setfont(Palatino);
    overallGPA.setTextPosition(sf::Vector2f(1337, 250));


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
                studentChooseOption(window, studentuser, 0);
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentChooseOption(window, studentuser, 1);
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);
            //click logout button
            if (logoutbut.isClick(event)) {
                studentuser.~Student();
                chooseRole(window);
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
        window.draw(s_studentScoreboardTexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        cur_schoolyeartextbox.drawTextbox(window);
        cur_semestertextbox.drawTextbox(window);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 7; j++)
                scoreboards[i][j].drawTextbox(window);
        semesterGPA.drawTextbox(window);
        overallGPA.drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
    for (int i = 0; i < n; i++)
        delete[] scoreboards[i];
    delete[] scoreboards;
    delete[] scorestudent;
    delete[] courseid;
    delete[] coursename;
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
                studentChooseOption(window, studentuser, 0);
            if (studenthomebuttonlist.isClickedKOrder(event, 4))
                studentChooseOption(window, studentuser, 1);
            if (studenthomebuttonlist.isClickedKOrder(event, 5))
                studentAboutUs(window, studentuser);

            //click logout button
            if (logoutbut.isClick(event)) {
                studentuser.~Student();
                chooseRole(window);
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
        window.draw(s_studentAboutUsTexture);
        studenthomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }

}