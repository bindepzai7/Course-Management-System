#include "LinkedList.h"
#include "Student.h"

int main() {
    LinkedList<Student> studentList;
    Student s = Student("23125021", Name("Duc", "Tuan"), "290705", 0, Date(29, 7, 2005), "000090");
    /*studentList.insert(Student("23125021", Name("Duc", "Tuan"), "290705", 0, Date(29,7,2005), "000090"));*/
    Node<Student>* curr = studentList.head;
    while (curr) {
        std::cout << curr->data.studentID << std::endl;
        curr = curr->next;
    }
    return 0;
}
