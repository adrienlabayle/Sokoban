#ifndef DEPOT_H
#define DEPOT_H

#include "StaticEntity.h"

class Depot : public StaticEntity {

    public:
        Depot(Coords coords);

        int getValue() const override;

};

#endif // DEPOT_H
