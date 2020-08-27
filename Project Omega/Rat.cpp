#include "stdafx.h"
#include "Rat.h"

/* Initializer functions */

void Rat::initVariables()
{
}

void Rat::initAnimations()
{
	/*this->animationComponent->addAnimation("IDLE", 25.f, 0, 0, 3, 0, 60, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 11.f, 0, 1, 3, 1, 60, 64);
	this->animationComponent->addAnimation("WALK_LEFT", 11.f, 0, 2, 3, 2, 60, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 11.f, 0, 3, 3, 3, 60, 64);
	this->animationComponent->addAnimation("WALK_UP", 11.f, 0, 4, 3, 4, 60, 64);
	this->animationComponent->addAnimation("ATTACK", 5.f, 0, 2, 1, 2, 60, 64);*/
	this->animationComponent->addAnimation("IDLE", 6.85f, 0, 0, 6, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 6.85f, 0, 0, 6, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_LEFT", 6.85f, 0, 0, 6, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 6.85f, 0, 0, 6, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_UP", 6.85f, 0, 0, 6, 0, 64, 64);
	this->animationComponent->addAnimation("ATTACK", 6.85f, 0, 0, 6, 0, 64, 64);
}

void Rat::initAI()
{
}

void Rat::initGui()
{
	hpBar_.setFillColor(sf::Color::Red);
	hpBar_.setSize(sf::Vector2f(60.f, 10.f));
	hpBar_.setPosition(this->sprite.getPosition());
}

/* Constructor */
Rat::Rat(sf::Vector2f pos, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
	: Enemy(enemy_spawner_tile)
{
	this->initVariables();
	this->initGui();

	this->createHitboxComponent(this->sprite, 13.f, 39.f, 30.f, 30.f);
	this->createMovementComponent(50.f, 1600.f, 1000.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1);

	this->generateAttributes(this->attributeComponent->level);

	this->setPosition(pos);
	this->initAnimations();

	this->follow_ = new AIFollow(*this, player);
}

/* Destructor */
Rat::~Rat()
{
	delete this->follow_;
}

/* Functions */
void Rat::updateAnimation(const float& dt)
{
	if (this->movementComponent->getState(to_int((MovementState::IS_IDLE))))
	{
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(to_int(MovementState::MOVING_LEFT)))
	{
		this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(to_int(MovementState::MOVING_RIGHT)))
	{
		this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(to_int(MovementState::MOVING_UP)))
	{
		this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(to_int(MovementState::MOVING_DOWN)))
	{
		this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}

	if (this->damageTimer_.getElapsedTime().asMilliseconds() <= this->damageTimerMax_)
	{

	}
	else
		this->sprite.setColor(sf::Color::White);
}

void Rat::update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
	Enemy::update(dt, mouse_pos_view, view);

	this->movementComponent->update(dt);

	//this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->follow_->update(dt);

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