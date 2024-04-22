#ifndef DROPDOWNLIST_H
#define DROPDOWNLIST_H


#include"LinkedList.h"
#include"button.h"
#include<SFML/Graphics.hpp>
#include<string>

class dropdownlist {
private:
	LinkedList<Button> buttonlist;
public:
	dropdownlist() {}
	dropdownlist(sf::Color color, sf::Vector2f size, bool isClicked, int numsofbutton) {
		for (int i = 0; i < numsofbutton; i++) {
			buttonlist.push_tail(Button(color, size, isClicked));
		}
	}
	dropdownlist(sf::Color color, sf::Vector2f size, bool isClicked,
		sf::Color textColor, LinkedList<std::string> &textlist, int txtsize, sf::Font& font)
	{
		Node<std::string>* cur = textlist.head;
		while (cur) {
			buttonlist.push_tail(Button(color, size, isClicked, textColor, cur->data, txtsize, font));
			cur = cur->next;
		}
	}
	~dropdownlist() {
		Node<Button>* curbut = buttonlist.head;
		while (curbut) {
			curbut->data.~Button();
			curbut = curbut->next;
		}
		buttonlist.~LinkedList();
	};
	void setpostionlistbutton(float Posx, float Posy, int i,float size) {
		Node<Button>* curbut = buttonlist.head;
		while (curbut) {
			curbut->data.setposition(sf::Vector2f(Posx, Posy + size* i));
			curbut = curbut->next;
			i++;
		}
	}
	//setpositon with limit view
	void setpostionlistbuttonwithlimit(float Posx, float Posy, int i, float distance,float Posylimabove,float Posylimunder,float jumpdistance) {
		Node<Button>* curbut = buttonlist.head;
		while (curbut) {
			float newPosy = Posy + distance * i;
			if (newPosy <= Posylimabove) newPosy = newPosy - jumpdistance;
			if (newPosy >= Posylimunder) newPosy = newPosy + jumpdistance;
			curbut->data.setposition(sf::Vector2f(Posx, newPosy));
			curbut = curbut->next;
			i++;
		}
	}


	//draw button without change color textbox when on mouse cursor
	void drawButwithoutchangeTextboxcolor(sf::RenderWindow& window, sf::Event event,sf::Color color) {
		Node<Button>* curbut = buttonlist.head;
		while (curbut) {
			/*curbut->data.setposition(sf::Vector2f(Posx, Posy + size * i));*/
			if (curbut->data.isonMousecursor(event)) {
				curbut->data.changecolor(color);
			}
			else
				curbut->data.changecolor(sf::Color::Transparent);
			curbut->data.drawbutton(window);
			curbut = curbut->next;
		}
	}
	//draw button with textbox and change button and textbox color on mouse cursor
	void drawButwithTextbox(sf::RenderWindow& window, sf::Event event, sf::Color color,sf::Color txtcolor) {
		Node<Button>* curbut = buttonlist.head;
		while (curbut) {
			/*curbut->data.setposition(sf::Vector2f(Posx, Posy + size * i));*/
			if (curbut->data.isonMousecursor(event)) {
				curbut->data.changecolor(color);
				curbut->data.changeTextColor(txtcolor);
			}
			else {
				curbut->data.changecolor(sf::Color::Transparent);
				curbut->data.changeTextColor(sf::Color::Transparent);
			}
			curbut->data.drawbutton(window);
			curbut = curbut->next;
		}
	}
	//drawTextboxwithNotchangeColor
	bool isClickedKOrder(sf::Event event, int k) {
		if (k > buttonlist.sizeoflist()) return false;
		int i = 1;
		Node<Button>* curbut = buttonlist.head;
		while (i < k) {
			curbut = curbut->next;
			i++;
		}
		if (curbut->data.isClick(event))
		{
			return true;

		}
		return false;
	}
	std::string getKoderButtonText(int k) {
		if (k > buttonlist.sizeoflist()) return "";
		int i = 1;
		Node<Button>* curbut = buttonlist.head;
		while (i < k) {
			curbut = curbut->next;
			i++;
		}
		return curbut->data.getText();
	}
	sf::Vector2f getpositionofKbut(int k) {
		if (k > buttonlist.sizeoflist()) return sf::Vector2f(0,0);
		int i = 1;
		Node<Button>* curbut = buttonlist.head;
		while (i < k) {
			curbut = curbut->next;
			i++;
		}
		return curbut->data.getpositionofbutton();
	}
};
#endif // !1
