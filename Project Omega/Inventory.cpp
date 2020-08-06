#include "stdafx.h"
#include "Inventory.h"

/* Private Functions */
void Inventory::initialize()
{
	this->numOfItems = 0;
	this->itemArray = new Item*[this->capacity];

	this->nullify();
}

void Inventory::nullify(const unsigned from)
{
	for (size_t i = from; i < this->capacity; i++)
	{
		this->itemArray[i] = nullptr;
	}
}

void Inventory::freeMemory()
{
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		delete this->itemArray[i];
	}

	delete[] this->itemArray;
}

/* Constructors & Destructors */
Inventory::Inventory(unsigned capacity)
	: capacity(capacity)
{
	this->initialize();
}

Inventory::~Inventory()
{
	this->freeMemory();
}

/* Accessors / Getters */
const unsigned& Inventory::size() const
{
	return this->numOfItems;
}

const unsigned& Inventory::maxSize() const
{
	return this->capacity;
}

/* Modifiers */

/* Functions */
void Inventory::clear()
{
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		delete this->itemArray[i];
	}
	this->numOfItems = 0;
	this->nullify();
}

const bool Inventory::empty() const
{
	return this->numOfItems == 0;
}

const bool Inventory::add(Item* item)
{
	// Check if inventory is full
	if (this->numOfItems < this->capacity)
	{
		// Add item if there's room in the inventory
		this->itemArray[this->numOfItems++] = item->clone();

		return true;
	}
	return false;
}

const bool Inventory::remove(unsigned index)
{
	if (this->numOfItems > 0)
	{
		if (index < 0 || index >= this->capacity)
			return false;

		delete this->itemArray[index];
		this->itemArray[index] = nullptr;
		--this->numOfItems;

		return true;
	}
	return false;
}

const bool Inventory::saveToFile(const std::string fileName)
{
	return false;
}

const bool Inventory::loadFromFile(const std::string fileName)
{
	return false;
}
