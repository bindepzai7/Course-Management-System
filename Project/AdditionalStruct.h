
#ifndef ADDITIONALSTRUCT_H
#define ADDITIONALSTRUCT_H

#include <iostream>
#include <sstream>
#include <string>
#include <time.h>

struct Date {
	int day;
	int month;
	int year;


	Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {} // Constructor with default parameters

	void setDate(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	//checked correct
	static Date getCurrentDate()
	{
		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t);
		int day = now.tm_mday;
		int month = now.tm_mon + 1;
		int year = now.tm_year + 1900;
		return Date(day, month, year);

	}

	//checked correct
	int getTimeInMinute(std::string time) {
		std::stringstream s(time);
		int hour, minute;
		s >> hour;
		s.ignore(100, ':');
		s >> minute;
		minute += hour * 60;
		return minute;
	}

	friend bool operator==(const Date& d1, const Date& d2)
	{
		return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
	}


	friend bool operator<(const Date& d1, const Date& d2)
	{
		if (d1.year < d2.year) {
			return true;
		}
		else if (d1.year == d2.year) {
			if (d1.month < d2.month) {
				return true;
			}
			else if (d1.month == d2.month) {
				if (d1.day < d2.day) {
					return true;
				}
			}
		}
		return false;
	}

	friend bool operator>(const Date& d1, const Date& d2)
	{
		if (d1 < d2 || d1 == d2) {
			return false;
		}
		return true;
	}

};

struct Name {
    std::string firstName;
    std::string lastName;
    Name(const std::string& s1 = "", const std::string& s2 = "") : firstName(s1), lastName(s2) {} // Constructor with default parameters
};

//Checked correct
static void standardizeString(std::string& s) {
	if (!s.empty()) {
		for (int i = 0; s[i + 1] != '\0'; ++i) {
			if (s[i] == ' ' and s[i + 1] == ' ') {
				s.erase(i, 1);
				--i;
			}
		}
	}
	if (!s.empty() and s[0] == ' ') s.erase(0, 1);
	if (!s.empty() and isspace(s.back())) s.erase(0, 1);
}

#endif


