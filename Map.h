#ifndef MAP_H
#define MAP_H

#include <vector>
#include <algorithm>

struct Coords {
    int r;
    int c;

    bool operator==(const Coords& other) const {
        return r == other.r && c == other.c;
    }
};

enum class Direction{
    Left,
    Right,
    Up,
    Down
};

class Map {
private:
    int height = 0;
    int width = 0;
    std::vector<int> cells;
    Coords playerCoords;
    std::vector<Coords> boxesCoords;

public:
    Map(int width = 0, int height = 0);
    bool moveBox(Coords pos, Coords wantedPos);
    void movePlayer(Direction dir);

    int getHeight() const;
    int getWidth() const;
    void setCells(Coords coords, int val);
    int getCells(Coords coords) const;
    int getDisplayCells(Coords coords) const;
    void setPlayerCoords(Coords coords);
    void addBoxCoords(Coords coords);
    bool isBoxCoords(Coords coords) const;
    void moveBoxCoords(Coords coords, Coords wantedCoords);
};

#endif // MAP_H
