#include "function.h"

int main() {
    LinkedList<Student> studentList;
    studentList.insert(Student("23125021", "Tuan"));
    studentList.insert(Student("23120000", "nguyen"));
    studentList.insert(Student("23120001", "uyen"));
    studentList.removedatafromfirst();
    Node<Student>* curr = studentList.getlist();
    while (curr) {
        std::cout << curr->data.studentID << std::endl;
        curr = curr->next;
    }
    return 0;
}