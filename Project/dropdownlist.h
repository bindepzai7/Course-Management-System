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
	dropdownlist(sf::Color color, sf::Vector2f size, bool isClicked,
		sf::Color textColor, LinkedList<std::string>& textlist, int txtsize, sf::Font& font)
	{
		Node<std::string>* cur = textlist.head;
		while (cur) {
			buttonlist.push_tail(Button(color, size, isClicked, textColor, cur->data, txtsize, font));
			cur = cur->next;
		}
	}
	void drawto(sf::RenderWindow& window, sf::Event event,float Posx,float Posy,float size, int i) {
		Node<Button>* curbut = buttonlist.head;
		while (curbut) {
			curbut->data.setposition(sf::Vector2f(Posx, Posy + size * i));
			if (curbut->data.isonMousecursor(event)) {
				curbut->data.changecolor(sf::Color::White);
			}
			else
				curbut->data.changecolor(sf::Color::Transparent);
			curbut->data.drawbutton(window);
			i++;
			curbut = curbut->next;
		}
	}
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
};
#endif // !1
