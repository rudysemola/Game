//
// Created by rudysemola on 14/08/16.
//
/*
 * La classe si occupa del controllo delle collisioni tra le diverse entità(in particolare player con le altre entità)
 */
#ifndef GAMESOFTWARE_COLLISIONENTITY_H
#define GAMESOFTWARE_COLLISIONENTITY_H

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

class CollEntity {
public:
    //Missle FireBall collides with enemy: dinamic fight
    void missleCollEnemy(std::vector<FireBall> &wPa, std::vector<Enemy *> eA);

    //Player'Weapon collides with enemy: dinamic fight
    void weaponCollEnemy(Player *&player, std::vector<Enemy *> eA);

    //Enemy fight during collision with player
    void fightAIEnemy(std::vector<Enemy *> &eA, Player *&player);

    //Enemy collision beetween their
    void collAIEnemy(std::vector<Enemy *> &eA);

    //Player collides with coins
    void isCaughtCollCoin(std::vector<Coin *> &coinsArray, Player *&player);

    //Player collides with powerUp
    void isCaughtCollPU(std::vector<PowerUp *> &pUp, Player *&player);

    //Player collides with BlockWeapon,player get a (new) weapon
    void isCaughtCollBlockW(std::vector<BlockWeapon *> &blockA, Player *&player, CreatorFactoryMethod &factory);
};


#endif //GAMESOFTWARE_COLLISIONENTITY_H
