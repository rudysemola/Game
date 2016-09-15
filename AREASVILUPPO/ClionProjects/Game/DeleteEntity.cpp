//
// Created by rudysemola on 14/08/16.
//

#include "DeleteEntity.h"
#include "Dice.h"

void DeleteEntity::deleteMissle(std::vector<FireBall> &wPa) {
    for (auto iterW = wPa.begin(); iterW != wPa.end(); iterW++) {
        if ((*iterW).isDestroy()) {
            wPa.erase(iterW);
            break;
        }
    }
}

void DeleteEntity::deleteCoins(std::vector<Coin *> &coinsArray) {
    for (auto itr = coinsArray.begin(); itr != coinsArray.end(); itr++) {
        if ((*itr)->isDestroy()) {
            coinsArray.erase(itr);
            break;
        }
    }
}

void DeleteEntity::deletePowerUp(std::vector<PowerUp *> &pUp) {
    for (auto itr = pUp.begin(); itr != pUp.end(); itr++) {
        if ((*itr)->isDestroy()) {
            pUp.erase(itr);
            break;
        }
    }
}

void DeleteEntity::deleteEnemy(CreatorFactoryMethod &factory, std::vector<Enemy *> &eA,
                               std::vector<PowerUp *> &powerUpArray) {
    for (auto itr = eA.begin(); itr != eA.end(); itr++) {
        if (!(*itr)->isAlive()) {
            Dice aDice(10);
            if (aDice.throwDice() <= 8)
                factory.primePowerUp(TypePowerUp::StarHP, powerUpArray, (*itr));
            else
                factory.primePowerUp(TypePowerUp::HeartLife, powerUpArray, (*itr));
            eA.erase(itr);
            break;
        }
    }
}

void DeleteEntity::deleteBlock(std::vector<BlockWeapon *> &blockA) {
    for (auto itr = blockA.begin(); itr != blockA.end(); itr++) {

        if ((*itr)->isDestroy()) {
            blockA.erase(itr);
            break;
        }
    }
}