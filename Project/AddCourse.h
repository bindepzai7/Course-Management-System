#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>


struct Date {
	int day;
	int month;
	int year;

	Date() {
		day = 1;
		month = 1;
		year = 1970;
	}

	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

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
};

class AddCourse {
private:
	std::string schoolYear, semester, courseID;
	Date startDate, endDate;
	bool writeData2File(); //return true if we write to file successfully
public:

	//Constructors
	AddCourse();
	AddCourse(const std::string& schoolYear, const std::string& semester, const std::string& courseID);
	AddCourse(const std::string& schoolYear, const std::string& semester, const std::string& courseID, const Date& startDate, const Date& endDate);


	//Function:
	
	//create an empty course
	void createCourse(const std::string& schoolYear, const std::string& semester);

	//Get data from course
	std::string getID() const;
	Date getStartDate() const;
	Date getEndDate() const;
	
	//Load data from text file
	bool loadData(std::ifstream& fin);

	//Load dates of a course
	bool loadDates();
	
	


};