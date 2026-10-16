#include "map.h"

Map::Map(int w, int h) :
    height(h), width(w)
{
    cells.assign(height * width, 0);
}

// Member methods

bool Map::moveBox(Coords pos, Coords wantedPos){
    if((wantedPos.r >= 0) && (wantedPos.r < height) && (wantedPos.c >= 0) && (wantedPos.c < width) && (getCells(wantedPos) != 1) && (!isBoxCoords(wantedPos))) // still in the map, not a wall and not a box
    {
        moveBoxCoords(pos, wantedPos);
        return 1;
    }
    return 0;
}

void Map::movePlayer(Direction dir){
    int dr = 0;
    int dc = 0;

    switch (dir){
    case Direction::Left:
        dc--;
        break;
    case Direction::Right:
        dc++;
        break;
    case Direction::Up:
        dr--;
        break;
    case Direction::Down:
        dr++;
        break;
    default:
        break;
    }

    Coords wantedCoords = {playerCoords.r + dr, playerCoords.c + dc};

    if((wantedCoords.c >= 0) && (wantedCoords.c < width) && (wantedCoords.r >= 0) && (wantedCoords.r < height) && (getCells(wantedCoords) != 1)) // still in the map and not a wall
    {
        if(isBoxCoords(wantedCoords)) // is a box
        {
            if (moveBox(wantedCoords, {wantedCoords.r + dr, wantedCoords.c + dc}))
            {
                playerCoords.r += dr;
                playerCoords.c += dc;
            }
        }
        else // then it is either an empty case or a depot
        {
            playerCoords.r += dr;
            playerCoords.c += dc;
        }
        //check if its in the grid, if its free, and if its movable, do recurence
    }
}

// Setter and getter

int Map::getHeight() const{
    return height;
}

int Map::getWidth() const{
    return width;
}

void Map::setCells(Coords coords, int val){
    cells[coords.r * width + coords.c] = val;
}

int Map::getCells(Coords coords) const{
    return cells[coords.r * width + coords.c];
}

int Map::getDisplayCells(Coords coords) const{
    if (isBoxCoords(coords))
        return 3;
    if (coords == playerCoords)
        return 4;
    return getCells(coords);
}

void Map::setPlayerCoords(Coords coords){
    playerCoords = coords;
}

void Map::addBoxCoords(Coords coords){
    boxesCoords.push_back(coords);
}

bool Map::isBoxCoords(Coords coords) const{
    auto it = std::find(boxesCoords.begin(), boxesCoords.end(), coords);

    if (it != boxesCoords.end()) {
        return 1;
    } else {
        return 0;
    }
}

void Map::moveBoxCoords(Coords coords, Coords wantedCoords){
    auto it = std::find(boxesCoords.begin(), boxesCoords.end(), coords);

    if (it != boxesCoords.end()) {
        *it = wantedCoords;
    }
}
