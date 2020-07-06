#include "Entity.h"

void Entity::initVariables()
{
	this->movementComponent = NULL;
}

Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
}

// Components functions
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity);
}

/* Functions */
void Entity::setPosition(const sf::Vector2f pos)
{
		this->sprite.setPosition(sf::Vector2f(pos.x, pos.y));
}

void Entity::move(const float& dt, const sf::Vector2f& direction)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(direction, dt);
	}
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
		target->draw(this->sprite);
}
