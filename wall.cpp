#include "Wall.h"

Wall::Wall(Coords coords) : StaticEntity(coords) {}

bool Wall::isWalkable() const {
    return false;
}

char Wall::getSymbol() const {
    return 'x';
}
