#include "stdafx.h"
#include "Item.h"

void Item::initVariables()
{
}

Item::Item(unsigned value)
{
	this->initVariables();

	this->value = value;
	this->type = to_int(ItemTypes::Default);
}

Item::~Item()
{
}