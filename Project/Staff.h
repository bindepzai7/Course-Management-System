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

	Staff(const std::string& username, const std::string& password, const std::string& staffID, const Name& staffName)
		: username(username), password(password), staffID(staffID), staffName(staffName) {}

};




#endif