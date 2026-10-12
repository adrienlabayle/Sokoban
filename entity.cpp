#include "entity.h"

Entity::Entity(int pos_x, int pos_y) :
    PosX(pos_x), PosY(pos_y)
{

}

void Entity::Move(Direction dir, Map& map){
    switch (dir)
    {
    case Direction::Left:

        break;
    case Direction::Right:
        break;
    case Direction::Up:
        break;
    case Direction::Down:
        break;
    default:
        break;
    }
}
