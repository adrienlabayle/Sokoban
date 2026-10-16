#ifndef PLAYER_H
#define PLAYER_H

#include "MobileEntity.h"

class Player : public MobileEntity {

    public:
        Player(Coords coords = {0, 0});

        bool isPushable() const override;
        bool canPush() const override;
        char getSymbol() const override;

};

#endif // PLAYER_H
