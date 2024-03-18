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
	bool writeData2File(); //return true if write to file successfully
public:

	//Constructors
	AddCourse();
	AddCourse(const std::string& schoolYear, const std::string& semester, const std::string& courseID);
	AddCourse(const std::string& schoolYear, const std::string& semester, const std::string& courseID, const Date& startDate, const Date& endDate);


	//Function:

		//Check if we can enrolled in course
		bool checkValidEnroll();
	
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