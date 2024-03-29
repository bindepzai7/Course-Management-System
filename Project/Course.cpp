
#include "Course.h"

//Add truong hop head rong
//Do sth with valid spot
//Check if there is already a course like that
//sua lai ham delete dung delete node at data

//								Basic constructor

Course::Course() {
	this->maxStudent = 50;
	this->credits = 0;
	this->courseID = "";
	this->validSlot = maxStudent;
}

Course::Course(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName) {
	if (maxStudent == NULL) {
		this->maxStudent = 50; //Default maxStudent
	}
	else this->maxStudent = maxStudent;
	this->courseID = courseID;
	this->courseName = courseName;
	this->teacherName = teacherName;
	this->validSlot = maxStudent;
	this->session = session;
	this->credits = credits;
}





//								About this course's info

bool Course::readACourseFromFileCourseList(std::ifstream& fin) {
	/*
	File: CourseList.csv
	This File should Have the format:
	courseID,courseName,teacherlastName,teacherfirstName,credits,maxStudent,session
	This function will read only one course
	if there is no more course to read it will return false
	*/
	if (getline(fin,this->courseID, ',')) {
		getline(fin, this->courseName, ',');
		getline(fin, this->teacherName.lastName, ',');
		getline(fin, this->teacherName.firstName, ',');
		fin >> (credits);
		fin.ignore(1000, ',');
		fin >> (maxStudent);
		this->validSlot = maxStudent;
		fin.ignore(1000, ',');
		getline(fin, session, '\n');
		return true;
	}
	return false;
}

std::string Course::getSession() {
	//stringSession ex: TUE, 7:30-10:30
	return this->session;
};
std::string Course::getCourseID() {
	return this->courseID;
}
std::string Course::getCourseName() {
	return this->courseName;
}
Name Course::getTeacherName() {
	return (this->teacherName.lastName + "," + this->teacherName.firstName);
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

bool Course::updateCourseInfo(const std::string& courseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session) {
	int a = this->maxStudent - MaxStudent;
	if (this->validSlot - a < 0) return false;
	this->validSlot -= a;
	this->session = session;
	this->courseID = courseID;
	this->courseName = courseName;
	this->teacherName.firstName = teacher.firstName;
	this->teacherName.lastName = teacher.lastName;
	this->maxStudent = MaxStudent;
	return true;
	
};

void Course::saveACourseToFileCourseList(std::ofstream& fout) {
	fout << this->courseID << "," << this->courseName << "," << this->teacherName.lastName << ',' << this->teacherName.firstName << ','
		<< this->credits << "," << this->maxStudent << ',' << this->session << '\n';
}



//								About students in this course

bool Course::loadStudentsFromCsvFileStaffUpload(const std::string& schoolYear, const std::string& semester) {
	/*
	These files should be the ones that staffs upload.
	Staff will upload this file and it will go to the studentOfEachCourse folder.
	*/

	studentsInThisCourse.empty(); //If we already load students from another course

	std::ifstream fin;
	fin.open ("Data/" + schoolYear + "/" + semester + "studentOfEachCourse" + courseID + ".cvs");

	if (fin.is_open()) {
		std::string input = "";
		getline(fin, input); //ignore the first line

		while (!fin.eof() and validSlot!=0) {
			//Read each student one by one 
			Student student;
			getline(fin, input, ',');
			if (input == "") break; //If there isn't No(1,2,3,4...) then there is no more student
			getline(fin, student.StudentID, ',');
			getline(fin, student.name.lastName, ',');
			getline(fin, student.name.firstName, '\n');
			studentsInThisCourse.addNodeInAscending(student);
			validSlot--;
		}
	}
	fin.close();
	if (validSlot == 0 and !fin.eof()) return false;
	return true;
}
		//We dont need to save back to the file staffs uploaded because we will store students data in the Score csv file
		//Or is it?
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

void Course::addStudentToThisCourse(const std::string& studentID, const Name& name) {
	Student student;
	student.StudentID = studentID;
	student.name = name;
	studentsInThisCourse.addNodeInAscending(student);
	--validSlot;
}

bool Course::updateStudentOfThisCourse(const std::string& studentID, const Name& name) {
	Node<Student>* cur = studentsInThisCourse.head;
	while (cur) {
		if (cur->data.StudentID == studentID) {
			cur->data.StudentID = studentID;
			cur->data.name = name;
			return true;
		}
		cur = cur->next;
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
	fout.open("Data/" + schoolYear + "/" + semester + "/" + "scoreOfEachCourse" + courseID + ".csv");
	if (fout.is_open()) {
		fout << "No,studentID,lastName,firstName,midScore,finScore,otherScore,totalScore\n";
		int i = 1;
		Node<Student>* cur = studentsInThisCourse.head;
		fout << i++ << cur->data.StudentID << "," << cur->data.name.lastName << "," << cur->data.name.firstName << '\n';
		cur = cur->next;
	}
	fout.close();
}

void Course::loadScoreFromCsvScoresFile(const std::string& schoolYear, const std::string& semester) {
	std::ifstream fin("Data/" + schoolYear + "/" + semester + "scoreOfEachCourse" + courseID + ".cvs");
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

Course::Student Course::findAStudentScoreOfThisCourse(const std::string& studentID) {
	Node<Student>* cur = studentsInThisCourse.head;
	while (cur) {
		if (cur->data.StudentID == studentID) {
			
			return cur->data;
		}
		cur = cur->next;
	}
	Student student;
	return student;
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
	std::ofstream fout("Data/" + schoolYear + "/" + semester + "scoreOfEachCourse" + courseID + ".cvs");
	if (fout.is_open()) {
		Node<Student>* cur = studentsInThisCourse.head;
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

std::string Course::getFinScoreOfAStudent(std::string studentID) {
	Node<Student>* cur = studentsInThisCourse.head;
	while (cur) {
		if (cur->data.StudentID == studentID) {
			return cur->data.finScore;
		}
		cur = cur->next;
	}
	return "";
}