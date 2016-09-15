//
// Created by rudysemola on 20/07/16.
//
/*
 * interfaccia delle armi,vedi: FireBall.h e Sword.h
*/

#ifndef GAMESOFTWARE_WEAPON_H
#define GAMESOFTWARE_WEAPON_H

#include "Entity.h"

class Weapon : public Entity {
public:
    inline explicit Weapon(bool poss=false,int s = 1) : possessed(poss),strength(s), destroy(false) { }

    inline virtual ~Weapon() {}

    virtual void update(Direction type) = 0;

    int getStrength() const { return strength; }

    void setStrength(int strength) {
        if (strength < 0)
            strength = 0;
        Weapon::strength = strength;
    }

    bool isPossessed() const { return possessed; }

    void setPossessed(bool possessed) { Weapon::possessed = possessed; }

    bool isDestroy() const { return destroy; }

    void setDestroy(bool destroy) { Weapon::destroy = destroy; }

    Direction getTypeW() const { return typeW; }

    void setTypeW(Direction typeW) { Weapon::typeW = typeW; }

protected:
    int strength;
    bool possessed;

    bool destroy;
    Direction typeW;
};

#endif //GAMESOFTWARE_WEAPON_H
