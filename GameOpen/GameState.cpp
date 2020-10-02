#include "GameState.h"

void GameState::iniKeybind()
{
	this->keybinds.emplace("Escape", this->supportedKey->at("Escape"));

	this->keybinds.emplace("MOVE_LEFT",this->supportedKey->at("A"));
	this->keybinds.emplace("MOVE_RIGHT",this->supportedKey->at("D"));
	this->keybinds.emplace("MOVE_TOP",this->supportedKey->at("W"));
	this->keybinds.emplace("MOVE_DOWN",this->supportedKey->at("S"));
}


GameState::GameState(sf::RenderWindow* window , std::map<std::string,int>* supportedKey)
    : State(window , supportedKey)
{
	this->iniKeybind();
}

GameState::~GameState()
{
}

void GameState::endState()
{
    printf("End Game\n");
}

void GameState::updateInput(const float& dt)
{

    //Keyboard
    this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
	{
		this->player.move(dt, -1.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
	{
		this->player.move(dt, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_TOP"))))
	{
		this->player.move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
	{
		this->player.move(dt, 0.f, 1.f);
	}
    
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player.move(dt, 1.f, 0.f);
	}*/
}

void GameState::update(const float& dt)
{
    this->updateInput(dt);

	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{

	if (!target)
	{
		target = this->window;
	}
        this->player.render(target);
    
}
