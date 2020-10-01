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

class State
{
private:

	sf::RenderWindow* window;
	std::vector<sf::Texture> texture;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void endState() = 0;
	
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

