#ifndef WALL_H
#define WALL_H

#include "StaticEntity.h"

class Wall : public StaticEntity {

    public:
        Wall(Coords coords);

        int getValue() const override;

};

#endif // WALL_H
