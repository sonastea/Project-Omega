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
	delete this->movementComponent;
}

// Components functions
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

/* Functions */
void Entity::setPosition(const sf::Vector2f pos)
{
		this->sprite.setPosition(sf::Vector2f(pos.x, pos.y));
}

void Entity::move(const sf::Vector2f& direction, const float& dt)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(direction, dt);
	}
}

void Entity::update(const float& dt)
{
	if (this->movementComponent)
		this->movementComponent->update(dt);
}

void Entity::render(sf::RenderTarget* target)
{
		target->draw(this->sprite);
}
