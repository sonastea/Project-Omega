#ifndef BOW_H
#define BOW_H

#include "RangedWeapon.h"

class Bow :
    public RangedWeapon
{
private:
    
public:
    Bow(unsigned value);
    virtual ~Bow();

    /* Functions */
    virtual Bow* clone();
};

#endif // Bow.h