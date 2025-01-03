
#include "Course.h"


//								Basic constructor

Course::Course() {
	this->maxStudent = 50;
	this->credits = 0;
	this->courseID = "";
	this->validSlot = maxStudent;
}




//								About this course's info


bool Course::readACourseFromFileCourseList(std::ifstream& fin) {
	std::string No;
	if (getline(fin, No, ',')) {
		getline(fin, this->courseID, ',');
		getline(fin, this->courseName, ',');
		getline(fin, this->teacherName.lastName, ',');
		getline(fin, this->teacherName.firstName, ',');
		fin >> (credits);
		fin.ignore(1000, ',');
		fin >> (maxStudent);
		this->validSlot = maxStudent;
		fin.ignore(1000, ',');
		getline(fin, session, ',');
		getline(fin, className, '\n');
		return true;
	}
	return false;
}

void Course::deleteAllStudentInCourse() {
	studentsInThisCourse.empty();
}

void Course::setCourse(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName, const std::string& className) {
	if (maxStudent == NULL) {
		this->maxStudent = 50; //Default maxStudent
	}
	else this->maxStudent = maxStudent;
	this->courseID = courseID;
	this->className = className;
	this->courseName = courseName;
	this->teacherName = teacherName;
	this->validSlot = maxStudent;
	this->session = session;
	this->credits = credits;
}

std::string Course::getSession() {
	//stringSession ex: TUE 7:30-10:30
	return this->session;
};
std::string Course::getCourseID() {
	return this->courseID;
}
std::string Course::getCourseName() {
	return this->courseName;
}
std::string Course::getTeacherName() {
	return (this->teacherName.lastName + "-" + this->teacherName.firstName);
}
int Course::getCredit() {
	return this->credits;
}
int Course::getMaxStudent() {
	return this->maxStudent;
}
int Course::getValidSlot() {
	return this->validSlot;
}
std::string Course::getClassName() {
	return this->className;
}

bool Course::updateCourseInfo(const std::string& className, const std::string& courseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session) {
	if (MaxStudent > 0) {
		int a = MaxStudent - this->maxStudent;
		if (this->validSlot + a < 0) return false;
		this->validSlot += a;
		this->maxStudent = MaxStudent;
	}
	if (session != "") {
		this->session = session;
	}
	if (courseID != "") {
		this->courseID = courseID;
	}
	if (courseName != "") {
		this->courseName = courseName;
	}
	if (credits > 0) {
		this->credits = credits;
	}
	if (teacher.firstName != "") {
		this->teacherName.firstName = teacher.firstName;
	}
	if (teacher.lastName != "") {
		this->teacherName.lastName = teacher.lastName;
	}
	if (className != "") {
		this->className = className;
	}
	return true;
	
};

void Course::saveACourseToFileCourseList(std::ofstream& fout) {
	fout << this->courseID << "," << this->courseName << "," << this->teacherName.lastName << ',' << this->teacherName.firstName << ','
		<< this->credits << "," << this->maxStudent << ',' << this->session << "," << this->className << '\n';
}



//								About students in this course

bool Course::loadStudentsFromCsvFileStaffUpload(const std::string& filename) {
	/*
	These files should be the ones that staffs upload.
	Staff will upload this file and it will go to the studentOfEachCourse folder.
	*/
	//I delete the valid spot 
	//studentsInThisCourse.empty(); //If we already load students from another course

	std::ifstream fin;
	//fin.open("Data/" + schoolYear + "/" + semester + "/studentOfEachCourse/" + this->courseID + ".csv");
	fin.open(filename);
	if (!fin.is_open()) {
		fin.close();
		return false;
	}
	std::string input = "";
	getline(fin, input); //ignore the first line

	while (!fin.eof()) {
		//Read each student one by one 
		Student student;
		getline(fin, input, ',');
		if (input == "") break; //If there isn't No(1,2,3,4...) then there is no more student
		getline(fin, student.StudentID, ',');
		getline(fin, student.name.lastName, ',');
		getline(fin, student.name.firstName, '\n');
		
		int found = student.name.firstName.find_last_of(",");
		while (found != std::string::npos) {
			student.name.firstName = student.name.firstName.substr(0, found);
			found = student.name.firstName.find_last_of(",");
		}
		studentsInThisCourse.addNodeInAscending(student);
	}
	fin.close();
	if ( !fin.eof()) return false;
	return true;
}
		
bool Course::deleteStudentFromThisCourse(const std::string& studentID) {
	Node<Student>* cur = studentsInThisCourse.head;
	int index = 0;
	while (cur) {
		if (cur->data.StudentID == studentID) {
			studentsInThisCourse.deleteAt(index); 
			++validSlot;
			return true;
		}
		cur = cur->next;
		++index;
	}
	return false;
}

bool Course::addStudentToThisCourse(const std::string& studentID, const Name& name) {
	if (!this->findIfStudentIsInThisCourse(studentID)) {
		Student student;
		student.StudentID = studentID;
		student.name = name;
		studentsInThisCourse.addNodeInAscending(student);
		return true;
	}
	return false;
}

bool Course::findIfStudentIsInThisCourse(const std::string& studentID) {
	Node<Student>* cur = studentsInThisCourse.head;
	while (cur) {
		if (cur->data.StudentID == studentID) {
			return true;
		}
		cur = cur->next;
	}
	return false;
}



//								About this course's students' score

void Course::createBlankScoreFile(const std::string& schoolYear, const std::string& semester) {
	std::ofstream fout;
	fout.open("Data/" + schoolYear + "/" + semester + "/scoreOfEachCourse/" + this->courseID + ".csv");
	if (fout.is_open()) {
		fout << "No,studentID,lastName,firstName,midScore,finScore,otherScore,totalScore\n";
		int i = 1;
		Node<Student>* cur = studentsInThisCourse.head;
		while (cur) {
			fout << i++ << "," << cur->data.StudentID << "," << cur->data.name.lastName << "," << cur->data.name.firstName << ",,,," << '\n';
			cur = cur->next;
		}
	}
	fout.close();
}

void Course::loadScoreFromCsvScoresFile(const std::string& schoolYear, const std::string& semester) {
	studentsInThisCourse.empty();
	std::ifstream fin("Data/" + schoolYear + "/" + semester + "/scoreOfEachCourse/" + this->courseID + ".csv");
	if (fin.is_open()) {
		std::string input = "";
		getline(fin, input); //Ignore the fisrt line
		while (!fin.eof()) {
			Student student;
			getline(fin, input, ',');
			if (input == "") break;
			getline(fin, student.StudentID, ',');
			getline(fin, student.name.lastName, ',');
			getline(fin, student.name.firstName, ',');
			getline(fin, student.midScore, ',');
			getline(fin, student.finScore, ',');
			getline(fin, student.otherScore, ',');
			getline(fin, student.totalScore, '\n');
			studentsInThisCourse.addNodeInAscending(student);
		}
	}
	fin.close();
}

bool Course::findAStudentOfThisCourse(const std::string& studentID, Course::Student& s) {
	Node<Course::Student>* cur = studentsInThisCourse.head;
	while (cur) {
		if (cur->data.StudentID == studentID and cur->data.getFinalScore()!="") {
			s = cur->data;
			return true;
		}
		cur = cur->next;
	}

	return false;
}

Node<Course::Student>* Course::findAStudentPosOfThisCourse(const std::string& studentID) {
	Node<Course::Student>* cur = studentsInThisCourse.head;
	while (cur) {
		if (cur->data.StudentID == studentID) {
			return cur;
		}
		cur = cur->next;
	}

	return nullptr;
}

bool Course::updateAStudentScoreOfThisCourse(const std::string& studentID, const std::string& totalScore, const std::string& finScore, const std::string& midScore, const std::string& otherScore) {
	Node<Student>* cur = studentsInThisCourse.head;
	while (cur) {
		if (cur->data.StudentID == studentID) {
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
		cur = cur->next;
	}
	return false;
}

void Course::saveScore2CsvScoresFile(const std::string& schoolYear, const std::string& semester) {
	std::ofstream fout("Data/" + schoolYear + "/" + semester + "/scoreOfEachCourse/" + this->courseID + ".csv");
	if (fout.is_open()) {
		Node<Student>* cur = studentsInThisCourse.head;
		int i = 0;
		fout << "No,studentID,lastName,firstName,midScore,finScore,otherScore,totalScore\n";
		while (cur) {
			fout << ++i << "," << cur->data.StudentID << "," << cur->data.name.lastName << "," << cur->data.name.firstName
				<< "," << cur->data.midScore << "," << cur->data.finScore << "," << cur->data.otherScore << "," << cur->data.totalScore << '\n';
			cur = cur->next;
		}
	}
	fout.close();
}

