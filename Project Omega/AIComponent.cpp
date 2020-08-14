#include "stdafx.h"
#include "AIComponent.h"

AIComponent::AIComponent(Entity& self, Entity& entity)
	: self_(self), entity_(entity)
{
}

AIComponent::~AIComponent()
{
}

/* Functions */
void AIComponent::update(const float& dt)
{
}
