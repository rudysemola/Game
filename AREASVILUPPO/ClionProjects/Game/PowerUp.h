//
// Created by rudysemola on 20/07/16.
//
/*
 * interfaccia dei potenziamenti dei personaggi"buoni",vedi: PUpConcrete.h e HeartLife.h
*/
#ifndef GAMESOFTWARE_POWERUP_H
#define GAMESOFTWARE_POWERUP_H

#include "Entity.h"

class PowerUp : public Entity {
public:
    inline explicit PowerUp(int nA,TypePowerUp type,bool d=false) : numActivator(nA),typePowerUp(type),destroy(d) { }

    inline virtual ~PowerUp() {}

    virtual void update() = 0;

    virtual int isCaught() = 0;

    int getNumActivator() const { return numActivator; }

    void setNumActivator(int numActivator) { PowerUp::numActivator = numActivator; }

    bool isDestroy() const { return destroy; }

    void setDestroy(bool destroy) { PowerUp::destroy = destroy; }

    TypePowerUp getTypePowerUp() const { return typePowerUp; }

    void setTypePowerUp(TypePowerUp typePowerUp) { PowerUp::typePowerUp = typePowerUp; }

protected:
    int numActivator;
    bool destroy;

    TypePowerUp typePowerUp;
};

#endif //GAMESOFTWARE_POWERUP_H
