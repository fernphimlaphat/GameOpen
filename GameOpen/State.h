#pragma once
#include<vector>

#include<stdio.h>

#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<stdio.h>

class State
{
private:

	std::vector<sf::Texture> texture;

public:
	State();
	virtual ~State();

	virtual void update() = 0;
	virtual void render() = 0;

};

