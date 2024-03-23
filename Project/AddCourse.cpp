#include "AddCourse.h"

bool AddCourse::writeData2File() {
    std::ifstream fin("Data/" + this->schoolYear + "/" + this->semester + "/CourseEndAndStartDate.txt");
    if (fin.is_open()) {

        bool success = false;
        std::string id, dates;
        LinkedList<std::string> courseList;

        //get all the old courses' data
        while (getline(fin, id)) {
            courseList.push_head(id);
        }

        //get the newly added course's data
        std::stringstream newCourse;
        newCourse << (this->courseID) << (this->startDate).day << " " << (this->startDate).month << " " << (this->startDate).year << " "
              << (this->endDate).day << " " << (this->endDate).month << " " << (this->endDate).year << " ";
        success = true;
        getline(newCourse, dates);
        courseList.push_head(dates);
        fin.close();

        //print all the data to text file
        std::ofstream fout("Data/" + this->schoolYear + "/" + this->semester + "/CourseEndAndStartDate.txt");
        while (courseList.head) {
            std::string data;
            courseList.pop_head(data);
            fout << data << std::endl;
        }
        fout.close();
        return success;
    }
    fin.close();
    return false;
}


AddCourse::AddCourse(const std::string& schoolYear, const std::string& semester, const std::string& courseID, const Date& startDate, const Date& endDate) {
    this->schoolYear = schoolYear;
    this->semester = semester;
    this->courseID = courseID;
    this->startDate = startDate;
    this->endDate = endDate;
}

bool AddCourse::checkValid() {
    Date today = Date::getCurrentDate();
    return (today < startDate);
}

void AddCourse::createCourse(const std::string& schoolYear, const std::string& semester) {
    this->schoolYear = schoolYear;
    this->semester = semester;
    //Course ID will be added on later
};

Date AddCourse::getStartDate() const {
    return this->startDate;
};
Date AddCourse::getEndDate() const {
    return this->endDate;
}
std::string AddCourse::getID() const
{
    return this->courseID;
}

bool AddCourse::loadDates() {
    std::ifstream fin("Data/" + (this->schoolYear) + "/" + semester + "/CourseEndAndStartDate.txt");
    if (fin) {
        std::string id;
        int d, m, y;
        Date start, end;
        while (fin >> id) {
            fin >> d >> m >> y;
            start.setDate(d, m, y);
            fin >> d >> m >> y;
            end.setDate(d, m, y);
            if (id == (this->courseID)) {
                fin.close();
                this->startDate = start;
                this->endDate = end;
                return true;
            }
        }
    }
    fin.close();
    return false;
};

bool AddCourse::loadData(std::ifstream& fin) {
    std::string id;
    int day, month, year;
    if (fin >> id) {
        (this->courseID) = id;
        fin >> day >> month >> year;
        (this->startDate).setDate(day, month, year);
        fin >> day >> month >> year;
        (this->endDate).setDate(day, month, year);
        return true;
    }
    return false;
};