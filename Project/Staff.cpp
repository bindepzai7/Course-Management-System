#include"Staff.h"
#include<iostream>

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
void Staff::writeSchoolyear2file(LinkedList<std::string> schoolyearstext) {
	std::ofstream fout;
	fout.open("Data/AllSchoolyear.txt");
	if (fout.is_open()) {
		Node<std::string>* cur = schoolyearstext.head;
		while (cur) {
			fout << cur->data;
			fout << " ";
			cur = cur->next;
		}
	}

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