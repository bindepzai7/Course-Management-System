#include "LinkedList.h"
#include "Student.h"

int main() {
    LinkedList<Student> studentList;
    studentList.addNodeInAscending(Student("23125021", Name("Duc", "Tuan"), "290703", 0, Date(29,7,2005), "000090"));
    studentList.addNodeInAscending(Student("23125017", Name("Duc", "Tuan"), "290708", 0, Date(29, 7, 2005), "000090"));
    studentList.addNodeInAscending(Student("23125015", Name("Duc", "Tuan"), "290705", 0, Date(29, 7, 2005), "000090"));
    studentList.addNodeInAscending(Student("23125015", Name("Duc", "Tuan"), "290705", 0, Date(29, 7, 2005), "000090"));
    if (studentList.findXData(Student("23125017", "290703")))
        std::cout << "OK";
    else std::cout << "username or password is not true, please try again";
    /*Node<Student>* curr = studentList.head;
    while (curr) {
        std::cout << curr->data.studentID << std::endl;
        curr = curr->next;
    }
    */
}
