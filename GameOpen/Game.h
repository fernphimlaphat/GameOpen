#pragma once

#include "MainMenuState.h"


class Game
{
private:
	//Variable
	sf::RenderWindow* window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoMode;
	sf::ContextSettings windowSetting;
	bool fullscreen;

	//deltatime
	sf::Clock dtClock;
	float dt;

	std::stack<State*> state;

	std::map<std::string, int> supportedKey;

	//Initializetion

	void iniVariable();
	void iniWindow();
	void iniKey();
	void iniState();

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

