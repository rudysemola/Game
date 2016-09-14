//
// Created by rudysemola on 30/07/16.
//
/*
 * Classe-interfaccia base.
 * Le classi o interfacce che ereditano sono:
 *      Player.h
 *      Enemy.h
 *      BlockWeapon.h
 *      Weapon.h
 *      Coin.h
 *      PowerUp.h
 */
#ifndef GAMESOFTWARE_ENTITY_H
#define GAMESOFTWARE_ENTITY_H

#include <SFML/Graphics.hpp>

#include "Enums.h"

class Entity {
public:
    //virtual ~Entity() = 0;

    virtual void changePositionRect(int x, int y) {
        rect.setPosition(x, y);
    }

    virtual void changeMoveRect(int x, int y) {
        rect.move(x, y);
    }

    sf::RectangleShape getRect() const { return rect; }

    void setRect(const sf::RectangleShape &rect) { Entity::rect = rect; }

    const sf::Sprite &getSprite() const { return sprite; }

    void setSprite(const sf::Sprite &sprite) { Entity::sprite = sprite; }

protected:
    sf::RectangleShape rect;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;
};

#endif //GAMESOFTWARE_ENTITY_H
