

#include "Course.h"

Course::Course() {
	maxStudent = 50;

	//on going
}

std::pair<std::string, std::pair<int, int> > Course::getDayAndSession() const {

	//stringSession ex: TUE, 7:30-10:30
	std::stringstream stringSession(this->session);
	std::string day, time;
	int startTime, endTime;
	stringSession >> day; //Read all char: MON, TUE, WED...
	stringSession.ignore(100, ' '); //Ignore till the next element;
	getline(stringSession, time, '-'); // get the start time as ex: 7:30
	startTime = getTimeInMinute(time);
	getline(stringSession, time);
	endTime = getTimeInMinute(time);
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
		//HELP HOW TO FIX THIS
		std::cout << "Please enter first name of teacher: ";
		getline(std::cin, s1);
		getline(std::cin, s2);
		this->techerName = Name(s1, s2);
		break;
	case 5:
		//Is it alright or not?
		std::cout << "Please enter new number of credits: ";
		while (!std::cin >> this->numberOfCredits && this->numberOfCredits >= 0) {
			std::cout << "Warning: the number of credits is not positive\n";
		}
		break;
	case 6:
		//I Dont wanna check correct anymore im too sleepy
		std::cout << "Please enter the maximum number of students in a course: ";
		if (!std::cin >> this->maxStudent or this->maxStudent <= 0)
			std::cout << "Input number is invalid\n";
		break;
	case 7:
		std::cout << "Please enter day and session: Ex: TUE, 7:30";
		getline(std::cin, this->session);
		break;
	default:
	}
	return true;
};

