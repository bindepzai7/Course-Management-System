#pragma once
#include <string>
#include "Student.h"
#include "LinkedList.h"

class Class {
	//std::string className;
	std::string classCode;
	//Name teacherName;
	//std::string schedule;

	

public:
	LinkedList<Student> studentList;
	//Class()//default constructor
	//	:className(""),classCode(""),teacherName(Name()),schedule(""){}
	Class(): classCode(""){}
	Class(const std::string &cC): classCode(cC){}
	//Class(const std::string& cN, const std::string& cC, const Name& n, std::string &schedule)//with parameter
	//	:className(cN), classCode(cC), teacherName(n), schedule(schedule) {}
	~Class() {};
	//function...

	bool operator==(const Class& cl2) const {
		return classCode == cl2.classCode;
	}

	bool operator>(const Class& cl2) const {
		return classCode > cl2.classCode;
	}

	bool operator<(const Class& cl2) const {
		return classCode < cl2.classCode;
	}

	void addStudent(Student s) {
		studentList.addNodeInAscending(s);
	}
	void removeStudent(Student& s) {
		studentList.removeNodeByData(s);
	}
	void loadStudentfromCSV(std::string filename);

	void saveStudent(std::string schoolyear,std::string classcode);

	std::string getclasscode() {
		return classCode;
	}

	/*LinkedList<Student> getstudentlist() {
		return studentList;
	}*/
	Node<Student>* getstudentnode() {
		return studentList.head;
	}
	/*void savechangestudentsdata(LinkedList<Student>& s) {
		studentList = s;
	}*/
	int getnumberofstudentinclass() {
		return studentList.sizeoflist();
	}
};

