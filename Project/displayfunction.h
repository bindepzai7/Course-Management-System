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
void staffhome(sf::RenderWindow &window,Staff &userstaff);

//menu

void staffChangePassword(sf::RenderWindow& window, Staff& userstaff);
void staffmanageschoolyeardisplay(sf::RenderWindow& window, Staff& userstaff);
void staffmanagesemesterdisplay(sf::RenderWindow& window,Staff &userstaff);
void staffmanagecourse(sf::RenderWindow& window,Staff &userstaff);
void staffmanageclass(sf::RenderWindow& window,Staff &userstaff);
void staffaboutUs(sf::RenderWindow& window, Staff& userstaff);

void staffviewprofile(sf::RenderWindow& window, Staff& userstaff);
void staffmanageschoolyear2display(sf::RenderWindow& window, Staff& userstaff, int Korderofbut);//schoolyear with button to add class or view semester;
void staffaddclasses(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear);
void staffaddfirstyearstudent(sf::RenderWindow& window, Staff& userstaff,std::string schoolyear, std::string addtoclass);

std::string filenametoimport();

void studenthome(sf::RenderWindow& window, Student& studentuser);


#endif // !_DISPLAYFUNCTION_H
