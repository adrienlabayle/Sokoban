#ifndef COORDS_H
#define COORDS_H

struct Coords {
    int r;
    int c;

    // Nécessaire pour pouvoir utiliser Coords dans une std::map ou std::set
    bool operator<(const Coords& other) const {
        if (c != other.c) return c < other.c;
        return r < other.r;
    }

    bool operator==(const Coords& other) const {
        return r == other.r && c == other.c;
    }

    Coords operator+(const Coords& other) const {
        return {r + other.r, c + other.c};
    }
};

enum class Direction {
    Left,
    Right,
    Up,
    Down
};

#endif // COORDS_H
