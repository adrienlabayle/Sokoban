#include "entity.h"

Entity::Entity(Coords coords) : coords(coords) {}

Entity::~Entity() {}

Coords Entity::getCoords() const {
    return coords;
}

void Entity::setCoords(Coords coords) {
    this->coords = coords;
}
