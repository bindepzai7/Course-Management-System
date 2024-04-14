#include<SFML/Graphics.hpp>
#include"displayfunction.h"



int main() {
    /*sf::RenderWindow window(sf::VideoMode(1470, 950), "Login window",sf::Style::Close);

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
    return 0;*/
    std::string filename = "studentuser.csv";
    LinkedList<User> userList = readUserFromCSV(filename);
    Node<User>* head = userList.head;
    while (head) {
        head->data.password = string_hashing(head->data.password);
        head = head->next;
        std::cout << head->data.username << std::endl;
    }
    /*updateUser2CSVfile(filename, userList);*/
    if (check_login(userList, "23125020", "12345678")) std::cout << "Login successfully" << std::endl;
    else std::cout << "password or username wrong" << std::endl;
}
