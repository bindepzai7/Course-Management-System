#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>



template <class T>
class Node {
public:
    T data;
    Node* next;


};

template <class T>
class LinkedList {
private:
    Node<T>* head;
public:

    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    /*void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }*/

    Node<T>* getlist()
    {
        return head;
    }
    T getdata()
    {
        return head->data;
    }
    void removedatafromfirst()
    {
        if (head)
        {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
    }
};




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

public:
	//basic student's feature
	std::string studentID;
	//Name name;
	std::string password;
	//bool studentGender;        //0 is male, 1 is female
	//Date birthDay;
	//std::string socialID;


    Student() : studentID(""), password("") {}
	Student(std::string n, std::string pas) : studentID(n), password(pas) {};
	//// check if input wrong username
	//bool checkUsername() const;
	////check if input wrong password
	//bool checkPassword() const;
	////change password
	//void changePassword() const;
	////Input gender
	//void inputGender() const;
};

//Linked list of Student to create on each Course...
//class studentList {
//public:
//	Student student;
//	studentList* next;
//
//	studentList(const Student& s);
//
//};

//CLASSES

//create list of class
//class classList {
//private:
//	std::string className;
//
//	studentList* headStudent;
//
//	classList* next;
//
//public:
//	void addStudent(Student s);
//
//	void removeStudent(Student s);
//};



//COURSES

//create Course Linked List
//class courseList {
//private:
//	std::string courseID;
//	std::string courseCode;
//	int numberOfCredits;
//	Name teacherName;
//	int maxStudent;
//	dateList* dayOfWeek;
//
//	classList* headClass;
//
//	courseList* next;
//	courseList* prev;
//
//public:
//	courseList();
//	void enrollStudent(const std::string& courseName, const Student& student);
//	void displayCourse() const;
//	~courseList();
//};


//SEMESTERS

//create Seme
class semester {
private:
	int numberOfSemester;
	Date startDate, endDate;

	//courseList* headCourse;

public:

};
#endif
//SCHOOL YEAR
