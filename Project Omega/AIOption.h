#ifndef AIOPTION_H
#define AIOPTION_H

#include "Entity.h"

class AIOption
{
protected:
	Entity& self_;
	Entity& entity_;

public:
	AIOption(Entity& self, Entity& entity)
		: self_(self), entity_(entity)
	{

	}

	virtual void update(const float& dt) = 0;
};

#endif // AIOption.h