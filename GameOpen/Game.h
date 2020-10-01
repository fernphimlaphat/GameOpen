#pragma once

#include "GameState.h"


class Game
{

//Variable
	sf::RenderWindow *window;
	sf::Event sfEvent;

	//deltatime
	sf::Clock dtClock;
	float dt;
	
	std::stack<State*> state; 

//Initializetion

	void iniWindow();
	void iniState();

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

