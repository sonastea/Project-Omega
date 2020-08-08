#include "stdafx.h"
#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(unsigned level, unsigned value, std::string texture_file)
	: Weapon(level, value, texture_file)
{
	this->type = to_int(ItemTypes::Ranged);

}

RangedWeapon::~RangedWeapon()
{
}

/* Functions */
void RangedWeapon::generate(const unsigned level_min, const unsigned level_max)
{
}
