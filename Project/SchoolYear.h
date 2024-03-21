#pragma once
#include <string>
#include "AdditionalStruct.h"
#include "Semester.h"
#include "LinkedList.h"
class SchoolYear {
private:
    int yearstart;
    int yearend;
    LinkedList<Semester> semesterList;

public:
    SchoolYear() :yearstart(0), yearend(0) {}
    // Constructor
    SchoolYear(const int& yearstart, const int& yearend)
        : yearstart(yearstart), yearend(yearend) {}

    void addSemester(const Semester& smt){
        semesterList.addNodeAtFront(smt);
    }
    int getyearstart() {
        return yearstart;
    }
    int getyearend() {
        return yearend;
    }
};