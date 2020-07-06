#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponent.h"

class Entity
{
private:
	void initVariables();

protected:
	sf::Sprite sprite;

	MovementComponent* movementComponent;

public:
	Entity();
	virtual ~Entity();

	// Components functions
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity);

	// Functions
	virtual void setPosition(const sf::Vector2f pos);
	virtual void move(const float& dt, const sf::Vector2f& direction);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

#endif