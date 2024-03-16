#ifndef SEMESTER_H
#define SEMESTER_H

#include "LinkedList.h"
#include "Course.h"

class Semester{
	std::string semester;
	LinkedList<Course> courseList;
	Date startDate, endDate;
};





#endif