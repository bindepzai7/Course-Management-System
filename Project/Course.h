#ifndef COURSE_H
#define COURSE_H

#include "AdditionalStruct.h"
#include "LinkedList.h"
#include <fstream>
#include <sstream>



class Course {

public:
    //Course basic information
    std::string courseID, courseName, session, className;
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
        bool operator=(const Student& s) {
            this->finScore = s.finScore;
            this->midScore = s.midScore;
            this->StudentID = s.StudentID;
            this->totalScore = s.totalScore;
            this->otherScore = s.otherScore;
            this->name.firstName = s.name.firstName;
            this->name.lastName = s.name.lastName;
            return true;
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

        std::string getStudentID() {
            return this->StudentID;
        }
        std::string getName() {
            return (this->name.lastName + " " + this->name.firstName);
        }
        std::string getTotalScore() {
            return this->totalScore;
        }
        std::string getMidScore() {
            return this->midScore;
        }
        std::string getFinalScore() {
            return this->finScore;
        }
        std::string getOtherScore() {
            return this->otherScore;
        }
    };
    LinkedList<Student> studentsInThisCourse;

    //Constructor
    Course();
    Course(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName, const std::string& className);

    //operator
    bool operator=(Course c) {
        this->courseID = c.courseID;
        this->courseName = c.courseName;
        this->credits = c.credits;
        this->maxStudent = c.maxStudent;
        this->validSlot = c.validSlot;
        this->teacherName = c.teacherName;
        this->session = c.session;
        this->className = c.className;
        return true;
    }
    bool operator==(const Course& c) {
        if (this->className != c.className and this->session!=c.session) return false;
        return (this->courseID == c.courseID);
    }


    //About this course's info

                /*
                File: CourseList.csv
                This File should Have the format:
                 courseID,courseName,teacherlastName,teacherfirstName,credits,maxStudent,session
                 This function will read only one course
                  if there is no more course to read it will return false

                 If used, must read the first line out first
                 */
    bool readACourseFromFileCourseList(std::ifstream& fin); //checked

             std::string getSession(); //checked
             std::string getCourseID(); //checked
             std::string getCourseName(); //checked
             std::string getTeacherName(); //checked
             std::string getClassName();
             int getCredit(); //checked
             int getMaxStudent(); //checked
             int getValidSlot();

    void setCourse(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName, const std::string& className);


    bool updateCourseInfo(const std::string& className, const std::string& courseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session);  //checked

    void saveACourseToFileCourseList(std::ofstream& fout);   //checked


    //About students in this course

    void deleteAllStudentInCourse();

    bool loadStudentsFromCsvFileStaffUpload(const std::string& filename);    //checked

    bool saveStudentsToCsvFile(const std::string& schoolYear, const std::string& semester);
   
    bool deleteStudentFromThisCourse(const std::string& studentID);   //checked

    bool addStudentToThisCourse(const std::string& studentID, const Name& name);    //checked

    bool findIfStudentIsInThisCourse(const std::string& studentID);    //checked

    bool updateStudentOfThisCourse(const std::string& studentID, const std::string& newID, const Name& name); //checked

    //About this course's students' score

    void createBlankScoreFile(const std::string& schoolYear, const std::string& semester);  //checked

    void loadScoreFromCsvScoresFile(const std::string& schoolYear, const std::string& semester);    //checked

    bool findAStudentOfThisCourse(const std::string& studentID, Student& s);    //checked

    bool updateAStudentScoreOfThisCourse(const std::string& studentID, const std::string& totalScore, const std::string& finScore, const std::string& midScore, const std::string& otherScore);  //checked

    void saveScore2CsvScoresFile(const std::string& schoolYear, const std::string& semester);    //checked


   
};


#endif