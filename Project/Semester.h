#ifndef SEMESTER_H
#define SEMESTER_H

#include "LinkedList.h"
#include "Course.h"

class Semester{
	LinkedList<Course> courseList;

	std::string season;
	Date startDay;
	Date endDay;
public:
	//default constructor
	Semester() :season(""), startDay(Date(0, 0, 0)), endDay(Date(0, 0, 0)) {}
	//constructor with parameters
	Semester(const std::string season, const Date& d1, const Date& d2)
		: season(season), startDay(d1), endDay(d2) {}

	void addCourse(const Course& course) {
		courseList.addNodeAtFront(course);
	}
};




#endif