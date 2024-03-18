


#include <string>
#include <fstream>
#include <iostream>

#include "AddCourse.h"

class ManageAddCourse {
private:


public:
	LinkedList<AddCourse> CoursesAdded;
	LinkedList<LinkedList<std::string>> AllData;
	std::string schoolYear, semester;

	ManageAddCourse();
	ManageAddCourse(const std::string& schoolYear, const std::string& semester);

	~ManageAddCourse();

	void createManageAddCourse(const std::string& schoolYear, const std::string& semester);
	bool saveCreatedCourse(const std::string& path) const;
};