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

    bool operator==(const SchoolYear& s2) const {
        return yearstart == s2.yearstart;
    }

    bool operator>(const SchoolYear& s2) const {
        return yearstart > s2.yearstart;
    }
    bool operator<(const SchoolYear& s2) const {
        return yearstart < s2.yearstart;
    }

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