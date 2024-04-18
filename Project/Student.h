#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "AdditionalStruct.h"
#include"LinkedList.h"

class Student {
public:
    std::string studentID;
    Name name;
   // std::string password;
    bool studentGender; // 0 is male, 1 is female
    Date birthDay;
    std::string socialID;

    // Default constructor
    Student() : studentID(""), name(Name()), studentGender(0), birthDay(Date()), socialID("") {}
    //Constructor with studentID and password
    Student(const std::string& studentID, const std::string& password) : studentID(studentID), name(Name()), studentGender(false), birthDay(Date()), socialID("") {}
    // Constructor with parameters
    Student(const std::string& studentID, const Name& name, bool studentGender, const Date& birthday, const std::string& socialID)
        : studentID(studentID), name(name), studentGender(studentGender), birthDay(birthday), socialID(socialID) {}
    ~Student(){}

    bool operator==(const Student& s2) const {
        return studentID == s2.studentID/*&&password==s2.password*/;
    }

    bool operator>(const Student& s2) const {
        return studentID > s2.studentID;
    }

    bool operator<(const Student& s2) const {
        return studentID < s2.studentID;
    }
   /* bool operator!=(const Student& s2) const {
        return studentID != s2.studentID || password!=s2.password;
    }*/
};
void LoadDataofStudent(LinkedList<Student>& studentlist, std::string filename);
bool getDataStudentromlist(LinkedList<Student>&s, std::string username, Student& studentuser);
#endif
