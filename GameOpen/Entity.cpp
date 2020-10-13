#include "Entity.h"

void Entity::iniVariable()
{
	//speed
	this->movementComponent = NULL;
}

Entity::Entity()
{
	////size
	//this->shape.setSize(sf::Vector2f(50.f, 50.f));
	////fill shape
	//this->shape.setFillColor(sf::Color::Blue);
	this->iniVariable();
}

Entity::~Entity()
{
}

//Component function
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::CreateMovementComponent(const float maxVelocity)
{
	this->movementComponent = new MovementComponent(this->sprite ,maxVelocity);
}

//function
void Entity::setPosition(const float x, const float y)
{
		this->sprite.setPosition(x,y);
}

void Entity::move(const float& dt,const float dir_x, const float dir_y)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y,dt); // set velocity
	}
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget *target)
{
	//draw
	
	target->draw(this->sprite);
	
}
