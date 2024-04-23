

#include "SchoolYear.h"


bool SchoolYear::loadSemesterListFromSemesterList() {
    semesterList.empty();
    std::ifstream fin;
    fin.open("Data/" + schoolYear + "/semesterStartAndEndDate.txt");
    if (fin.is_open()) {
        Semester s;
        while (s.readASemesterFromCsvFile(fin)) {
            semesterList.addNodeInAscending(s);
        }
        fin.close();
        return true;
    }
    fin.close();
    return false;
}

bool SchoolYear::saveSemesterListToSemesterList() {
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

bool SchoolYear::updateSemesterInfo(const std::string& desSemester, const std::string& newSemester, const Date& start, const Date& end) {
    Node<Semester>* cur = semesterList.head;
    while (cur) {
        if (cur->data.getSemester() == desSemester) {
            cur->data.updateSemesterInfo(newSemester, start, end);
            return true;
        }
    }
    return false;
}

bool SchoolYear::addSemester(const std::string& semester, const Date& startDate, const Date& endDate) {
    if (!checkExistence(semester)) {
        Semester s(semester, startDate, endDate);
        if (s.addNewSemesterFolder(schoolYear, semester)) {
            semesterList.addNodeAtFront(s);
            saveCurrentSemestertofile(schoolYear, semester);
            saveSemesterListToSemesterList();
            return true;
        }

    }
    return false;
}

bool SchoolYear::deleteSemester(const std::string& semester) {
    Node<Semester>* cur = semesterList.head;
    int index = 0;
    while (cur) {
        if (cur->data.getSemester() == semester) {
            if (schoolYear == getCurrentSchoolyear()) {
                if (semester == getCurrentSemester()) {
                    return false;
                }
            }
            cur->data.deleteSemesterFolder(schoolYear);
            semesterList.deleteAt(index);
            saveSemesterListToSemesterList();
            return true;
        }
        cur = cur->next;
        ++index;
    }
    return false;
}

bool SchoolYear::checkExistence(const std::string semester) {
    Node<Semester>* cur = semesterList.head;
    while (cur) {
        if (cur->data.getSemester() == semester) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

int SchoolYear::getnumberofsemeseter() {
    return semesterList.sizeoflist();
}