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

        bool operator==(const CourseStudent& s2) const {
            return StudentID == s2.StudentID;
        }

        bool operator>(const CourseStudent& s2) const {
            return StudentID > s2.StudentID;
        }

        bool operator<(const CourseStudent& s2) const {
            return StudentID < s2.StudentID;
        }
    };
    struct ScoreStudent {
        std::string StudentID;
        Name name;
        std::string totalScore, finScore, midScore, otherScore;
        ScoreStudent() {
            StudentID = "";
            totalScore = "";
            finScore = "";
            midScore = "";
            otherScore = "";
        }
    };

public:
    LinkedList<ScoreStudent> scoreStudents;
    LinkedList<CourseStudent> students;
    std::string courseID, courseName, session;
    int credits, maxStudent;
    Name teacherName;
   

    Course();

    Course(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName);

    bool readCourseFromCsvFile(std::ifstream& fin);

    void loadCourseStudentsFromCsvFile(const std::string& schoolYear, const std::string& semester);

    void saveCourseStudents2CsvFile(const std::string& schoolYear, const std::string& semester);

    bool updateCourse();

    //get session data as a string (MON, TUE, ...) and an int (time in minutes)
    std::pair<std::string, std::pair<int, int>> getDayAndSession() const;

    bool delStudentOfThisCourse(const std::string& studentID);

    void addStudentToThisCourse(const std::string& studentID, const Name& name);

    bool findStudentOfThisCourse(const std::string& studentID);

    bool updateStudentOfThisCourse(const std::string& studentID, const Name& name);

    void loadStudentScoreFromCvsFile(const std::string& schoolYear, const std::string& semester);

    void saveStudentScore2CsvFile(const std::string& schoolYear, const std::string& semester);

    void createBlankScoreFile(const std::string& schoolYear, const std::string& semester);

    ScoreStudent findAStudentScoreOfThisCourse(const std::string& studentID);

    bool updateAStudentScoreOfThisCourse(const std::string& studentID, const std::string& totalScore, const std::string& finScore, const std::string& midScore, const std::string& otherScore);

};


#endif