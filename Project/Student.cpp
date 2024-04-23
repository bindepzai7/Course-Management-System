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
std::string calculateOverall(std::string studentID) {
	LinkedList<std::string> schoolyearstext;
	std::string tmp = "20" + studentID.substr(0, 2);
	int Kyear = std::stoi(tmp);
	while (Kyear <= std::stoi(getCurrentSchoolyear().substr(0, 4)) and Kyear<8+Kyear) {
		schoolyearstext.addNodeInAscending(std::to_string(Kyear) + "-" + std::to_string(Kyear + 1));
		Kyear++;
	}
	Node<std::string>* cur = schoolyearstext.head;
	int numberofschoolyear = Kyear - std::stoi(tmp);
	int* numsemesterofyear = new int[numberofschoolyear];
	for (int i = 0; i < numberofschoolyear; i++) {
		if (cur) {
			int startyear = std::stoi(cur->data.substr(0, 4));
			int endyear = std::stoi(cur->data.substr(5, 8));
			SchoolYear schoolyearchosen(startyear, endyear);
			schoolyearchosen.loadSemesterListFromSemesterList();
			int n = schoolyearchosen.getnumberofsemeseter();
			numsemesterofyear[i] = n;
			cur = cur->next;
		}
	}
	float overall = 0;
	Node < std::string>* cur2 = schoolyearstext.head;
	for (int i = 0; i < numberofschoolyear; i++)
	{
		if (cur2) {
			for (int j = 0; j < numsemesterofyear[i]; j++) {
				Semester curSemester(std::to_string(j + 1));
				curSemester.loadCourseListFromFileCourseList(cur2->data);
				Node<Course>* courseList = curSemester.courseList.head;
				Course::Student stu;
				int n = 0;
				while (courseList) {
					courseList->data.loadScoreFromCsvScoresFile(cur2->data,std::to_string(j + 1));
					if (courseList->data.findIfStudentIsInThisCourse(studentID) and courseList->data.findAStudentOfThisCourse(studentID,stu)) {
						n++;
					}
					courseList = courseList->next;
				}
				if (n > 0) {
					Course::Student* scorestudent = new Course::Student[n];
					courseList = curSemester.courseList.head;
					n = 0;
					while (courseList) {
						if (courseList->data.findIfStudentIsInThisCourse(studentID)) {
							if(courseList->data.findAStudentOfThisCourse(studentID, scorestudent[n]));
							n++;
						}
						courseList = courseList->next;
					}
					if (n > 0) {
						float sum = 0;
						for (int i = 0; i < n; i++) {
							if (scorestudent[i].getTotalScore() != "")
								sum += std::stof(scorestudent[i].totalScore);
						}
						float semGPA = sum / n;
						std::ostringstream oss;
						oss << std::fixed << std::setprecision(1) << semGPA;
						std::cout << semGPA;
						overall += semGPA;
						delete[] scorestudent;
					}
					else numsemesterofyear[i]--;
				}
				else numsemesterofyear[i]--;
			}
			overall = overall / numsemesterofyear[i];
			cur2 = cur2->next;
		}
	}
	
	overall = overall * 4 / 10;
	std::cout << overall;
	std::ostringstream OSS;
	OSS << std::fixed << std::setprecision(1) << overall;
	std::string OverallGPA = OSS.str();
	delete[] numsemesterofyear;
	return OverallGPA;
}

