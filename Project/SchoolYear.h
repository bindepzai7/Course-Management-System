#pragma once
#include <string>
#include "AdditionalStruct.h"

class SchoolYear {
private:
    int year;
    Date startDate;
    Date endDate;
public:
    SchoolYear() :year(0), startDate(Date()), endDate(Date()) {}
    // Constructor
    SchoolYear(const int& year, const Date startDate,const Date endDate)
        : year(year), startDate(startDate), endDate(endDate) {}
};