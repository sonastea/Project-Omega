#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "EnemySpawner.h"

class Entity;
class EnemySpawner;

class Enemy :
    public Entity
{
private:
    // Variables
    EnemySpawner& enemySpawner;

    // Initializer Functions
    void initVariables();
    void initAnimations();

public:
    // Constructor / Destructor
    Enemy(EnemySpawner& enemy_spawner, sf::Vector2f pos, sf::Texture& texture_sheet);
    virtual ~Enemy();

    // Functions
    void updateAnimation(const float& dt);
    void update(const float& dt, sf::Vector2f& mouse_pos_view);
    void render(sf::RenderTarget& target, sf::Shader* shader = nullptr, const sf::Vector2f light_position = sf::Vector2f(), const bool show_hitbox = false);
};

#endif // Entity.h