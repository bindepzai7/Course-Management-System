#ifndef SEMESTER_H
#define SEMESTER_H

#include <fstream>

#include "LinkedList.h"
#include "Course.h"

class Semester{
	LinkedList<Course> courseList;
	std::string semester;
	std::string schoolYear;
	Date startDay;
	Date endDay;
public:
	//default constructor
	Semester() : semester(""), schoolYear(""), startDay(Date(0, 0, 0)), endDay(Date(0, 0, 0)) {}
	//constructor with parameters
	Semester(const std::string& semester, const std::string& schoolYear, const Date& startDate, const Date& endDate) : semester(semester), schoolYear(schoolYear), startDay(startDate), endDay(endDate) {}


	std::string getSemester() {
		return this->semester;
	}
	std::string getSchoolYear() {
		return this->schoolYear;
	}
	Date getStartDate() {
		return this->startDay;
	}
	Date getEndDAte() {
		return this->endDay;
	}

	void loadCourseListFromFileCourseList();
	
	void saveCourseListToFileCourseList();

	bool checkIfThereIsAlreadyACourse(std::string CourseID);

	bool updateACourseOfCourseList(std::string destCourseID, const std::string& modiCourseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session);

	void addACourseToCourseList(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName);

	bool deleteACourseFromCourseList(const std::string& courseID);

	bool readASemesterFromCsvFile(std::ifstream& fin);

	void saveASemesterToCsvFile(std::ofstream& fout);

	void updateSemesterInfo(const std::string& newSemester, const std::string& schoolYear, const Date& startDate, const Date& endDate);

};




#endif