#include "stdafx.h"
#include "Weapon.h"

/* Initializer Functions */
void Weapon::initVariables()
{
	this->range = 20;
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

const unsigned& Weapon::getRange() const
{
	return this->range;
}
