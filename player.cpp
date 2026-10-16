#include "Player.h"

Player::Player(Coords coords) : MobileEntity(coords) {}

bool Player::isPushable() const {
    return false;
}

bool Player::canPush() const {
    return true;
}

char Player::getSymbol() const {
    return 'P';
}
