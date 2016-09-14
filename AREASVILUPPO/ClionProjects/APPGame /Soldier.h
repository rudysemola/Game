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

#ifndef GAMESOFTWARE_BLUESOLDIER_H
#define GAMESOFTWARE_BLUESOLDIER_H

#include "Enemy.h"
#include "CSRandom.h"

class Soldier : public Enemy {
public:
    explicit Soldier(bool r=false,bool danger=false,int l=75,bool al=true,AbStrategyMove* move=new CSRandom);

    virtual ~Soldier() { }

    virtual void updateMove(Player*& player) override;

    virtual void update() override;

    virtual void fight(Player* &player) override;

private:
    bool red;
    bool dangerous;
};


#endif //GAMESOFTWARE_BLUESOLDIER_H
