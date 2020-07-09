#include "Player.h"

/* Initializer functions */

void Player::initVariables()
{
}

void Player::initComponents()
{

}

/* Constructors / Destructors */

Player::Player(sf::Vector2f pos, sf::Texture& texture_sheet)
{
	this->initVariables();


	this->setPosition(pos);

	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 10, 0, 180, 180);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 1, 7, 1, 180, 180);

}

Player::~Player()
{
}

// Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	if (this->movementComponent->getState(IS_IDLE))
		this->animationComponent->play("IDLE", dt);
	else if (this->movementComponent->getState(MOVING_RIGHT))
		this->animationComponent->play("WALK_RIGHT", dt);

}
