#include <iostream>
#include <string.h>

#include "function.h"
#include "someBasicStruct.h"

//Implemention of Student class


//void Student::displayInfo() const {
//	std::cout << "StudentID: " << studentID << "\tName: " << name << std::endl;
//}




//Implemention of StudentNode class
studentNode::studentNode(const Student& s) :student(s), next(nullptr) {}



//Implemention of CourseList class
courseList::courseList() :head(nullptr) {};

void courseList::enrollStudent(const std::string& courseName, const Student& student) {

}

void courseList::displayCourse() const {

}

courseList::~courseList() {

}




