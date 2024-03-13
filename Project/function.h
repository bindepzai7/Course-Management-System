#pragma once
#include <string>
//	SOME BASIC STRUCTURE
struct Date {
	int day, month, year;
};

struct Name {
	std::string firstName;
	std::string lastName;
};

struct dateList {
	Date d;
	dateList* next;
};

// STUDENTS

//infor of student...need to add more
class Student {

private:
	//basic student's feature
	std::string studentID;
	Name name;
	std::string password;
	bool studentGender;        //0 is male, 1 is female
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
class studentList {
public:
	Student student;
	studentList* next;

	studentList(const Student& s);
};

//CLASSES

//create list of class
class classList {
private:
	std::string className;

	studentList* headStudent;

	classList* next;
	classList* prev;

public:
};



//COURSES

//create Course Linked List
class courseList {
private:
	std::string courseID;
	std::string courseCode;
	int numberOfCredits;
	Name teacherName;
	int maxStudent;
	dateList* dayOfWeek;

	classList* headClass;

	courseList* next;
	courseList* prev;

public:
	courseList();
	void enrollStudent(const std::string& courseName, const Student& student);
	void displayCourse() const;
	~courseList();
};


//SEMESTERS

//create Seme
class semester {
private:
	int numberOfSemester;
	Date startDate, endDate;

	courseList* headCourse;

public:

};

//SCHOOL YEAR
class schoolYear {
private:
	int yearBegin;
	int yearEnd;
	semester first, second, third;

public:

};
