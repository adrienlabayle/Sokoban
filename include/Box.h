#ifndef BOX_H
#define BOX_H

#include "MobileEntity.h"
#include "staticentity.h"

class Box : public MobileEntity {

    public:
        Box(Coords coords, bool alreadyDone = false);

        bool isDone() const;
        void setDone(const StaticEntity& staticEntity);

    private:
        bool done = false;

};

#endif // BOX_H
