//
// Created by rudysemola on 28/07/16.
//
/*
 * Attributi della classe(ereditati):
 * sf::RectangleShape rect;
 * sf::Image image;
 * sf::Texture texture;
 * sf::Sprite sprite;
 * sf::Text text;
 *      Weapon *weapon;
 *      int hitpoint;
 *      int numCoins;
 *      int life;
 *
 *      TypeWeapon  typeWeapon;
 *      int counterWalking;
 *      int movementSpeed;
 *      Direction typeP;
 *      bool canMoveUp, canMoveDown, canMoveLeft, canMoveRight;
*/

#ifndef GAMESOFTWARE_KNIGHTFUTURISTIC_H
#define GAMESOFTWARE_KNIGHTFUTURISTIC_H

#include"Player.h"

class Knight : public Player {
public:
    explicit Knight(bool futur=false,Weapon* w=nullptr);

    virtual ~Knight() { }

    virtual void updateMove() override;

    virtual void update() override;

private:
    bool futuristic;
};

#endif //GAMESOFTWARE_KNIGHTFUTURISTIC_H
