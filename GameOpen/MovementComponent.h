#pragma once
#include<vector>

#include<stdio.h>

#include<stack>
#include<map>
#include<vector>

#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<stdio.h>
#include<iostream>

class MovementComponent
{
private:
	sf::Sprite& sprite;
	float maxVelocity;

	//inifunction
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;

public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity);
	virtual ~MovementComponent();

	const sf::Vector2f& getvelocity() const;

	//function
	void move(const float x, const float y, const float& dt);
	void update(const float& dt);
};

