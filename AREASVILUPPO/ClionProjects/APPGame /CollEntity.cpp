//
// Created by rudysemola on 14/08/16.
//

#include "CollEntity.h"
#include "CSChase.h"

void CollEntity::missleCollEnemy(std::vector<FireBall> &wPa, std::vector<Enemy *> eA) {
    for (auto itrw = wPa.begin(); itrw != wPa.end(); itrw++) {
        for (auto itre = eA.begin(); itre != eA.end(); itre++) {
            if ((*itrw).getSprite().getGlobalBounds().intersects((*itre)->getRect().getGlobalBounds())) {
                int damage = (*itrw).getStrength();
                std::cout << "damage: " << (*itrw).getStrength() << std::endl;
                int newHPenemy = (*itre)->getLife() - damage;
                (*itre)->setLife(newHPenemy);
                std::cout << "Life Enemy: " << (*itre)->getLife() << std::endl;

                if ((*itre)->getLife() == 0)
                    (*itre)->setAlive(false);

                (*itre)->setStrategyMove(new CSChase);
            }
        }
    }
}

void CollEntity::weaponCollEnemy(Player *&player, std::vector<Enemy *> eA) {
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        if (player->getWeapon() != nullptr && player->getWeapon()->isPossessed()) {
            if (player->getWeapon()->getSprite().getGlobalBounds().intersects((*itre)->getRect().getGlobalBounds())) {
                int damage = player->getWeapon()->getStrength();
                std::cout << "damage: " << player->getWeapon()->getStrength() << std::endl;
                int newHPenemy = (*itre)->getLife() - damage;
                (*itre)->setLife(newHPenemy);
                std::cout << "Life Enemy: " << (*itre)->getLife() << std::endl;

                if ((*itre)->getLife() == 0)
                    (*itre)->setAlive(false);

                (*itre)->setStrategyMove(new CSChase);
            }
        }
    }
}

void CollEntity::fightAIEnemy(std::vector<Enemy *> &eA, Player *&player) {
    for (auto itr = eA.begin(); itr != eA.end(); itr++) {
        if ((*itr)->getRect().getGlobalBounds().intersects(player->getSprite().getGlobalBounds())) {
            (*itr)->fight(player);

            if (player->getTypeP() == Direction::Up)
                player->changePositionRect(player->getRect().getPosition().x, player->getRect().getPosition().y + 32);
            if (player->getTypeP() == Direction::Down)
                player->changePositionRect(player->getRect().getPosition().x, player->getRect().getPosition().y - 32);
            if (player->getTypeP() == Direction::Left)
                player->changePositionRect(player->getRect().getPosition().x + 32, player->getRect().getPosition().y);
            if (player->getTypeP() == Direction::Right)
                player->changePositionRect(player->getRect().getPosition().x - 32, player->getRect().getPosition().y);

            player->update();
            (*itr)->setStrategyMove(new CSChase);
        }
    }
}

void CollEntity::collAIEnemy(std::vector<Enemy *> &eA) {
    for (auto itr1 = eA.begin(); itr1 != eA.end(); itr1++) {
        for (auto itr2 = eA.begin(); itr2 != eA.end(); itr2++) {
            if ((*itr1) != (*itr2)) {
                if ((*itr2)->getRect().getGlobalBounds().intersects((*itr1)->getSprite().getGlobalBounds())) {

                    if ((*itr1)->getDirectionType() == Direction::Up)
                        (*itr1)->setDirectionType(Direction::Down);
                    else if ((*itr1)->getDirectionType() == Direction::Down)
                        (*itr1)->setDirectionType(Direction::Up);
                    else if ((*itr1)->getDirectionType() == Direction::Right)
                        (*itr1)->setDirectionType(Direction::Left);
                    else if ((*itr1)->getDirectionType() == Direction::Left)
                        (*itr1)->setDirectionType(Direction::Right);

                    (*itr1)->update();
                }
            }
        }
    }
}

void CollEntity::isCaughtCollCoin(std::vector<Coin *> &coinsArray, Player *&player) {

    for (auto itr = coinsArray.begin(); itr != coinsArray.end(); itr++) {
        int addValue = player->getNumCoins();
        if (player->getRect().getGlobalBounds().intersects((*itr)->getSprite().getGlobalBounds())) {
            addValue += (*itr)->isCaught();
            player->setNumCoins(addValue);
            (*itr)->setDestroy(true);
            std::cout << "numero monete: " << player->getNumCoins() << std::endl;
        }
    }
}

void CollEntity::isCaughtCollPU(std::vector<PowerUp *> &pUp, Player *&player) {
    for (auto itr = pUp.begin(); itr != pUp.end(); itr++) {
        int addHP = player->getHitpoint();
        int addLife = player->getLife();
        if (player->getRect().getGlobalBounds().intersects((*itr)->getSprite().getGlobalBounds())) {
            if ((*itr)->getTypePowerUp() == TypePowerUp::StarHP) {
                addHP += (*itr)->isCaught();
                player->setHitpoint(addHP);
                (*itr)->setDestroy(true);
                std::cout << "HP: " << player->getHitpoint() << std::endl;
            }
            if ((*itr)->getTypePowerUp() == TypePowerUp::HeartLife) {
                addLife += (*itr)->isCaught();
                player->setLife(addLife);
                (*itr)->setDestroy(true);
                std::cout << "life: " << player->getLife() << std::endl;
            }
        }
    }
}

void CollEntity::isCaughtCollBlockW(std::vector<BlockWeapon *> &blockA, Player *&player,
                                    CreatorFactoryMethod &factory) {
    for (auto itr = blockA.begin(); itr != blockA.end(); itr++) {

        if (player->getRect().getGlobalBounds().intersects((*itr)->getSprite().getGlobalBounds())) {
            Weapon *newWeapon;
            TypeWeapon typeW;

            if (player->getRect().getPosition().y < 600 - 88) {
                newWeapon = factory.createWeapon(TypeWeapon::Sword_super);
                typeW = TypeWeapon::Sword_super;
                std::cout << "nuova arma SuperSword" << std::endl;
            }
            else if (player->getRect().getPosition().y >= 600 - 88 &&
                     player->getRect().getPosition().y < 2 * 600 - 88) {
                newWeapon = factory.createWeapon(TypeWeapon::Sword);
                typeW = TypeWeapon::Sword;
                std::cout << "nuova arma Sword" << std::endl;
            }
            else if (player->getRect().getPosition().y >= 2 * 600 - 88) {
                newWeapon = factory.createWeapon(TypeWeapon::Fireball);
                typeW = TypeWeapon::Fireball;
                std::cout << "nuova arma Fireball" << std::endl;
            }

            newWeapon->setPossessed(true);
            if (newWeapon != nullptr) {
                player->setWeapon(newWeapon);
                player->setTypeWeapon(typeW);
            }

            (*itr)->setDestroy(true);
        }
    }
}