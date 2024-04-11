#ifndef BUTTON_H
#define BUTTON_H

#include<SFML/Graphics.hpp>
#include<string>

class Button {
private:
	sf::RectangleShape recbutton;

	sf::Text textbox;

	bool isClicked;
public:
	Button() {}
	//constructer button without Text
	Button(sf::Color color, sf::Vector2f size, bool isClicked) {
		recbutton.setSize(size);
		recbutton.setFillColor(color);
		this->isClicked = isClicked;
	}
	//constructer of button with Textbox
	Button(sf::Color color, sf::Vector2f size, bool isClicked, sf::Color textColor, std::string text, int txtsize, sf::Font& font) {
		recbutton.setSize(size);
		recbutton.setFillColor(color);
		this->isClicked = isClicked;

		textbox.setFillColor(textColor);
		textbox.setCharacterSize(txtsize);
		textbox.setString(text);
		textbox.setFont(font);
	}
	~Button() {}
	void setposition(sf::Vector2f point) {
		recbutton.setPosition(point);

		float x_coor = (point.x + recbutton.getLocalBounds().width / 2) - (textbox.getLocalBounds().width / 2);
		float y_coor = (point.y + recbutton.getLocalBounds().height / 2) - (textbox.getLocalBounds().height*3/4);
		textbox.setPosition(sf::Vector2f(x_coor, y_coor));
	}
	void setButposition(sf::Vector2f point) {
		recbutton.setPosition(point);
	}
	void setTextboxposition(sf::Vector2f point) {
		textbox.setPosition(point);
	}
	void settexture(sf::Texture* texture) {
		recbutton.setTexture(texture);
	}
	void changecolor(sf::Color color) {
		recbutton.setFillColor(color);
	}
	void changeTextColor(sf::Color color) {
		textbox.setFillColor(color);
	}
	void changesize(sf::Vector2f size) {
		recbutton.setSize(size);
	}
	void setRectextur(sf::IntRect& sizerec) {
		recbutton.setTextureRect(sizerec);
	}
	void drawbutton(sf::RenderWindow& window) {
		window.draw(recbutton);
		window.draw(textbox);
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
				float PosXbuttonmax = recbutton.getPosition().x + recbutton.getLocalBounds().width;
				float PosYbuttonmax = recbutton.getPosition().y + recbutton.getLocalBounds().height;
				if (x_coor > PosXbutton && x_coor<PosXbuttonmax &&
					y_coor>PosYbutton && y_coor < PosYbuttonmax) {
					/*if (isClicked == false)
						isClicked = true;
					else isClicked = false;*/
					return true;
				}
			}
		}
		return false;
	}
	bool isonMousecursor(sf::Event event) {
		//coordinate of cursor on window
		float x_coor = event.mouseMove.x*1.0f;
		float y_coor = event.mouseMove.y*1.0f;
		//coordinate of button 
		float PosXbutton = recbutton.getPosition().x;
		float PosYbutton = recbutton.getPosition().y;
		//coordinate of button with width and height
		float PosXbuttonmax = recbutton.getPosition().x + recbutton.getLocalBounds().width;
		float PosYbuttonmax = recbutton.getPosition().y + recbutton.getLocalBounds().height;

		if (x_coor >= PosXbutton && x_coor<=PosXbuttonmax &&
			y_coor>=PosYbutton && y_coor <= PosYbuttonmax) {

			return true;
		}

		return false;
	}
	void setisClicked(bool isClicked) {
		this->isClicked = isClicked;
	}
	bool getisClick() {
		return isClicked;
	}
	std::string getText() {
		return textbox.getString();
	}
};

#endif // !BUTTON_H



