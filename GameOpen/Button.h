#pragma once

#include<stdio.h>
#include<iostream>

#include<ctime>
#include<cstdlib>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

class Button
{

private:

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;
	
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;



public:
	Button(float x, float y, float w, float h, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor , sf::Color activeColor);
	~Button();

	//Function

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

};

