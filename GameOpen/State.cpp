#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKey)
{
	this->window = window;
	this->supportedKey = supportedKey;
	this->quit = false;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	// TODO: insert return statement here
	return this->quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}
