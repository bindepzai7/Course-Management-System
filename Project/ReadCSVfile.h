#ifndef READCSVFILE_H
#define READCSVFILE_H

#include "LinkedList.h"
#include "Student.h"
#include <iostream>
#include <string>

void readCSVofStudent(LinkedList<Student>& s, std::string schoolyear, std::string classcode); /*{
	std::ifstream fin;
	fin.open("Data/"+schoolyear+"/"+classcode);
	std::string No,studentID, firstname, lastname, socialID, gender, username, password;
	std::string dob;
	Date dateofbirth;
	int count = 0;
	if (fin.is_open()) {
		while (!fin.eof()) {
			if (count == 0) {
				std::string temp;
				getline(fin, temp);
				count = 1;
			}
			else {
				getline(fin, No, ',');
				getline(fin, studentID, ',');
				getline(fin, lastname, ',');
				getline(fin, firstname, ',');
				getline(fin, dob, ',');
				getline(fin, gender, ',');
				getline(fin, socialID, ',');
				getline(fin, username, ',');

				std::istringstream ss(dob);
				int d, m, y;
				char delimiter;
				bool gen = 0;
				if (gender == "1") gen = 1;
				ss >> d >> delimiter >> m >> delimiter >> y;
				s.addNodeInAscending(Student(studentID, Name(firstname, lastname), gen, Date(d, m, y), socialID));
			}
		}
	}
	fin.close();
}*/

//void readCSVofStudentUser(LinkedList<Student>& s, std::ifstream& fin) {
//	fin.open("studentuser.csv");
//	std::string No, studentID, firstname, lastname, socialID, gender, username, password;
//	std::string dob;
//	Date dateofbirth;
//	int count = 0;
//	if (fin.is_open()) {
//		while (!fin.eof()) {
//			if (count == 0) {
//				std::string temp;
//				getline(fin, temp);
//				count = 1;
//			}
//			else {
//				getline(fin, No, ',');
//				getline(fin, studentID, ',');
//				getline(fin, password);
//				s.addNodeInAscending(Student(studentID, password));
//			}
//		}
//	}
//	fin.close();
//}

#endif