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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
	{
		this->quit = true;
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}*/
}

void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition());
}


