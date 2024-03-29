#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H


#include <string>
#include "AdditionalStruct.h"
#include "Semester.h"
#include "LinkedList.h"



class SchoolYear {
private:
    int yStart;
    int yEnd;
    std::string schoolYear;
    LinkedList<std::string> schoolYearList;
    LinkedList<Semester> semesterList;

public:
    SchoolYear() :yStart(0), yEnd(0), schoolYear("") {}
    // Constructor
    SchoolYear(const int& yStart, const int& yEnd)
        : yStart(yStart), yEnd(yEnd), schoolYear(yStart+"-"+yEnd) {}

    bool operator==(const SchoolYear& s2) const {
        return yStart == s2.yStart;
    }
    bool operator>(const SchoolYear& s2) const {
        return yStart > s2.yStart;
    }
    bool operator<(const SchoolYear& s2) const {
        return yStart < s2.yStart;
    }


    int getStartYear() {
        return yStart;
    }
    int getEndYear() {
        return yEnd;
    }
    std::string getSchoolYear() {
        return schoolYear;
    }

    bool loadSemesterListFromSemesterList() {
        std::ifstream fin;
        fin.open("Data/" + schoolYear + "/semesterStartAndEndDate.txt"); 
        if (fin.is_open()) {
            Semester s;
            while (s.readASemesterFromCsvFile(fin)) {
                semesterList.addNodeAtFront(s);
            }
            fin.close();
            return true;
        }
        fin.close();
        return false;
    }

    bool saveSemesterListToSemesterList() {
        std::ofstream fout;
        fout.open("Data/" + schoolYear + "/semesterStartAndEndDate.txt");
        if (fout.is_open()) {
            Semester s;
            while (semesterList.pop_head(s)) {
                s.saveASemesterToCsvFile(fout);
            }
            fout.close();
            return true;
        }
        fout.close();
        return false;
    }

  
    bool updateSemesterInfo(const std::string& desSemester, const std::string& newSemester, const std::string& schoolYear, const Date& start, const Date& end) {
        Node<Semester>* cur = semesterList.head;
        while (cur) {
            if (cur->data.getSemester() == desSemester) {
                cur->data.updateSemesterInfo(newSemester, schoolYear, start, end);
                return true;
            }
        }
        return false;
    }


    bool addSemester(const std::string& semester, const std::string& schoolYear, const Date& startDate, const Date& endDate) {
        if (!checkExistence(semester)) {
            Semester s(semester, schoolYear, startDate, endDate);
            semesterList.addNodeAtFront(s);
            return true;
        }
        return false;
    }


    bool deleteSemester(const std::string& semester) {
        Node<Semester>* cur = semesterList.head;
        int index = 0;
        while (cur) {
            if (cur->data.getSemester() == semester) {
                semesterList.deleteAt(index);
                return true;
            }
            cur = cur->next;
            ++index;
        }
        return false;
    }

    bool checkExistence(const std::string semester) {
        Node<Semester>* cur = semesterList.head;
        while (cur) {
            if (cur->data.getSemester() == semester) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool getCurrentSemester() {
        std::ifstream fin;
        fin.open("Data/CurrentSemester.txt");
        if (fin.is_open()) {
         


            fin.close();
            return true;
        }
        fin.close();
        return false;
    }
    void setCurrentSemester() {}




};




#endif