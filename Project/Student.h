#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Date {
    int day, month, year;
    Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {} // Constructor with default parameters
};

struct Name {
    std::string firstName;
    std::string lastName;
    Name(const std::string& s1 = "", const std::string& s2 = "") : firstName(s1), lastName(s2) {} // Constructor with default parameters
};

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
