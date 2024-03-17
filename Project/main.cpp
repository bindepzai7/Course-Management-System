#include "LinkedList.h"
#include "Student.h"

int main() {
    LinkedList<Student> studentList;
    studentList.addNodeInAscending(Student("23125021", Name("Duc", "Tuan"), "290705", 0, Date(29,7,2005), "000090"));
    studentList.addNodeInAscending(Student("23125017", Name("Duc", "Tuan"), "290705", 0, Date(29, 7, 2005), "000090"));
    studentList.addNodeInAscending(Student("23125015", Name("Duc", "Tuan"), "290705", 0, Date(29, 7, 2005), "000090"));
    Node<Student>* curr = studentList.head;
    while (curr) {
        std::cout << curr->data.studentID << std::endl;
        curr = curr->next;
    }
    /*LinkedList<int> intList;
    intList.addNodeInAscending(5);
    intList.addNodeInAscending(3);
    intList.addNodeInAscending(1);
    intList.addNodeInAscending(4);
    Node<int>* curr = intList.head;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;*/
}
