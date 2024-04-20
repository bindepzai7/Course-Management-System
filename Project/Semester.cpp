

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

void Semester::updateSemesterInfo(const std::string& newSemester, const Date& startDate, const Date& endDate) {
	this->semester = newSemester;
	this->startDay.setDate(startDate.day, startDate.month, startDate.year);
	this->endDay.setDate(endDate.day, endDate.month, endDate.year);
}


bool Semester::addNewSemesterFolder(const std::string& schoolYear, const std::string& newSemester) {
	if (!exists("Data/" + schoolYear + "/" + newSemester)) {
		create_directory("Data/" + schoolYear + "/" + newSemester);
		create_directory("Data/" + schoolYear + "/" + newSemester + "/scoreOfEachCourse");
		create_directory("Data/" + schoolYear + "/" + newSemester + "/studentOfEachCourse");
		return true;
	}
	return false;
}


bool Semester::deleteSemesterFolder(const std::string& schoolYear) {
	if (exists("Data/" + schoolYear + "/" + semester)) {
		remove_all("Data/" + schoolYear + "/" + semester);
		return true;
	}
	return false;
}


bool Semester::loadCourseListFromFileCourseList(const std::string& schoolYear) {
	std::ifstream fin;
	fin.open("Data/" + schoolYear + "/" + semester + "/CourseList.csv");
	if (fin.is_open()) {
		std::string s;
		getline(fin, s);  //ignore the first line
		Course c;
		while (c.readACourseFromFileCourseList(fin)) {
			std::cout << c.courseID << " ";
			courseList.addNodeAtFront(c);
		}
		fin.close();
		return true;
	}
	fin.close();
	return false;
}

bool Semester::saveCourseListToFileCourseList(const std::string& schoolYear) {
	std::ofstream fout;
	fout.open("Data/" + schoolYear + "/" + semester + "/CourseList.csv");
	if (fout.is_open()) {
		fout << "No,courseID,courseNam,teacher_lastName,teacher_firstName,credits,max_student,dayAndSession,classes\n";
		Course c;
		int i = 1;
		while (courseList.pop_head(c)) {
			fout << i++ << ',';
			c.saveACourseToFileCourseList(fout);
		}
		fout.close();
		return true;
	}
	fout.close();
	return false;
}

bool Semester::checkIfThereIsAlreadyACourse(const Course& c) {
	Node<Course>* cur = courseList.head;
	while (cur) {
		if (cur->data == c) return true;
		cur = cur->next;
	}
	return false;
}

bool Semester::findACourseInCourseList(const std::string& courseID, Course& c) {
	Node<Course>* cur = courseList.head;
	while (cur) {
		if (cur->data.getCourseID() == courseID) {
			c = cur->data;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

bool Semester::updateACourseOfCourseList(const std::string& destCourseID, const std::string& modiCourseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session, const std::string& className) {
	Node<Course>* cur = courseList.head;
	while (cur) {
		if (cur->data.getCourseID() == destCourseID) {
			cur->data.updateCourseInfo(className, modiCourseID, courseName, teacher, MaxStudent, credits, session);
			return true;
		}
		cur = cur->next;
	}
	return false;
}

bool Semester::addACourseToCourseList(const Course& c) {
	if (!checkIfThereIsAlreadyACourse(c)) {
		courseList.addNodeAtFront(c);
		return true;
	}
	return false;
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


