

#include "ManageAddCourse.h"

void ManageAddCourse::createManageAddCourse(const std::string& schoolYear, const std::string& semester) {
	this->schoolYear = schoolYear;
	this->semester = semester;
}

bool ManageAddCourse::saveCreatedCourse(const std::string& path) const {
	std::ofstream fout;
	fout.open(path);
	
	fout.close();


	return true;
}