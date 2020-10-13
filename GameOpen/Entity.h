#pragma once

#include"MovementComponent.h"

class Entity
{

private:
	void iniVariable();

protected:
	sf::Sprite sprite;

	//sf::RectangleShape shape;
	MovementComponent* movementComponent;


public:
	Entity();
	virtual ~Entity();

	//Component function
	void setTexture(sf::Texture& texture);
	void CreateMovementComponent(const float maxVelocity);

	//Function
	virtual void setPosition(const float x,const float y);
	virtual void move(const float& dt,const float x,const float y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

