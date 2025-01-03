

#include"displayfunction.h"
#include"filesystem"

void staffaddclasses( Staff& userstaff, std::string schoolyear) {
    sf::RenderWindow window(sf::VideoMode(1470, 950), "Login window", sf::Style::Close);
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
    //save and delete button
    Button savebut(sf::Color(186, 158, 146, 100), sf::Vector2f(133, 42), false);
    Button deletebut(sf::Color(186, 158, 146, 100), sf::Vector2f(133, 42), false);
    savebut.setposition(sf::Vector2f(182, 491));
    deletebut.setposition(sf::Vector2f(182, 537));

    //school year current textbox
    OutputTextBox cur_schoolyeartextbox(28, sf::Color::Black, schoolyear);
    cur_schoolyeartextbox.setfont(Palatino);
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(1110, 357));

    //list of class at current schoolyear
    userstaff.emptyclasseslist();
    int yearstart = stoi(schoolyear.substr(0, 4));
    int yearend = stoi(schoolyear.substr(5, schoolyear.size()));
    for (int i = 0; i < 4; i++)
        userstaff.readAllClassinSchoolYear(std::to_string(yearstart - i) + "-" + std::to_string(yearend - i));
    LinkedList<std::string> classestext = userstaff.getclassescode();
    dropdownlist classesbutton(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, classestext, 30, Palatino);
    classesbutton.setpostionlistbuttonwithlimit(475, 320, 0, 65, 310, 830, 500);

    TextBox addclasstxtbox(24, sf::Color::Black, false);
    addclasstxtbox.setfont(Palatino);
    addclasstxtbox.setTextPosition(sf::Vector2f(950, 515));


    //init newposy of list classes button
    float newposy = 320;

    //for scroll wheel
    const int maxbuttondisplay = 8;
    int numberofbutton = classestext.sizeoflist();
    float Posylimabove = 310.0f;
    float Posylimunder = 800.0f;
    float jumpdistance = 500.0f;

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
            if (logoutbut.isClick(event)) chooseRole(window);
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
            if (savebut.isonMousecursor(event)) {
                savebut.changecolor(sf::Color(186, 158, 146, 100));
            }
            else savebut.changecolor(sf::Color::Transparent);
            if (deletebut.isonMousecursor(event))
                deletebut.changecolor(sf::Color(186, 158, 146, 100));
            else
                deletebut.changecolor(sf::Color::Transparent);


            //click class button
            for (int i = 1; i <= classestext.sizeoflist(); i++) {
                if (classesbutton.isClickedKOrder(event, i)) {
                    staffmanageclass(window, userstaff, schoolyear, i);
                    break;
                }
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



            //wheel scrool
            if (event.type == event.MouseWheelScrolled and numberofbutton > maxbuttondisplay) {
                newposy = newposy + event.mouseWheelScroll.delta * 10.0f;
                if (classesbutton.getpositionofKbut(numberofbutton).y <= Posylimunder - 10) {

                    newposy = 275 - (numberofbutton - maxbuttondisplay - 1) * 65;

                }
                else if (classesbutton.getpositionofKbut(maxbuttondisplay).y >= Posylimunder - 10) {

                    newposy = 325;
                }
                classesbutton.setpostionlistbuttonwithlimit(475, newposy, 0, 65, Posylimabove, Posylimunder, jumpdistance);
            }

            //add class button is Press
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                int x_coor = event.mouseButton.x;
                int y_coor = event.mouseButton.y;
                std::cout << x_coor;
                if (x_coor > 1150 && x_coor < 1350 && y_coor>575 && y_coor < 615) {
                    if (userstaff.getmode()) {
                        std::string newschoolyeartext = addclasstxtbox.getText();
                        userstaff.addClassforNewSchoolYear(Class(newschoolyeartext));
                        LinkedList<std::string> classestext2 = userstaff.getclassescode();
                        userstaff.writeClasstoFile(schoolyear, classestext2);
                        window.close();
                        staffaddclasses( userstaff, schoolyear);
                    }
                    else announcement("this mode is not allow to add schoolyear!\nPlease move to edit mode");
                }
            }
        }
       

        window.clear();
        window.draw(s_Staffaddclasstexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        classesbutton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        cur_schoolyeartextbox.drawTextbox(window);
        addclasstxtbox.drawTextbox(window);
        deletebut.drawbutton(window);
        savebut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
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

    //save and delete button
    Button savebut(sf::Color(186, 158, 146, 100), sf::Vector2f(133, 42), false);
    Button deletebut(sf::Color(186, 158, 146, 100), sf::Vector2f(133, 42), false);
    savebut.setposition(sf::Vector2f(182, 491));
    deletebut.setposition(sf::Vector2f(182, 537));

    //list of class at current schoolyear

    int yearstart = stoi(schoolyear.substr(0, 4));
    int yearend = stoi(schoolyear.substr(5, schoolyear.size()));
    for (int i = 0; i < 4; i++)
        userstaff.readAllClassinSchoolYear(std::to_string(yearstart - i) + "-" + std::to_string(yearend - i));
    LinkedList<std::string> classestext = userstaff.getclassescode();
    dropdownlist classesbutton(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, classestext, 30, Palatino);
    classesbutton.setpostionlistbuttonwithlimit(475, 320, 0, 65, 310, 830, 500);

    sf::Vector2f Posofclasschosen = classesbutton.getpositionofKbut(Korderbut);
    std::string textofbutton = classesbutton.getKoderButtonText(Korderbut);
    Button classchosenbutton(sf::Color(192, 200, 184), sf::Vector2f(300, 50), false, sf::Color::Black, textofbutton, 30, Palatino);//Nen lay mau gi??
    classchosenbutton.setposition(sf::Vector2f(Posofclasschosen.x, Posofclasschosen.y));

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

    //init newposy of list classes button and class button chosen
    float newposy = 320;
    float newposyofclasschosen = Posofclasschosen.y;
    if (Korderbut > limitnumsofbutton)  newposyofclasschosen = newposyofclasschosen - 500.f;


    //for scroll wheel
    const int maxbuttondisplay = 8;
    int numberofbutton = classestext.sizeoflist();
    float Posylimabove = 310.0f;
    float Posylimunder = 800.0f;
    float jumpdistance = 500.0f;
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
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffSemesterLobby(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff, getCurrentSchoolyear(), getCurrentSemester());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                window.close();
                staffaddclasses(userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5)) {
                window.close();
                staffaboutUs(userstaff);
            }

            //click class button
            for (int i = 1; i <= classestext.sizeoflist(); i++) {
                if (classchosenbutton.isClick(event)) {
                    window.close();
                    staffaddclasses(userstaff, schoolyear);
                }
                if (classesbutton.isClickedKOrder(event, i)) {
                    classesbutton.~dropdownlist();
                    staffhomebuttonlist.~dropdownlist();
                    textstaffhomebutton.~LinkedList();
                    classestext.~LinkedList();
                    staffmanageclass(window, userstaff, schoolyear, i);
                    break;
                }

            }



            //wheel scrool
            if (event.type == event.MouseWheelScrolled and numberofbutton > maxbuttondisplay) {

                newposy = newposy + event.mouseWheelScroll.delta * 10.0f;
                newposyofclasschosen = newposyofclasschosen + event.mouseWheelScroll.delta * 10.0f;

                if (classesbutton.getpositionofKbut(numberofbutton).y <= Posylimunder - 10) {
                    newposy = 275 - (numberofbutton - maxbuttondisplay - 1) * 65;
                    newposyofclasschosen = classesbutton.getpositionofKbut(Korderbut).y + 10.f;
                }
                else if (classesbutton.getpositionofKbut(maxbuttondisplay).y >= Posylimunder - 10) {
                    newposy = 325;
                    newposyofclasschosen = classesbutton.getpositionofKbut(Korderbut).y - 10.f;
                }

                classesbutton.setpostionlistbuttonwithlimit(475, newposy, 0, 65, Posylimabove, Posylimunder, jumpdistance);
                classchosenbutton.setpositiontwithbuttonlimit(Posofclasschosen.x, newposyofclasschosen, Posylimabove, Posylimunder, jumpdistance);
            }

            //click logout button
            if (logoutbut.isClick(event)) chooseRole(window);

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
            if (savebut.isonMousecursor(event)) {
                savebut.changecolor(sf::Color(186, 158, 146, 100));
            }
            else savebut.changecolor(sf::Color::Transparent);
            if (deletebut.isonMousecursor(event))
                deletebut.changecolor(sf::Color(186, 158, 146, 100));
            else
                deletebut.changecolor(sf::Color::Transparent);


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
                    if (x_coor > 929 and x_coor < 1396.5 and y_coor >381 and y_coor < 486.4) {
                        staffviewstudentinclass(window, userstaff, schoolyear, textofbutton);
                    }
                    if (x_coor > 929 and x_coor < 1396.5 and y_coor >537.4 and y_coor < 642.8) {
                        staffaddfirstyearstudent(window, userstaff, schoolyear, textofbutton);
                    }
                    if (x_coor > 929 and x_coor < 1396.5 and y_coor >694 and y_coor < 799.4) {
                        staffChooseOption(window, userstaff, textofbutton);
                    }
                }
            }
            if (userstaff.getmode() and deletebut.isClick(event)) {
                std::string classdelete = classchosenbutton.getText();
                userstaff.deleteClass(Class(classdelete));
                LinkedList<std::string> classestext2 = userstaff.getclassescode();
                userstaff.writeClasstoFile(schoolyear, classestext2);
                std::filesystem::remove("Data/" + schoolyear + "/" + classdelete + ".csv");
                if (Korderbut > classestext2.sizeoflist()) Korderbut = Korderbut - 1;
                staffmanageclass(window, userstaff, schoolyear, Korderbut);
            }
        }

        window.clear();
        window.draw(s_Coursetexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        classesbutton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        classchosenbutton.drawbutton(window);
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        deletebut.drawbutton(window);
        savebut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
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

    //class current textbox
    OutputTextBox cur_classtextbox(28, sf::Color::Black, addtoclass);
    cur_classtextbox.setfont(Palatino);
    cur_classtextbox.setTextPosition(sf::Vector2f(1090.f, 216.f));

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
    gender.setTextPosition(sf::Vector2f(1085, 365));

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
                        window.close();
                        staffHome(userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                        break;
                    }
                    if (x_coor > 1240 && x_coor < 1353 && y_coor>218 && y_coor < 251) {
                        staffviewstudentinclass(window, userstaff, schoolyear, addtoclass);
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
                        socialID = addSocialID.getText();
                        std::string dayofbirth = adddayofbirth.getText();
                        if (studentID == "" || name.firstName == "" && name.lastName == "" || socialID == "" || dayofbirth.size() != 10) {
                            announcement("Leave data blank or wrong date format!\nPlease enter all student data\nor enter correct date format dd/mm/yyyy!");
                        }
                        else {
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
                            curclass.addStudent(Student(studentID, name, studentGender, birthDay, socialID));
                            curclass.saveStudent(schoolyear, addtoclass);
                            addStudentID.setText("");
                            addSocialID.setText("");
                            adddayofbirth.setText("");
                            addFirstname.setText("");
                            addLastname.setText("");
                            gender.setTextPosition(sf::Vector2f(1085, 365));
                            studentGender = 0;
                        }
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
                if (filename != "") {
                    curclass.loadStudentfromCSV(filename);
                    curclass.saveStudent(schoolyear, addtoclass);
                }
            }
            else importbut.setisClicked(false);
        }


        window.clear();
        window.draw(s_add1styearstudenttexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        cur_classtextbox.drawTextbox(window);
        addStudentID.drawTextbox(window);
        addFirstname.drawTextbox(window);
        addLastname.drawTextbox(window);
        gender.drawTextbox(window);
        adddayofbirth.drawTextbox(window);
        addSocialID.drawTextbox(window);
        importbut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
}

std::string filenametoimport() {
    sf::RenderWindow window(sf::VideoMode(800, 300), "Enter Filename", sf::Style::Close);
    sf::Texture enterFilenameTexture;
    enterFilenameTexture.loadFromFile("Design UI/Enter filename.png");
    enterFilenameTexture.setSmooth(true);
    sf::Sprite s_enterFilenameTexture;
    s_enterFilenameTexture.setTexture(enterFilenameTexture);
    sf::Font Palatino;
    Palatino.loadFromFile("Font/Palatino.ttf");

    TextBox enterfile(24, sf::Color::Black, false);
    enterfile.setfont(Palatino);
    enterfile.setTextPosition(sf::Vector2f(120, 220));

    Button enterbut(sf::Color::Transparent, sf::Vector2f(306, 46), false, sf::Color::Transparent, "", 28, Palatino);
    enterbut.setposition(sf::Vector2f(458, 54));

    Button cancelbut(sf::Color::Transparent, sf::Vector2f(306, 46), false, sf::Color::Transparent, "", 28, Palatino);
    cancelbut.setposition(sf::Vector2f(458, 120));

    std::string filename = "";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (enterfile.isClick(event, 103, 208, 764, 259)) {
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
            if (enterbut.isClick(event)) {
                filename = enterfile.getText();
                window.close();
            }
            if (cancelbut.isClick(event)) {
                window.close();
            }
        }
        window.clear();
        window.draw(s_enterFilenameTexture);
        enterfile.drawTextbox(window);
        enterbut.drawbutton(window);
        window.display();
    }
    return filename;
}

void staffviewstudentinclass(sf::RenderWindow& window, Staff& userstaff, std::string schoolyearchoose, std::string classchosen) {
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

    //navigation bar current textbox
    OutputTextBox schoolyeartextbox(22, sf::Color(119, 106, 92), getCurrentSchoolyear());
    schoolyeartextbox.setfont(Palatino);
    schoolyeartextbox.setTextPosition(sf::Vector2f(181, 667));

    OutputTextBox semestertextbox(22, sf::Color(119, 106, 92), getCurrentSemester());
    semestertextbox.setfont(Palatino);
    semestertextbox.setTextPosition(sf::Vector2f(218, 702));

    //class current textbox
    OutputTextBox cur_classtextbox(28, sf::Color::Black, classchosen);
    cur_classtextbox.setfont(Palatino);
    cur_classtextbox.setTextPosition(sf::Vector2f(1120.f, 216.f));


    //log out button
    Button logoutbut(sf::Color(192, 200, 184), sf::Vector2f(90, 30), false, sf::Color::Black, "Log out", 20, Palatino);
    logoutbut.setposition(sf::Vector2f(227, 895));

    //mode button
    Button editmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "EDIT", 20, Palatino);
    editmode.setposition(sf::Vector2f(46, 491));
    Button viewmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "VIEW", 20, Palatino);
    viewmode.setposition(sf::Vector2f(46, 538));

    //save and delete button
    Button savebut(sf::Color(186, 158, 146, 100), sf::Vector2f(133, 42), false);
    Button deletebut(sf::Color(186, 158, 146, 100), sf::Vector2f(133, 42), false);
    savebut.setposition(sf::Vector2f(182, 491));
    deletebut.setposition(sf::Vector2f(182, 537));



    //list of student

    Class curclass(classchosen);
    int kyear = std::stoi(classchosen.substr(0, 2));
    std::string schoolyear = "20" +std::to_string(kyear) + "-20" + std::to_string(kyear+1);
    curclass.loadStudentfromCSV("Data/" + schoolyear + "/" + classchosen + ".csv");
    curclass.saveStudent(schoolyearchoose, classchosen);
    int n = curclass.getnumberofstudentinclass();
    //LinkedList<Student> studentlist = curclass.getstudentlist();
    //Node<Student>* head = curclass.getstudentnode();
    Node<Student>* cur = curclass.studentList.head;


    TextBox** studentTextBox = new TextBox * [n];

    float Posx[6] = { 355,410,575,870,965,1200 };
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
            studentTextBox[i][j].setsize(24);
            studentTextBox[i][j].setColor(sf::Color::Black);
            studentTextBox[i][j].setselected(false);
            studentTextBox[i][j].setfont(Palatino);
            studentTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);
        }

        studentTextBox[i][0].setText(std::to_string(i + 1)); // Assuming you want to set index 0 to an index value
        studentTextBox[i][1].setText(cur->data.studentID);
        studentTextBox[i][2].setText(cur->data.name.lastName + "-" + cur->data.name.firstName);

        if (cur->data.studentGender == 0)
            studentTextBox[i][3].setText("X");
        else
            studentTextBox[i][3].setText("O");
        studentTextBox[i][4].setText(std::to_string(cur->data.birthDay.day) + "/" + std::to_string(cur->data.birthDay.month) + "/" + std::to_string(cur->data.birthDay.year));
        studentTextBox[i][5].setText(cur->data.socialID);
        cur = cur->next;
    }

    //button of list student
    dropdownlist StudentsButton(sf::Color::Transparent, sf::Vector2f(1090, 40), false, n);
    StudentsButton.setpostionlistbuttonwithlimit(Posx[0], Posy - 5, 0, distance, Posylimabove, Posylimunder, jumpsize);
    int kbuttonchose = -1;
    Button studentchosen(sf::Color::Transparent, sf::Vector2f(1096, 40), false);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                userstaff.~Staff();
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        window.close();
                        staffHome( userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                        break;
                    }
                    if (x_coor > 390 && x_coor < 640 && y_coor>867 && y_coor < 917) {
                        if (schoolyear == getCurrentSchoolyear())
                            staffaddfirstyearstudent(window, userstaff, schoolyear, classchosen);
                        else announcement("This class is not first year class\nso it's not allowed to add students ");
                    }

                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1)) {
                window.close();
                staffmanageschoolyeardisplay(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                window.close();
                staffSemesterLobby(userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                window.close();
                staffmanagecourse(userstaff, getCurrentSchoolyear(), getCurrentSemester());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                window.close();
                staffaddclasses(userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5)) {
                window.close();
                staffaboutUs(userstaff);
            }


            //click logout button
            if (logoutbut.isClick(event)) {
                userstaff.~Staff();
                chooseRole(window);
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
                if (savebut.isonMousecursor(event)) {
                    savebut.changecolor(sf::Color(186, 158, 146, 100));
                }
                else savebut.changecolor(sf::Color::Transparent);
                if (deletebut.isonMousecursor(event))
                    deletebut.changecolor(sf::Color(186, 158, 146, 100));
                else
                    deletebut.changecolor(sf::Color::Transparent);

            if (event.type == event.MouseWheelScrolled and n > numberofbutton) {
                Posy = Posy + event.mouseWheelScroll.delta * 10.0f;
                if (studentTextBox[n - 1][0].getPositionofTextbox().y <= Posylimunder - 10) {
                    std::cout << studentTextBox[n - 1][0].getPositionofTextbox().y;
                    std::cout << Posy;
                    Posy = 325 - (n - numberofbutton - 1) * distance;
                }
                else if (studentTextBox[numberofbutton - 1][0].getPositionofTextbox().y >= Posylimunder) {

                    std::cout << Posy;
                    Posy = 388;

                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        studentTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);

                    }
                }
                StudentsButton.setpostionlistbuttonwithlimit(Posx[0], Posy - 5, 0, distance, Posylimabove, Posylimunder, jumpsize);
                studentchosen.setButposition(StudentsButton.getpositionofKbut(kbuttonchose + 1));
            }
            //init node tmp for change data;
            Node<Student>* tmp = curclass.studentList.head;
            for (int i = 0; i < n; i++)
            {
                if (StudentsButton.isClickedKOrder(event, i + 1)) {
                    studentchosen.setButposition(StudentsButton.getpositionofKbut(i + 1));
                    studentchosen.changecolor(sf::Color(186, 158, 146, 100));
                    kbuttonchose = i;
                }
                if (userstaff.getmode()) {
                    for (int j = 0; j < 6; j++)
                    {
                        if (studentTextBox[i][j].isClickwithoutPosagrument(event)) {
                            studentTextBox[i][j].setselected(true);
                            setnotseleted(studentTextBox, n, i, j,6);
                        }
                        if (event.type == sf::Event::TextEntered) {
                            if (studentTextBox[i][j].isselectedbox()) {
                                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                                    studentTextBox[i][j].setselected(false);
                                else
                                    studentTextBox[i][j].typedText(event);
                            }
                        }

                    }
                    //savebuttonclick
                    if (tmp) {
                        tmp->data.studentID = studentTextBox[i][1].getText();
                        std::string fullname = studentTextBox[i][2].getText();
                        std::string dob = studentTextBox[i][4].getText();
                        if (studentTextBox[i][3].getText() == "X") tmp->data.studentGender = 0;
                        else tmp->data.studentGender = 1;
                        int found = fullname.find("-");
                        int foundday = dob.find("/");
                        int foundmonth = -1;
                        if (foundday > 0)  foundmonth = dob.find("/", foundday + 1);
                        if (found > 0 and foundday > 0 and foundmonth > 0) {
                            tmp->data.name.lastName = fullname.substr(0, found);
                            tmp->data.name.firstName = fullname.substr(found + 1, fullname.size());
                            tmp->data.birthDay.day = std::stoi(dob.substr(0, foundday));
                            if (foundday < foundmonth)
                                tmp->data.birthDay.month = std::stoi(dob.substr(foundday + 1, foundmonth));
                            if (foundmonth + 1 < dob.size())
                                tmp->data.birthDay.year = std::stoi(dob.substr(foundmonth + 1, dob.size()));
                            tmp->data.socialID = studentTextBox[i][5].getText();

                        }
                        tmp = tmp->next;
                    }




                    //deletebutton
                    if (deletebut.isClick(event) and kbuttonchose != -1) {
                        Student studentdeleted;
                        studentdeleted.studentID = studentTextBox[kbuttonchose][1].getText();
                        std::string fullname = studentTextBox[kbuttonchose][2].getText();
                        int found = fullname.find("-");
                        //std::cout << found;
                        if (found != 0) {
                            studentdeleted.name.lastName = fullname.substr(0, found);
                            // std::cout << studentdeleted.name.lastName;
                            studentdeleted.name.firstName = fullname.substr(found + 1, fullname.size());
                            //std::cout << studentdeleted.name.firstName;
                        }
                        if (studentTextBox[kbuttonchose][3].getText() == "X") studentdeleted.studentGender = 0;
                        else studentdeleted.studentGender = 1;
                        std::string dob = studentTextBox[kbuttonchose][4].getText();
                        int foundday = dob.find("/");
                       
                        int foundmonth = -1;
                        if (foundday > 0)  foundmonth = dob.find("/", foundday + 1);
                        
                        if (found > 0 and foundday > 0 and foundmonth > 0) {
                            studentdeleted.birthDay.day = std::stoi(dob.substr(0, foundday));
                            if (foundday < foundmonth)
                                studentdeleted.birthDay.month = std::stoi(dob.substr(foundday + 1, foundmonth));
                            if (foundmonth + 1 < dob.size())
                                studentdeleted.birthDay.year = std::stoi(dob.substr(foundmonth + 1, dob.size()));
                        }
                            studentdeleted.socialID = studentTextBox[kbuttonchose][5].getText();
                            curclass.removeStudent(studentdeleted);
                            curclass.saveStudent(schoolyear, classchosen);
                        staffviewstudentinclass(window, userstaff, schoolyear, classchosen);
                        break;
                    }
                }

            }
            if (savebut.isClick(event)) {
                //curclass.savechangestudentsdata();
                curclass.saveStudent(schoolyear, classchosen);
                staffviewstudentinclass(window, userstaff, schoolyear, classchosen);
                break;
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
        cur_classtextbox.drawTextbox(window);
        deletebut.drawbutton(window);
        savebut.drawbutton(window);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++)
                studentTextBox[i][j].drawTextbox(window);
        StudentsButton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146, 100));
        studentchosen.drawbutton(window);
        window.display();

    }
    for (int i = 0; i < n; i++)
        delete[] studentTextBox[i];
    delete[] studentTextBox;
}


void staffChooseOption(sf::RenderWindow& window, Staff& userstaff, std::string classchosen) {

    ///////////////////////////////////CODE HERE
    sf::Texture staffChooseOptionTexture;
    staffChooseOptionTexture.loadFromFile("Design UI/[Staff - 8] choosing to view scoreboard.jpg");
    staffChooseOptionTexture.setSmooth(true);
    sf::Sprite s_staffChooseOptionTexture;
    s_staffChooseOptionTexture.setTexture(staffChooseOptionTexture);
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



    ////////??????/////CODE HERE TIM SCHOOLYEAR CO CLASS

    userstaff.readAllSchoolyear();
    LinkedList<std::string> schoolyearstext = userstaff.getschoolyearstext();
    dropdownlist schoolyears(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, schoolyearstext, 30, Palatino);
    schoolyears.setpostionlistbuttonwithlimit(475, 320, 0, 65, 310, 830, 500);


    //init newposy of list school years button
    float newposy = 320;

    //for scroll wheel
    const int maxbuttondisplay = 8;
    int numberofbutton = schoolyearstext.sizeoflist();

    float Posylimabove = 310.0f;
    float Posylimunder = 800.0f;
    float jumpdistance = 500.0f;

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
                        window.close();
                        staffHome( userstaff);
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
                userstaff.~Staff();
                chooseRole(window);
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



            //list of year button
            for (int i = 1; i <= schoolyearstext.sizeoflist(); i++) {
                if (schoolyears.isClickedKOrder(event, i))
                {
                    staffChooseOption2(window, userstaff, classchosen, i);
                    break;
                }
            }


            //wheel scrool
            if (event.type == event.MouseWheelScrolled and numberofbutton > maxbuttondisplay) {
                newposy = newposy + event.mouseWheelScroll.delta * 10.0f;
                if (schoolyears.getpositionofKbut(numberofbutton).y <= Posylimunder - 10) {
                    newposy = 275 - (numberofbutton - maxbuttondisplay - 1) * 65;
                }
                else if (schoolyears.getpositionofKbut(maxbuttondisplay).y >= Posylimunder - 10) {
                    newposy = 325;
                }
                schoolyears.setpostionlistbuttonwithlimit(475, newposy, 0, 65, Posylimabove, Posylimunder, jumpdistance);
            }

        }


        window.clear();
        window.draw(s_staffChooseOptionTexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        schoolyears.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }

}


void staffChooseOption2(sf::RenderWindow& window, Staff& userstaff, std::string classchosen, int Korderofbut) {
    const int limitnumsofbutton = 8;//limit of number of button that display wiht schoolyear 
    sf::Texture staffChooseOption2texture;
    staffChooseOption2texture.loadFromFile("Design UI/[Staff - 8] choosing to view scoreboard.jpg");
    staffChooseOption2texture.setSmooth(true);
    sf::Sprite s_staffChooseOption2texture;
    s_staffChooseOption2texture.setTexture(staffChooseOption2texture);
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

    //userstaff.readAllSchoolyear();
    LinkedList<std::string> schoolyearstext = userstaff.getschoolyearstext();
    dropdownlist schoolyears(sf::Color(168, 158, 146), sf::Vector2f(300, 50), false, sf::Color::Black, schoolyearstext, 30, Palatino);
    schoolyears.setpostionlistbuttonwithlimit(475, 320, 0, 65, 310, 830, 500);

    sf::Vector2f Posofschoolyearclicked = schoolyears.getpositionofKbut(Korderofbut);
    std::cout << Korderofbut;
    std::string textofbutton = schoolyears.getKoderButtonText(Korderofbut);
    std::cout << textofbutton;

    Button schoolyearclickbutton(sf::Color(192, 200, 184), sf::Vector2f(300, 50), false, sf::Color::Black, textofbutton, 30, Palatino);//Nen lay mau gi??
    schoolyearclickbutton.setposition(sf::Vector2f(Posofschoolyearclicked.x, Posofschoolyearclicked.y));



    ////////CODE HERE TIM CAC SEMESTER TRONG SCHOOLYEAR
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

    //init newposy of list school years button
    float newposy = 320;
    float newposyofschoolyearclicked = Posofschoolyearclicked.y;
    if (Korderofbut > limitnumsofbutton)  newposyofschoolyearclicked = newposyofschoolyearclicked - 500.f;


    //for scroll wheel
    const int maxbuttondisplay = 8;
    int numberofbutton = schoolyearstext.sizeoflist();
    float Posylimabove = 310.0f;
    float Posylimunder = 800.0f;
    float jumpdistance = 500.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
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
                userstaff.~Staff();
                chooseRole(window);
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

            //list of year button
            for (int i = 1; i <= schoolyearstext.sizeoflist(); i++) {
                if (schoolyearclickbutton.isClick(event)) {
                    staffhomebuttonlist.~dropdownlist();
                    textstaffhomebutton.~LinkedList();
                    staffChooseOption(window, userstaff, classchosen);
                    break;
                }
                if (schoolyears.isClickedKOrder(event, i)) {
                    staffhomebuttonlist.~dropdownlist();
                    textstaffhomebutton.~LinkedList();
                    staffChooseOption2(window, userstaff, classchosen, i);
                    break;
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
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        window.close();
                        staffHome( userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                        break;
                    }
                    if (numbersemester > 0 and x_coor > 910 and x_coor < 1385 and y_coor >545 and y_coor < 645) {
                        //staffscoreboard    /////////////////////////////// 
                        staffViewStudentScoreboard(window, userstaff, classchosen, textofbutton, std::to_string(numbersemester));
                        break;
                    }
                }
            }

            //wheel scrool
            if (event.type == event.MouseWheelScrolled and numberofbutton > maxbuttondisplay) {

                newposy = newposy + event.mouseWheelScroll.delta * 10.0f;
                newposyofschoolyearclicked = newposyofschoolyearclicked + event.mouseWheelScroll.delta * 10.0f;

                if (schoolyears.getpositionofKbut(numberofbutton).y <= Posylimunder - 10) {
                    newposy = 275 - (numberofbutton - maxbuttondisplay - 1) * 65;
                    newposyofschoolyearclicked = schoolyears.getpositionofKbut(Korderofbut).y + 10.f;
                }
                else if (schoolyears.getpositionofKbut(maxbuttondisplay).y >= Posylimunder - 10) {
                    newposy = 325;
                    newposyofschoolyearclicked = schoolyears.getpositionofKbut(Korderofbut).y - 10.f;
                }

                schoolyears.setpostionlistbuttonwithlimit(475, newposy, 0, 65, Posylimabove, Posylimunder, jumpdistance);
                schoolyearclickbutton.setpositiontwithbuttonlimit(Posofschoolyearclicked.x, newposyofschoolyearclicked, Posylimabove, Posylimunder, jumpdistance);
            }


        }

        window.clear();
        window.draw(s_staffChooseOption2texture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        schoolyears.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        schoolyearclickbutton.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        for (int i = 0; i < n; i++)
            semesterbut[i].drawbutton(window);
        semesterbutchosen.drawbutton(window);
        window.display();
    }
    delete[] semesterbut;
}


void staffViewStudentScoreboard(sf::RenderWindow& window, Staff& userstaff, std::string classchosen, std::string schoolyear, std::string semeseter) {
    sf::Texture staffclassscoreboard;
    staffclassscoreboard.loadFromFile("Design UI/[Staff -8] View Scoreboard.jpg");
    staffclassscoreboard.setSmooth(true);
    sf::Sprite s_staffclassscoreboard;
    s_staffclassscoreboard.setTexture(staffclassscoreboard);
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

    // textbox title

    OutputTextBox classtilte(26, sf::Color::Black, classchosen);
    classtilte.setfont(Palatino);
    classtilte.setTextPosition(sf::Vector2f(900, 215));
    OutputTextBox schoolyeartilte(22, sf::Color::Black, schoolyear);
    schoolyeartilte.setfont(Palatino);
    schoolyeartilte.setTextPosition(sf::Vector2f(1240, 200));

    OutputTextBox semestertilte(22, sf::Color::Black, semeseter);
    semestertilte.setfont(Palatino);
    semestertilte.setTextPosition(sf::Vector2f(1280, 232));

    //list of student

    Class curclass(classchosen);
  
    curclass.loadStudentfromCSV("Data/" + schoolyear + "/" + classchosen + ".csv");
    int n = curclass.getnumberofstudentinclass();
    Node<Student>* cur = curclass.studentList.head;


    TextBox** studentTextBox = new TextBox * [n];

    float Posx[6] = { 378,431,600,900,1008,1223 };
    float Posy = 385;
    float distance = 60;
    float Posylimabove = 365;
    float Posylimunder = 580;
    float jumpsize = 1000;
    int numberofbutton = 4;
    for (int i = 0; i < n; i++)
    {
        studentTextBox[i] = new TextBox[6];
        for (int j = 0; j < 6; j++)
        {
            studentTextBox[i][j].setsize(24);
            studentTextBox[i][j].setColor(sf::Color::Black);
            studentTextBox[i][j].setselected(false);
            studentTextBox[i][j].setfont(Palatino);
            studentTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);
        }

        studentTextBox[i][0].setText(std::to_string(i + 1)); // Assuming you want to set index 0 to an index value
        studentTextBox[i][1].setText(cur->data.studentID);
        studentTextBox[i][2].setText(cur->data.name.lastName + "-" + cur->data.name.firstName);

        if (cur->data.studentGender == 0)
            studentTextBox[i][3].setText("X");
        else
            studentTextBox[i][3].setText("");
        studentTextBox[i][4].setText(std::to_string(cur->data.birthDay.day) + "/" + std::to_string(cur->data.birthDay.month) + "/" + std::to_string(cur->data.birthDay.year));
        studentTextBox[i][5].setText(cur->data.socialID);
        cur = cur->next;
    }

    //button of list student
    dropdownlist StudentsButton(sf::Color::Transparent, sf::Vector2f(1090, 40), false, n);
    StudentsButton.setpostionlistbuttonwithlimit(Posx[0], Posy - 5, 0, distance, Posylimabove, Posylimunder, jumpsize);
    Button studentchosen(sf::Color::Transparent, sf::Vector2f(1096, 40), false);
    int kstudentchosen=-1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                userstaff.~Staff();
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        window.close();
                        staffHome( userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                    }
                    if (x_coor > 1380 && x_coor < 1427 && y_coor>212 && y_coor < 259) {
                        staffChooseOption(window, userstaff, classchosen);
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


            if (event.type == event.MouseWheelScrolled) {
                int y_coor = event.mouseWheelScroll.y;
                if (y_coor > Posylimabove - 5 and y_coor < Posylimunder + 20 and n > numberofbutton) {
                    Posy = Posy + event.mouseWheelScroll.delta * 10.0f;
                    if (studentTextBox[n - 1][0].getPositionofTextbox().y <= Posylimunder - 10) {
                        std::cout << studentTextBox[n - 1][0].getPositionofTextbox().y;
                        std::cout << Posy;
                        Posy = 335 - (n - numberofbutton - 1) * distance;
                    }
                    else if (studentTextBox[numberofbutton - 1][0].getPositionofTextbox().y >= Posylimunder) {

                        std::cout << Posy;
                        Posy = 388;

                    }
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            studentTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);

                        }
                    }
                    StudentsButton.setpostionlistbuttonwithlimit(Posx[0], Posy - 5, 0, distance, Posylimabove, Posylimunder, jumpsize);
                    if(kstudentchosen>0) studentchosen.setButposition(StudentsButton.getpositionofKbut(kstudentchosen + 1));
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (StudentsButton.isClickedKOrder(event, i + 1)) {
                    kstudentchosen = i;
                    studentchosen.changecolor(sf::Color(186, 158, 146, 100));
                    studentchosen.setButposition(StudentsButton.getpositionofKbut(kstudentchosen + 1));
                    Semester cursemester(semeseter);
                    cursemester.loadCourseListFromFileCourseList(schoolyear);
                    if (cursemester.courseList.sizeoflist() > 0) {
                        staffViewStudentScoreboard2(window, userstaff, classchosen, schoolyear, semeseter, kstudentchosen);
                        break;
                    }
                }
            }
        }

        window.clear();
        window.draw(s_staffclassscoreboard);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        logoutbut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        classtilte.drawTextbox(window);
        semestertilte.drawTextbox(window);
        schoolyeartilte.drawTextbox(window);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++)
                studentTextBox[i][j].drawTextbox(window);
        StudentsButton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146, 100));
        studentchosen.drawbutton(window);
        window.display();
    }
    for (int i = 0; i < n; i++)
        delete[] studentTextBox[i];
    delete[] studentTextBox;
}

void staffViewStudentScoreboard2(sf::RenderWindow& window, Staff& userstaff, std::string classchosen, std::string schoolyear, std::string semeseter, int kstudentchosen) {
    sf::Texture staffclassscoreboard;
    staffclassscoreboard.loadFromFile("Design UI/[Staff -8] View Scoreboard.jpg");
    staffclassscoreboard.setSmooth(true);
    sf::Sprite s_staffclassscoreboard;
    s_staffclassscoreboard.setTexture(staffclassscoreboard);
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

    //save and delete button
    Button savebut(sf::Color(186, 158, 146, 100), sf::Vector2f(133, 42), false);
    Button deletebut(sf::Color(186, 158, 146, 100), sf::Vector2f(133, 42), false);
    savebut.setposition(sf::Vector2f(182, 491));
    deletebut.setposition(sf::Vector2f(182, 537));

    viewmode.setposition(sf::Vector2f(46, 538));

    // textbox title

    OutputTextBox classtilte(26, sf::Color::Black, classchosen);
    classtilte.setfont(Palatino);
    classtilte.setTextPosition(sf::Vector2f(900, 215));
    OutputTextBox schoolyeartilte(22, sf::Color::Black, schoolyear);
    schoolyeartilte.setfont(Palatino);
    schoolyeartilte.setTextPosition(sf::Vector2f(1240, 200));

    OutputTextBox semestertilte(22, sf::Color::Black, semeseter);
    semestertilte.setfont(Palatino);
    semestertilte.setTextPosition(sf::Vector2f(1280, 232));

    //list of student

    Class curclass(classchosen);

    curclass.loadStudentfromCSV("Data/" + schoolyear + "/" + classchosen + ".csv");
    int n = curclass.getnumberofstudentinclass();
    Node<Student>* cur = curclass.studentList.head;


    TextBox** studentTextBox = new TextBox * [n];

    float Posx[6] = { 378,431,600,900,1008,1223 };
    float Posy = 385;
    float distance = 60;
    float Posylimabove = 365;
    float Posylimunder = 580;
    float jumpsize = 1000;
    int numberofbutton = 4;
    for (int i = 0; i < n; i++)
    {
        studentTextBox[i] = new TextBox[6];
        for (int j = 0; j < 6; j++)
        {
            studentTextBox[i][j].setsize(24);
            studentTextBox[i][j].setColor(sf::Color::Black);
            studentTextBox[i][j].setselected(false);
            studentTextBox[i][j].setfont(Palatino);
            studentTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);
        }

        studentTextBox[i][0].setText(std::to_string(i + 1)); // Assuming you want to set index 0 to an index value
        studentTextBox[i][1].setText(cur->data.studentID);
        studentTextBox[i][2].setText(cur->data.name.lastName + "-" + cur->data.name.firstName);

        if (cur->data.studentGender == 0)
            studentTextBox[i][3].setText("X");
        else
            studentTextBox[i][3].setText("");
        studentTextBox[i][4].setText(std::to_string(cur->data.birthDay.day) + "/" + std::to_string(cur->data.birthDay.month) + "/" + std::to_string(cur->data.birthDay.year));
        studentTextBox[i][5].setText(cur->data.socialID);
        cur = cur->next;
    }

    //button of list student
    dropdownlist StudentsButton(sf::Color::Transparent, sf::Vector2f(1090, 40), false, n);
    StudentsButton.setpostionlistbuttonwithlimit(Posx[0], Posy - 5, 0, distance, Posylimabove, Posylimunder, jumpsize);
    Button studentchosen(sf::Color::Transparent, sf::Vector2f(1096, 40), false);
    studentchosen.changecolor(sf::Color(186, 158, 146, 100));
    studentchosen.setButposition(StudentsButton.getpositionofKbut(kstudentchosen + 1));
    //scoreboard
    Semester cursemester(semeseter);
    cursemester.loadCourseListFromFileCourseList(schoolyear);
    Node<Course>* curcourselist = cursemester.courseList.head;
    int numbercousestudy = 0;
    Course::Student stu;
    while (curcourselist) {
        curcourselist->data.loadScoreFromCsvScoresFile(schoolyear, semeseter);
        if (curcourselist->data.findIfStudentIsInThisCourse(studentTextBox[kstudentchosen][1].getText()) and curcourselist->data.findAStudentOfThisCourse(studentTextBox[kstudentchosen][1].getText(), stu)) {
            numbercousestudy++;
        }
        curcourselist = curcourselist->next;
    }
    std::cout << "/" << numbercousestudy << "/";
    Course::Student* scorestudent = new Course::Student[numbercousestudy];
    std::string* courseid = new std::string[numbercousestudy];
    std::string* coursename = new std::string[numbercousestudy];
    Node<Course>* cur2courselist = cursemester.courseList.head;
 
    numbercousestudy = 0;
    while (cur2courselist) {
        if (cur2courselist->data.findIfStudentIsInThisCourse(studentTextBox[kstudentchosen][1].getText()))
        {
            if(cur2courselist->data.findAStudentOfThisCourse(studentTextBox[kstudentchosen][1].getText(), scorestudent[numbercousestudy])){
            courseid[numbercousestudy] = cur2courselist->data.getCourseID();
            coursename[numbercousestudy] = cur2courselist->data.getCourseName();
            numbercousestudy++;
            }
        }
        cur2courselist = cur2courselist->next;
    }





    //for draw and position
    float Posx2[7] = { 373,416,561,993,1130,1255,1380 };
    float Posy2 = 685;
    //float distance2 = 60;
    float Posylimabove2 = 680;
    float Posylimunder2 = 830;
    //float jumpsize2 = 1000;
    int numberofbutton2 = 3;
    TextBox** scoreboards = new TextBox * [numbercousestudy];
    for (int i = 0; i < numbercousestudy; i++) {
        scoreboards[i] = new TextBox[7];
        for (int j = 0; j < 7; j++) {
            scoreboards[i][j].setsize(20);
            scoreboards[i][j].setColor(sf::Color::Black);
            //scoreboards[i][j].setselected(false);
            scoreboards[i][j].setfont(Palatino);
            scoreboards[i][j].setTextboxpostitionwithlimit(Posx2[j], Posy2 + distance * i, Posylimabove2, Posylimunder2, jumpsize);
        }
        std::cout << courseid[i];
        scoreboards[i][0].setText(std::to_string(i + 1));
        scoreboards[i][1].setText(courseid[i]);
        scoreboards[i][2].setText(coursename[i]);
        scoreboards[i][3].setText(scorestudent[i].getMidScore());
        scoreboards[i][4].setText(scorestudent[i].getFinalScore());
        scoreboards[i][5].setText(scorestudent[i].getOtherScore());
        scoreboards[i][6].setText(scorestudent[i].getTotalScore());
    }
    float sum = 0;
    for (int i = 0; i < numbercousestudy; i++) {
        sum += std::stof(scorestudent[i].getTotalScore());
    }
    float semGPA = sum / numbercousestudy;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << semGPA;
    std::string seGPA = oss.str();
    OutputTextBox semesterGPA(29, sf::Color(119, 106, 92), seGPA);
    semesterGPA.setfont(Palatino);
    semesterGPA.setTextPosition(sf::Vector2f(555, 875));
    OutputTextBox overallGPA(29, sf::Color(119, 106, 92), calculateOverall(studentTextBox[kstudentchosen][1].getText()));
    overallGPA.setfont(Palatino);
    overallGPA.setTextPosition(sf::Vector2f(835, 875));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                userstaff.~Staff();
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        window.close();
                        staffHome(userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                    }
                    if (x_coor > 1380 && x_coor < 1427 && y_coor>212 && y_coor < 259) {
                        staffChooseOption(window, userstaff,classchosen);
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
            if (savebut.isonMousecursor(event)) {
                savebut.changecolor(sf::Color(186, 158, 146, 100));
            }
            else savebut.changecolor(sf::Color::Transparent);
            if (deletebut.isonMousecursor(event))
                deletebut.changecolor(sf::Color(186, 158, 146, 100));
            else
                deletebut.changecolor(sf::Color::Transparent);


            if (event.type == event.MouseWheelScrolled) {
                int y_coor = event.mouseWheelScroll.y;
                if (y_coor > Posylimabove - 5 and y_coor < Posylimunder + 20 and n > numberofbutton) {
                    Posy = Posy + event.mouseWheelScroll.delta * 10.0f;
                    if (studentTextBox[n - 1][0].getPositionofTextbox().y <= Posylimunder - 10) {
                        std::cout << studentTextBox[n - 1][0].getPositionofTextbox().y;
                        std::cout << Posy;
                        Posy = 335 - (n - numberofbutton - 1) * distance;
                    }
                    else if (studentTextBox[numberofbutton - 1][0].getPositionofTextbox().y >= Posylimunder) {

                        std::cout << Posy;
                        Posy = 388;

                    }
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            studentTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);

                        }
                    }
                    StudentsButton.setpostionlistbuttonwithlimit(Posx[0], Posy - 5, 0, distance, Posylimabove, Posylimunder, jumpsize);
                    studentchosen.setButposition(StudentsButton.getpositionofKbut(kstudentchosen + 1));
                }
                if (y_coor > Posylimabove2 - 5 and y_coor < Posylimunder2 + 20 and numbercousestudy>numberofbutton2) {
                    Posy2 = Posy2 + event.mouseWheelScroll.delta * 10.0f;
                    if (scoreboards[numbercousestudy - 1][0].getPositionofTextbox().y <= Posylimunder2 - 10) {
                        std::cout << Posy2;
                        Posy2 = 645 - (numbercousestudy - numberofbutton2 - 1) * distance;
                    }
                    else if (scoreboards[numberofbutton2 - 1][0].getPositionofTextbox().y >= Posylimunder2) {
                        std::cout << Posy2;
                        Posy2 = 688;
                    }
                    for (int i = 0; i < numbercousestudy; i++)
                        for (int j = 0; j < 7; j++)
                            scoreboards[i][j].setTextboxpostitionwithlimit(Posx2[j], Posy2 + distance * i, Posylimabove2, Posylimunder2, jumpsize);
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (StudentsButton.isClickedKOrder(event, i + 1)) {

                    kstudentchosen = i;
                    staffViewStudentScoreboard2(window, userstaff, classchosen, schoolyear, semeseter, kstudentchosen);
                }
            }
            for (int i = 0; i < numbercousestudy; i++) {
                if (userstaff.getmode())
                    for (int j = 0; j < 7; j++) {
                        if (scoreboards[i][j].isClickwithoutPosagrument(event)) {
                            scoreboards[i][j].setselected(true);
                            setnotseleted(scoreboards, numbercousestudy, i, j, 7);
                        }
                        if (event.type == sf::Event::TextEntered) {
                            if (scoreboards[i][j].isselectedbox()) {
                                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                                    scoreboards[i][j].setselected(false);
                                else
                                    scoreboards[i][j].typedText(event);
                            }
                        }
                    }

            }
            Node<Course>* tmp = cursemester.courseList.head;
            for (int i = 0; i < numbercousestudy; i++) {
                if(tmp) {
                    if (tmp->data.findIfStudentIsInThisCourse(studentTextBox[kstudentchosen][1].getText())) {
                        tmp->data.updateAStudentScoreOfThisCourse(studentTextBox[kstudentchosen][1].getText(), scoreboards[i][6].getText(),
                            scoreboards[i][4].getText(), scoreboards[i][3].getText(), scoreboards[i][5].getText());
                        if (savebut.isClick(event)) {
                            tmp->data.saveScore2CsvScoresFile(schoolyear, semeseter);
                        }
                    }
                    tmp = tmp->next;
                }
            }
        }

        window.clear();
        window.draw(s_staffclassscoreboard);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        logoutbut.drawbutton(window);
        savebut.drawbutton(window);
        deletebut.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        classtilte.drawTextbox(window);
        semestertilte.drawTextbox(window);
        schoolyeartilte.drawTextbox(window);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++)
                studentTextBox[i][j].drawTextbox(window);
        StudentsButton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146, 100));
        studentchosen.drawbutton(window);
        for (int i = 0; i < numbercousestudy; i++)
            for (int j = 0; j < 7; j++)
                scoreboards[i][j].drawTextbox(window);
       if(numbercousestudy>0) semesterGPA.drawTextbox(window);
        overallGPA.drawTextbox(window);
        window.display();
    }
    for (int i = 0; i < n; i++)
        delete[] studentTextBox[i];
    delete[] studentTextBox;
    for (int i = 0; i < numbercousestudy; i++)
        delete[] scoreboards[i];
    delete[] scoreboards;
    delete[] scorestudent;
    delete[] courseid;
    delete[] coursename;
}
