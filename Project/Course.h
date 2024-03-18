#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include "LinkedList.h"
#include "Class.h"

class Course {

    LinkedList<Class> classList;

    std::string courseID;
    std::string courseName;
    int numberOfCredits;
    Name techerName;
    int maxStudent;

};



#endif