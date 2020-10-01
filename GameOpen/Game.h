#pragma once

#include "State.h"


class Game
{

//Variable
	sf::RenderWindow *window;
	sf::Event sfEvent;

	//deltatime
	sf::Clock dtClock;
	float dt;
		

//Initializetion

	void iniWindow();

private:

public:
	//Constructor/Destuctor
	Game();
	virtual ~Game();

//function
	void updateDT();
	void updateSFMLEvent();
	void update();
	void render();
	void run();
};

