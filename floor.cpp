#include "Floor.h"

Floor::Floor(Coords coords) : StaticEntity(coords) {}

bool Floor::isWalkable() const {
    return true;
}

char Floor::getSymbol() const {
    return ' ';
}
