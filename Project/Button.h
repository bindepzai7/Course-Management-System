#ifndef BUTTON_H
#define BUTTON_H

#include<SFML/Graphics.hpp>

class Button {
private:
	sf::RectangleShape recbutton;


	bool isselect;
	bool isoncursor;
public:
	//defaut constructer button
	Button() {};
	Button(sf::Color color, bool isoncursor, sf::Vector2f size) {
		recbutton.setSize(size);
		this->isoncursor = isoncursor;
		if (this->isoncursor == true) {
			recbutton.setFillColor(color);
		}
		else {
			recbutton.setFillColor(sf::Color::Transparent);
		}
	}
	void setpostion(sf::Vector2f point) {
		recbutton.setPosition(point);
	}
	void settexture(sf::Texture *texture) {
		recbutton.setTexture(texture);
	}
	void changecolor(sf::Color color) {
		recbutton.setFillColor(color);
	}
	void changesize(sf::Vector2f size) {
		recbutton.setSize(size);
	}
	void setRectextur(sf::IntRect &sizerec) {
		recbutton.setTextureRect(sizerec);
	}
	void drawbutton(sf::RenderWindow &window) {
		window.draw(recbutton);
	}
	bool isClick(sf::Event event) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//coordinate of window 
				float x_coor = event.mouseButton.x;
				float y_coor = event.mouseButton.y;
				//coordinate of button 
				float PosXbutton = recbutton.getPosition().x;
				float PosYbutton = recbutton.getPosition().y;
				//coordinate of button with width and height
				float PoxXbuttonmax = recbutton.getPosition().x + recbutton.getLocalBounds().width;
				float PosYbuttonmax = recbutton.getPosition().y + recbutton.getLocalBounds().height;
				if (x_coor > PosXbutton && x_coor<PosYbuttonmax &&
					y_coor>PosYbutton && y_coor < PosYbuttonmax) return true;
			}
		}
		return false;
	}
	bool isonMousecursor(sf::Event event) {
		//coordinate of cursor on window
		float x_coor = event.mouseMove.x;
		float y_coor = event.mouseMove.y;
		//coordinate of button 
		float PosXbutton = recbutton.getPosition().x;
		float PosYbutton = recbutton.getPosition().y;
		//coordinate of button with width and height
		float PoxXbuttonmax = recbutton.getPosition().x + recbutton.getLocalBounds().width;
		float PosYbuttonmax = recbutton.getPosition().y + recbutton.getLocalBounds().height;
		
		if (x_coor > PosXbutton && x_coor<PosYbuttonmax &&
			y_coor>PosYbutton && y_coor < PosYbuttonmax) return true;

		return false;
	}
};

#endif // !BUTTON_H

