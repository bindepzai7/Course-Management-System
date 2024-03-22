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
	std::string username;
	std::string password;
	std::string staffID;
	Name staffName;
    
public:
	Staff(const std::string& username, const std::string& password) : username(username), password(password) {}
	Staff(const std::string& username, const std::string& password, const std::string& staffID, const Name& staffName)
		: username(username), password(password), staffID(staffID), staffName(staffName) {}
	
	bool operator ==(const Staff& s2) const {
		return staffID == s2.staffID;
	}
	bool operator>(const Staff& s2) const {
		return staffID > s2.staffID;
	}

	bool operator<(const Staff& s2) const {
		return staffID < s2.staffID;
	}

	bool operator!=(const Staff& s2) const {
		return username != s2.username || password != s2.password;
	}
	void addNewSchoolyear(SchoolYear& newschoolyear) {
		schoolyearlist.addNodeInAscending(newschoolyear);
	}
	void addClassforNewSchoolYear(Class& newclass) {
		classlist.addNodeInAscending(newclass);
	}

	void readAllSchoolyear(std::ifstream fin);
	void writeSchoolyear2file(std::ofstream fout);
};




#endif