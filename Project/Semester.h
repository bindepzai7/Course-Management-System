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
	Semester() :schoolYear(""), startDay(Date(0, 0, 0)), endDay(Date(0, 0, 0)) {}
	//constructor with parameters
	Semester(const std::string schoolYear, const Date& d1, const Date& d2) : schoolYear(schoolYear), startDay(d1), endDay(d2) {}




	void loadCourseListFromFileCourseList() {
		std::ifstream fin;
		fin.open("Data/" + schoolYear + "/" + semester + "/CourseList.csv");
		if (fin.is_open()) {
			Course c;
			while (c.readACourseFromFileCourseList(fin)) {
				courseList.addNodeAtFront(c);
			}
		}
		fin.close();
	}
	
	void saveCourseListToFileCourseList() {
		std::ofstream fout;
		fout.open("Data/" + schoolYear + "/" + semester + "/CourseList.csv");
		if (fout.is_open()) {
			Course c;
			courseList.pop_head(c);
			c.saveACourseToFileCourseList(fout);
		}
		fout.close();
	}

	bool checkIfThereIsAlreadyACourse(std::string CourseID) {
		Node<Course>* cur = courseList.head;
		while (cur) {
			if (cur->data.getCourseID() == CourseID) return true;
			cur = cur->next;
		}
		return false;
	}

	bool updateACourseOfCourseList(std::string destCourseID, const std::string& modiCourseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session) {
		Node<Course>* cur = courseList.head;
		while (cur) {
			if (cur->data.getCourseID() == destCourseID) {
				cur->data.updateCourseInfo(modiCourseID, courseName, teacher, MaxStudent, credits, session);
			}
			cur = cur->next;
		}
		return false;
	}

	bool addACourseToCourseList(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName) {
		Course c(courseID, courseName, session, credits, maxStudent, teacherName);
		courseList.addNodeAtFront(c);
	}

	bool deleteACourseFromCourseList(std::string courseID) {
		Node<Course>* cur = courseList.head;
		int i = 0;
		while (cur) {
			if (cur->data.getCourseID() == courseID) {
				courseList.deleteAt(i);
				return true;
			}
			cur = cur->next;
			++i;
		}
		return false;
	}



};




#endif