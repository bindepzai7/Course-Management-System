#pragma once
#include <string>
#include "Student.h"
#include "LinkedList.h"

class Class {
	std::string className;
	Name teacherName;

	LinkedList<Student>* studentList;

public:
	void addStudent(Student s) {
		studentList->addNodeInAscending(s);
	}

	void removeStudent(Student& s) {
		studentList->removeNodeByData(s);
	}


};