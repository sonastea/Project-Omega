#ifndef RAT_H
#define RAT_H

#include "Enemy.h"

#include "AIFollow.h"

class Rat :
    public Enemy
{
private:
    // Initializer Functions
    void initVariables();
    void initAnimations();
    void initAI();
    void initGui();

    sf::RectangleShape hpBar_;

    AIFollow* follow_;

public:
    // Constructor / Destructor
    Rat(sf::Vector2f pos, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
    virtual ~Rat();

    // Functions
    void updateAnimation(const float& dt);
    void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

    void render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox);
};

#endif // RAT_H