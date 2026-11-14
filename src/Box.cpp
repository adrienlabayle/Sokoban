#include "Box.h"

Box::Box(Coords coords, bool alreadyDone) : MobileEntity(coords), done(alreadyDone) {}

bool Box::isDone() const{
    return done;
}

void Box::setDone(const StaticEntity& staticEntity){
    done = (staticEntity.getValue() == 2) ? true : false;
}