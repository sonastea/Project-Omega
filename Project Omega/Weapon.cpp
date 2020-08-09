#include "stdafx.h"
#include "Weapon.h"

/* Initializer Functions */
void Weapon::initVariables()
{
	this->range = 50;
	this->damageMin = 1;
	this->damageMax = 2;

	/* Timer */
	this->attackTimer.restart();
	this->attackTimerMax = 500;
}

Weapon::Weapon(unsigned level, unsigned value, std::string texture_file)
	: Item(level, value)
{
	this->initVariables();

	if (!this->weaponTexture.loadFromFile(texture_file))
	{
		std::cout << "ERROR::PLAYER::COULD NOT LOAD WEAPON TEXTURE::" << texture_file << "\n";
	}
	this->weaponSprite.setTexture(this->weaponTexture);
}

/* Constructor / Destructor */
Weapon::Weapon(unsigned level, unsigned damage_min, unsigned damage_max,
	unsigned range, unsigned value,
	std::string texture_file)
	: Item(level, value)
{
	this->initVariables();

	this->damageMin = damageMin;
	this->damageMax = damageMax;
	this->range = range;

	if (!this->weaponTexture.loadFromFile(texture_file))
	{
		std::cout << "ERROR::PLAYER::COULD NOT LOAD WEAPON TEXTURE::" << texture_file << "\n";
	}
	this->weaponSprite.setTexture(this->weaponTexture);
}

Weapon::~Weapon()
{
}

/* Accessors / Getters */
const unsigned& Weapon::getDamageMin() const
{
	return this->damageMin;
}

const unsigned& Weapon::getDamagemax() const
{
	return this->damageMax;
}

const unsigned Weapon::getDamage() const
{
	return rand() % (this->damageMax - this->damageMin + 1) + (this->damageMin);
}

const unsigned& Weapon::getRange() const
{
	return this->range;
}

const bool Weapon::getAttackTimer()
{
	if (this->attackTimer.getElapsedTime().asMilliseconds() >= this->attackTimerMax)
	{
		this->attackTimer.restart();
		return true;
	}

	return false;
}
