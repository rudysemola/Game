//
// Created by rudysemola on 16/08/16.
//

#include"Player.h"

Player::Player(Weapon *w) : weapon(w), hitpoint(100), numCoins(0), life(3), counterWalking(0), movementSpeed(1),
                            typeP(Direction::Up), typeWeapon(TypeWeapon::null),
                            canMoveUp(true), canMoveDown(true), canMoveLeft(true), canMoveRight(true) { }

Player::~Player() {
    if (weapon != nullptr)
        delete weapon;
}

void Player::changeDisplayWeapon(sf::RectangleShape temprect) {
    weapon->setRect(temprect);
    weapon->setTypeW(typeP);
    weapon->update(typeP);
}

void Player::setWeapon(Weapon *weapon) {
    if (Player::weapon != nullptr)
        delete Player::weapon;

    Player::weapon = weapon;
}

void Player::setHitpoint(int hitpoint) {
    if (hitpoint < 0)
        hitpoint = 0;
    Player::hitpoint = hitpoint;

    if (Player::hitpoint == 0) {
        Player::hitpoint = 100;
        int lessLife = Player::getLife() - 1;
        setLife(lessLife);
        std::cout << "Player life less: " << Player::getLife();
    }
    std::cout << "Player HP: " << Player::hitpoint;
}

void Player::setNumCoins(int numCoins) {
    if (numCoins < 0)
        numCoins = 0;

    Player::numCoins = numCoins;

    if (Player::numCoins >= 100) {
        Player::numCoins = 0;
        int plusLife = Player::getLife() + 1;
        setLife(plusLife);
        std::cout << "Player life plus: " << Player::getLife();
    }
}

void Player::setLife(int life) {
    if (life <= 0) {
        life = 0;
        std::cout << "Player DEAD.GAME OVER: " << Player::getLife();
    }

    Player::life = life;
}