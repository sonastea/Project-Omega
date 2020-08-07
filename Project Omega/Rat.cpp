#include "stdafx.h"
#include "Rat.h"

/* Initializer functions */

void Rat::initVariables()
{
}

void Rat::initAnimations()
{
	this->animationComponent->addAnimation("IDLE", 25.f, 0, 0, 3, 0, 60, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 11.f, 0, 1, 3, 1, 60, 64);
	this->animationComponent->addAnimation("WALK_LEFT", 11.f, 0, 2, 3, 2, 60, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 11.f, 0, 3, 3, 3, 60, 64);
	this->animationComponent->addAnimation("WALK_UP", 11.f, 0, 4, 3, 4, 60, 64);
	this->animationComponent->addAnimation("ATTACK", 5.f, 0, 2, 1, 2, 60, 64);
}

void Rat::initGui()
{
	hpBar_.setFillColor(sf::Color::Red);
	hpBar_.setSize(sf::Vector2f(60.f, 10.f));
	hpBar_.setPosition(this->sprite.getPosition());
}

/* Constructor */
Rat::Rat(sf::Vector2f pos, sf::Texture& texture_sheet)
	: Enemy()
{
	this->initVariables();
	this->initGui();

	this->createHitboxComponent(this->sprite, 13.f, 39.f, 30.f, 30.f);
	this->createMovementComponent(50.f, 1600.f, 1000.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1);

	this->setPosition(pos);
	this->initAnimations();
}

/* Destructor */
Rat::~Rat()
{
}

/* Functions */
void Rat::updateAnimation(const float& dt)
{
	if (this->movementComponent->getState(IS_IDLE))
	{
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
}

void Rat::update(const float& dt, sf::Vector2f& mouse_pos_view)
{
	this->movementComponent->update(dt);

	//this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	// Update GUI REMOVE THIS!!!!
	hpBar_.setSize(sf::Vector2f(60.f * (static_cast<float>(this->attributeComponent->hp) / this->attributeComponent->hpMax), 10.f));
	hpBar_.setPosition(this->sprite.getPosition());
}

void Rat::render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox)
{
	if (shader)
	{
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		target.draw(this->sprite, shader);
	}
	else
	{
		target.draw(this->sprite);
	}

	target.draw(this->hpBar_);

	if (show_hitbox)
		this->hitboxComponent->render(target);
}