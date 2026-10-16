#include "Bloc.h"

Bloc::Bloc(Coords coords) : MobileEntity(coords) {}

bool Bloc::isPushable() const {
    return true;
}

bool Bloc::canPush() const {
    return false;
}

char Bloc::getSymbol() const {
    return '$';
}
