#ifndef COORDS_H
#define COORDS_H

struct Coords {
    int r;
    int c;

    bool operator==(const Coords& other) const {
        return r == other.r && c == other.c;
    }
};

enum class Direction {
    Left,
    Right,
    Up,
    Down
};

#endif // COORDS_H
