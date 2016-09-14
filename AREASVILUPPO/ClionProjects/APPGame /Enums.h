//
// Created by rudysemola on 28/07/16.
//
/*
 * Questo file contiene tutti li enum per il gioco
 */
#ifndef GAMESOFTWARE_ENUMS_H
#define GAMESOFTWARE_ENUMS_H

enum class TypePlayer {
    PlayerKnightFuturistic, PlayerKnightSupreme
};

enum class TypeEnemy {
    EnemyBlueSoldier_11,
    EnemyBlueSoldier_12,
    EnemyBlueSoldier_13,
    EnemyRedSoldier_21,
    EnemyRedSoldier_23,
    EnemyRedSoldier_Dangerous_31,
    EnemyGhostSoldier_32,
    EnemyGhostSoldier_DarkForce_33,
    AllEnemy
};

enum class TypeTile {
    NoCollGrass_11,
    CollWall_11,
    CollWall_12,
    CollWall_21,
    CollWall_22,
    NoCollGrass_12,
    NoCollGrass_21,
    NoCollGrass_22,
    CollWater_11,
    CollWater_12,
    CollWater_21,
    CollWater_22,
    CollGrass,
    CollTrampolineRotate_11,
    CollTrampolineRotate_12,
    CollTrampoline_21,
    CollTrampoline_22,
    CollTrampoline_31,
    CollTrampoline_32
};

enum class TypeCoin {
    SilverCoin_11,
    SilverCoin_12,
    SilverCoin_13,
    SilverCoin_21,
    SilverCoin_22,
    SilverCoin_23,
    SilverCoin_31,
    SilverCoin_32,
    SilverCoin_33,
    GoldCoin_11,
    GoldCoin_12,
    GoldCoin_13,
    GoldCoin_21,
    GoldCoin_22,
    GoldCoin_23,
    GoldCoin_31,
    GoldCoin_32,
    GoldCoin_33,
    AllCoins,
};

enum class TypePowerUp {
    StarHP, HeartLife, AllPowerUp
};

enum class TypeWeapon {
    Fireball, Sword, Sword_super, null
};

enum class Direction {
    Up, Down, Left, Right, null
};

#endif //GAMESOFTWARE_ENUMS_H
