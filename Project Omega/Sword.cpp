#include "stdafx.h"
#include "Sword.h"

Sword::Sword(unsigned level, unsigned damage_min, unsigned damage_max,
	unsigned range, unsigned value,
	std::string texture_file)
	: MeleeWeapon(level, damage_min, damage_max, range, value, texture_file)
{
	// Visual Weapon
	this->weaponSprite.setOrigin
	(
		this->weaponSprite.getGlobalBounds().width / 2.f,
		this->weaponSprite.getGlobalBounds().height
	);

	std::cout << this->damageMax << " " << this->damageMin << "\n";
}

Sword::~Sword()
{
}

Sword* Sword::clone()
{
	return new Sword(*this);
}

void Sword::update(const sf::Vector2f mouse_pos_view, const sf::Vector2f center)
{
	// Update visual weapon
	this->weaponSprite.setPosition(center);

	float dX = mouse_pos_view.x - this->weaponSprite.getPosition().x;
	float dY = mouse_pos_view.y - this->weaponSprite.getPosition().y;

	const float PI = 3.14159265f;
	float deg = atan2(dY, dX) * 180.f / PI;

	this->weaponSprite.setRotation(deg + 90.f);
}

void Sword::render(sf::RenderTarget& target, sf::Shader* shader)
{
	if (shader)
		target.draw(this->weaponSprite, shader);
	else
		target.draw(this->weaponSprite);
}

