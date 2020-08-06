#include "stdafx.h"
#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(unsigned value)
	: Item(value)
{
	this->type = to_int(ItemTypes::Ranged);

}

RangedWeapon::~RangedWeapon()
{
}
