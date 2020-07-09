#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
class Player :
    public Entity
{
private:
    // Variables

    // Initializer functions
    void initVariables();
    void initComponents();

public:
    Player(sf::Vector2f pos, sf::Texture& texture_sheet);
    virtual ~Player();

    // Functions
    virtual void update(const float& dt);
};

#endif