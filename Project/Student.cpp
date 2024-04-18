#include"Student.h"
#include<iostream>

void LoadDataofStudent(LinkedList<Student>& studentlist, std::string filename) {
	std::ifstream fin;
	fin.open(filename);
	std::string No, studentID, firstname, lastname, socialID, gender, username, password;
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
				studentlist.addNodeInAscending(Student(studentID, Name(firstname, lastname), gen, Date(d, m, y), socialID));
			}
		}
	}
	fin.close();
}

bool getDataStudentromlist(LinkedList<Student>&s, std::string username, Student& studentuser) {
	Node<Student>* cur = s.head;
	while (cur && cur->data.studentID != username) {
		cur = cur->next;
	}
	if (!cur) return false;
	studentuser = cur->data;
	return true;
}
