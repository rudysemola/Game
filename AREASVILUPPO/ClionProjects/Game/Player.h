//
// Created by rudysemola on 19/07/16.
//
/*
 * interfaccia dei personaggi "buoni",l'utente può selezionere uno tra questi: Knight.h
*/

#ifndef GAMESOFTWARE_PLAYER_H
#define GAMESOFTWARE_PLAYER_H

#include <iostream>

#include "Entity.h"
#include "Weapon.h"

class Player : public Entity {
public:
    explicit Player(Weapon *w);

    virtual ~Player();

    virtual void updateMove() = 0;

    virtual void update() = 0;

    void changeDisplayWeapon(sf::RectangleShape temprect);

    Weapon *getWeapon() const { return weapon; }

    void setWeapon(Weapon *weapon);

    int getHitpoint() const { return hitpoint; }

    void setHitpoint(int hitpoint);

    int getNumCoins() const { return numCoins; }

    void setNumCoins(int numCoins);


    int getLife() const { return life; }

    void setLife(int life);

    TypeWeapon getTypeWeapon() const { return typeWeapon;}

    void setTypeWeapon(TypeWeapon typeWeapon) { Player::typeWeapon = typeWeapon; }

    const Direction getTypeP() const { return typeP; }

    void setTypeP(Direction typeP) { Player::typeP = typeP; }

    void setCanMoveUp(bool canMoveUp) { Player::canMoveUp = canMoveUp; }
    void setCanMoveDown(bool canMoveDown) { Player::canMoveDown = canMoveDown; }
    void setCanMoveLeft(bool canMoveLeft) { Player::canMoveLeft = canMoveLeft; }
    void setCanMoveRight(bool canMoveRight) { Player::canMoveRight = canMoveRight; }

protected:
    Weapon *weapon;
    int hitpoint;
    int numCoins;
    int life;

    TypeWeapon  typeWeapon;
    int counterWalking;
    int movementSpeed;
    Direction typeP;
    bool canMoveUp, canMoveDown, canMoveLeft, canMoveRight;
};

#endif //GAMESOFTWARE_PLAYER_H
