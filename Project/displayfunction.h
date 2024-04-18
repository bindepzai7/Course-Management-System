#ifndef DISPLAYFUNCTION_H
#define DISPLAYFUNCTION_H

#include"User.h"
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


struct account
{
	bool isselectedusername = false;
	bool isselectedpassword = false;
	bool iswrongaccount = false;
};



void chooseRole(sf::RenderWindow& window);
void loginWindow(sf::RenderWindow& window, bool role);
void anoucement(std::string anoucmenttext);



                                 //STAFF


//about staff
void staffHome(sf::RenderWindow& window, Staff& userstaff);
void staffviewprofile(sf::RenderWindow& window, Staff& userstaff);
void staffChangePassword(sf::RenderWindow& window, Staff& userstaff);
void staffaboutUs(sf::RenderWindow& window, Staff& userstaff);

//manage schoolyear 
void staffmanageschoolyeardisplay(sf::RenderWindow& window, Staff& userstaff);
void staffmanageschoolyear2display(sf::RenderWindow& window, Staff& userstaff, int Korderofbut);//schoolyear with button to add class or view semester;

//Manage semester
void staffSemesterLobby(sf::RenderWindow& window, Staff& userstaff);
void staffSemesterLobby2(sf::RenderWindow& window, Staff& userstaff, int Korderofbut);
void staffmanagesemesterdisplay(sf::RenderWindow& window,Staff &userstaff, std::string schoolyear);

//manage course
void staffmanagecourse(sf::RenderWindow& window,Staff &userstaff, std::string schoolyear, std::string semester);
void staffaddcourse(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string semester);
void staffviewstudentofcourse(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string semester, std::string coursechosen);

//manage class
void staffaddclasses(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear);
void staffmanageclass(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, int Korderbut);
void staffaddfirstyearstudent(sf::RenderWindow& window, Staff& userstaff,std::string schoolyear, std::string addtoclass);
void staffviewstudentinclass(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string classchosen);
void staffChooseOption(sf::RenderWindow& window, Staff& userstaff, std::string classchosen);
void staffChooseOption2(sf::RenderWindow& window, Staff& userstaff, std::string classchosen, int Korderofbut);

std::string filenametoimport();





                                //STUDENT



void studenthome(sf::RenderWindow& window, Student& studentuser);
void studentprofileview(sf::RenderWindow& window, Student& studentuser);
void studentAboutUs(sf::RenderWindow& window, Student& studentuser);
void studentChangePassword(sf::RenderWindow& window, Student& studentuser);
void studentCourse(sf::RenderWindow& window, Student& studentuser, std::string schoolyear, std::string semester);
void studentScoreboard(sf::RenderWindow& window, Student& studentuser, std::string schoolyear, std::string semester);
void studentChooseOption(sf::RenderWindow& window, Student& studentuser, int viewType);

#endif // !_DISPLAYFUNCTION_H
