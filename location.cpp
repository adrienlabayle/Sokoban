#include "Location.h"

Location::Location(Coords coords) : StaticEntity(coords) {}

bool Location::isWalkable() const {
    return true;
}

bool Location::isGoal() const {
    return true;
}

char Location::getSymbol() const {
    return '-';
}
