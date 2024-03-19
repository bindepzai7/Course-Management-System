#ifndef STAFF_H
#define STAFF_H	

#include <string>
#include "Student.h"

class Staff {
	std::string username;
	std::string password;
	std::string staffID;
	Name staffName;
	
public:
	Staff(const std::string& username, const std::string& password) : username(username), password(password) {}
	Staff(const std::string& username, const std::string& password, const std::string& staffID, const Name& staffName)
		: username(username), password(password), staffID(staffID), staffName(staffName) {}
	

	bool operator!=(const Staff& s2) const {
		return username != s2.username || password != s2.password;
	}
};




#endif