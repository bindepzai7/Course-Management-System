#pragma once
#include <string>
#include "Student.h"
#include "LinkedList.h"

class Class {
	std::string className;
	std::string classCode;
	Name teacherName;
	std::string schedule;

	LinkedList<Student> studentList;

public:
	Class()//default constructor
		:className(""),classCode(""),teacherName(Name()),schedule(""){}
	Class(const std::string& cN, const std::string& cC, const Name& n, std::string &schedule)//with parameter
		:className(cN), classCode(cC), teacherName(n), schedule(schedule) {}

	//function...

	void addStudent(Student s) {
		studentList.addNodeInAscending(s);
	}
	void removeStudent(Student& s) {
		studentList.removeNodeByData(s);
	}
};

