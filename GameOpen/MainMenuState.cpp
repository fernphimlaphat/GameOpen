#include "MainMenuState.h"

void MainMenuState::iniFont()
{
	if (!this->font.loadFromFile("Fonts/FC Motorway Semi-condensed Regular.otf"))
	{
		printf("Error font");
	}
}

void MainMenuState::iniKeybind()
{
	//	this->keybinds["Escape"]  = this->supportedKey->at("Escape");

	this->keybinds["CLOSE"] = this->supportedKey->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKey->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKey->at("D");
	this->keybinds["MOVE_TOP"] = this->supportedKey->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKey->at("S");

	//this->keybinds.emplace("MOVE_LEFT", this->supportedKey->at("A"));

}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKey)
	: State(window, supportedKey)
{
	this->iniFont();
	this->iniKeybind();
	this->background.setSize(sf::Vector2f(window->getSize().x , window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::endState()
{
	printf("End Game\n");
}

void MainMenuState::updateInput(const float& dt)
{

	//Keyboard
	this->checkForQuit();
	

}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();

	this->updateInput(dt);

	//position mouse
	/*system("cls");
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";*/

}

void MainMenuState::render(sf::RenderTarget* target)
{

	if (!target)
	{
		target = this->window;
	}
	target->draw(this->background);

}
