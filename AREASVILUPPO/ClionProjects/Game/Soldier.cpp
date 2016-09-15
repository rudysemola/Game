//
// Created by rudysemola on 28/07/16.
//

#include <iostream>

#include "Soldier.h"
#include "Dice.h"

Soldier::Soldier(bool r,bool danger,int l,bool al,AbStrategyMove* move) : red(r),dangerous(danger),Enemy(l,al,move) {
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Blue);

    sf::Sprite tempsprite(texture);
    tempsprite.setTextureRect(sf::IntRect(0,0,32,32));

    if(!red)
        image.loadFromFile("/home/rudysemola/AREASVILUPPO/Resource/sprite/soldierbluesprite.png");
    else {
        image.loadFromFile(
                "/home/rudysemola/AREASVILUPPO/Resource/sprite/soldierredsprite.png");
        Soldier::life = 100;
    }
    texture.loadFromImage(image);
    sprite = tempsprite;

    if(dangerous)
        Soldier::life += 30;
}

void Soldier::update() {
    sprite.setPosition(rect.getPosition());
}

void Soldier::updateMove(Player*& player) {
    strategyMove->preferenceMove(rect,sprite,typeEnemy,directionType,changeDirection,counterWalking,
                                 movementSpeed,counterLength,movementLength,canMoveUp,
                                 canMoveDown,canMoveLeft,canMoveRight,player);
}

void Soldier::fight(Player* &player) {
    Dice aDice(6);
    int damageHP;

    if(!red) {
        damageHP = 30;

        if(aDice.throwDice() == 1) {
            damageHP /= 2;
            std::cout << "B:colpito,lieve danno" << std::endl;
        }
        else if(aDice.throwDice() <= 5) {
            std::cout << "B:colpito,danno consistente" << std::endl;
        }
        else {
            damageHP *= 2;
            std::cout << "B:colpito,danno massimo" << std::endl;
        }
    }
    else {
        damageHP = 40;

        if(aDice.throwDice() == 1) {
            if(!dangerous) {
                damageHP /= 2 +15;
                std::cout << "R:colpito,lieve danno" << std::endl;
            }
            else {
                damageHP /= 2;
                std::cout << "Rdange:colpito,danno consistente" << std::endl;
            }
        }
        else if(aDice.throwDice() <= 5) {
            if(!dangerous) {
                std::cout << "R:colpito,danno consistente" << std::endl;
            }
            else {
                damageHP *= 2 -15;
                std::cout << "Rdange:colpito,danno pericoloso" << std::endl;
            }
        }
        else {
            if(!dangerous) {
                damageHP *= 2;
                std::cout << "R:colpito,danno massimo" << std::endl;
            }
            else {
                damageHP = damageHP*2 +15;
                std::cout << "Rdange:colpito,danno pericoloso massimo" << std::endl;
            }
        }
    }

    int newHP = player->getHitpoint() - damageHP;
    player->setHitpoint(newHP);
}
