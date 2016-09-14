//
// Created by rudysemola on 19/07/16.
//
/*
 * Classe che rappresenta le monete del gioco ogni volta che il player li ottiene-per collisione- aumenta il suo numCoin
 * (sono di due tipi: argento value=3 e d'oro value=10)
 */
#ifndef GAMESOFTWARE_COIN_H
#define GAMESOFTWARE_COIN_H

#include "Entity.h"

class Coin : public Entity {
public:
    explicit Coin(bool r = false, int v = 3,bool d=false);

    inline virtual ~Coin() {}

    virtual void update();

    int isCaught();

    bool isDestroy() const { return destroy; }
    void setDestroy(bool destroy) { Coin::destroy = destroy; }

private:
    int value;
    bool raro;

    bool destroy;
};


#endif //GAMESOFTWARE_COIN_H
