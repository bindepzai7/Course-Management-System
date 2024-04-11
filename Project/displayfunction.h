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
void staffhome(sf::RenderWindow &window,LinkedList<User> &userlist,Staff &userstaff);
void staffmanageschoolyeardisplay(Staff &userstaff);
void staffmanageschoolyear2display(sf::RenderWindow &window,Staff& userstaff,int Korderofbut);//schoolyear with button to add class or view semester;
void staffmanagesemesterdisplay(Staff &userstaff);
void staffmanagecourse(Staff &userstaff);
void abousUs(sf::RenderWindow& window);
void studenthome(sf::RenderWindow &window);


#endif // !_DISPLAYFUNCTION_H
