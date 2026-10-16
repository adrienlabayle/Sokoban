#include "MobileEntity.h"

MobileEntity::MobileEntity(Coords coords) : Entity(coords) {}

Coords MobileEntity::getNextCoords(Direction dir) const {
    Coords next = coords;

    switch (dir) {
    case Direction::Left:
        next.c -= 1;
        break;
    case Direction::Right:
        next.c += 1;
        break;
    case Direction::Up:
        next.r -= 1;
        break;
    case Direction::Down:
        next.r += 1;
        break;
    default:
        break;
    }

    return next;
}

void MobileEntity::move(Direction dir) {
    coords = getNextCoords(dir);
}
