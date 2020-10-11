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

	//this->keybinds["MOVE_LEFT"] = this->supportedKey->at("A");
	//this->keybinds["MOVE_RIGHT"] = this->supportedKey->at("D");
	//this->keybinds["MOVE_TOP"] = this->supportedKey->at("W");
	//this->keybinds["MOVE_DOWN"] = this->supportedKey->at("S");

	//this->keybinds.emplace("MOVE_LEFT", this->supportedKey->at("A"));

}

void MainMenuState::iniButton()
{
	this->button["Game_State"] = new Button(100, 100, 150, 50,
		&this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->button["Exit_State"] = new Button(100, 300, 150, 50,
		&this->font, "Quit",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKey, std::stack<State*>* state)
	: State(window, supportedKey,state)
{
	this->iniFont();
	this->iniKeybind();
	this->iniButton();

	

	this->background.setSize(sf::Vector2f(window->getSize().x , window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	auto it = this->button.begin();
	for (it = this->button.begin(); it != this->button.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::endState()
{
	printf("End MenuState\n");
}

void MainMenuState::updateInput(const float& dt)
{

	//Keyboard
	this->checkForQuit();
	

}

void MainMenuState::updateButton()
{
	//update all button
	for(auto &it : this->button)
	{
		it.second->update(this->mousePosView);
	}

	//New
	if (this->button["Game_State"]->isPressed())
	{
		this->state->push(new GameState(this->window,this->supportedKey,this->state));
	}

	//quit
	if (this->button["Exit_State"]->isPressed())
	{
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();

	this->updateInput(dt);
	
	this->updateButton();

	
}

void MainMenuState::renderButton(sf::RenderTarget* target)
{
	for (auto& it : this->button)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{

	if (!target)
	target = this->window;
	
	target->draw(this->background);
	this->renderButton(target);

}
