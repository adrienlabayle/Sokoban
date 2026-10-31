#include "Floor.h"

Floor::Floor(Coords coords) : StaticEntity(coords) {}

int Floor::getValue() const {
    return 0;
}
