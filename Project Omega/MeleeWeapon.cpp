#include "stdafx.h"
#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(unsigned value)
	: Item(value)
{
	this->type = to_int(ItemTypes::Melee);
}

MeleeWeapon::~MeleeWeapon()
{
}