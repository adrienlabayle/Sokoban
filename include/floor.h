#ifndef FLOOR_H
#define FLOOR_H

#include "StaticEntity.h"

class Floor : public StaticEntity {

    public:
        Floor(Coords coords);

        int getValue() const override;

};

#endif // FLOOR_H
