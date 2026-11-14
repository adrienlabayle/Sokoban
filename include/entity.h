#ifndef ENTITY_H
#define ENTITY_H

#include "Coords.h"

class Entity {

    protected:
        Coords coords;

    public:
        Entity(Coords coords);
        virtual ~Entity();

        Coords getCoords() const;
        void setCoords(Coords coords);

};

#endif // ENTITY_H
