#ifndef STATICENTITY_H
#define STATICENTITY_H

#include "Entity.h"

class StaticEntity : public Entity {

    public:
        StaticEntity(Coords coords);

        virtual bool isWalkable() const = 0;
        virtual bool isGoal() const;

};
#endif // STATICENTITY_H
