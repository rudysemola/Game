//
// Created by rudysemola on 19/07/16.
//
/*
 * Interfaccia dei personaggi "cattivi",vedi: Soldier.h,GhostSoldier.h
*/

#ifndef GAMESOFTWARE_ENEMY_H
#define GAMESOFTWARE_ENEMY_H

#include"Entity.h"
#include "Player.h"
#include "AbStrategyMove.h"

class Enemy : public Entity {
public:
    inline Enemy(int l, bool al, AbStrategyMove *move) : life(l), alive(al), strategyMove(move), changeDirection(false),
                                                         counterWalking(0), movementSpeed(1),
                                                         counterLength(0), movementLength(30),
                                                         canMoveUp(true), canMoveDown(true), canMoveLeft(true),
                                                         canMoveRight(true) { }

    inline virtual ~Enemy() {
        if (strategyMove != nullptr)
            delete strategyMove;
    }

    virtual void updateMove(Player *&player) = 0;

    virtual void update() = 0;

    virtual void fight(Player *&player) = 0;

    int getLife() const { return life; }

    void setLife(int life) {
        if (life < 0)
            life = 0;
        Enemy::life = life;
    }

    bool isAlive() const { return alive; }

    void setAlive(bool alive) { Enemy::alive = alive; }

    void setStrategyMove(AbStrategyMove *strategyMove) {
        if (Enemy::strategyMove != nullptr)
            delete Enemy::strategyMove;

        Enemy::strategyMove = strategyMove;
    }

    TypeEnemy getTypeEnemy() const { return typeEnemy; }

    void setTypeEnemy(TypeEnemy typeEnemy) { Enemy::typeEnemy = typeEnemy; }

    Direction getDirectionType() const { return directionType; }

    void setDirectionType(Direction directionType) { Enemy::directionType = directionType; }

    void setCanMoveUp(bool canMoveUp) { Enemy::canMoveUp = canMoveUp; }
    void setCanMoveDown(bool canMoveDown) { Enemy::canMoveDown = canMoveDown; }
    void setCanMoveLeft(bool canMoveLeft) { Enemy::canMoveLeft = canMoveLeft; }
    void setCanMoveRight(bool canMoveRight) { Enemy::canMoveRight = canMoveRight; }

protected:
    int life;
    bool alive;
    AbStrategyMove *strategyMove;

    TypeEnemy typeEnemy;
    Direction directionType;
    bool changeDirection;
    int counterWalking;
    int movementSpeed;
    int counterLength;
    int movementLength;
    bool canMoveUp, canMoveDown, canMoveLeft, canMoveRight;
};

#endif //GAMESOFTWARE_ENEMY_H
