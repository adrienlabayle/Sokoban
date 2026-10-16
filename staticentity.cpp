#include "staticentity.h"

StaticEntity::StaticEntity(Coords coords) : Entity(coords) {}

bool StaticEntity::isGoal() const {
    return false;
}
