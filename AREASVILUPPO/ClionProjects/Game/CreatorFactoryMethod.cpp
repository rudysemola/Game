//
// Created by rudysemola on 28/07/16.
//

#include "CreatorFactoryMethod.h"
#include "Dice.h"

#include "Knight.h"
#include "Soldier.h"
#include "GhostSoldier.h"

#include "Sword.h"

Player *CreatorFactoryMethod::createPlayer(TypePlayer type,sf::Vector2i& screen) {
    Player * player;

    switch (type) {
        case TypePlayer ::PlayerKnightFuturistic :
        {
            player = new Knight(true);
            player->changePositionRect(250, 150);
            player->update();
            return player;
        }
        case TypePlayer ::PlayerKnightSupreme :
        {
            player = new Knight();
            player->changePositionRect(250, 150);
            player->update();
            return player;
        }
    }
}

void CreatorFactoryMethod::createAllEnemy(std::vector<Enemy *> &enemyArray) {
    std::vector<Enemy *> tempArray;

    tempArray = createEnemy(TypeEnemy::EnemyBlueSoldier_11);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        enemyArray.push_back((*itr));

    tempArray.clear();
    tempArray = createEnemy(TypeEnemy::EnemyBlueSoldier_12);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        enemyArray.push_back((*itr));

    tempArray.clear();
    tempArray = createEnemy(TypeEnemy::EnemyBlueSoldier_13);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        enemyArray.push_back((*itr));

    tempArray.clear();
    tempArray = createEnemy(TypeEnemy::EnemyRedSoldier_21);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        enemyArray.push_back((*itr));

    tempArray.clear();
    tempArray = createEnemy(TypeEnemy::EnemyRedSoldier_23);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        enemyArray.push_back((*itr));

    tempArray.clear();
    tempArray = createEnemy(TypeEnemy::EnemyRedSoldier_Dangerous_31);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        enemyArray.push_back((*itr));

    tempArray.clear();
    tempArray = createEnemy(TypeEnemy::EnemyGhostSoldier_32);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        enemyArray.push_back((*itr));

    tempArray.clear();
    tempArray = createEnemy(TypeEnemy::EnemyGhostSoldier_DarkForce_33);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        enemyArray.push_back((*itr));
}

std::vector<Enemy *> CreatorFactoryMethod::createEnemy(TypeEnemy typeEnemy) {
    std::vector<Enemy *> enemyArray;

    if(typeEnemy == TypeEnemy::AllEnemy) {
        createAllEnemy(enemyArray);

        return enemyArray;
    }

    switch (typeEnemy) {
        case TypeEnemy::EnemyBlueSoldier_11 :
        {
            Enemy *e1 = new Soldier;
            e1->changePositionRect(100, 150);
            e1->update();
            Enemy *e2 = new Soldier;
            e2->changePositionRect(100, 300);
            e2->update();
            Enemy *e3 = new Soldier;
            e3->changePositionRect(100, 400);
            e3->update();
            Enemy *e4 = new Soldier;
            e4->changePositionRect(100,500);
            e4->update();
            enemyArray.push_back(e1);
            enemyArray.push_back(e2);
            enemyArray.push_back(e3);
            enemyArray.push_back(e4);

            for (auto itr=enemyArray.begin(); itr!=enemyArray.end(); itr++) {
                (*itr)->setTypeEnemy(TypeEnemy::EnemyBlueSoldier_11);
            }

            return enemyArray;
        }
        case TypeEnemy::EnemyBlueSoldier_12 :
        {
            Enemy *e1 = new Soldier;
            e1->changePositionRect(800+100, 150);
            e1->update();
            Enemy *e2 = new Soldier;
            e2->changePositionRect(800+350, 150);
            e2->update();
            Enemy *e3 = new Soldier;
            e3->changePositionRect(800+600, 150);
            e3->update();
            Enemy *e4 = new Soldier;
            e4->changePositionRect(800+400, 350);
            e4->update();
            enemyArray.push_back(e1);
            enemyArray.push_back(e2);
            enemyArray.push_back(e3);
            enemyArray.push_back(e4);

            for (auto itr=enemyArray.begin(); itr!=enemyArray.end(); itr++) {
                (*itr)->setTypeEnemy(TypeEnemy::EnemyBlueSoldier_12);
            }

            return enemyArray;
        }
        case TypeEnemy::EnemyBlueSoldier_13 :
        {
            Enemy *e1 = new Soldier;
            e1->changePositionRect(2*800+400, 200);
            e1->update();
            Enemy *e2 = new Soldier;
            e2->changePositionRect(2*800+400, 400);
            e2->update();
            Enemy *e3 = new Soldier;
            e3->changePositionRect(2*800+400, 600);
            e3->update();
            enemyArray.push_back(e1);
            enemyArray.push_back(e2);
            enemyArray.push_back(e3);

            for (auto itr=enemyArray.begin(); itr!=enemyArray.end(); itr++) {
                (*itr)->setTypeEnemy(TypeEnemy::EnemyBlueSoldier_13);
            }

            return enemyArray;
        }
        case TypeEnemy::EnemyRedSoldier_21 :
        {
            Enemy *e1 = new Soldier(true);
            e1->changePositionRect(150, 600+200);
            e1->update();
            Enemy *e2 = new Soldier(true);
            e2->changePositionRect(400, 600+200);
            e2->update();
            Enemy *e3 = new Soldier(true);
            e3->changePositionRect(650, 600+200);
            e3->update();
            enemyArray.push_back(e1);
            enemyArray.push_back(e2);
            enemyArray.push_back(e3);

            for (auto itr=enemyArray.begin(); itr!=enemyArray.end(); itr++) {
                (*itr)->setTypeEnemy(TypeEnemy::EnemyRedSoldier_21);
            }

            return enemyArray;
        }
        case TypeEnemy::EnemyRedSoldier_23 :
        {
            Enemy *e1 = new Soldier(true);
            e1->changePositionRect(2*800+100, 600+200);
            e1->update();
            Enemy *e2 = new Soldier(true);
            e2->changePositionRect(2*800+450, 600+200);
            e2->update();
            Enemy *e3 = new Soldier(true);
            e3->changePositionRect(2*800+650, 600+200);
            e3->update();
            Enemy *e4 = new Soldier(true);
            e4->changePositionRect(2*800+300, 600+200);
            e4->update();
            enemyArray.push_back(e1);
            enemyArray.push_back(e2);
            enemyArray.push_back(e3);
            enemyArray.push_back(e4);

            for (auto itr=enemyArray.begin(); itr!=enemyArray.end(); itr++) {
                (*itr)->setTypeEnemy(TypeEnemy::EnemyRedSoldier_23);
            }

            return enemyArray;
        }
        case TypeEnemy::EnemyRedSoldier_Dangerous_31 :
        {
            Enemy *e1 = new Soldier(true,true);
            e1->changePositionRect(100, 2*600-100);
            e1->update();
            Enemy *e2 = new Soldier(true,true);
            e2->changePositionRect(100, 2*600+100);
            e2->update();
            Enemy *e3 = new Soldier(true,true);
            e3->changePositionRect(600, 2*600-100);
            e3->update();
            Enemy *e4 = new Soldier(true,true);
            e4->changePositionRect(600, 2*600+100);
            e4->update();
            enemyArray.push_back(e1);
            enemyArray.push_back(e2);
            enemyArray.push_back(e3);
            enemyArray.push_back(e4);

            for (auto itr=enemyArray.begin(); itr!=enemyArray.end(); itr++) {
                (*itr)->setTypeEnemy(TypeEnemy::EnemyRedSoldier_Dangerous_31);
            }

            return enemyArray;
        }
        case TypeEnemy ::EnemyGhostSoldier_32 :
        {
            Enemy *e1 = new GhostSoldier;
            e1->changePositionRect(800+500, 2*600-50);
            e1->update();
            Enemy *e2 = new GhostSoldier;
            e2->changePositionRect(800+350, 2*600+50);
            e2->update();
            enemyArray.push_back(e1);
            enemyArray.push_back(e2);

            for (auto itr=enemyArray.begin(); itr!=enemyArray.end(); itr++) {
                (*itr)->setTypeEnemy(TypeEnemy::EnemyGhostSoldier_32);
            }

            return enemyArray;
        }
        case TypeEnemy ::EnemyGhostSoldier_DarkForce_33 :
        {
            Enemy *e1 = new GhostSoldier(true);
            e1->changePositionRect(2*800+400, 2*600+150);
            e1->update();
            enemyArray.push_back(e1);

            for (auto itr=enemyArray.begin(); itr!=enemyArray.end(); itr++) {
                (*itr)->setTypeEnemy(TypeEnemy::EnemyGhostSoldier_DarkForce_33);
            }

            return enemyArray;
        }
    }
}

void CreatorFactoryMethod::createRandomEnemy(std::vector<Enemy *> &enemyArray) {
    Dice aDice(8);
    Dice xDice(3*700);
    Dice yDice(3*500);

    switch (aDice.throwDice()-1) {
        case static_cast<int>(TypeEnemy::EnemyBlueSoldier_11) :
        {
            Enemy *e1 = new Soldier;
            int x = xDice.throwDice()+50;
            int y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyBlueSoldier_11);
            enemyArray.push_back(e1);
        }
        case static_cast<int>(TypeEnemy::EnemyBlueSoldier_12) :
        {
            Enemy *e1 = new Soldier;
            int x = xDice.throwDice()+50;
            int y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyBlueSoldier_12);
            enemyArray.push_back(e1);
            Enemy *e2 = new Soldier;
            x = xDice.throwDice()+50;
            y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyBlueSoldier_12);
            enemyArray.push_back(e2);

        }
        case static_cast<int>(TypeEnemy::EnemyBlueSoldier_13) :
        {
            Enemy *e1 = new Soldier;
            int x = xDice.throwDice()+50;
            int y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyBlueSoldier_13);
            enemyArray.push_back(e1);
            Enemy *e2 = new Soldier;
            x = xDice.throwDice()+50;
            y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyBlueSoldier_13);
            enemyArray.push_back(e2);
            Enemy *e3 = new Soldier;
            x = xDice.throwDice()+50;
            y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyBlueSoldier_13);
            enemyArray.push_back(e3);
        }
        case static_cast<int>(TypeEnemy::EnemyRedSoldier_21 ):
        {
            Enemy *e1 = new Soldier(true);
            int x = xDice.throwDice()+50;
            int y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyRedSoldier_21);
            enemyArray.push_back(e1);

        }
        case static_cast<int>(TypeEnemy::EnemyRedSoldier_23) :
        {
            Enemy *e1 = new Soldier(true);
            int x = xDice.throwDice()+50;
            int y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyRedSoldier_23);
            enemyArray.push_back(e1);
            Enemy *e2 = new Soldier(true);
            x = xDice.throwDice()+50;
            y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyRedSoldier_23);
            enemyArray.push_back(e2);
        }
        case static_cast<int>(TypeEnemy::EnemyRedSoldier_Dangerous_31) :
        {
            Enemy *e1 = new Soldier(true,true);
            int x = xDice.throwDice()+50;
            int y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyRedSoldier_Dangerous_31);
            enemyArray.push_back(e1);

        }
        case static_cast<int>(TypeEnemy ::EnemyGhostSoldier_32) :
        {
            Enemy *e1 = new GhostSoldier;
            int x = xDice.throwDice()+50;
            int y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyGhostSoldier_32);
            enemyArray.push_back(e1);



        }
        case static_cast<int>(TypeEnemy ::EnemyGhostSoldier_DarkForce_33) :
        {
            Enemy *e1 = new GhostSoldier(true);
            int x = xDice.throwDice()+50;
            int y = yDice.throwDice()+50;
            e1->changePositionRect(x,y);
            e1->update();
            e1->setTypeEnemy(TypeEnemy::EnemyGhostSoldier_DarkForce_33);
            enemyArray.push_back(e1);
        }
    }

}

void CreatorFactoryMethod::createAllCoins(std::vector<Coin *>& coinsArray) {
    std::vector<Coin *> tempArray;

    tempArray = createCoins(TypeCoin::SilverCoin_11);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::SilverCoin_12);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::SilverCoin_13);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::SilverCoin_21);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::SilverCoin_22);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::SilverCoin_23);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray = createCoins(TypeCoin::SilverCoin_31);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::SilverCoin_32);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::SilverCoin_33);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::GoldCoin_11);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::GoldCoin_12);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray =  createCoins(TypeCoin::GoldCoin_13);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::GoldCoin_21);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::GoldCoin_22);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::GoldCoin_23);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::GoldCoin_31);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::GoldCoin_32);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));

    tempArray.clear();
    tempArray = createCoins(TypeCoin::GoldCoin_33);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        coinsArray.push_back((*itr));
}

std::vector<Coin *> CreatorFactoryMethod::createCoins(TypeCoin typeCoin) {
    std::vector<Coin *> coinsArray;

    if(typeCoin == TypeCoin::AllCoins) {
        createAllCoins(coinsArray);

        return coinsArray;
    }

    switch (typeCoin) {
        case TypeCoin::SilverCoin_11 : {
            Coin *coin1 = new Coin;
            coin1->changePositionRect(650, 100);
            coin1->update();
            Coin *coin2 = new Coin;
            coin2->changePositionRect(650, 400);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::SilverCoin_12 : {
            Coin *coin1 = new Coin;
            coin1->changePositionRect(800 + 50, 350);
            coin1->update();
            Coin *coin2 = new Coin;
            coin2->changePositionRect(800 + 650, 350);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::SilverCoin_13 : {
            Coin *coin1 = new Coin;
            coin1->changePositionRect(2 * 800 + 650, 200);
            coin1->update();
            Coin *coin2 = new Coin;
            coin2->changePositionRect(2 * 800 + 650, 300);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::SilverCoin_21 : {
            Coin *coin1 = new Coin;
            coin1->changePositionRect(360, 600 + 50);
            coin1->update();
            Coin *coin2 = new Coin;
            coin2->changePositionRect(360, 600 + 150);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::SilverCoin_22 : {
            Coin *coin1 = new Coin;
            coin1->changePositionRect(800 + 50, 600 + 200);
            coin1->update();
            Coin *coin2 = new Coin;
            coin2->changePositionRect(800 + 50, 600 + 250);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::SilverCoin_23 : {
            Coin *coin1 = new Coin;
            coin1->changePositionRect(2 * 800 + 390, 600 + 100);
            coin1->update();
            Coin *coin2 = new Coin;
            coin2->changePositionRect(2 * 800 + 390, 600 + 300);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::SilverCoin_31 : {
            Coin *coin1 = new Coin;
            coin1->changePositionRect(360, 2 * 600);
            coin1->update();
            Coin *coin2 = new Coin;
            coin2->changePositionRect(400, 2 * 600);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::SilverCoin_32 : {
            Coin *coin1 = new Coin;
            coin1->changePositionRect(800 + 100, 2 * 600 + 200);
            coin1->update();
            Coin *coin2 = new Coin;
            coin2->changePositionRect(800 + 600, 2 * 600 + 200);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::SilverCoin_33 : {
            Coin *coin1 = new Coin;
            coin1->changePositionRect(2 * 800 + 650, 2 * 600);
            coin1->update();
            Coin *coin2 = new Coin;
            coin2->changePositionRect(2 * 800 + 650, 2 * 600 - 50);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }

        case TypeCoin::GoldCoin_11 : {
            Coin *coin1 = new Coin(true);
            coin1->changePositionRect(50, 100);
            coin1->update();
            Coin *coin2 = new Coin(true);
            coin2->changePositionRect(50, 400);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::GoldCoin_12 : {
            Coin *coin1 = new Coin(true);
            coin1->changePositionRect(800 + 50, 50);
            coin1->update();
            Coin *coin2 = new Coin(true);
            coin2->changePositionRect(800 + 650, 50);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::GoldCoin_13 : {
            Coin *coin1 = new Coin(true);
            coin1->changePositionRect(2 * 800 + 50, 150);
            coin1->update();
            Coin *coin2 = new Coin(true);
            coin2->changePositionRect(2 * 800 + 50, 350);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::GoldCoin_21 : {
            Coin *coin1 = new Coin(true);
            coin1->changePositionRect(360, 600 + 10);
            coin1->update();
            Coin *coin2 = new Coin(true);
            coin2->changePositionRect(360, 600 + 200);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::GoldCoin_22 : {
            Coin *coin1 = new Coin(true);
            coin1->changePositionRect(800 + 650, 600 + 200);
            coin1->update();
            Coin *coin2 = new Coin(true);
            coin2->changePositionRect(800 + 650, 600 + 250);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::GoldCoin_23 : {
            Coin *coin1 = new Coin(true);
            coin1->changePositionRect(2 * 800 + 390, 600 + 190);
            coin1->update();
            Coin *coin2 = new Coin(true);
            coin2->changePositionRect(2 * 800 + 390, 600 + 330);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::GoldCoin_31 : {
            Coin *coin1 = new Coin(true);
            coin1->changePositionRect(360, 2 * 600 + 50);
            coin1->update();
            Coin *coin2 = new Coin(true);
            coin2->changePositionRect(400, 2 * 600 + 50);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::GoldCoin_32 : {
            Coin *coin1 = new Coin(true);
            coin1->changePositionRect(800 + 500, 2 * 600 + 50);
            coin1->update();
            Coin *coin2 = new Coin(true);
            coin2->changePositionRect(800 + 600, 2 * 600 + 50);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
        case TypeCoin::GoldCoin_33 : {
            Coin *coin1 = new Coin(true);
            coin1->changePositionRect(2 * 800 + 100, 2 * 600 + 100);
            coin1->update();
            Coin *coin2 = new Coin(true);
            coin2->changePositionRect(2 * 800 + 100, 2 * 600 + 350);
            coin2->update();

            coinsArray.push_back(coin1);
            coinsArray.push_back(coin2);

            return coinsArray;
        }
    }
}

void CreatorFactoryMethod::createAllPowerUp(std::vector<PowerUp *> &pUpArray) {
    std::vector<PowerUp *> tempArray;

    tempArray = createPowerUp(TypePowerUp::StarHP);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        pUpArray.push_back((*itr));

    tempArray.clear();
    tempArray = createPowerUp(TypePowerUp::HeartLife);
    for(auto itr=tempArray.begin(); itr!=tempArray.end(); itr++)
        pUpArray.push_back((*itr));
}

std::vector<PowerUp *> CreatorFactoryMethod::createPowerUp(TypePowerUp typePU) {
    std::vector<PowerUp *> pUpArray;

    if(typePU == TypePowerUp::AllPowerUp) {
        createAllPowerUp(pUpArray);

        return pUpArray;
    }

    if(typePU == TypePowerUp::StarHP) {
        PowerUp *star1 = new PUpConcrete(TypePowerUp::StarHP);
        star1->changePositionRect(800+50, 300);
        star1->update();
        PowerUp *star2 = new PUpConcrete(TypePowerUp::StarHP);
        star2->changePositionRect(800+650, 300);
        star2->update();

        pUpArray.push_back(star1);
        pUpArray.push_back(star2);
    }
    if(typePU == TypePowerUp::HeartLife) {
        PowerUp *heart1 = new PUpConcrete(TypePowerUp::HeartLife);
        heart1->changePositionRect(400, 400);
        heart1->update();
        PowerUp *heart2 = new PUpConcrete(TypePowerUp::HeartLife);
        heart2->changePositionRect(2*800+400, 400);
        heart2->update();

        pUpArray.push_back(heart1);
        pUpArray.push_back(heart2);
    }

    return pUpArray;
}


void CreatorFactoryMethod::primePowerUp(TypePowerUp typePU, std::vector<PowerUp *> &pUpArray, Enemy *enemy) {
    if(typePU == TypePowerUp::StarHP) {
        PowerUp *starPrime = new PUpConcrete(TypePowerUp::StarHP);
        starPrime->changePositionRect(enemy->getRect().getPosition().x, enemy->getRect().getPosition().y);
        starPrime->update();

        pUpArray.push_back(starPrime);
    }
    else if(typePU == TypePowerUp::HeartLife) {
        PowerUp *heartPrime = new PUpConcrete(TypePowerUp::HeartLife);
        heartPrime->changePositionRect(enemy->getRect().getPosition().x, enemy->getRect().getPosition().y);
        heartPrime->update();

        pUpArray.push_back(heartPrime);
    }
}

std::vector<BlockWeapon *> CreatorFactoryMethod::createBlockW() {
    std::vector<BlockWeapon *> block;

    BlockWeapon *b1 = new BlockWeapon;
    b1->changePositionRect(800+380, 100);
    b1->update();
    BlockWeapon *b2 = new BlockWeapon;
    b2->changePositionRect(800+500,600+200);
    b2->update();
    BlockWeapon *b3 = new BlockWeapon;
    b3->changePositionRect(800+150,2*600+50);
    b3->update();

    block.push_back(b1);
    block.push_back(b2);
    block.push_back(b3);

    return block;
}

Weapon* CreatorFactoryMethod::createWeapon(TypeWeapon typeW) {
    switch (typeW) {
        case TypeWeapon::Fireball :
        {
            Weapon * fireball = new FireBall;
            fireball->changePositionRect(650,600+100);
            fireball->update(Direction::null);
            return fireball;
        }

        case TypeWeapon::Sword :
        {
            Weapon * sword = new Sword;
            sword->changePositionRect(800+500,600+200);
            sword->update(Direction::null);
            return sword;
        }
        case TypeWeapon::Sword_super :
        {
            Weapon * sword = new Sword(true);
            sword->changePositionRect(2*800+100,600+200);
            sword->update(Direction::null);
            return sword;
        }
    }
}

void CreatorFactoryMethod::createMissles(Player* &player, FireBall &weapon, std::vector<FireBall> &wMissle) {
    sf::RectangleShape temprect = weapon.getRect();
    temprect.setPosition(player->getRect().getPosition().x + player->getRect().getSize().x / 2 -
                         weapon.getRect().getSize().x / 2,
                         player->getRect().getPosition().y + player->getRect().getSize().y / 2 -
                         weapon.getRect().getSize().y / 2);
    weapon.setRect(temprect);
    weapon.setTypeW(player->getTypeP());
    wMissle.push_back(weapon);
}