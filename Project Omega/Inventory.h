#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory
{
private:
	Item** itemArray;
	unsigned numOfItems;
	unsigned capacity;

	void initialize();
	void nullify(const unsigned from = 0);
	void freeMemory();

public:
	Inventory(unsigned capacity);
	virtual ~Inventory();

	/* Accessors / Getters */
	const unsigned& size() const;
	const unsigned& maxSize() const;

	/* Modifiers */

	/* Functions */
	void clear();
	const bool empty() const;

	const bool add(Item* item);
	const bool remove(unsigned index);

	const bool saveToFile(const std::string fileName);
	const bool loadFromFile(const std::string fileName);
};

#endif // Inventory.h