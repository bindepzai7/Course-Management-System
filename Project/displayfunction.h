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
#include <cstdio>
#include<Windows.h>


struct account
{
	bool isselectedusername = false;
	bool isselectedpassword = false;
	bool iswrongaccount = false;
};



void chooseRole(sf::RenderWindow& window);
void loginWindow(sf::RenderWindow& window, bool role);
void announcement(std::string announcement);



                                 //STAFF


//about staff
void staffHome(Staff& userstaff);
void staffviewprofile(sf::RenderWindow& window, Staff& userstaff);
void staffChangePassword(sf::RenderWindow& window, Staff& userstaff);
void staffaboutUs(Staff& userstaff);

//manage schoolyear 
void staffmanageschoolyeardisplay(Staff& userstaff);
void staffmanageschoolyear2display(sf::RenderWindow& window,Staff& userstaff, int Korderofbut);//schoolyear with button to add class or view semester;

//Manage semester
void staffSemesterLobby(Staff& userstaff);
void staffSemesterLobby2(sf::RenderWindow& window, Staff& userstaff, int Korderofbut);
void staffmanagesemesterdisplay(sf::RenderWindow& window,Staff &userstaff, std::string schoolyear);

//manage course
void staffmanagecourse(Staff &userstaff, std::string schoolyear, std::string semester);
void staffaddcourse(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string semester);
void staffviewstudentofcourse(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string semester, std::string coursechosen);
void staffCourseScoreboard(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string semester, std::string coursechosen);

//manage class
void staffaddclasses(Staff& userstaff, std::string schoolyear);
void staffmanageclass(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, int Korderbut);
void staffaddfirstyearstudent(sf::RenderWindow& window, Staff& userstaff,std::string schoolyear, std::string addtoclass);
void staffviewstudentinclass(sf::RenderWindow& window, Staff& userstaff, std::string schoolyearchoose, std::string classchosen);
void staffChooseOption(sf::RenderWindow& window, Staff& userstaff, std::string classchosen);
void staffChooseOption2(sf::RenderWindow& window, Staff& userstaff, std::string classchosen, int Korderofbut);
void staffViewStudentScoreboard(sf::RenderWindow& window, Staff& userstaff, std::string classchosen, std::string schoolyear, std::string semeseter);
void staffViewStudentScoreboard2(sf::RenderWindow& window, Staff& userstaff, std::string classchosen, std::string schoolyear, std::string semeseter, int kstudentchosen);

std::string filenametoimport();

std::string exportFile();



                                //STUDENT



void studenthome( Student& studentuser);
void studentprofileview( Student& studentuser);
void studentAboutUs( Student& studentuser);
void studentChangePassword( Student& studentuser);
void studentCourse(sf::RenderWindow& window, Student& studentuser, std::string schoolyear, std::string semester);
void studentScoreboard(sf::RenderWindow& window, Student& studentuser, std::string schoolyear, std::string semester);
void studentChooseOption(Student& studentuser, int viewType);
void studentChooseOption2(sf::RenderWindow& window, Student& studentuser, int viewType,int korderbut);

#endif // !_DISPLAYFUNCTION_H
