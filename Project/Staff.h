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
    
public:
	Staff() : StaffID(""), socialID(""),staffName("") {}
	Staff(const std::string& StaffID, const std::string& socialID, const Name& staffName)
		: StaffID(StaffID), socialID(socialID), staffName(staffName) {}
	
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

	LinkedList<std::string> getschoolyearstext() {
		Node<SchoolYear>* cur = schoolyearlist.head;
		LinkedList<std::string> schoolyearstext;
		while (cur) {
			schoolyearstext.addNodeAtFront(cur->data.getSchoolYear());
			cur = cur->next;
		}
		return schoolyearstext;
	}
	//bool operator!=(const Staff& s2) const {
	//	return username != s2.username || password != s2.password;
	//}
	void addNewSchoolyear(SchoolYear newschoolyear) {
		schoolyearlist.addNodeInAscending(newschoolyear);
	}
	void addClassforNewSchoolYear(Class& newclass) {
		classlist.addNodeInAscending(newclass);
	}

	void readAllSchoolyear();
	void writeSchoolyear2file();
	void readAllClassinSchoolYear(std::ifstream fin);
	void writeClasstoFile(std::ofstream fout);
};


void LoadDataofStaff(LinkedList<Staff>& s, std::ifstream fin);
bool getDataStafffromlist(LinkedList<Staff>s, std::string username, Staff& userstaff);

#endif