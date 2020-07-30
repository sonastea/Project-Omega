#include "stdafx.h"
#include "Sword.h"

Sword::Sword()
{
	// Visual Weapon
	if (!this->weaponTexture.loadFromFile("Assets/Models/Weapon/stellar-sword.png"))
	{
		std::cout << "ERROR::SWORD::COULD NOT LOAD WEAPON TEXTURE." << "\n";
	}

	this->weaponSprite.setTexture(weaponTexture);

	this->weaponSprite.setOrigin
	(
		this->weaponSprite.getGlobalBounds().width / 2.f,
		this->weaponSprite.getGlobalBounds().height
	);
}

Sword::~Sword()
{
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

