
#include "Course.h"

Course::Course() {
	this->maxStudent = 50;
	this->credits = 0;
	this->courseID = "";
}

Course::Course(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName) {
	if (maxStudent == NULL) {
		this->maxStudent = 50;
	}
	else this->maxStudent = maxStudent;
	this->courseID = courseID;
	this->courseName = courseName;
	this->teacherName = teacherName;
	this->session = session;
	this->credits = credits;
}

bool Course::readCourseFromCsvFile(std::ifstream& fin) {
	if (getline(fin, courseID, ',')) {
		standardizeString(courseID);
		getline(fin, courseName, ',');
		standardizeString(courseName);
		Name(teacherName);
		fin >> (credits);
		fin.ignore(1, ',');
		fin >> (maxStudent);
		fin.ignore(1, ',');
		getline(fin, session, '\n');
		standardizeString(session);
		return true;
	}
	return false;
}

void Course::loadCourseStudentsFromCsvFile(const std::string& schoolYear, const std::string& semester) {
	students.empty();
	std::ifstream fin("Data/" + schoolYear + "/" + semester + "studentOfEachCourse" + courseID + ".cvs");
	if (fin.is_open()) {
		std::string input = "";
		getline(fin, input);
		while (!fin.eof()) {
			CourseStudent student;
			getline(fin, input, ',');
			if (input == "") return;
			getline(fin, student.StudentID, ',');
			getline(fin, student.name.lastName, ',');
			getline(fin, student.name.firstName, '\n');
			students.push_tail(student);
		}
	}
	fin.close();
}

void Course::saveCourseStudents2CsvFile(const std::string& schoolYear, const std::string& semester) {
	std::ofstream fout("Data/" + schoolYear + "/" + semester + "studentOfEachCourse" + courseID + ".cvs");
	if (fout.is_open()) {
		Node<CourseStudent>* cur = students.head;
		int i = 0;
		fout << "No,studentID,lastName,firstName\n";
		while (cur) {
			fout << ++i << "," << cur->data.StudentID << "," << cur->data.name.lastName << "," << cur->data.name.firstName << '\n';
			cur = cur->next;
		}
	}
	fout.close();
}


std::pair<std::string, std::pair<int, int> > Course::getDayAndSession() const {
	//stringSession ex: TUE, 7:30-10:30
	std::stringstream stringSession(this->session);
	std::string day, time;
	Date d;
	int startTime, endTime;
	stringSession >> day; //Read all char: MON, TUE, WED...
	getline(stringSession, time, '-'); // get the start time as ex: 7:30
	startTime = d.getTimeInMinute(time);
	getline(stringSession, time);
	endTime = d.getTimeInMinute(time);
	return std::make_pair(day, std::make_pair(startTime, endTime));
};

bool Course::updateCourse() {
	int option;
	std::string s1, s2;
	std::cout << "1. Escape\n"
		<< "2. Course ID\n"
		<< "3. Course name\n"
		<< "4. Teacher\n"
		<< "5. Credits\n"
		<< "6. Maximum number of students in course\n"
		<< "7. Day-session\n"
		<< "Please enter your option: ";
	std::cin >> option;

	if (option < 1 || option > 7) {
		std::cout << "Invalid option\nPlease enter again:\n";
		return true;
	}

	switch (option) {
	case 1: return false;
	case 2:
		std::cout << "Please enter new course ID: ";
		std::cin >> (this->courseID);
		break;
	case 3:
		std::cout << "Please enter new name of course: ";
		getline(std::cin, this->courseName);
		break;
	case 4:
		std::cout << "Please enter first name of teacher: ";
		getline(std::cin, s1); 
		getline(std::cin, s2);
		this->teacherName = Name(s1, s2);
		break;
	case 5:
		std::cout << "Please enter new number of credits: ";
		while (!std::cin >> this->credits or this->credits <= 0) {
			std::cout << "Warning: the number of credits is invalid\n";
		}
		break;
	case 6:
		std::cout << "Please enter the maximum number of students in a course: ";
		if (!std::cin >> this->maxStudent or this->maxStudent <= 0)
			std::cout << "Input number is invalid\n";
		break;
	case 7:
		std::cout << "Please enter day and session: Ex: TUE, 7:30-11:10";
		getline(std::cin, this->session);
		break;
	}
	return true;
};


//   [&] capture lambda expression external variables by reference
bool Course::delStudentOfThisCourse(const std::string& studentID) {
	//Find the index of student with StudentID inputted, return -1 if false
	int index = students.findIndexOfPartialData([&](CourseStudent list) {return list.StudentID == studentID; });
	if (index == -1) return false;
	students.deleteAt(index);
	return true;
}

void Course::addStudentToThisCourse(const std::string& studentID, const Name& name) {
	CourseStudent courseStudent;
	courseStudent.StudentID = studentID;
	courseStudent.name = name;
	students.addNodeInAscending(courseStudent);
}

bool Course::updateStudentOfThisCourse(const std::string& studentID, const Name& name) {
	int index = students.findIndexOfPartialData([&](CourseStudent list) {return list.StudentID == studentID; });
	if (index == -1) return false;
	Node<CourseStudent>* cur = students.head;
	for (int i = 0; i < index; ++i) {
		cur = cur->next;
	}
	cur->data.StudentID = studentID;
	cur->data.name = name;
	return true;
}

bool Course::findStudentOfThisCourse(const std::string& studentID) {
	int i = students.findIndexOfPartialData([&](CourseStudent list) {return list.StudentID == studentID; });
	if (int i = -1) return false;
	else return true;
}


void Course::loadStudentScoreFromCvsFile(const std::string& schoolYear, const std::string& semester) {
	std::ifstream fin("Data/" + schoolYear + "/" + semester + "scoreOfEachCourse" + courseID + ".cvs");
	if (fin.is_open()) {
		std::string input = "";
		getline(fin, input);
		while (!fin.eof()) {
			ScoreStudent student;
			getline(fin, input, ',');
			if (input == "") return;
			getline(fin, student.StudentID, ',');
			getline(fin, student.name.lastName, ',');
			getline(fin, student.name.firstName, ',');
			getline(fin, student.midScore, ','); 
			getline(fin, student.finScore, ','); 
			getline(fin, student.otherScore, ',');
			getline(fin, student.totalScore, '\n');
			scoreStudents.push_head(student);
		}

	}
	fin.close();
}

void Course::saveStudentScore2CsvFile(const std::string& schoolYear, const std::string& semester) {
	std::ofstream fout("Data/" + schoolYear + "/" + semester + "scoreOfEachCourse" + courseID + ".cvs");
	if (fout.is_open()) {
		Node<ScoreStudent>* cur = scoreStudents.head;
		int i = 0;
		fout << "No,studentID,lastName,firstName,midScore,finScore,otherScore,totalScore\n";
		while (cur) {
			fout << ++i << "," << cur->data.StudentID << "," << cur->data.name.lastName << "," << cur->data.name.firstName
				<< "," << cur->data.midScore << cur->data.finScore << cur->data.otherScore << cur->data.totalScore << '\n';
			cur = cur->next;
		}
	}
	fout.close();
}

Course::ScoreStudent Course::findAStudentScoreOfThisCourse(const std::string& studentID) {
	int index = students.findIndexOfPartialData([&](CourseStudent list) {return list.StudentID == studentID; });
	if (index == -1) {
		ScoreStudent scoreStudent;
		return scoreStudent;
	}
	Node<ScoreStudent>* cur = scoreStudents.head;
	for (int i = 0; i < index; ++i) {
		cur = cur->next;
	}
	return cur->data;
}

bool Course::updateAStudentScoreOfThisCourse(const std::string& studentID, const std::string& totalScore, const std::string& finScore, const std::string& midScore, const std::string& otherScore) {
	int index = students.findIndexOfPartialData([&](CourseStudent list) {return list.StudentID == studentID; });
	if (index == -1) return false;
	Node<ScoreStudent>* cur = scoreStudents.head;
	for (int i = 0; i < index; ++i) {
		cur = cur->next;
	}
	if (midScore != cur->data.midScore) {
		cur->data.midScore = midScore;
	}
	if (finScore != cur->data.finScore) {
		cur->data.finScore = finScore;
	}
	if (otherScore != cur->data.otherScore) {
		cur->data.otherScore = otherScore;
	}
	if (totalScore != cur->data.totalScore) {
		cur->data.totalScore = totalScore;
	}
	return true;
}

void Course::createBlankScoreFile(const std::string& schoolYear, const std::string& semester) {
	std::ofstream fout;
	fout.open("Data/" + schoolYear + "/" + semester + "/" + "scoreOfEachCourse" + courseID + ".csv");
	if (fout.is_open()) {
		fout << "No,studentID,lastName,firstName,midScore,finScore,otherScore,totalScore\n";
		int i = 1;
		Node<CourseStudent>* cur = students.head;
		fout << i++ << cur->data.StudentID << "," << cur->data.name.lastName << "," << cur->data.name.firstName << '\n';
		cur = cur->next;
	}
	fout.close();
}