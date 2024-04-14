#include "function.h"
#include "user.h"
#include <iostream>

int main() {
    std::string filename = "studentuser.csv";
    LinkedList<User> userList = read_csv(filename);
    Node<User>* head = userList.head;
    write_csv(filename, userList);
    if (login(userList, "23125020", "123456789")) std::cout << "Login successfully" << std::endl;
    else std::cout << "password or username wrong" << std::endl;
}
