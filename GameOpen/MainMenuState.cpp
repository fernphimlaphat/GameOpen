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

	this->gamestate_btn = new Button(100, 100, 150, 50,
		&this->font,"New Game",
		sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));

	this->background.setSize(sf::Vector2f(window->getSize().x , window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	delete this->gamestate_btn;
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

	this->gamestate_btn->update(this->mousePosView);
	

}

void MainMenuState::render(sf::RenderTarget* target)
{

	if (!target)
	target = this->window;
	
	target->draw(this->background);

	this->gamestate_btn->render(target);

}
