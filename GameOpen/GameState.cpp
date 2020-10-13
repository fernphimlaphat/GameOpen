#include "GameState.h"

//ini
void GameState::iniKeybind()
{
//	this->keybinds["Escape"]  = this->supportedKey->at("Escape");

	this->keybinds["CLOSE"]  = this->supportedKey->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKey->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKey->at("D");
	this->keybinds["MOVE_TOP"] = this->supportedKey->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKey->at("S");

	//this->keybinds.emplace("MOVE_LEFT", this->supportedKey->at("A"));

}

void GameState::iniTexture()
{
	if (!this->texture["Play_IDLE"].loadFromFile("img/npc and player/player/Player1.png"))
	{
		printf("NOT LOAD PLAYER");
	}

}

void GameState::iniPlayer()
{
	this->player = new Player(0,0, this->texture["Play_IDLE"]);
}

//Contruc Destruc
GameState::GameState(sf::RenderWindow* window , std::map<std::string,int>* supportedKey, std::stack<State*>* state)
    : State(window , supportedKey,state)
{
	this->iniKeybind();
	this->iniTexture();
	this->iniPlayer();
}

GameState::~GameState()
{
	delete this->player;
}

//void gamestate::endstate()
//{
//    printf("end game\n");
//}

void GameState::updateInput(const float& dt)
{

    //Keyboard
    //this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
	{
		this->player->move(dt, -1.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
	{
		this->player->move(dt, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_TOP"))))
	{
		this->player->move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
	{
		this->player->move(dt, 0.f, 1.f);
	}
	//quit to main menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
	{
		this->endState();
	}
    
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player.move(dt, 1.f, 0.f);
	}*/
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();

    this->updateInput(dt);

	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{

	if (!target)
	{
		target = this->window;
	}
        this->player->render(target);
    
}
