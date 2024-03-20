#ifndef _DISPLAYFUNCTION_H
#define _DISPLAYFUNCTION_H
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
void staffhome(sf::RenderWindow &window);
void studenthome(sf::RenderWindow &window);



#endif // !_DISPLAYFUNCTION_H
