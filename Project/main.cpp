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
        chooseRole(window);
        window.display();
    }
    return 0;
    


    //std::string filename = "Data/staffuser.csv";
    //LinkedList<User> userList = readUserFromCSV(filename);
    //Node<User>* head = userList.head;
    ////need to update 2 times
    //updateUser2CSVfile(filename, userList);
    //if (check_login(userList, "dinhbatien", "12345678")) std::cout << "Login successfully" << std::endl;
    //else std::cout << "password or username wrong" << std::endl;


    /*std::string filename = "Data/staffAccount.txt";
    LinkedList<Staff> staffList;
    LoadDataofStaff(staffList, filename);
    Node<Staff>* head = staffList.head;
    while (head) {
        std::cout << head->data.getStaffID() << std::endl;
        head = head->next;
    }*/

}
