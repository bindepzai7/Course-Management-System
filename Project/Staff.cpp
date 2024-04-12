#include"Staff.h"
#include<iostream>
#include <sys/stat.h> // For mkdir function
#include <sys/types.h>

void Staff::readAllSchoolyear() {
	std::ifstream fin;
	fin.open("Data/AllSchoolYear.txt");
	int yearstart, yearend;
	char dash;
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> yearstart;
			fin >> dash;
			fin >> yearend;
			schoolyearlist.addNodeInAscending(SchoolYear(yearstart, yearend));
		}
	}
	fin.close();
	
}
void Staff::writeSchoolyear2file(LinkedList<std::string> &schoolyearstext) {
	std::ofstream fout;
	fout.open("Data/AllSchoolyear.txt");
	if (fout.is_open()) {
		Node<std::string>* cur = schoolyearstext.head;
		while (cur) {
			fout << cur->data;
			fout << std::endl;
			cur = cur->next;
		}
	}
	fout.close();
}

void Staff::readAllClassinSchoolYear(std::string schoolyear) {
	std::wstring folderPath = L"Data/" + std::wstring(schoolyear.begin(), schoolyear.end());
	struct _stat info;
	if (_wstat(folderPath.c_str(), &info) != 0) {
		// Folder doesn't exist, create it
		if (_wmkdir(folderPath.c_str()) != 0) {
			// Failed to create folder
			std::cout << "Failed to create school year folder " << std::endl;
			return;
		}
	}

	std::ifstream fin;
	fin.open("Data/"+schoolyear+"/classList.txt");
	std::string classcode;
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> classcode;
			classlist.addNodeInAscending(Class(classcode));
		}
	}
	fin.close();
}

void Staff::writeClasstoFile(std::string schoolyear, LinkedList<std::string> &classestext) {
	std::ofstream fout;
	fout.open("Data/" + schoolyear + "/classList.txt");
	if (fout.is_open()) {
		Node<std::string>* cur = classestext.head;
		while (cur) {
			fout << cur->data;
			fout << std::endl;
			cur = cur->next;
		}
	}
	fout.close();
}

void LoadDataofStaff(LinkedList<Staff>& s, std::ifstream fin) {
	 
}

bool getDataStafffromlist(LinkedList<Staff>s, std::string username, Staff &userstaff) {
	Node<Staff>* cur = s.head;
	while (cur && cur->data.getStaffID() != username) {
		cur = cur->next;
	}
	if (!cur) return false;
	userstaff = cur->data;
	return true;
}