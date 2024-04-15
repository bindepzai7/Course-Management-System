#ifndef SEMESTER_H
#define SEMESTER_H

#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Course.h"
#include <filesystem>
using namespace std::filesystem;

class Semester {
	LinkedList<Course> courseList;
	std::string semester;
	Date startDay;
	Date endDay;
public:
	//default constructor
	Semester() : semester(""), startDay(Date(0, 0, 0)), endDay(Date(0, 0, 0)) {}
	//constructor with parameters
	Semester(const std::string& semester, const Date& startDate, const Date& endDate) : semester(semester), startDay(startDate), endDay(endDate) {}


	//				About this semester's info

	std::string getSemester() {
		return this->semester;
	}
	std::string getStartDate() {
		return startDay.getDate();
	}
	std::string getEndDate() {
		return endDay.getDate();
	}

	bool addNewSemesterFolder(const std::string& schoolYear, const std::string& newSemester);   //checked

	bool readASemesterFromCsvFile(std::ifstream& fin);  //checked

	void saveASemesterToCsvFile(std::ofstream& fout);  //checked

	void updateSemesterInfo(const std::string& newSemester, const Date& startDate, const Date& endDate);   //checked

	bool deleteSemesterFolder(const std::string& schoolYear, const std::string& semester); //checked


	//About CourseList 


	bool loadCourseListFromFileCourseList(const std::string& schoolYear);   //checked

	bool saveCourseListToFileCourseList(const std::string& schoolYear);    //checked

	bool checkIfThereIsAlreadyACourse(const std::string& CourseID);  //checked

	bool findACourseInCourseList(const std::string& courseID, Course& c);

	bool updateACourseOfCourseList(const std::string& destCourseID, const std::string& modiCourseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session);    //checked

	bool addACourseToCourseList(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName);    //checked

	bool deleteACourseFromCourseList(const std::string& courseID);  //checked



};




#endif