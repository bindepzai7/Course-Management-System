#include<SFML/Graphics.hpp>
#include"displayfunction.h"



int main() {
    sf::RenderWindow window(sf::VideoMode(1296, 838), "Login window",sf::Style::Close);

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
}
