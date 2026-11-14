#ifndef STATICENTITY_H
#define STATICENTITY_H

#include "Entity.h"

class StaticEntity : public Entity {

    public:
        StaticEntity(Coords coords);

        virtual int getValue() const = 0;
};
#endif // STATICENTITY_H
