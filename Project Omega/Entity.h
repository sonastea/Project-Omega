#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponent.h"
#include "AnimationComponent.h"

class Entity
{
private:
	void initVariables();

protected:
	sf::Sprite sprite;

	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;

public:
	Entity();
	virtual ~Entity();

	// Components functions
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocityy, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);


	// Functions
	virtual void setPosition(const sf::Vector2f pos);
	virtual void move(const sf::Vector2f& direction, const float& dt);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

#endif