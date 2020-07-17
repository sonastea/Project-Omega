#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player :
    public Entity
{
private:
    // Variables
    bool isAttacking;

    // Initializer functions
    void initVariables();
    void initComponents();

public:
    Player(sf::Vector2f pos, sf::Texture& texture_sheet);
    virtual ~Player();

    // Functions
    void updateAttack();
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};

#endif