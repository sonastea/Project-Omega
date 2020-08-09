#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "EnemySpawnerTile.h"

class Enemy :
    public Entity
{
private:
    // Variables
    EnemySpawnerTile& enemySpawnerTile_;
    unsigned gainExp;

    // Initializer Functions
    virtual void initVariables() = 0;
    virtual void initAnimations() = 0;

public:
    // Constructor / Destructor
    Enemy(EnemySpawnerTile& enemy_spawner_tile);
    virtual ~Enemy();
    
    // Accessors / Getters
    const unsigned& getGainExp() const;
    EnemySpawnerTile& getEnemySpawnerTile();

    // Functions
    virtual void generateAttributes(const unsigned level);

    virtual void loseHP(const int hp);
    virtual const bool isDead() const;

    virtual const AttributeComponent* getAttributeComponent() const;

    virtual void updateAnimation(const float& dt) = 0;
    
    virtual void update(const float& dt, sf::Vector2f& mouse_pos_view) = 0;
    virtual void render(sf::RenderTarget& target, sf::Shader* shader = nullptr, const sf::Vector2f light_position = sf::Vector2f(), const bool show_hitbox = false) = 0;
};

#endif // Entity.h