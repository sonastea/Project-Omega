#include "Entity.h"

void Entity::initVariables()
{
	this->hitboxComponent = NULL;
	this->movementComponent = NULL;
	this->animationComponent = NULL;
}

Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->hitboxComponent;
	delete this->movementComponent;
	delete this->animationComponent;
}


// Components functions
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createHitboxComponent(sf::Sprite& sprite, 
	float offset_x, float offset_y, float width, float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width, height);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}


/* Functions */
void Entity::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(sf::Vector2f(pos.x, pos.y));
}

void Entity::move(const sf::Vector2f& direction, const float& dt)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(direction, dt);
	}
}

void Entity::update(const float& dt)
{
	if (this->movementComponent)
		this->movementComponent->update(dt);
}

void Entity::render(sf::RenderTarget& target)
{
		target.draw(this->sprite); // rendering itself to the screen

		if (this->hitboxComponent)
			this->hitboxComponent->render(target);
}
