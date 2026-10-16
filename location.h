#ifndef LOCATION_H
#define LOCATION_H

#include "StaticEntity.h"

class Location : public StaticEntity {

    public:
        Location(Coords coords);

        bool isWalkable() const override;
        bool isGoal() const override;
        char getSymbol() const override;

};

#endif // LOCATION_H
