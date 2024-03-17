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
struct Course
{
	std::string courseID;
	int numberOfCredits;
	Name teacherName;
	int maxStudent;
	dateList* dayOfWeek;
	classList* headClass;
};

//create Course Linked List
class courseList {
private:
	/*Course data;
	std::string courseID;
	std::string courseCode;
	int numberOfCredits;
	Name teacherName;
	int maxStudent;
	dateList* dayOfWeek;
	classList* headClass;
	courseList* next;
	courseList* prev;*/
	Course data;
	courseList* next;
public:
	courseList(Course data, courseList* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
	//void enrollStudent(const std::string& courseName, const Student& student);
	Course getData() {
		return this->data;
	}
	courseList* getNext() {
		return this->next;
	}
	void setNext(courseList* next)
	{
		this->next = next;
	}
	void displayCourse() const;
	//~courseList();
};


//SEMESTERS

//create Seme
class semester {
private:
	int numberOfSemester;
	Date startDate, endDate;

	courseList* headCourse;

public:
	semester(int numSemester, Date start, Date end)
	{
		numberOfSemester = numSemester;
		startDate = start;
		endDate = end;
		this->headCourse = nullptr;
	}
	//destructor
	~semester()
	{
		while (this->headCourse != nullptr) popCourse();
	}
	//using stack to add new course at begin list
	void pushCourse(Course Data);
	//pop course
	void popCourse();
	//remove any course
	void removeCourse(Course Data);
};

//SCHOOL YEAR
class schoolYear {
private:
	int yearBegin;
	int yearEnd;
	//semester first, second, third;

public:
	/*schoolYear(int start, int end)
	{
		yearBegin = start;
		yearEnd = end;
	}*/
	int getBeginYear()
	{
		return yearBegin;
	}
	int getEndYear()
	{
		return yearEnd;
	}
};
