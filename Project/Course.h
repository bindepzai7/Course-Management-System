#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include "LinkedList.h"
#include "Class.h"
#include <fstream>

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

    LinkedList<CourseStudent> students;
    std::string courseID, courseName, session;
    int No, credits, maxStudent;
    Name teacherName;
   


    Course();

    bool readCourseFromCsvFile(std::ifstream& fin);

    void loadCourseStudentsFromCsvFile(const std::string& schoolYear, const std::string& semester);

    void saveCourseStudents2CsvFile(const std::string& schoolYear, const std::string& semester);

    bool updateCourse();

    //get session data as a string (MON, TUE, ...) and an int (time in minutes)
    std::pair<std::string, std::pair<int, int>> getDayAndSession() const;

    bool delStudentOfThisCourse(const std::string& studentID);

    bool updateStudentOfThisCourse(const std::string& studentID, const Name& name);

    void loadScoreCourseStudents(const std::string& schoolYear, const std::string& semester);

    std::string getFinScoreOfStudent(const std::string& schoolYear, const std::string& semester, const std::string& studentID);


};

\

#endif