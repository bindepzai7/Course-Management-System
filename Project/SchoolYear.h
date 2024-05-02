#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H


#include <string>
#include "AdditionalStruct.h"
#include "Semester.h"
#include "LinkedList.h"


class SchoolYear {
private:
    int yStart;
    int yEnd;
    std::string schoolYear;
public:
    LinkedList<Semester> semesterList;
    SchoolYear() :yStart(0), yEnd(0), schoolYear("") {}
    // Constructor
    SchoolYear(const int& yStart, const int& yEnd)
        : yStart(yStart), yEnd(yEnd), schoolYear(std::to_string(yStart) + "-" + std::to_string(yEnd)) {}
    SchoolYear(const std::string& schoolyear) : schoolYear(schoolyear), yStart(0), yEnd(0) {}
    ~SchoolYear(){}
    bool operator==(const SchoolYear& s2) const {
        return yStart == s2.yStart;
    }
    bool operator>(const SchoolYear& s2) const {
        return yStart > s2.yStart;
    }
    bool operator<(const SchoolYear& s2) const {
        return yStart < s2.yStart;
    }


    int getStartYear() {
        return yStart;
    }
    int getEndYear() {
        return yEnd;
    }
    std::string getSchoolYear() {
        return schoolYear;
    }

    bool loadSemesterListFromSemesterList();

    bool saveSemesterListToSemesterList();

    bool updateSemesterInfo(const std::string& desSemester, const std::string& newSemester, const Date& start, const Date& end);

    bool addSemester(const std::string& semester, const Date& startDate, const Date& endDate);

    bool deleteSemester(const std::string& semester);

    bool checkExistence(const std::string semester);

    int getnumberofsemeseter();
    
};




#endif