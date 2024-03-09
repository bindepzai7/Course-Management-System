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
	bool haslimit = false;
	int limit;
	//delete character
	void deletelastcharacter()
	{
		std::string t=text;
		t.pop_back();
		textbox.setString(text + "_");
	}
	void inputlogically(int chartyped)
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
		if (isSelected)
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
	//set textbox limit
	void setlimit(bool toF)
	{
		haslimit = toF;
	}
	void setlimit(bool toF, int lim)
	{
		haslimit = toF;
		limit = lim;
	}
	//change selected state
	void setselected(bool sel)
	{
		isSelected = sel;
		//if not selected remove the'_' at the end
		if (!isSelected)
		{
			text.pop_back();
			textbox.setString(text);
		}

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
		int chartyped = e.text.unicode;
		if (chartyped < 128)
		{
			{
				if (haslimit)
				{
					//if it has limit exist, go two function
					if (text.size()<= limit)
						inputlogically(chartyped);
					else if (text.size() > limit && chartyped == Backspace_key)
						deletelastcharacter();
				}
				else
					//if no limit run this function
				{
					inputlogically(chartyped);
				}
			}
		}
	}
};

#endif