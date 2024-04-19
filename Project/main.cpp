#include<SFML/Graphics.hpp>
#include"displayfunction.h"



int main() {
    sf::RenderWindow window(sf::VideoMode(1470, 950), "Login window",sf::Style::Close);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        Staff user;
        staffHome(window, user);
        
        //chooseRole(window);
        window.display();
    }
    


    //std::string filename = "Data/studentuser.csv";
    //LinkedList<User> userList = readUserFromCSV(filename);
    //Node<User>* head = userList.head;
    ///*while (head) {
    //    head->data.password = string_hashing(head->data.password);
    //    head = head->next;
    //}*/
    ////need to update 2 times
    //updateUser2CSVfile(filename, userList);
    //if (check_login(userList, "23125001", "12345678")) std::cout << "Login successfully" << std::endl;
    //else std::cout << "password or username wrong" << std::endl;

    /*std::string filename = "Data/staffAccount.txt";
    LinkedList<Staff> staffList;
    LoadDataofStaff(staffList, filename);
    Node<Staff>* head = staffList.head;
    while (head) {
        std::cout << head->data.getStaffID() << std::endl;
        head = head->next;
    }*/
    return 0;
}
