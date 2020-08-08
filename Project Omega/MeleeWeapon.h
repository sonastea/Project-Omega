#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H

#include "Weapon.h"

class MeleeWeapon :
    public Weapon
{
private:

protected:

public:
    MeleeWeapon(unsigned level, unsigned damage_min, unsigned damage_max, 
        unsigned range, unsigned value, 
        std::string texture_file);
    virtual ~MeleeWeapon();

    /* Functions */
    virtual MeleeWeapon* clone() = 0;
    virtual void generate(const unsigned level_min, const unsigned level_max);

    virtual void update(const sf::Vector2f mouse_pos_view, const sf::Vector2f center) = 0;
    virtual void render(sf::RenderTarget& target, sf::Shader* shader) = 0;
};

#endif // MeleeWeapon.h