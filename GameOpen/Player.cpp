#include "Player.h"

//ini
void Player::iniVariable()
{

}

void Player::iniComponent()
{
	this->CreateMovementComponent(100.f);
}

//Con Destructor
Player::Player(float x, float y,sf::Texture& texture)
{
	this->iniVariable();
	this->iniComponent();

	this->setTexture(texture);
	this->setPosition(x, y);
}

Player::~Player()
{
}
