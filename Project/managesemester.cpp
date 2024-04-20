


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
    Button editmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "EDIT", 20, Palatino);
    editmode.setposition(sf::Vector2f(46, 491));
    Button viewmode(sf::Color(168, 158, 146), sf::Vector2f(133, 43), false, sf::Color::Black, "VIEW", 20, Palatino);
    viewmode.setposition(sf::Vector2f(46, 538));

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
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(580, 430));

    //Add semester button
    Button semester1but(sf::Color::Transparent, sf::Vector2f(50, 50), false, sf::Color::Black, "[  ]", 40, Palatino);
    semester1but.setposition(sf::Vector2f(1138, 183));
    Button semester2but(sf::Color::Transparent, sf::Vector2f(50, 50), false, sf::Color::Black, "[  ]", 40, Palatino);
    semester2but.setposition(sf::Vector2f(1222, 183));
    Button semester3but(sf::Color::Transparent, sf::Vector2f(50, 50), false, sf::Color::Black, "[  ]", 40, Palatino);
    semester3but.setposition(sf::Vector2f(1305, 183));


    //Add start and end date
    TextBox addStartDate(24, sf::Color::Black, false);
    addStartDate.setfont(Palatino);
    addStartDate.setTextPosition(sf::Vector2f(1090, 280));

    TextBox addEndDate(24, sf::Color::Black, false);
    addEndDate.setfont(Palatino);
    addEndDate.setTextPosition(sf::Vector2f(1090, 370));

    //innit
    SchoolYear year(schoolyear);
    std::string semester = "";
    std::string Startdate = "";
    Date start, end;
    std::string Enddate = "";
    year.loadSemesterListFromSemesterList();
    int n = year.getnumberofsemeseter();
    Node<Semester>* cur = year.semesterList.head;




    TextBox** semesterTextBox = new TextBox * [n];

    float Posx[3] = {500,780,1080 };
    float Posy = 630;
    float distance = 60;
    float Posylimabove = 620;
    float Posylimunder = 775;
    float jumpsize = 500;
    int numberofbutton = 3;
    for (int i = 0; i < n; i++)
    {
        semesterTextBox[i] = new TextBox[3];
        for (int j = 0; j < 3; j++)
        {
            semesterTextBox[i][j].setsize(24);
            semesterTextBox[i][j].setColor(sf::Color::Black);
            semesterTextBox[i][j].setselected(false);
            semesterTextBox[i][j].setfont(Palatino);
            semesterTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);
        }

        semesterTextBox[i][0].setText(cur->data.getSemester()); // Assuming you want to set index 0 to an index value
        semesterTextBox[i][1].setText(cur->data.getStartDate());
        semesterTextBox[i][2].setText(cur->data.getEndDate());
        cur = cur->next;
    }
    //button of list student
    dropdownlist SemesterButton(sf::Color::Transparent, sf::Vector2f(1000, 40), false, n);
    SemesterButton.setpostionlistbuttonwithlimit(Posx[0]-100, Posy - 5, 0, distance, Posylimabove, Posylimunder, jumpsize);
    int kbuttonchose = -1;
    Button semesterchosen(sf::Color::Transparent, sf::Vector2f(1006, 40), false);

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

            //Add end and start date
            if (addStartDate.isClick(event, 1077, 265, 1380, 316)) {
                addStartDate.setselected(true);
                addEndDate.setselected(false);
            }
            else if (addEndDate.isClick(event, 1077, 357, 1380, 408)) {
                addStartDate.setselected(false);
                addEndDate.setselected(true);
            }
            if (event.type == sf::Event::TextEntered) {
                if (addStartDate.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addStartDate.setselected(false);
                    else
                        addStartDate.typedText(event);
                }
                else if (addEndDate.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addEndDate.setselected(false);
                    else
                        addEndDate.typedText(event);
                }
            }
            //add student button is Press
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 1110 && x_coor < 1380 && y_coor>453 && y_coor < 499) {

                        Startdate = addStartDate.getText();
                        Enddate = addEndDate.getText();
                        if (Startdate.size() != 10 or Enddate.size() != 10 or (!semester1but.getisClick() and !semester2but.getisClick() and !semester3but.getisClick())) {
                            announcement("Blank data or wrong date format!\nFill blank spaces and enter correct date format dd/mm/yyyy! (10 chars)");
                        }
                        else {
                            if (semester1but.getisClick()) semester = "1";
                            else {
                                if (semester2but.getisClick()) {
                                    semester = "2";
                                }
                                else {
                                    if (semester3but.getisClick()) {
                                        semester = "3";
                                    }
                                }
                            }
                            int i = 0;
                            while (Startdate[i] != 47 && Startdate[i] != 45 && i < Startdate.size())
                                i++;
                            start.day = std::stoi(Startdate.substr(0, i));
                            int j = i + 1;
                            while (Startdate[j] != 47 && Startdate[j] != 45 && j < Startdate.size())
                                j++;
                            start.month = std::stoi(Startdate.substr(i + 1, j - 1));
                            start.year = std::stoi(Startdate.substr(j + 1, Startdate.size() - 1));
                           
                            i = 0;
                            while (Enddate[i] != 47 && Enddate[i] != 45 && i < Enddate.size())
                                i++;
                            end.day = std::stoi(Enddate.substr(0, i));
                            j = i + 1;
                            while (Enddate[j] != 47 && Enddate[j] != 45 && j < Enddate.size())
                                j++;
                            end.month = std::stoi(Enddate.substr(i + 1, j - 1));
                            end.year = std::stoi(Enddate.substr(j + 1, Enddate.size() - 1));
                            


                            year.addSemester(semester, start, end);
                            addStartDate.setText("");
                            addEndDate.setText("");
                            staffmanagesemesterdisplay(window, userstaff, schoolyear);
                        }
                    }
                }
            }


            //if semester is choose to add
            if (semester1but.isClick(event)) {
                semester1but.setisClicked(true);
                semester2but.setisClicked(false);
                semester3but.setisClicked(false);
            }
            if (semester2but.isClick(event)) {
                semester1but.setisClicked(false);
                semester2but.setisClicked(true);
                semester3but.setisClicked(false);
            }
            if (semester3but.isClick(event)) {
                semester1but.setisClicked(false);
                semester2but.setisClicked(false);
                semester3but.setisClicked(true);
            }
            //change color button when on cursor

            else savebut.changecolor(sf::Color::Transparent);
            if (deletebut.isonMousecursor(event))
                deletebut.changecolor(sf::Color(186, 158, 146, 100));
            else
                deletebut.changecolor(sf::Color::Transparent);







            //init node tmp for change data;
            Node<Semester>* tmp = year.semesterList.head;
            for (int i = 0; i < n; i++)
            {
                if (SemesterButton.isClickedKOrder(event, i + 1)) {
                    semesterchosen.setButposition(SemesterButton.getpositionofKbut(i + 1));
                    semesterchosen.changecolor(sf::Color(186, 158, 146, 100));
                    kbuttonchose = i;
                }
                if (!userstaff.getmode()) {
                    if (semesterchosen.isClick(event)) {
                        std::string choice = semesterTextBox[i][0].getText();
                        userstaff.~Staff();
                        staffmanagecourse(window, userstaff, schoolyear, choice);
                    }
                }
                else {
                    for (int j = 0; j < 3; j++)
                    {
                        if (semesterTextBox[i][j].isClickwithoutPosagrument(event)) {
                            semesterTextBox[i][j].setselected(true);
                            setnotseleted(semesterTextBox, n, i, j, 3);
                        }
                        if (event.type == sf::Event::TextEntered) {
                            if (semesterTextBox[i][j].isselectedbox()) {
                                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                                    semesterTextBox[i][j].setselected(false);
                                else
                                    semesterTextBox[i][j].typedText(event);
                            }
                        }

                    }
                    //savebuttonclick
                    if (tmp) {
                        std::string start = semesterTextBox[i][1].getText();
                        std::string end = semesterTextBox[i][2].getText();
                        int foundday = start.find("/");
                        std::cout << foundday;
                        int foundmonth = -1;
                        if (foundday > 0) 
                            foundmonth = start.find("/");
                        std::cout << foundmonth;
                        if (foundday > 0 and foundmonth > 0) {
                            tmp->data.startDay.day = std::stoi(start.substr(0, foundday));
                            if (foundday < foundmonth)
                                tmp->data.startDay.month = std::stoi(start.substr(foundday + 2, foundmonth));
                            if (foundmonth + 2 < start.size())
                                tmp->data.startDay.year = std::stoi(start.substr(foundmonth + 2, start.size()));
                        }

                        foundday = end.find("/");
                        foundmonth = -1;
                        if (foundday > 0) {
                            foundmonth = end.find("/", foundday + 1);
                            if (foundday > 0 and foundmonth > 0) {
                                tmp->data.endDay.day = std::stoi(end.substr(0, foundday));
                                if (foundday < foundmonth)
                                    tmp->data.endDay.month = std::stoi(end.substr(foundday + 2, foundmonth));
                                if (foundmonth + 1 < end.size())
                                    tmp->data.endDay.year = std::stoi(end.substr(foundmonth + 2, end.size()));
                            }
                        }
                        tmp = tmp->next;
                    }
                    

                    //deletebutton
                    if (deletebut.isClick(event) and kbuttonchose != -1) {
                        if (!year.deleteSemester(semesterTextBox[kbuttonchose][0].getText())) {
                            announcement("Cant delete current semester.\nPlease set new current semester first.");
                        }
                        else staffmanagesemesterdisplay(window, userstaff, schoolyear);
                    }
                }

            }

            if (savebut.isClick(event)) {
                year.saveSemesterListToSemesterList();
                staffmanagesemesterdisplay(window, userstaff, schoolyear);
            }
        }


        window.clear();
        window.draw(s_Semestertexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        cur_schoolyeartextbox.drawTextbox(window);
        logoutbut.drawbutton(window);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) semesterTextBox[i][j].drawTextbox(window);
        }
        SemesterButton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146, 100));
        semesterchosen.drawbutton(window);

        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        if (semester1but.getisClick()) semester1but.drawbutton(window);
        else {
            if (semester2but.getisClick()) {
                semester2but.drawbutton(window);
            }
            else {
                if (semester3but.getisClick()) {
                    semester3but.drawbutton(window);
                }
            }
        }
        deletebut.drawbutton(window);
        savebut.drawbutton(window);
        addEndDate.drawTextbox(window);
        addStartDate.drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
    for (int i = 0; i < n; i++)
        delete[] semesterTextBox[i];
    delete[] semesterTextBox;
}