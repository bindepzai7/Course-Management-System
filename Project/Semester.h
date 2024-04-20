#ifndef SEMESTER_H
#define SEMESTER_H

#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Course.h"
#include <filesystem>
using namespace std::filesystem;

class Semester {
public:
	std::string semester;
	Date startDay;
	Date endDay;

	LinkedList<Course> courseList;
	//default constructor
	Semester() : semester(""), startDay(Date(0, 0, 0)), endDay(Date(0, 0, 0)) {}
	//constructor with parameters
	Semester(const std::string& semester, const Date& startDate, const Date& endDate) : semester(semester), startDay(startDate), endDay(endDate) {}
	Semester(const std::string& semester) {
		this->semester = semester;
	}
	bool operator==(const Semester& s) {
		if (this->semester == s.semester) return true;
		return false;
	}
	bool operator<(const Semester& s) {
		if (this->semester < s.semester) return true;
		else return false;
	}

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

	bool deleteSemesterFolder(const std::string& schoolYear); //checked


	//About CourseList 


	bool loadCourseListFromFileCourseList(const std::string& schoolYear);   //checked

	int getNumberOfCourse() {
		return courseList.sizeoflist();
	}

	Node<Course>* getCourseList() {
		return courseList.head;
	}

	bool saveCourseListToFileCourseList(const std::string& schoolYear);    //checked

	bool checkIfThereIsAlreadyACourse(const Course& c);  //checked

	bool findACourseInCourseList(const std::string& courseID, Course& c);

	bool updateACourseOfCourseList(const std::string& destCourseID, const std::string& modiCourseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session, const std::string& className);    //checked

	bool addACourseToCourseList(const Course& c);    //checked

	bool deleteACourseFromCourseList(const std::string& courseID);  //checked



};




#endif