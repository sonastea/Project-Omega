#include "Player.h"

// Initializer functions

void Player::initVariables()
{
}

void Player::initComponents()
{
	this->createMovementComponent(100.f);
}

// Constructors / Destructors

Player::Player(sf::Vector2f direction, sf::Texture& texture)
{
	this->initVariables();
	this->initComponents();

	this->setTexture(texture);
	this->setPosition(direction);
}

Player::~Player()
{
}
