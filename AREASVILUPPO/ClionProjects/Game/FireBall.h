//
// Created by rudysemola on 21/07/16.
//
/*
 * Attributi della classe(ereditati):
 * sf::RectangleShape rect;
 * sf::Image image;
 * sf::Texture texture;
 * sf::Sprite sprite;
 * sf::Text text;
 *   int strength;
 *   bool possessed;
 *   bool destroy;
 *   Direction typeW;
 */
#ifndef GAMESOFTWARE_FIREBALL_H
#define GAMESOFTWARE_FIREBALL_H

#include "Weapon.h"

class FireBall : public Weapon {
public:
    explicit FireBall(bool poss=false,int s = 5);

    virtual ~FireBall() { }

    virtual void update(Direction type) override;

private:
    int movementSpeed;
    int lifeTime;
    int counterLifeTime;
    int counterAnimation;
};


#endif //GAMESOFTWARE_FIREBALL_H
