#ifndef STAFF_H
#define STAFF_H	

#include <string>
#include<fstream>
#include "Student.h"
#include"SchoolYear.h"
#include"Class.h"

class Staff {
private:
	LinkedList<SchoolYear> schoolyearlist;
	LinkedList<Class> classlist;
	std::string StaffID;
	//std::string password;
	std::string socialID;
	Name staffName;
	Date dob;
	bool gender;

	bool mode;//1 is 
    
public:
	Staff() : StaffID(""), mode(false), socialID(""),staffName(""),gender(0),dob(Date()) {}
	Staff(const std::string& StaffID, const std::string& socialID, const Name& staffName,const bool& gender,const Date &dob)
		: StaffID(StaffID), socialID(socialID), staffName(staffName),gender(gender), dob(dob), mode(false) {}
	~Staff() {};
	
	bool operator ==(const Staff& s2) const {
		return StaffID == s2.StaffID;
	}
	bool operator>(const Staff& s2) const {
		return StaffID > s2.StaffID;
	}

	bool operator<(const Staff& s2) const {
		return StaffID < s2.StaffID;
	}

	std::string getStaffID() {
		return StaffID;
	}

	std::string getStaffSocialID() {
		return socialID;
	}
	std::string getdob() {
		return dob.getDate();
	}
	std::string getFirstname() {
		return staffName.firstName;
	}
	std::string getLastname() {
		return staffName.lastName;
	}
	bool getGender() {
		return gender;
	}
	void setmode(bool mode) {
		this->mode = mode;
	}

	bool getmode() {
		return this->mode;
	}

	LinkedList<std::string> getschoolyearstext() {
		Node<SchoolYear>* cur = schoolyearlist.head;
		LinkedList<std::string> schoolyearstext;
		while (cur) {
			schoolyearstext.addNodeAtFront(cur->data.getSchoolYear());
			cur = cur->next;
		}
		return schoolyearstext;
	}

	LinkedList<std::string> getclassescode() {
		Node<Class>* cur = classlist.head;
		LinkedList<std::string> classescode;
		while (cur) {
			classescode.addNodeAtFront(cur->data.getclasscode());
			cur = cur->next;
		}
		return classescode;
	}
	//bool operator!=(const Staff& s2) const {
	//	return username != s2.username || password != s2.password;
	//}
	void addNewSchoolyear(SchoolYear newschoolyear) {
		schoolyearlist.addNodeInAscending(newschoolyear);
	}
	void addClassforNewSchoolYear(Class newclass) {
		classlist.addNodeInAscending(newclass);
	}

	void readAllSchoolyear();
	void writeSchoolyear2file(LinkedList<std::string> &schoolyearstext);
	void readAllClassinSchoolYear(std::string schoolyear);
	void writeClasstoFile(std::string schoolyear, LinkedList<std::string> &classestext);
};


void LoadDataofStaff(LinkedList<Staff>& staffList, std::string filename);
bool getDataStafffromlist(LinkedList<Staff>&s, std::string username, Staff& userstaff);

#endif