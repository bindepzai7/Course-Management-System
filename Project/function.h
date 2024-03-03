#pragma once
#include <string.h>
//	SOME BASIC STRUCTURE
struct Date {
	int day, month, year;
};

struct Name {
	std::string firstName;
	std::string lastName;
};



//infor of student...need to add more
class Student {

private:
	//basic student's feature
	std::string studentID;
	Name name;
	std::string password;
	bool studentGender;//0 is male, 1 is female
	Date birthDay;
	std::string socialID;

public:

	Student(const Name& n, std::string& id) : name(n), studentID(id) {};
	void displayInfo() const;
	// check if input wrong username
	bool checkUsername() const;
	//check if input wrong password
	bool checkPassword() const;
	//change password
	void changePassword() const;
	//Input gender
	void inputGender() const;
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
