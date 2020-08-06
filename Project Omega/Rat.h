#ifndef RAT_H
#define RAT_H

#include "Enemy.h"

class Rat :
    public Enemy
{
private:
    // Initializer Functions
    void initVariables();
    void initAnimations();
public:
    // Constructor / Destructor
    Rat(sf::Vector2f pos, sf::Texture& texture_sheet);
    virtual ~Rat();

    // Functions
    void takeDamage(const int damage);

    void updateAnimation(const float& dt);
    void update(const float& dt, sf::Vector2f& mouse_pos_view);
    void render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox);
};

#endif // RAT_H