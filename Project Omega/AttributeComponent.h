#ifndef ATTRIBUTECOMPONENT_H
#define ATTRIBUTECOMPONENT_H

class AttributeComponent
{
public:
	/* ========================VARIABLES======================== */

	// Leveling
	unsigned exp;
	unsigned level;
	unsigned expNext;
	unsigned attributePoints;
	
	// Attributes
	int vitality;
	int strength;
	int dexterity;
	int agility;
	int intelligence;
	
	// Stats
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	int accuracy;
	int defence;
	int luck;

	/* ========================FUNCTIONS======================== */

	// Constructor / Destructor
	AttributeComponent(unsigned level);
	virtual ~AttributeComponent();

	// Functions
	std::string debugPrint() const;

	void gainExp(const unsigned exp);

	void updateStats(const bool reset);
	void updateLevel();
	
	void update();
};

#endif