#ifndef STUDENT_H
#define STUDENT_H

#include <string>
struct Date {
	int day, month, year;
	Date(int d, int m, int y) :day(d), month(m), year(y){}//constructor

	Date() :day(0), month(0), year(0) {}
};

struct Name {
	std::string firstName;
	std::string lastName;
public:
	Name(std::string s1, std::string s2) : firstName(s1), lastName(s2){}//constructor

	Name() : firstName(""), lastName("") {} // Default constructor
};

class Student {
public:

	std::string studentID;
	Name name;
	std::string password;
	bool studentGender;        //0 is male, 1 is female
	Date birthDay;
	std::string socialID;


	Student() : studentID(""), name(Name()), password(""), studentGender(0), birthDay(Date()), socialID(""){}
	Student(std::string& sID, Name& n, std::string& pass, bool& sG, Date& bd, std::string& soID):studentID(sID), name(n), password(pass), studentGender(sG), birthDay(bd), socialID(soID) {}

};



#endif 