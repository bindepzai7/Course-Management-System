#ifndef COURSE_H
#define COURSE_H

#include "AdditionalStruct.h"
#include "LinkedList.h"
#include <fstream>
#include <sstream>


class Course {
private:

        //Course basic information
    std::string courseID, courseName, session;
    int credits, maxStudent, validSlot;
    Name teacherName;

        //Course's students' info and score struct
    struct Student {
        std::string StudentID;
        Name name;
        std::string totalScore, finScore, midScore, otherScore;
        Student() {
            StudentID = "";
            totalScore = "";
            finScore = "";
            midScore = "";
            otherScore = "";
        }
        bool operator==(const Student& s2) const {
            return StudentID == s2.StudentID;
        }

        bool operator>(const Student& s2) const {
            return StudentID > s2.StudentID;
        }

        bool operator<(const Student& s2) const {
            return StudentID < s2.StudentID;
        }
    };
    //Course's student list
    LinkedList<Student> studentsInThisCourse;
public:

    //Constructor
    Course();
    Course(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName);

    //operator
    bool operator==(std::string courseID) {
        return (this->courseID == courseID);
    }


    //About this course's info
    bool readACourseFromFileCourseList(std::ifstream& fin);

    std::string getSession();
    std::string getCourseID();
    std::string getCourseName();
    Name getTeacherName();
    int getCredit();
    int getMaxStudent();
    int getValidSlot();

    bool updateCourseInfo(const std::string& courseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session);

    void saveACourseToFileCourseList(std::ofstream& fout);


    //About students in this course
    bool loadStudentsFromCsvFileStaffUpload(const std::string& schoolYear, const std::string& semester);
   
    bool deleteStudentFromThisCourse(const std::string& studentID);

    void addStudentToThisCourse(const std::string& studentID, const Name& name);

    bool findIfStudentIsInThisCourse(const std::string& studentID);

    bool updateStudentOfThisCourse(const std::string& studentID, const Name& name);

    //About this course's students' score

    void createBlankScoreFile(const std::string& schoolYear, const std::string& semester);

    void loadScoreFromCsvScoresFile(const std::string& schoolYear, const std::string& semester);

    Student findAStudentScoreOfThisCourse(const std::string& studentID);

    bool updateAStudentScoreOfThisCourse(const std::string& studentID, const std::string& totalScore, const std::string& finScore, const std::string& midScore, const std::string& otherScore);

    void saveScore2CsvScoresFile(const std::string& schoolYear, const std::string& semester);

    std::string getFinScoreOfAStudent(std::string studentID);

   
};


#endif