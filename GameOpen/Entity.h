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

class Entity
{

private:


protected:
	sf::RectangleShape shape;
	float movementSpeed;


public:
	Entity();
	virtual ~Entity();

	//Function
	virtual void move(const float& dt,const float x,const float y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

