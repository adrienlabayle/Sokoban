#include "Depot.h"

Depot::Depot(Coords coords) : StaticEntity(coords) {}

int Depot::getValue() const {
    return 2;
}
