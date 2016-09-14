//
// Created by rudysemola on 14/08/16.
//

#include "DrawEntity.h"

void DrawEntity::drawMissle(sf::RenderWindow &w, std::vector<FireBall> &wPa, Player *&playeruseW) {
    for (auto iterW = wPa.begin(); iterW != wPa.end(); iterW++) {
        (*iterW).update(playeruseW->getTypeP());
        w.draw((*iterW).getSprite());
    }
}

void DrawEntity::weaponDisplay(Player *&playeruseW, sf::RenderWindow &w) {
    sf::RectangleShape temprect = playeruseW->getWeapon()->getRect();

    if (playeruseW->getTypeP() == Direction::Up)
        temprect.setPosition(playeruseW->getRect().getPosition().x, playeruseW->getRect().getPosition().y - 10);
    else if (playeruseW->getTypeP() == Direction::Down)
        temprect.setPosition(playeruseW->getRect().getPosition().x + 32,
                             playeruseW->getRect().getPosition().y + 32 + 10);
    else if (playeruseW->getTypeP() == Direction::Right)
        temprect.setPosition(playeruseW->getRect().getPosition().x + 32, playeruseW->getRect().getPosition().y);
    else if (playeruseW->getTypeP() == Direction::Left)
        temprect.setPosition(playeruseW->getRect().getPosition().x - 10,
                             playeruseW->getRect().getPosition().y + 10 + 32);

    playeruseW->changeDisplayWeapon(temprect);

    w.draw(playeruseW->getWeapon()->getSprite());
}

void DrawEntity::drawAIEnemy(std::vector<Enemy *> &eA, sf::RenderWindow &w) {
    for (auto itr = eA.begin(); itr != eA.end(); itr++) {
        w.draw((*itr)->getSprite());
    }
}

void DrawEntity::drawCoins(std::vector<Coin *> &coinsArray, sf::RenderWindow &w) {
    for (auto itr = coinsArray.begin(); itr != coinsArray.end(); itr++) {
        (*itr)->update();
        w.draw((*itr)->getSprite());
    }
}

void DrawEntity::drawPowerUp(std::vector<PowerUp *> &pUp, sf::RenderWindow &w) {
    for (auto itr = pUp.begin(); itr != pUp.end(); itr++) {
        (*itr)->update();
        w.draw((*itr)->getSprite());
    }
}

void DrawEntity::drawBlockW(std::vector<BlockWeapon *> &blockA, sf::RenderWindow &w) {
    for (auto itr = blockA.begin(); itr != blockA.end(); itr++) {
        (*itr)->update();
        w.draw((*itr)->getSprite());
    }
}