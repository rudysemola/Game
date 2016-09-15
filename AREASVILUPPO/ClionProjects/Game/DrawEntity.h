//
// Created by rudysemola on 14/08/16.
//
/*
 * ...
 */
#ifndef GAMESOFTWARE_DRAWENTITY_H
#define GAMESOFTWARE_DRAWENTITY_H

#include "Player.h"
#include "Enemy.h"
#include "BlockWeapon.h"
#include "FireBall.h"
#include "Coin.h"
#include "PowerUp.h"

class DrawEntity {
public:
    void drawMissle(sf::RenderWindow &w, std::vector<FireBall> &wPa, Player *&playeruseW);

    //When it is used Display Player'Weapon
    void weaponDisplay(Player *&playeruseW, sf::RenderWindow &w);

    //AI draw enemy
    void drawAIEnemy(std::vector<Enemy *> &eA, sf::RenderWindow &w);

    void drawCoins(std::vector<Coin *> &coinsArray, sf::RenderWindow &w);

    void drawPowerUp(std::vector<PowerUp *> &pUp, sf::RenderWindow &w);

    void drawBlockW(std::vector<BlockWeapon *> &blockA, sf::RenderWindow &w);
};


#endif //GAMESOFTWARE_DRAWENTITY_H
