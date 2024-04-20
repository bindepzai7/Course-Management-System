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
	bool isencode = false;
	//set limit of textbox
	bool haslimit = false;
	int limit = 0;
	//delete character
	void deletelastcharacter()
	{
		text.pop_back();
		if (isencode == false)
			textbox.setString(text + "_");
		else {
			std::string text_encode;
			for (int i = 0; i < text.size(); i++)
			{
				text_encode += "*";
			}
			textbox.setString(text_encode + "_");
		}
		
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
		if(isencode==false)
		textbox.setString(text +"_");
		else {
			std::string text_encode;
			for (int i = 0; i < text.size(); i++)
			{
				text_encode += "*";
			}
		textbox.setString(text_encode+"_");
		}
	}
public:
	TextBox(){}
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
	~TextBox()
	{
		//std::cout << "object being delete"<<std::endl;
	}
	void setsize(int size) {
		textbox.setCharacterSize(size);
	}
	void setColor(sf::Color color) {
		textbox.setFillColor(color);
	}
	void setText(std::string text) {
		this->text = text;
		textbox.setString(text);
	}
	void setfont(sf::Font& font)
	{
		textbox.setFont(font);
	}
	void setTextPosition(sf::Vector2f point)
	{
		textbox.setPosition(point);
	}
	void setTextboxpostitionwithlimit(float Posx, float Posy, float Posylimabove, float Posylimunder, float jumpsize) {
		if (Posy <= Posylimabove) {
			Posy = Posylimabove - jumpsize;
		}
		else if (Posy >= Posylimunder) {
			Posy = Posylimunder + jumpsize;
		}
		textbox.setPosition(sf::Vector2f(Posx, Posy));
	}
	//change selected state
	void setselected(bool sel)
	{
		isSelected = sel;
		if(isencode==false)
		textbox.setString(text+"_");
		else {
			std::string text_encode;
			for (int i = 0; i < text.size(); i++)
			{
				text_encode += "*";
			}
			textbox.setString(text_encode + "_");
		}
		//if not selected remove the'_' at the end
		if (isSelected==false)
		{
			/*text.pop_back();*/
			textbox.setString(text+"");
		}

	}
	void setlimit(bool islim)
	{
		haslimit = islim;
	}
	void setlimit(bool islim, int lim)
	{
		haslimit = islim;
		limit = lim - 1;
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
	void settextencode(bool encode)
	{
		isencode = encode;
		std::string text_encode;
		if (isencode == true){
			for (int i = 0; i < text.size(); i++)
			{
				text_encode += "*";
			}
		}
		textbox.setString(text_encode);
	}
	void typedText(sf::Event e)
	{
		sf::Uint32 chartyped = e.text.unicode;
		if (chartyped < 128)
		{
			if (haslimit)
			{
				//if text is not reach limit of box continue to type
				if (text.size() <= limit)
				{
					inputlogically(chartyped);
				}
				else if (text.size() > limit && chartyped == Backspace_key)
					deletelastcharacter();
			}
			else
			{
			    inputlogically(chartyped);
			}
		}
	}
	bool isClick(sf::Event event,int Posx,int Posy,int Posxmax,int Posymax) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//coordinate of window 
				int x_coor = event.mouseButton.x;
				int y_coor = event.mouseButton.y;
				
				if (x_coor > Posx && x_coor<Posxmax &&
					y_coor>Posy && y_coor < Posymax) {
					return true;
				}
			}
		}
		return false;
	}
	bool isClickwithoutPosagrument(sf::Event event) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//coordinate of window 
				int x_coor = event.mouseButton.x;
				int y_coor = event.mouseButton.y;
				int Posx = textbox.getPosition().x;
				int Posy = textbox.getPosition().y;
				int Posxmax = textbox.getPosition().x + textbox.getLocalBounds().width + 20.0f;
				int Posymax = textbox.getPosition().y + textbox.getLocalBounds().height + 20.0f;
				if (x_coor > Posx && x_coor<Posxmax &&
					y_coor>Posy && y_coor < Posymax) {
					return true;
				}
			}
		}
		return false;
	}

	sf::Vector2f getPositionofTextbox() {
		return textbox.getPosition();
	}
};

class OutputTextBox
{
private:
	//feature of textbox
	sf::Text o_textbox;
	std::string text;
public:
	
	OutputTextBox(int size, sf::Color color, std::string input_text)
	{
		o_textbox.setCharacterSize(size);
		o_textbox.setFillColor(color);
		o_textbox.setString(input_text);
		
	}
	~OutputTextBox()
	{
		//std::cout << "object being delete" << std::endl;
	}
	void setfont(sf::Font& font)
	{
		o_textbox.setFont(font);
	}
	void setTextPosition(sf::Vector2f point)
	{
		o_textbox.setPosition(point);
	}
	void setStyleBold()
	{
		o_textbox.setStyle(sf::Text::Bold);
	}
	//change selected state
	
	std::string getText()
	{
		return text;
	}
	void drawTextbox(sf::RenderWindow& window)
	{
		window.draw(o_textbox);
	}
};

void setnotseleted(TextBox**& Studenttextbox, int n, int x, int y,int col);
#endif