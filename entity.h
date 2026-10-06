#ifndef ENTITY_H
#define ENTITY_H

enum class Direction {
    Left,
    Right,
    Up,
    Down
};

class Entity
{
public:
    Entity(int pos_x, int pos_y);

    void Move(Direction);

private:
    int PosX = 0;
    int PosY = 0;
};

#endif // ENTITY_H
