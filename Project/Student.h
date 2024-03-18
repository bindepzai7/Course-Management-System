#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "AdditionalStruct.h"


class Student {
public:
    std::string studentID;
    Name name;
    std::string password;
    bool studentGender; // 0 is male, 1 is female
    Date birthDay;
    std::string socialID;

    // Default constructor
    Student() : studentID(""), name(Name()), password(""), studentGender(false), birthDay(Date()), socialID("") {}
    //Constructor with studentID and password
    Student(const std::string& studentID, const std::string& password) : studentID(studentID), password(password){}
    // Constructor with parameters
    Student(const std::string& studentID, const Name& name, const std::string& password, bool studentGender, const Date& birthday, const std::string& socailID)
        : studentID(studentID), name(name), password(password), studentGender(studentGender), birthDay(birthday), socialID(socialID) {}


    bool operator==(const Student& s2) const {
        return studentID == s2.studentID/*&&password==s2.password*/;
    }

    bool operator>(const Student& s2) const {
        return studentID > s2.studentID;
    }

    bool operator<(const Student& s2) const {
        return studentID < s2.studentID;
    }
    bool operator!=(const Student& s2) const {
        return studentID != s2.studentID||password!=s2.password;
    }

};

#endif
