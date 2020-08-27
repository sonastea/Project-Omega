#include "stdafx.h"
#include "Enemy.h"

/* Initializer functions */

void Enemy::initVariables()
{
	this->gainExp = 10;
	this->damageTimerMax_ = 1000;
	this->despawnTimerMax_ = 1000;
}

void Enemy::initAnimations()
{
}

/* Constructors / Destructors */

Enemy::Enemy(EnemySpawnerTile& enemy_spawner_tile)
	: enemySpawnerTile_(enemy_spawner_tile)
{
	this->initVariables();
	this->initAnimations();
}

Enemy::~Enemy()
{
}

/* Accessors / Getters */
const unsigned& Enemy::getGainExp() const
{
	return this->gainExp;
}

EnemySpawnerTile& Enemy::getEnemySpawnerTile()
{
	return this->enemySpawnerTile_;
}

const bool Enemy::getDamageTimerDone() const
{
	return this->damageTimer_.getElapsedTime().asMilliseconds() >= this->damageTimerMax_;
}

const bool Enemy::getDespawnTimerDone() const
{
	return this->despawnTimer_.getElapsedTime().asMilliseconds() >= this->despawnTimerMax_;
}

/* Modifiers / Setters */
void Enemy::resetDamageTimer()
{
	this->damageTimer_.restart();
}

/* Functions */
void Enemy::generateAttributes(const unsigned level)
{
	this->gainExp = level * (rand() % 5 + 1);
}

void Enemy::loseHP(const int hp)
{
	if (this->attributeComponent)
	{
		this->attributeComponent->loseHP(hp);
	}
}

const bool Enemy::isDead() const
{
	if (this->attributeComponent)
	{
		return this->attributeComponent->isDead();
	}

	return false;
}

const AttributeComponent* Enemy::getAttributeComponent() const
{
	if (this->attributeComponent)
	{
		return this->attributeComponent;
	}
	else
	{
		std::cout << "ERROR::ENEMY::ATTRIBUTECOMPONENT IS NOT INITIALISZED" << "\n";
		return nullptr;
	}
}

void Enemy::update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
	if (vectorDistance(this->getPosition(), view.getCenter()) < 1500.f)
		this->despawnTimer_.restart();
}