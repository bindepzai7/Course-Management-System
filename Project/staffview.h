#include"displayfunction.h"
#include"dropdownlist.h"
#include"Textbox.h"
#include"LinkedList.h"
#include"Staff.h"
#include"Student.h"
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include<Windows.h>


void staffaboutUs(sf::RenderWindow& window, Staff& userstaff);
void staffviewprofile(sf::RenderWindow& window, Staff& userstaff);

void staffhome(sf::RenderWindow& window, Staff& userstaff);


void staffmanageschoolyeardisplay(sf::RenderWindow& window, Staff& userstaff);


void staffmanageschoolyear2display(sf::RenderWindow& window, Staff& userstaff, int Korderofbut);

void staffaddclasses(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear);


void staffaddfirstyearstudent(sf::RenderWindow& window, Staff& userstaff, std::string schoolyear, std::string addtoclass);


std::string filenametoimport();



void staffmanagesemesterdisplay(sf::RenderWindow& window, Staff& userstaff);



void staffmanagecourse(sf::RenderWindow& window, Staff& userstaff);;



void staffmanageclass(sf::RenderWindow& window, Staff& userstaff);