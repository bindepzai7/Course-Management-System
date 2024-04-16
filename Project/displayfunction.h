#ifndef DISPLAYFUNCTION_H
#define DISPLAYFUNCTION_H
#include"Staff.h"
#include"User.h"
#include<SFML/Graphics.hpp>
#include<string>
struct account
{
	bool isselectedusername = false;
	bool isselectedpassword = false;
	bool iswrongaccount = false;
};



void chooseRole(sf::RenderWindow& window);
void loginWindow(sf::RenderWindow& window, bool role);




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
void staffmanagesemesterdisplay(sf::RenderWindow& window,Staff &userstaff, std::string schoolyear);

//manage course
void staffmanagecourse(sf::RenderWindow& window,Staff &userstaff, std::string schoolyear, std::string semester);


//manage class
void staffaddclasses(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear);
void staffmanageclass(sf::RenderWindow& window, Staff& userstaff);
void staffaddfirstyearstudent(sf::RenderWindow& window, Staff& userstaff,std::string schoolyear, std::string addtoclass);

std::string filenametoimport();





                                //STUDENT



void studenthome(sf::RenderWindow& window, Student& studentuser);
void studentprofileview(sf::RenderWindow& window, Student& studentuser);
void studentAboutUs(sf::RenderWindow& window, Student& studentuser);
void studentChangePassword(sf::RenderWindow& window, Student& studentuser);
void studentCourse(sf::RenderWindow& window, Student& studentuser);
void studentScoreboard(sf::RenderWindow& window, Student& studentuser);




#endif // !_DISPLAYFUNCTION_H
