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
void staffmanageschoolyeardisplay(sf::RenderWindow& window,Staff &userstaff);
void staffmanagesemesterdisplay(sf::RenderWindow& window,Staff &userstaff);
void staffmanagecourse(sf::RenderWindow& window,Staff &userstaff);
void abousUs(sf::RenderWindow& window);
void studenthome(sf::RenderWindow &window);


#endif // !_DISPLAYFUNCTION_H
