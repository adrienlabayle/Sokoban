#ifndef PLAYER_H
#define PLAYER_H

#include "MobileEntity.h"

class Player : public MobileEntity {

    public:
        Player(Coords coords = {0, 0});

};

#endif // PLAYER_H
