#ifndef BLOC_H
#define BLOC_H

#include "MobileEntity.h"

class Bloc : public MobileEntity {

    public:
        Bloc(Coords coords);

        bool isPushable() const override;
        bool canPush() const override;
        char getSymbol() const override;

};

#endif // BLOC_H
