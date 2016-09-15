//
// Created by rudysemola on 14/08/16.
//
/*
 *
 */
#ifndef GAMESOFTWARE_DELETEENTITY_H
#define GAMESOFTWARE_DELETEENTITY_H

#include <vector>

#include "Coin.h"
#include "PowerUp.h"
#include "BlockWeapon.h"
#include "Weapon.h"
#include "FireBall.h"
#include "Player.h"
#include "Enemy.h"
#include "CreatorFactoryMethod.h"

#include "Enums.h"

class DeleteEntity {
public:
    void deleteMissle(std::vector<FireBall> &wPa);

    void deleteCoins(std::vector<Coin *> &coinsArray);

    void deletePowerUp(std::vector<PowerUp *> &pUp);

    //delete Enemy after player success fight;player has a PowerUp prime
    void deleteEnemy(CreatorFactoryMethod &factory,std::vector<Enemy *> &eA,std::vector<PowerUp *> &powerUpArray);

    //delete BlockWeapon after collision
    void deleteBlock(std::vector<BlockWeapon *> &blockA);
};


#endif //GAMESOFTWARE_DELETEENTITY_H
