#ifndef ITEM_H
#define ITEM_H

enum class ItemTypes : int { Default = 0, Melee = 1, Ranged = 2};

enum class ItemRarity : int { Normal = 0, Stellar = 1, XNova = 2, Mythical = 3, Ethereal = 4 };

class Item
{
private:
	void initVariables();
	
protected:
	/* Variables */
	int type;
	unsigned value;

public:
	/* Constructor / Destructor */
	Item(unsigned value);
	virtual ~Item();

	/* Functions */
	virtual Item* clone() = 0;
};

#endif // Item.h