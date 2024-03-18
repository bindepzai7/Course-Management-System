


#include <iostream>
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

int getTimeInMinute(std::string time) {
	std::stringstream s(time);
	int hour, minute;
	s >> hour;
	s.ignore(100, ':');
	s >> minute;
	minute += hour * 60;
	return minute;
}