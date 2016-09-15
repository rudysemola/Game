//
// Created by rudysemola on 11/08/16.
//
/*
 *Classe dei blocchi che allla collisione con il player danno un'arma
 */
#ifndef GAMESOFTWARE_BLOCKWEAPON_H
#define GAMESOFTWARE_BLOCKWEAPON_H

#include"Entity.h"

class BlockWeapon : public Entity {
public:
    explicit BlockWeapon(bool d=false);

    virtual ~BlockWeapon() {}

    virtual void update();

    bool isDestroy() const { return destroy; }

    void setDestroy(bool destroy) { BlockWeapon::destroy = destroy; }

private:
    bool destroy;
};


#endif //GAMESOFTWARE_BLOCKWEAPON_H
