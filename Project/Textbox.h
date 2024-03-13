#ifndef _TEXTBOX_H
#define _TEXTBOX_H

#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>

//define some keys
#define Backspace_key 8
#define Enter_key 13
#define ESC_key 27

class TextBox
{
private:
	//feature of textbox
	sf::Text textbox;
	std::string text;

	bool isSelected = false;
	//delete character
	void deletelastcharacter()
	{
		text.pop_back();
		textbox.setString(text + "_");
	}
	void inputlogically(sf::Uint32 chartyped)
	{
		if (chartyped != Backspace_key && chartyped != Enter_key && chartyped != ESC_key)
		{
			text += static_cast<char>(chartyped);
		}
		//if enter Backspace delete last character
		else if (chartyped == Backspace_key)
		{
			if(text.size()>0)
			deletelastcharacter();
		}
		textbox.setString(text +"_");
	}
public:
	TextBox (int size, sf::Color color, bool sel)
	{
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		isSelected=sel;
		//check if textbox is selected to create symbol
		if (isSelected==true)
			textbox.setString("_");
		else
			textbox.setString("");
	}
	void setfont(sf::Font& font)
	{
		textbox.setFont(font);
	}
	void setTextPosition(sf::Vector2f point)
	{
		textbox.setPosition(point);
	}
	//change selected state
	void setselected(bool sel)
	{
		isSelected = sel;
		textbox.setString(text+"_");
		//if not selected remove the'_' at the end
		if (isSelected==false)
		{
			/*text.pop_back();*/
			textbox.setString(text+"");
		}

	}
	bool isselectedbox()
	{
		return isSelected;
	}
	std::string getText()
	{
		return text;
	}
	void drawTextbox(sf::RenderWindow& window)
	{
		window.draw(textbox);
	}
	void typedText(sf::Event e)
	{
		sf::Uint32 chartyped = e.text.unicode;
		if (chartyped < 128)
		{
			{
			    inputlogically(chartyped);
			}
		}
	}
};
#endif