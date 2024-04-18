

#include"displayfunction.h"

void staffSemesterLobby(sf::RenderWindow& window, Staff& userstaff) {
    sf::Texture SemesterLobbyTexture;
    SemesterLobbyTexture.loadFromFile("Design UI/[Staff - 4.1] Manage Semester.jpg");
    SemesterLobbyTexture.setSmooth(true);
    sf::Sprite s_SemesterLobbyTexture;
    s_SemesterLobbyTexture.setTexture(SemesterLobbyTexture);
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
    Button editmode(sf::Color(168, 158, 146), sf::Vector2f(132.6, 42.5), false, sf::Color::Black, "EDIT", 20, Palatino);
    editmode.setposition(sf::Vector2f(45.7, 490.68));
    Button viewmode(sf::Color(168, 158, 146), sf::Vector2f(132.6, 42.5), false, sf::Color::Black, "VIEW", 20, Palatino);
    viewmode.setposition(sf::Vector2f(45.7, 538.28));

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
                staffSemesterLobby(window, userstaff);
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window, userstaff, getCurrentSchoolyear(), getCurrentSemester());
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                staffaddclasses(window, userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5))
                staffaboutUs(window, userstaff);


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



            //list of year button
            for (int i = 1; i <= schoolyearstext.sizeoflist(); i++) {
                if (schoolyears.isClickedKOrder(event, i))
                {
                    staffSemesterLobby2(window, userstaff, i);
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
        window.draw(s_SemesterLobbyTexture);
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


void staffSemesterLobby2(sf::RenderWindow& window, Staff& userstaff, int Korderofbut) {
    const int limitnumsofbutton = 8;//limit of number of button that display wiht schoolyear 
    sf::Texture SemesterLobbytexture;
    SemesterLobbytexture.loadFromFile("Design UI/[Staff - 4.2] Manage Semester.jpg");
    SemesterLobbytexture.setSmooth(true);
    sf::Sprite s_SemesterLobbytexture;
    s_SemesterLobbytexture.setTexture(SemesterLobbytexture);
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
    Button editmode(sf::Color(168, 158, 146), sf::Vector2f(132.6, 42.5), false, sf::Color::Black, "EDIT", 20, Palatino);
    editmode.setposition(sf::Vector2f(45.7, 490.68));
    Button viewmode(sf::Color(168, 158, 146), sf::Vector2f(132.6, 42.5), false, sf::Color::Black, "VIEW", 20, Palatino);
    viewmode.setposition(sf::Vector2f(45.7, 538.28));

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
                userstaff.~Staff();
            }

            if (staffhomebuttonlist.isClickedKOrder(event, 1))
                staffmanageschoolyeardisplay(window, userstaff);
            if (staffhomebuttonlist.isClickedKOrder(event, 2))
                staffSemesterLobby(window, userstaff);
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window, userstaff, getCurrentSchoolyear(), getCurrentSemester());
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                staffaddclasses(window, userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5))
                staffaboutUs(window, userstaff);

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

            //list of year button
            for (int i = 1; i <= schoolyearstext.sizeoflist(); i++) {
                if (schoolyearclickbutton.isClick(event))
                    staffSemesterLobby(window, userstaff);
                if (schoolyears.isClickedKOrder(event, i)) {
                    staffSemesterLobby2(window, userstaff, i);
                }

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
                    if (x_coor > 910 and x_coor < 1385 and y_coor >545 and y_coor < 645) {
                        staffmanagesemesterdisplay(window, userstaff, textofbutton);
                    }
                }
            }

            //wheel scrool
            if (event.type == event.MouseWheelScrolled and numberofbutton > maxbuttondisplay) {

                newposy = newposy + event.mouseWheelScroll.delta * 5.0f;
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
        window.draw(s_SemesterLobbytexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        schoolyears.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146));
        schoolyearclickbutton.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
}



void staffmanagesemesterdisplay(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear) {
    sf::Texture Semestertexture;
    Semestertexture.loadFromFile("Design UI/[Staff - 4] Manage Semester.jpg");
    Semestertexture.setSmooth(true);
    sf::Sprite s_Semestertexture;
    s_Semestertexture.setTexture(Semestertexture);
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
    Button editmode(sf::Color(168, 158, 146), sf::Vector2f(132.6, 42.5), false, sf::Color::Black, "EDIT", 20, Palatino);
    editmode.setposition(sf::Vector2f(45.7, 490.68));
    Button viewmode(sf::Color(168, 158, 146), sf::Vector2f(132.6, 42.5), false, sf::Color::Black, "VIEW", 20, Palatino);
    viewmode.setposition(sf::Vector2f(45.7, 538.28));


    //school year current textbox
    OutputTextBox cur_schoolyeartextbox(28, sf::Color::Black, schoolyear);
    cur_schoolyeartextbox.setfont(Palatino);
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(580, 430));

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
                staffSemesterLobby(window, userstaff);
            if (staffhomebuttonlist.isClickedKOrder(event, 3))
                staffmanagecourse(window, userstaff, getCurrentSchoolyear(), getCurrentSemester());
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                staffaddclasses(window, userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5))
                staffaboutUs(window, userstaff);


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
        }

        window.clear();
        window.draw(s_Semestertexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        cur_schoolyeartextbox.drawTextbox(window);
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
}