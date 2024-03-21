#pragma once
#include <string>
#include "AdditionalStruct.h"
#include "Semester.h"
#include "LinkedList.h"
class SchoolYear {
private:
    int year;
    Date startDate;
    Date endDate;
    LinkedList<Semester> semesterList;

public:
    SchoolYear() :year(0), startDate(Date()), endDate(Date()) {}
    // Constructor
    SchoolYear(const int& year, const Date startDate,const Date endDate)
        : year(year), startDate(startDate), endDate(endDate) {}

    void addSemester(const Semester& smt){
        semesterList.addNodeAtFront(smt);
    }
};