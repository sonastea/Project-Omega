#include "Player.h"

/* Initializer functions */

void Player::initVariables()
{
}

void Player::initComponents()
{
	this->createMovementComponent(300.f, 15.f, 5.f);
}

/* Constructors / Destructors */

Player::Player(sf::Vector2f pos, sf::Texture& texture)
{
	this->initVariables();
	this->initComponents();

	this->setTexture(texture);
	this->setPosition(pos);
}

Player::~Player()
{
}
