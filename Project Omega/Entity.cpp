#include "Entity.h"

void Entity::initVariables()
{
	this->texture = NULL;
	this->sprite = NULL;
	this->movementSpeed = 100.f;
}

Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->sprite;
}

// Components functions
void Entity::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite->setTexture(*this->texture);
}

void Entity::move(const float& dt, const sf::Vector2f& direction)
{
	if (this->sprite)
	{
		this->sprite->move(direction * this->movementSpeed * dt);
	}
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	if (this->sprite)
	{
		target->draw(*this->sprite);
	}
}
