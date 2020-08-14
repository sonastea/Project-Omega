#include "stdafx.h"
#include "AIFollow.h"

AIFollow::AIFollow(Entity& self, Entity& entity)
	: AIOption(self, entity)
{
}

AIFollow::~AIFollow()
{
}

void AIFollow::update(const float& dt)
{
	sf::Vector2f moveVec;
	moveVec.x = entity_.getPosition().x - self_.getPosition().x;
	moveVec.y = entity_.getPosition().y - self_.getPosition().y;
	float vecLength = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));
	moveVec /= vecLength;

	if ((self_.getPosition().x != entity_.getPosition().x) && std::abs(vecLength) < 500.f)
		self_.move(sf::Vector2f(moveVec.x, moveVec.y), dt);
}
