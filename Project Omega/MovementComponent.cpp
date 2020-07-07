#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, 
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
	this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

/* Functions */
void MovementComponent::move(const sf::Vector2f direction, const float& dt)
{
	/* Accelerating a sprite until it reaches the max velcoity */
	this->velocity.x += this->acceleration * direction.x;
	this->velocity.y += this->acceleration * direction.y;
}

void MovementComponent::update(const float& dt)
{
	/* 
	Decelerates the sprite and controls the maximum velocity 
	Moves the sprite
	*/

	if (this->velocity.x > 0.f) // Check for positive x
	{
		// Max velocity check
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = maxVelocity;

		// Deceleration
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else if (this->velocity.x < 0.f) // Check for negative x
	{
		// Max velocity check
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -maxVelocity;

		// Deceleration
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}


	if (this->velocity.y > 0.f) // Check for positive y
	{
		// Max velocity check
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = maxVelocity;

		// Deceleration
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f) // Check for negative y
	{
		// Max velocity check
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -maxVelocity;

		// Deceleration
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}
	

	// Final move
	this->sprite.move(this->velocity * dt); // Uses velocity
}
