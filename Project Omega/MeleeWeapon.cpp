#include "stdafx.h"
#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(unsigned level, unsigned damage_min, unsigned damage_max,
	unsigned range, unsigned value,
	std::string texture_file)
	: Weapon(level, damage_min, damage_max, range, value, texture_file)
{
	this->type = to_int(ItemTypes::Melee);
}

MeleeWeapon::~MeleeWeapon()
{
}

/* Functions */
void MeleeWeapon::generate(const unsigned level_min, const unsigned level_max)
{
	this->level = rand() % (level_max - level_min + 1) + level_min;

	this->damageMin = this->level * (rand() % 2 + 1);
	this->damageMax = this->level * (rand() % 2 + 1) + this->damageMin;
	
	this->range = this->level + rand() % 10 + 50;

	this->value = this->level + this->damageMin + this->damageMax + this->range + (rand() % this->level * 10);

	std::cout << this->level << " " << this->damageMin << " " << this->damageMax << " " << this->range << " " << this->value << "\n";
}
