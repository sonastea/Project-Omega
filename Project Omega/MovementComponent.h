#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

enum class MovementState : int { IS_IDLE = 0, MOVING = 1, MOVING_LEFT = 2, MOVING_RIGHT = 3, MOVING_UP = 4, MOVING_DOWN = 5 };

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;

	// Initializer functions

public:
	MovementComponent(sf::Sprite& sprite, 
		float maxVelocity, float acceleration, float deceleration);
	virtual ~MovementComponent();

	// Accesors / Getters
	const float& getMaxVelocity() const;
	const sf::Vector2f& getVelocity() const;

	// Functions
	const bool getState(const short unsigned state) const;
	void stopVelocity();
	void stopVelocityX();
	void stopVelocityY();

	void move(const sf::Vector2f direction, const float& dt);
	void update(const float& dt);
};

#endif