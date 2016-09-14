//
// Created by rudysemola on 13/09/16.
//

#include "gtest/gtest.h"

#include "../CollEntity.h"
#include "../Soldier.h"
#include "../Knight.h"
#include "../Sword.h"

TEST(CollEntity, MissleCollEnemy) {
    CollEntity coll;
    std::vector<FireBall> wPa;
    std::vector<Enemy *> eA;

    FireBall f1;
    f1.setStrength(10);
    wPa.push_back(f1);
    Enemy* e1 = new Soldier;
    e1->changePositionRect(100,100);
    e1->setLife(20);
    eA.push_back(e1);
    coll.missleCollEnemy(wPa,eA);
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        ASSERT_EQ(20,(*itre)->getLife());
        ASSERT_TRUE((*itre)->isAlive());
    }

    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        (*itre)->changePositionRect(0,0);
        (*itre)->update();
    }
    coll.missleCollEnemy(wPa,eA);
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        ASSERT_EQ(10,(*itre)->getLife());
        ASSERT_TRUE((*itre)->isAlive());
    }

    for (auto itre = eA.begin(); itre != eA.end(); itre++)
        (*itre)->setLife(10);
    coll.missleCollEnemy(wPa,eA);
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        ASSERT_EQ(0,(*itre)->getLife());
        ASSERT_FALSE((*itre)->isAlive());
    }
}

TEST(CollEntity, WeaponCollEnemy) {
    CollEntity coll;
    Player* player = new Knight(false,new Sword(false,true,1));
    std::vector<Enemy *> eA;

    Enemy* e1 = new Soldier;
    e1->changePositionRect(100,100);
    e1->setLife(20);
    eA.push_back(e1);
    coll.weaponCollEnemy(player,eA);
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        ASSERT_EQ(20,(*itre)->getLife());
        ASSERT_TRUE((*itre)->isAlive());
    }

    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        (*itre)->changePositionRect(0,0);
        (*itre)->update();
    }
    coll.weaponCollEnemy(player,eA);
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        ASSERT_EQ(19,(*itre)->getLife());
        ASSERT_TRUE((*itre)->isAlive());
    }

    for (auto itre = eA.begin(); itre != eA.end(); itre++)
        (*itre)->setLife(1);
    coll.weaponCollEnemy(player,eA);
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        ASSERT_EQ(0,(*itre)->getLife());
        ASSERT_FALSE((*itre)->isAlive());
    }

}

TEST(CollEntity,collAIEnemy) {
    CollEntity coll;
    std::vector<Enemy *> eA;

    Enemy* e1 = new Soldier;
    e1->changePositionRect(0,0);
    e1->setDirectionType(Direction::Right);
    Enemy* e2 = new Soldier;
    e2->changePositionRect(100,100);
    e2->setDirectionType(Direction::Right);
    eA.push_back(e1);
    eA.push_back(e2);

    coll.collAIEnemy(eA);
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        for(auto itr2=eA.begin(); itr2 != eA.end(); itr2++) {
            if((*itre) != (*itr2)) {
                ASSERT_NE((*itre)->getRect().getPosition().x,(*itr2)->getRect().getPosition().x);
                ASSERT_NE((*itre)->getRect().getPosition().y,(*itr2)->getRect().getPosition().y);
            }
        }

    }

    bool first = true;
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        if(first) {
            (*itre)->changePositionRect(110,120);
            (*itre)->setDirectionType(Direction::Left);
            (*itre)->update();
            first = false;
        }
    }
    coll.collAIEnemy(eA);
    first = true;
    for (auto itre = eA.begin(); itre != eA.end(); itre++) {
        if(first) {
            ASSERT_EQ(Direction::Right,(*itre)->getDirectionType());
            first = false;
        }
    }
}

TEST(CollEntity,IsCaughtCollCoin) {
    CollEntity coll;
    Player* player = new Knight();
    std::vector<Coin*> coins;

    Coin* coin1 = new Coin;
    coin1->changePositionRect(100,100);
    coin1->update();
    coins.push_back(coin1);

    coll.isCaughtCollCoin(coins,player);
    ASSERT_EQ(0,player->getNumCoins());
    for (auto itr = coins.begin(); itr != coins.end(); itr++) {
        ASSERT_FALSE((*itr)->isDestroy());
    }

    player->changePositionRect(100,100);
    player->update();
    coll.isCaughtCollCoin(coins,player);
    ASSERT_EQ(3,player->getNumCoins());
    for (auto itr = coins.begin(); itr != coins.end(); itr++) {
        ASSERT_TRUE((*itr)->isDestroy());
    }
}

TEST(CollEntity,IsCaughtCollPU) {
    CollEntity coll;
    Player* player = new Knight();
    player->setHitpoint(100);
    player->setLife(3);
    std::vector<PowerUp*> pUp;

    PowerUp* powerUp = new PUpConcrete(TypePowerUp::StarHP);
    powerUp->changePositionRect(100,100);
    powerUp->update();
    pUp.push_back(powerUp);

    coll.isCaughtCollPU(pUp,player);
    ASSERT_EQ(100,player->getHitpoint());
    for (auto itr = pUp.begin(); itr != pUp.end(); itr++) {
        ASSERT_FALSE((*itr)->isDestroy());
    }

    player->changePositionRect(100,100);
    player->update();
    coll.isCaughtCollPU(pUp,player);
    ASSERT_NE(100,player->getHitpoint());
    for (auto itr = pUp.begin(); itr != pUp.end(); itr++) {
        ASSERT_TRUE((*itr)->isDestroy());
    }

    for (auto itr = pUp.begin(); itr != pUp.end(); itr++) {
        (*itr)->setTypePowerUp(TypePowerUp::HeartLife);
    }
    coll.isCaughtCollPU(pUp,player);
    ASSERT_NE(3,player->getLife());
    for (auto itr = pUp.begin(); itr != pUp.end(); itr++) {
        ASSERT_TRUE((*itr)->isDestroy());
    }

    player->changePositionRect(250,300);
    player->setLife(3);
    coll.isCaughtCollPU(pUp,player);
    ASSERT_EQ(3,player->getLife());
    for (auto itr = pUp.begin(); itr != pUp.end(); itr++) {
        ASSERT_TRUE((*itr)->isDestroy());
    }
}

TEST(CollEntity,IsCaughtCollBlockW) {
    CollEntity coll;
    CreatorFactoryMethod creator;
    Player* player = new Knight();
    std::vector<BlockWeapon*> blocks;

    BlockWeapon* block1 = new BlockWeapon();
    block1->changePositionRect(200,200);
    block1->update();
    blocks.push_back(block1);

    coll.isCaughtCollBlockW(blocks,player,creator);
    for (auto itr = blocks.begin(); itr != blocks.end(); itr++) {
        ASSERT_FALSE((*itr)->isDestroy());
    }
    ASSERT_EQ(nullptr,player->getWeapon());

    player->changePositionRect(200,200);
    coll.isCaughtCollBlockW(blocks,player,creator);
    for (auto itr = blocks.begin(); itr != blocks.end(); itr++) {
        ASSERT_TRUE((*itr)->isDestroy());
    }
    ASSERT_NE(nullptr,player->getWeapon());
}

TEST(CollEntity,FightAIEnemy) {
    CollEntity coll;
    Player* player = new Knight();
    std::vector<Enemy *> eA;

    player->changePositionRect(100,150);
    player->setTypeP(Direction::Right);
    player->update();
    Enemy* e1 = new Soldier;
    e1->changePositionRect(250,250);
    e1->update();
    eA.push_back(e1);

    coll.fightAIEnemy(eA,player);
    ASSERT_EQ(100,player->getRect().getPosition().x);
    ASSERT_EQ(150,player->getRect().getPosition().y);

    player->setTypeP(Direction::Right);
    player->changePositionRect(260,250);
    player->update();
    coll.fightAIEnemy(eA,player);
    ASSERT_NE(100,player->getHitpoint());
    ASSERT_NE(260,player->getRect().getPosition().x);
    ASSERT_EQ(250,player->getRect().getPosition().y);

    int HP = player->getHitpoint();
    player->setTypeP(Direction::Left);
    player->changePositionRect(280,250);
    player->update();
    coll.fightAIEnemy(eA,player);
    ASSERT_NE(HP,player->getHitpoint());
    ASSERT_NE(280,player->getRect().getPosition().x);
    ASSERT_EQ(250,player->getRect().getPosition().y);

    HP = player->getHitpoint();
    player->setTypeP(Direction::Up);
    player->changePositionRect(250,280);
    player->update();
    coll.fightAIEnemy(eA,player);
    ASSERT_NE(HP,player->getHitpoint());
    ASSERT_EQ(250,player->getRect().getPosition().x);
    ASSERT_NE(280,player->getRect().getPosition().y);

    HP = player->getHitpoint();
    player->setTypeP(Direction::Down);
    player->changePositionRect(250,255);
    player->update();
    coll.fightAIEnemy(eA,player);
    ASSERT_NE(HP,player->getHitpoint());
    ASSERT_EQ(250,player->getRect().getPosition().x);
    ASSERT_NE(255,player->getRect().getPosition().y);
}

