#ifndef SEMESTER_H
#define SEMESTER_H

#include "LinkedList.h"
#include "Course.h"
#include "AddCourse.h"

class Semester{
	LinkedList<Course> courseList;
	std::string semester;
	std::string schoolYear;
	Date startDay;
	Date endDay;
public:
	//default constructor
	Semester() :schoolYear(""), startDay(Date(0, 0, 0)), endDay(Date(0, 0, 0)) {}
	//constructor with parameters
	Semester(const std::string schoolYear, const Date& d1, const Date& d2)
		: schoolYear(schoolYear), startDay(d1), endDay(d2) {}

	void addCourse(const std::string& schoolYear, const std::string& semester, const std::string courseID, const Date& startDate, const Date& endDate) {
		AddCourse addCourse(schoolYear, semester, courseID, startDate, endDate);
		if (addCourse.checkValid()) {
			addCourse.writeData2File();
		}
	}
};




#endif