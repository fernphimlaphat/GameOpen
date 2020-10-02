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

	std::map<std::string, int> supportedKey;

//Initializetion

	void iniWindow();
	void iniKey();
	void iniState();

private:

public:
	//Constructor/Destuctor
	Game();
	virtual ~Game();

//Function

	//regular
	void endApp();

	//Update
	void updateDT();
	void updateSFMLEvent();
	void update();

	//Render
	void render();

	//core
	void run();
};

