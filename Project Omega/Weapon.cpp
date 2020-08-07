#include "stdafx.h"
#include "Weapon.h"

/* Initializer Functions */
void Weapon::initVariables()
{
	this->range = 30;
	this->damageMin = 1;
	this->damageMax = 2;

	/* Timer */
	this->attackTimer.restart();
	this->attackTimerMax = 500;
}

/* Constructor / Destructor */
Weapon::Weapon(unsigned value, std::string texture_file)
	: Item(value)
{
	this->initVariables();

	if (!this->weaponTexture.loadFromFile(texture_file))
	{
		std::cout << "ERROR::SWORD::COULD NOT LOAD WEAPON TEXTURE::" << texture_file << "\n";
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
