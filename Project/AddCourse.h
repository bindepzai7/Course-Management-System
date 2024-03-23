#ifndef ADDCOURSE_H
#define ADDCOURSE_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


#include "LinkedList.h"
#include "AdditionalStruct.h"


class AddCourse {
private:
	std::string schoolYear, semester, courseID;
	Date startDate, endDate;
	
public:
	//Constructors
	AddCourse(const std::string& schoolYear, const std::string& semester, const std::string& courseID, const Date& startDate, const Date& endDate);

	//Function:

	bool writeData2File(); //return true if write to file successfully

		//Check if we can enrolled in course
		bool checkValid();

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

#endif