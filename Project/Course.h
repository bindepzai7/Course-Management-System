#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include "LinkedList.h"
#include "Class.h"


#include <sstream>


class Course {
private:
    struct CourseStudent {
        std::string StudentID;
        Name name;
    };
    struct ScoreStudent {
        std::string StudentID;
        Name name;
        std::string totalScore, finScore, midScore, otherScore;
    };

public:

    LinkedList<Class> classList;
    LinkedList<std::string> sessions;
    std::string courseID, courseName, session;
    int numberOfCredits;
    Name techerName;
    int maxStudent;
    LinkedList<ScoreStudent> scoreStudents;
    Course();

    bool updateCourse();

    //get session data as a string (MON, TUE, ...) and an int (time in minutes)
    std::pair<std::string, std::pair<int, int>> getDayAndSession() const;

    //What is this?
    void saveCourseStudents();


    void deleteCourseStudents(const std::string ID);



};



#endif