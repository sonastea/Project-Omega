#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
class Weapon :
    public Item
{
private:
    /* Initializer Functions */
    void initVariables();

protected:
    sf::Texture weaponTexture;
    sf::Sprite weaponSprite;

    unsigned damageMin;
    unsigned damageMax;
    unsigned range;

    sf::Clock attackTimer;
    sf::Int32 attackTimerMax;

    float cooldown;
    float cooldownMax;
    float cooldownIteration;

public:
    /* Constructor / Destructor */
    Weapon(unsigned value, std::string texture_file);
    virtual ~Weapon();

    // Getters / Accessors
    const unsigned& getDamageMin() const;
    const unsigned& getDamagemax() const;
    const unsigned& getRange() const;
    const bool getAttackTimer();

    /* Functions */
    virtual Item* clone() = 0;

    virtual void update(const sf::Vector2f mouse_pos_view, const sf::Vector2f center) = 0;
    virtual void render(sf::RenderTarget& target, sf::Shader* shader = nullptr) = 0;

};

#endif // Weapon.h