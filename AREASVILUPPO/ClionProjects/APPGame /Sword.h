//
// Created by rudysemola on 11/08/16.
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
#ifndef GAMESOFTWARE_SWORD_H
#define GAMESOFTWARE_SWORD_H

#include "Weapon.h"

class Sword : public Weapon {
public:
    explicit Sword(bool sSw = false,bool poss=false, int s = 1);

    virtual ~Sword() { }

    virtual void update(Direction type) override;

    bool isSuperWeapon() const { return superSword; }

    void setSuperWeapon(bool superWeapon) { Sword::superSword = superWeapon; }

private:
    bool superSword;
};


#endif //GAMESOFTWARE_SWORD_H
