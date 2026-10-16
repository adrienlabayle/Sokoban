#ifndef MOBILEENTITY_H
#define MOBILEENTITY_H

#include "Entity.h"

class MobileEntity : public Entity {

    public:
        MobileEntity(Coords coords);

        virtual bool isPushable() const = 0;
        virtual bool canPush() const = 0;

        Coords getNextCoords(Direction dir) const;
        void move(Direction dir);

};

#endif // MOBILEENTITY_H
