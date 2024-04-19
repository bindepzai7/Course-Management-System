

#include"displayfunction.h"


void staffmanagecourse(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string semester) {

    sf::Texture Coursetexture;
    Coursetexture.loadFromFile("Design UI/[Staff - 5] Manage Course.jpg");
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
    Button savebut(sf::Color(186, 158, 146, 100), sf::Vector2f(135, 40), false);
    Button deletebut(sf::Color(186, 158, 146, 100), sf::Vector2f(135, 40), false);
    savebut.setposition(sf::Vector2f(180, 490));
    deletebut.setposition(sf::Vector2f(180, 540));

    //school year current textbox
    OutputTextBox cur_schoolyeartextbox(28, sf::Color::Black, schoolyear);
    cur_schoolyeartextbox.setfont(Palatino);
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(1160, 180));

    //semester current textbox
    OutputTextBox cur_semestertextbox(28, sf::Color::Black, semester);
    cur_semestertextbox.setfont(Palatino);
    cur_semestertextbox.setTextPosition(sf::Vector2f(1215, 250));


    Semester s(semester);
    s.loadCourseListFromFileCourseList(schoolyear);
    int n = s.getNumberOfCourse();
    Node<Course>* cur = s.courseList.head;
    
    TextBox** CourseTextBox = new TextBox * [n];

    float Posx[8] = { 345,374,494,837,886,941,1057,1286 };
    float Posy = 416;
    float distance = 60;
    float Posylimabove = 365;
    float Posylimunder = 810;
    float jumpsize = 500;
    int numberofbutton = 8;
    for (int i = 0; i < n && cur; i++)
    {
        CourseTextBox[i] = new TextBox[8];
        for (int j = 0; j < 8; j++)
        {
            CourseTextBox[i][j].setsize(18);
            CourseTextBox[i][j].setColor(sf::Color::Black);
            CourseTextBox[i][j].setselected(false);
            CourseTextBox[i][j].setfont(Palatino);
            CourseTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);
        }
        CourseTextBox[i][0].setText(std::to_string(i + 1)); // Assuming you want to set index 0 to an index value
        CourseTextBox[i][1].setText(cur->data.getCourseID());
        CourseTextBox[i][2].setText(cur->data.getCourseName());
        CourseTextBox[i][3].setText(std::to_string(cur->data.getCredit()));
        CourseTextBox[i][4].setText(std::to_string(cur->data.getMaxStudent()));
        CourseTextBox[i][5].setText(cur->data.getClassName());
        CourseTextBox[i][6].setText(cur->data.getTeacherName());
        CourseTextBox[i][7].setText(cur->data.getSession());
        cur = cur->next;
    }
    
    //button of list student
    dropdownlist courseButton(sf::Color::Transparent, sf::Vector2f(1100, 40), false, n);
    courseButton.setpostionlistbuttonwithlimit(Posx[0], Posy - 5, 0, distance, Posylimabove, Posylimunder, jumpsize);
    int kbuttonchose = -1;
    Button courseChosen(sf::Color::Transparent, sf::Vector2f(1100, 40), false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                for (int i = 0; i < n; ++i) {
                    delete[] CourseTextBox[i];
                }
                delete[] CourseTextBox;
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        for (int i = 0; i < n; ++i) {
                            delete[] CourseTextBox[i];
                        }
                        delete[] CourseTextBox;
                        staffHome(window, userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        for (int i = 0; i < n; ++i) {
                            delete[] CourseTextBox[i];
                        }
                        delete[] CourseTextBox;
                        staffviewprofile(window, userstaff);
                    }
                    if (x_coor > 390 && x_coor < 640 && y_coor>867 && y_coor < 917) {
                        for (int i = 0; i < n; ++i) {
                            delete[] CourseTextBox[i];
                        }
                        delete[] CourseTextBox;
                        staffaddcourse(window, userstaff, schoolyear, semester);
                    }
                }
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 1)) {
                for (int i = 0; i < n; ++i) {
                    delete[] CourseTextBox[i];
                }
                delete[] CourseTextBox;
                staffmanageschoolyeardisplay(window, userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 2)) {
                for (int i = 0; i < n; ++i) {
                    delete[] CourseTextBox[i];
                }
                delete[] CourseTextBox;
                staffSemesterLobby(window, userstaff);
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 3)) {
                for (int i = 0; i < n; ++i) {
                    delete[] CourseTextBox[i];
                }
                delete[] CourseTextBox;
                staffmanagecourse(window, userstaff, getCurrentSchoolyear(), getCurrentSemester());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 4)) {
                for (int i = 0; i < n; ++i) {
                    delete[] CourseTextBox[i];
                }
                delete[] CourseTextBox;
                staffaddclasses(window, userstaff, getCurrentSchoolyear());
            }
            if (staffhomebuttonlist.isClickedKOrder(event, 5)) {
                for (int i = 0; i < n; ++i) {
                    delete[] CourseTextBox[i];
                }
                delete[] CourseTextBox;
                staffaboutUs(window, userstaff);
            }



            //click logout button
            if (logoutbut.isClick(event)) {
                for (int i = 0; i < n; ++i) {
                    delete[] CourseTextBox[i];
                }
                delete[] CourseTextBox;
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






            if (event.type == event.MouseWheelScrolled and n > 8) {
                Posy = Posy + event.mouseWheelScroll.delta * 10.0f;
                if (CourseTextBox[n - 1][0].getPositionofTextbox().y <= Posylimunder - 10) {
                    std::cout << CourseTextBox[n - 1][0].getPositionofTextbox().y;
                    std::cout << Posy;
                    Posy = 325 - (n - numberofbutton - 1) * distance;
                }
                else if (CourseTextBox[numberofbutton - 1][0].getPositionofTextbox().y >= Posylimunder) {

                    std::cout << Posy;
                    Posy = 388;

                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        CourseTextBox[i][j].setTextboxpostitionwithlimit(Posx[j], Posy + distance * i, Posylimabove, Posylimunder, jumpsize);

                    }
                }
                courseButton.setpostionlistbuttonwithlimit(Posx[0], Posy - 5, 0, distance, Posylimabove, Posylimunder, jumpsize);
                courseChosen.setButposition(courseButton.getpositionofKbut(kbuttonchose + 1));
            }
            //init node tmp for change data;
            Node<Course>* tmp = s.courseList.head;
            for (int i = 0; i < n; i++)
            {
                if (courseButton.isClickedKOrder(event, i + 1)) {
                    courseChosen.setButposition(courseButton.getpositionofKbut(i + 1));
                    courseChosen.changecolor(sf::Color(186, 158, 146, 100));
                    kbuttonchose = i;
                }
                if (userstaff.getmode()) {
                    for (int j = 0; j < 8; j++)
                    {
                        if (CourseTextBox[i][j].isClickwithoutPosagrument(event)) {
                            CourseTextBox[i][j].setselected(true);
                            setnotseleted(CourseTextBox, n, i, j);
                        }
                        if (event.type == sf::Event::TextEntered) {
                            if (CourseTextBox[i][j].isselectedbox()) {
                                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                                    CourseTextBox[i][j].setselected(false);
                                else
                                    CourseTextBox[i][j].typedText(event);
                            }
                        }

                    }
                    //savebuttonclick
                    if (tmp) {
                        tmp->data.courseID = CourseTextBox[i][1].getText();

                        tmp->data.courseName = CourseTextBox[i][2].getText();

                        tmp->data.credits = std::stoi(CourseTextBox[i][3].getText());

                        tmp->data.maxStudent = std::stoi(CourseTextBox[i][4].getText());

                        tmp->data.className = CourseTextBox[i][5].getText();

                        tmp->data.session = CourseTextBox[i][7].getText();

                        std::string fullname = CourseTextBox[i][6].getText();
                        int found = fullname.find("-");
                        if (found > 0) {
                            tmp->data.teacherName.lastName = fullname.substr(0, found);
                            tmp->data.teacherName.firstName = fullname.substr(found + 1, fullname.size());
                        }
                        
                        tmp = tmp->next;
                    }


                    if (savebut.isClick(event)) {
                        s.saveCourseListToFileCourseList(schoolyear);
                        staffmanagecourse(window, userstaff, schoolyear, semester);
                    }

                    //deletebutton
                    if (deletebut.isClick(event) and kbuttonchose != -1) {
                        s.deleteACourseFromCourseList(CourseTextBox[kbuttonchose][1].getText());
                        remove("Data/"+schoolyear+"/"+semester+"/studentOfEachCourse/" + CourseTextBox[kbuttonchose][1].getText() + ".csv");
                        remove("Data/" + schoolyear + "/" + semester + "/scoreOfEachCourse/" + CourseTextBox[kbuttonchose][1].getText() + ".csv");
                        s.saveCourseListToFileCourseList(schoolyear);
                        staffmanagecourse(window, userstaff, schoolyear, semester);
                    }
                }
            }
            


        }

        window.clear();
        window.draw(s_Coursetexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        cur_schoolyeartextbox.drawTextbox(window);
        cur_semestertextbox.drawTextbox(window);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 8; j++)
                CourseTextBox[i][j].drawTextbox(window);
        courseButton.drawButwithoutchangeTextboxcolor(window, event, sf::Color(168, 158, 146, 100));
        courseChosen.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        deletebut.drawbutton(window);
        savebut.drawbutton(window);
        window.display();
    }
}

void staffaddcourse(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string semester) {
    sf::Texture addCourseTexture;
    addCourseTexture.loadFromFile("Design UI/[Staff - 5.1] Add Course.jpg");
    addCourseTexture.setSmooth(true);
    sf::Sprite s_addCourseTexture;
    s_addCourseTexture.setTexture(addCourseTexture);
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
    //school year current textbox
    OutputTextBox cur_schoolyeartextbox(28, sf::Color::Black, schoolyear);
    cur_schoolyeartextbox.setfont(Palatino);
    cur_schoolyeartextbox.setTextPosition(sf::Vector2f(1160, 180));

    //semester current textbox
    OutputTextBox cur_semestertextbox(28, sf::Color::Black, semester);
    cur_semestertextbox.setfont(Palatino);
    cur_semestertextbox.setTextPosition(sf::Vector2f(1215, 250));

    //innit semester
    Semester s(semester);
    std::string courseID = "", courseName = "", session = "", className = "", credit ="", maxStudent="";
    Name teacherName;

    //load courseInfo and innit course
    s.loadCourseListFromFileCourseList(schoolyear);
    Course c;

    //add student with information 
    TextBox addCourseID(24, sf::Color::Black, false);
    addCourseID.setfont(Palatino);
    addCourseID.setTextPosition(sf::Vector2f(450, 390));

    TextBox addCourseName(24, sf::Color::Black, false);
    addCourseName.setfont(Palatino);
    addCourseName.setTextPosition(sf::Vector2f(450, 497));

    TextBox addCredits(24, sf::Color::Black, false);
    addCredits.setfont(Palatino);
    addCredits.setTextPosition(sf::Vector2f(450, 604));

    TextBox addClassName(24, sf::Color::Black, false);
    addClassName.setfont(Palatino);
    addClassName.setTextPosition(sf::Vector2f(450, 695));

    TextBox addMaxStudent(24, sf::Color::Black, false);
    addMaxStudent.setfont(Palatino);
    addMaxStudent.setTextPosition(sf::Vector2f(970, 390));

    TextBox addTeacherName(24, sf::Color::Black, false);
    addTeacherName.setfont(Palatino);
    addTeacherName.setTextPosition(sf::Vector2f(970, 497));

    TextBox addSession(24, sf::Color::Black, false);
    addSession.setfont(Palatino);
    addSession.setTextPosition(sf::Vector2f(970, 604));

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

            //click to add student to class

            if (addCourseID.isClick(event, 450, 380, 815, 420)) {
                addCourseID.setselected(true);
                addCourseName.setselected(false);
                addCredits.setselected(false);
                addClassName.setselected(false);
                addMaxStudent.setselected(false);
                addTeacherName.setselected(false);
                addSession.setselected(false);
            }
            else if (addCourseName.isClick(event, 450, 487, 815, 527)) {
                addCourseID.setselected(false);
                addCourseName.setselected(true);
                addCredits.setselected(false);
                addClassName.setselected(false);
                addMaxStudent.setselected(false);
                addTeacherName.setselected(false);
                addSession.setselected(false);
            }
            else  if (addCredits.isClick(event, 450, 594, 815, 634)) {
                addCourseID.setselected(false);
                addCourseName.setselected(false);
                addCredits.setselected(true);
                addClassName.setselected(false);
                addMaxStudent.setselected(false);
                addTeacherName.setselected(false);
                addSession.setselected(false);
            }
            else  if (addClassName.isClick(event, 450, 685, 815, 731)) {
                addCourseID.setselected(false);
                addCourseName.setselected(false);
                addCredits.setselected(false);
                addClassName.setselected(true);
                addMaxStudent.setselected(false);
                addTeacherName.setselected(false);
                addSession.setselected(false);
            }
            else if (addMaxStudent.isClick(event, 970, 380, 1335, 420)) {
                addCourseID.setselected(false);
                addCourseName.setselected(false);
                addCredits.setselected(false);
                addClassName.setselected(false);
                addMaxStudent.setselected(true);
                addTeacherName.setselected(false);
                addSession.setselected(false);
            }
            else if (addTeacherName.isClick(event, 970, 487, 1335, 527)) {
                addCourseID.setselected(false);
                addCourseName.setselected(false);
                addCredits.setselected(false);
                addClassName.setselected(false);
                addMaxStudent.setselected(false);
                addTeacherName.setselected(true);
                addSession.setselected(false);
            }
            else if (addSession.isClick(event, 970, 594, 1335, 634)) {
                addCourseID.setselected(false);
                addCourseName.setselected(false);
                addCredits.setselected(false);
                addClassName.setselected(false);
                addMaxStudent.setselected(false);
                addTeacherName.setselected(false);
                addSession.setselected(true);
            }

            if (event.type == sf::Event::TextEntered) {
                if (addCourseID.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addCourseID.setselected(false);
                    else
                        addCourseID.typedText(event);
                }
                else if (addCourseName.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addCourseName.setselected(false);
                    else
                        addCourseName.typedText(event);
                }
                else if (addCredits.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addCredits.setselected(false);
                    else
                        addCredits.typedText(event);
                }
                else if (addClassName.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addClassName.setselected(false);
                    else
                        addClassName.typedText(event);
                }
                else if (addMaxStudent.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addMaxStudent.setselected(false);
                    else
                        addMaxStudent.typedText(event);
                }
                else if (addTeacherName.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addTeacherName.setselected(false);
                    else
                        addTeacherName.typedText(event);
                }
                else if (addSession.isselectedbox()) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        addSession.setselected(false);
                    else
                        addSession.typedText(event);
                }
            }
         

            //add student button is Press
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x_coor = event.mouseButton.x;
                    int y_coor = event.mouseButton.y;
                    if (x_coor > 45 && x_coor < 100 && y_coor>47 && y_coor < 100) {
                        staffHome(window, userstaff);
                    }
                    if (x_coor > 40 && x_coor < 77 && y_coor>887 && y_coor < 932) {
                        staffviewprofile(window, userstaff);
                    }
                    if (x_coor > 1150 && x_coor < 1350 && y_coor>666 && y_coor < 706) {
                        courseID = addCourseID.getText();
                        courseName = addCourseName.getText();
                        className = addClassName.getText();
                        credit = addCredits.getText();
                        maxStudent = addMaxStudent.getText();
                        session = addSession.getText();
                        std::string name = addTeacherName.getText();
                        if (name == "" or courseID == "" or courseName == "" or className == "" or credit == "" or maxStudent == "0" or session == "") {
                            announcement("Error!\nPlease check your date format (dd/mm/yyyy)\nAnd fill all blank spaces.\n ");
                        }
                        else {
                            int found = name.find_last_of(" ");
                            teacherName.lastName = name.substr(0, found);
                            teacherName.firstName = name.substr(found + 1);
                            c.setCourse(courseID, courseName, session, std::stoi(credit), std::stoi(maxStudent), teacherName, className);
                            s.addACourseToCourseList(c);

                            c.saveStudentsToCsvFile(schoolyear, semester);
                            s.saveCourseListToFileCourseList(schoolyear);

                            addCourseID.setText("");
                            addCourseName.setText("");
                            addClassName.setText("");
                            addCredits.setText("");
                            addMaxStudent.setText("");
                            addTeacherName.setText("");
                            addSession.setText("");
                            c.deleteAllStudentInCourse();
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
                if (filename != "" and c.courseID != "") {
                    c.loadStudentsFromCsvFileStaffUpload(filename);
                }
            }
            else importbut.setisClicked(false);




        }

        window.clear();
        window.draw(s_addCourseTexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        addCourseID.drawTextbox(window);
        addCourseName.drawTextbox(window);
        addClassName.drawTextbox(window);
        addCredits.drawTextbox(window);
        addMaxStudent.drawTextbox(window);
        addTeacherName.drawTextbox(window);
        addSession.drawTextbox(window);
        importbut.drawbutton(window);
        cur_schoolyeartextbox.drawTextbox(window);
        cur_semestertextbox.drawTextbox(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        window.display();
    }
}

void staffviewstudentofcourse(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string semester, std::string coursechosen) {
    sf::Texture staffviewstudentofcourseTexture;
    staffviewstudentofcourseTexture.loadFromFile("Design UI/[Staff - 5.2] View Course Student.jpg");
    staffviewstudentofcourseTexture.setSmooth(true);
    sf::Sprite s_staffviewstudentofcourseTexture;
    s_staffviewstudentofcourseTexture.setTexture(staffviewstudentofcourseTexture);
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
    OutputTextBox cur_coursetextbox(28, sf::Color::Black, coursechosen);
    cur_coursetextbox.setfont(Palatino);
    cur_coursetextbox.setTextPosition(sf::Vector2f(1120.f, 216.f));

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
                    if (x_coor > 390 && x_coor < 640 && y_coor>867 && y_coor < 917) {
                        //////////////////////UNDERCONSTRUCTION CODE HERE
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
        window.draw(s_staffviewstudentofcourseTexture);
        staffhomebuttonlist.drawButwithTextbox(window, event, sf::Color(168, 158, 146), sf::Color(239, 233, 222));
        logoutbut.drawbutton(window);
        if (userstaff.getmode()) editmode.drawbutton(window);
        else viewmode.drawbutton(window);
        schoolyeartextbox.drawTextbox(window);
        semestertextbox.drawTextbox(window);
        cur_coursetextbox.drawTextbox(window);
        window.display();
    }
}
