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
 *      int life;
 *      bool alive;
 *      AbStrategyMove *strategyMove;
 *      TypeEnemy typeEnemy;
 *      Direction directionType;
 *      bool changeDirection;
 *      int counterWalking;
 *      int movementSpeed;
 *      int counterLength;
 *      int movementLength;
*/

#ifndef GAMESOFTWARE_GHOSTSOLDIER_H
#define GAMESOFTWARE_GHOSTSOLDIER_H

#include "Enemy.h"
#include "Weapon.h"
#include "CSRandom.h"

class GhostSoldier : public Enemy {
public:
    explicit GhostSoldier(bool dforce = false,int energy=0,int l=125,bool al=true,AbStrategyMove* move=new CSRandom);

    virtual ~GhostSoldier() { }

    virtual void updateMove(Player*& player) override;

    virtual void update() override;

    virtual void fight(Player* &player) override;


private:
    bool darkForce;
    int enegyDrain;
};


#endif //GAMESOFTWARE_GHOSTSOLDIER_H
