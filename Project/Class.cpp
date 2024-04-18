#include"Class.h"

#include "LinkedList.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void Class::loadStudentfromCSV(std::string filename) {
	std::ifstream fin;
	fin.open(filename);
	std::string No, studentID, firstname, lastname, socialID, gender, username;
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
				getline(fin, socialID);

				std::istringstream ss(dob);
				int d, m, y;
				char delimiter;
				bool gen = 0;
				if (gender == "1") gen = 1;
				ss >> d >> delimiter >> m >> delimiter >> y;
				studentList.addNodeInAscending(Student(studentID, Name(firstname, lastname), gen, Date(d, m, y), socialID));
			}
		}
	}
	else std::cout << "error";
	fin.close();
}
void Class::saveStudent(std::string schoolyear,std::string classcode) {
	std::ofstream fout;
	
	fout.open("Data/" + schoolyear + "/" + classcode + ".csv");
	if (fout.is_open()) {
		Node<Student>* cur = studentList.head;
		int i = 0;
		if(cur)
		fout << "No,studentID,lastName,firstName,dayOfBirth,gender,socialID\n";
		while (cur) {
			fout << ++i << "," << cur->data.studentID << "," << cur->data.name.lastName << "," << cur->data.name.firstName
				<< "," << cur->data.birthDay.day << "/" << cur->data.birthDay.month << "/" << cur->data.birthDay.year << "," << cur->data.studentGender << "," << cur->data.socialID << '\n';
			cur = cur->next;
		}
	}
	else std::cout << "error";
	fout.close();
}
