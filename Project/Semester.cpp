

#include "Semester.h"


bool Semester::readASemesterFromCsvFile(std::ifstream& fin) {
	std::string semester;
	if (fin >> semester) {
		this->semester = semester;
		fin >> this->startDay.day >> this->startDay.month >> this->startDay.year;
		fin >> this->endDay.day >> this->endDay.month >> this->endDay.year;
		return true;
	}
	return false;
}

void Semester::saveASemesterToCsvFile(std::ofstream& fout) {
	fout << this->semester << " " << this->startDay.day << " " << this->startDay.month << " " << this->startDay.year << " "
		<< this->endDay.day << " " << this->endDay.month << " " << this->endDay.year << '\n';
}

void Semester::updateSemesterInfo(const std::string& newSemester, const std::string& schoolYear, const Date& startDate, const Date& endDate) {
	this->semester = newSemester;
	this->schoolYear = schoolYear;
	this->startDay.setDate(startDate.day, startDate.month, startDate.year);
	this->endDay.setDate(endDate.day, endDate.month, endDate.year);
}

bool Semester::addNewSemesterFolder(const std::string& schoolYear, const std::string& newSemester) {
	if (!exists("Data/" + schoolYear + "/" + semester)) {
		create_directory("Data/" + schoolYear + "/" + semester);
		return true;
	}
	return false;
}


void Semester::loadCourseListFromFileCourseList() {
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

void Semester::saveCourseListToFileCourseList() {
	std::ofstream fout;
	fout.open("Data/" + schoolYear + "/" + semester + "/CourseList.csv");
	if (fout.is_open()) {
		Course c;
		while (courseList.pop_head(c)) {
			c.saveACourseToFileCourseList(fout);
		}
	}
	fout.close();
}

bool Semester::checkIfThereIsAlreadyACourse(std::string CourseID) {
	Node<Course>* cur = courseList.head;
	while (cur) {
		if (cur->data.getCourseID() == CourseID) return true;
		cur = cur->next;
	}
	return false;
}

bool Semester::updateACourseOfCourseList(std::string destCourseID, const std::string& modiCourseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session) {
	Node<Course>* cur = courseList.head;
	while (cur) {
		if (cur->data.getCourseID() == destCourseID) {
			cur->data.updateCourseInfo(modiCourseID, courseName, teacher, MaxStudent, credits, session);
		}
		cur = cur->next;
	}
	return false;
}

void Semester::addACourseToCourseList(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName) {
	Course c(courseID, courseName, session, credits, maxStudent, teacherName);
	courseList.addNodeAtFront(c);
}

bool Semester::deleteACourseFromCourseList(const std::string& courseID) {
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


