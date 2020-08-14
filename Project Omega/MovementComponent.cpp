#include "stdafx.h"
#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, 
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
}

/* Accessors */

const float& MovementComponent::getMaxVelocity() const
{
	return this->maxVelocity;
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

/* Functions */

const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
	case to_int(MovementState::IS_IDLE):
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;
		break;

	case to_int(MovementState::MOVING):
		if (this->velocity.x != 0.f || this->velocity.y != 0.f)
			return true;
		break;

	case to_int(MovementState::MOVING_LEFT):
		if (this->velocity.x < 0.f)
			return true;
		break;

	case to_int(MovementState::MOVING_RIGHT):
		if (this->velocity.x > 0.f)
			return true;
		break;

	case to_int(MovementState::MOVING_UP):
		if (this->velocity.y < 0.f)
			return true;
		break;

	case to_int(MovementState::MOVING_DOWN):
		if (this->velocity.y > 0.f)
			return true;
		break;
	}
	return false;
}

void MovementComponent::stopVelocity()
{
	/* Resets the velocity to 0. */

	this->velocity.x = 0.f;
	this->velocity.y = 0.f;
}

void MovementComponent::stopVelocityX()
{
	/* Resets the velocity x to 0. */

	this->velocity.x = 0.f;
}

void MovementComponent::stopVelocityY()
{
	/* Resets the velocity y to 0. */

	this->velocity.y = 0.f;
}


void MovementComponent::move(const sf::Vector2f direction, const float& dt)
{
	/* Accelerating a sprite until it reaches the max velcoity */
	this->velocity.x += this->acceleration * direction.x * dt;
	this->velocity.y += this->acceleration * direction.y * dt;
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
			this->velocity.x = this->maxVelocity;

		// Deceleration x pos
		this->velocity.x -= deceleration * dt;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else if (this->velocity.x < 0.f) // Check for negative x
	{
		// Max velocity check
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		// Deceleration x neg
		this->velocity.x += deceleration * dt;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}


	if (this->velocity.y > 0.f) // Check for positive y
	{
		// Max velocity check
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		// Deceleration
		this->velocity.y -= deceleration * dt;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f) // Check for negative y
	{
		// Max velocity check
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		// Deceleration
		this->velocity.y += deceleration * dt;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}
	

	// Final move
	this->sprite.move(this->velocity * dt); // Uses velocity
}
