#ifndef AICOMPONENT_H
#define AICOMPONENT_H

#include "Entity.h"
#include "AIFollow.h"

class AIComponent
{
private:
	Entity& entity_;
	Entity& self_;

public:
	AIComponent(Entity& self, Entity& entity);
	~AIComponent();

	/* Functions */
	void update(const float& dt);

};

#endif // AIComponent.h