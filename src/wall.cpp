#include "Wall.h"

Wall::Wall(Coords coords) : StaticEntity(coords) {}

int Wall::getValue() const {
    return 1;
}
