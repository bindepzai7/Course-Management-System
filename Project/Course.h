#ifndef COURSE_H
#define COURSE_H

#include "AdditionalStruct.h"
#include "LinkedList.h"
#include <fstream>
#include <sstream>



class Course {
private:
    //Course basic information
    std::string courseID, courseName, session, className;
    int credits, maxStudent, validSlot;
    Name teacherName;
public:
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
            return (this->name.lastName + "-" + this->name.firstName);
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
    Course(const std::string& courseID) {
        this->courseID = courseID;
        courseName = "";
        credits =0;
        maxStudent = 0;
        validSlot = 0;
        session = "";
        className = "";
    }
    ~Course() {}
    //operator
    void operator=(const Course& c) {
        courseID = c.courseID;
        courseName = c.courseName;
        credits = c.credits;
        maxStudent = c.maxStudent;
        validSlot = c.validSlot;
        teacherName = c.teacherName;
        session = c.session;
        className = c.className;
    }
    bool operator==(const Course& c) {
        if (this->className != c.className and this->session!=c.session) return false;
        return (this->courseID == c.courseID);
    }
    bool operator<(const Course& c) {
        if (this->courseID < c.courseID) return true;
        else return false;
    }

    //About this course's info
    bool readACourseFromFileCourseList(std::ifstream& fin); //checked
    
    std::string getSession(); //checked
    std::string getCourseID(); //checked
    std::string getCourseName(); //checked
    std::string getTeacherName(); //checked
    std::string getClassName();
    int getCredit(); //checked
    int getMaxStudent(); //checked
    int getValidSlot();
    void setSession(const std::string& session) {
        this->session = session;
    }
    void setCourseID(const std::string& courseID) {
        this->courseID = courseID;
    }
    void setCourseName(const std::string& courseName) {
        this->courseName = courseName;
    }
    void setTeacherName(const std::string& firstName, const std::string& lastName) {
        this->teacherName.firstName = firstName;
        this->teacherName.lastName = lastName;
    }
    void setClassName(const std::string& className) {
        this->className = className;
    }
    void setCredit(const int& credits) {
        this->credits = credits;
    }
    void setMaxStudent(const int& maxStudent) {
        this->maxStudent = maxStudent;
    }

    void setCourse(const std::string& courseID, const std::string& courseName, const std::string& session, const int& credits, const int& maxStudent, const Name& teacherName, const std::string& className);

    bool updateCourseInfo(const std::string& className, const std::string& courseID, const std::string& courseName, const Name& teacher, const int& MaxStudent, const int& credits, const std::string& session);  //checked

    void saveACourseToFileCourseList(std::ofstream& fout);   //checked


    //About students in this course

    int countStudent() {
        return studentsInThisCourse.sizeoflist();
    }

    void deleteAllStudentInCourse();

    bool loadStudentsFromCsvFileStaffUpload(const std::string& filename);    //checked

   
    bool deleteStudentFromThisCourse(const std::string& studentID);   //checked

    bool addStudentToThisCourse(const std::string& studentID, const Name& name);    //checked

    bool findIfStudentIsInThisCourse(const std::string& studentID);    //checked


    //About this course's students' score

    void createBlankScoreFile(const std::string& schoolYear, const std::string& semester);  //checked

    void loadScoreFromCsvScoresFile(const std::string& schoolYear, const std::string& semester);    //checked

    bool findAStudentOfThisCourse(const std::string& studentID, Student& s);    //checked

    Node<Course::Student>* findAStudentPosOfThisCourse(const std::string& studentID);

    bool updateAStudentScoreOfThisCourse(const std::string& studentID, const std::string& totalScore, const std::string& finScore, const std::string& midScore, const std::string& otherScore);  //checked

    void saveScore2CsvScoresFile(const std::string& schoolYear, const std::string& semester);    //checked

   
};


#endif