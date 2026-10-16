#ifndef WALL_H
#define WALL_H

#include "StaticEntity.h"

class Wall : public StaticEntity {

    public:
        Wall(Coords coords);

        bool isWalkable() const override;
        char getSymbol() const override;

};

#endif // WALL_H
