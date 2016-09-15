//
// Created by rudysemola on 28/07/16.
//

#include <iostream>

#include "GhostSoldier.h"
#include "Dice.h"

GhostSoldier::GhostSoldier(bool dforce,int energy,int l, bool al,AbStrategyMove* move) : darkForce(dforce),enegyDrain(energy),Enemy(l, al,move) {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Blue);

    sf::Sprite tempsprite(texture);
    tempsprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    image.loadFromFile(
            "/home/rudysemola/AREASVILUPPO/Resource/sprite/ghostsprite.png");
    texture.loadFromImage(image);
    sprite = tempsprite;

    if (darkForce)
        GhostSoldier::life += 25;
}

void GhostSoldier::update() {
    sprite.setPosition(rect.getPosition());
}

void GhostSoldier::updateMove(Player*& player) {
    strategyMove->preferenceMove(rect,sprite,typeEnemy,directionType,changeDirection,counterWalking,
                                 movementSpeed,counterLength,movementLength,canMoveUp,
                                 canMoveDown,canMoveLeft,canMoveRight,player);
}

void GhostSoldier::fight(Player *&player) {
    int damageHP = 50;
    Dice aDice(6);

    if (aDice.throwDice() == 1) {
        if (!darkForce) {
            damageHP /= 2 - 10;
            std::cout << "GH:colpito,lieve danno" << std::endl;
        }
        else {
            damageHP /= 2;
            std::cout << "GHdark:colpito,danno consistente" << std::endl;
        }
    }
    else if (aDice.throwDice() <= 5) {
        if (!darkForce) {
            damageHP /= 2 + 10;
            std::cout << "GH:colpito,danno consistente" << std::endl;
        }
        else {
            damageHP *= 2 - 10;
            std::cout << "GHdark:colpito,danno oscuro" << std::endl;
        }
    }
    else {
        if (!darkForce) {
            damageHP *= 2;
            std::cout << "GH:colpito,danno massimo" << std::endl;
        }
        else {
            damageHP *= 3;
            std::cout << "GHdark:colpito,danno oscuro massimo" << std::endl;
        }
    }

    enegyDrain += damageHP;
    if(darkForce)
        enegyDrain *= 2;

    if(enegyDrain > 100) {
        life += 25;
        std::cout << "GH life :" << life << std::endl;
        std::cout << "GH energyDrain :" << enegyDrain << std::endl;
    }

    int newHP = player->getHitpoint() - damageHP;
    player->setHitpoint(newHP);
}
