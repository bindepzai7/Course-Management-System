#pragma once
#include <string.h>


//infor of student...need to add more
class Student {
public:
	int studentID;
	std::string name;

	Student(const std::string& n, int id) : name(n), studentID(id) {};
	void displayInfo() const;
};

//Linked list of Student to create on each Course...
class studentNode {
public:
	Student student;
	studentNode* next;

	studentNode(const Student& s);
};

//create Course Linked List
class courseList {
private:
	int courseCode;
	studentNode* head;
public:
	courseList();
	void enrollStudent(const std::string& courseName, const Student& student);
	void displayCourse() const;
	~courseList();
};

