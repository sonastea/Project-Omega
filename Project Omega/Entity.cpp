#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::White);
	this->movementSpeed = 100.f;
}

Entity::~Entity()
{
}

void Entity::move(const float& dt, const sf::Vector2f& direction)
{
	this->shape.move(direction * dt * this->movementSpeed);
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
