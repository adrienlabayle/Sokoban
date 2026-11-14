#ifndef MOBILEENTITY_H
#define MOBILEENTITY_H

#include "Entity.h"

class MobileEntity : public Entity {

    public:
        MobileEntity(Coords coords);

        void move(Direction dir);

};

#endif // MOBILEENTITY_H
