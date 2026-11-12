#include "map.h"

Map::Map(int w, int h) :
    height(h), width(w), cells(w * h)
{

}

// Member methods

bool Map::moveBox(Coords coords, Coords wantedCoords){
    // We check again if this is effectivly a box
    auto it = std::find_if(boxes.begin(), boxes.end(), [&coords](const MobileEntity& box) {
        return box.getCoords() == coords;
    });

    if (it != boxes.end()) {
        if((wantedCoords.r >= 0) && (wantedCoords.r < height) && (wantedCoords.c >= 0) && (wantedCoords.c < width) && (getCells(wantedCoords).getValue() != 1) && (!isBox(wantedCoords)))
        {   // still in the map, not a wall and not a box
            it->setCoords(wantedCoords);
            it->setDone(getCells(wantedCoords));
            return 1;
        }
        return 0;
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

    Coords wantedCoords = player.getCoords() + Coords{dr, dc};

    if((wantedCoords.c >= 0) && (wantedCoords.c < width) && (wantedCoords.r >= 0) && (wantedCoords.r < height) && (getCells(wantedCoords).getValue() != 1)) // still in the map and not a wall
    {
        if(isBox(wantedCoords)) // is a box
        {
            if (moveBox(wantedCoords, {wantedCoords.r + dr, wantedCoords.c + dc}))
            {   // we have moved successfully the box next to him, so we can move the player
                player.setCoords(wantedCoords);
            }
        }
        else // then it is either an empty case or a depot
        {
            player.setCoords(wantedCoords);
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

void Map::setCells(Coords coords, std::unique_ptr<StaticEntity>&& staticEntity){
    cells[coords.r * width + coords.c] = std::move(staticEntity);
}

const StaticEntity& Map::getCells(Coords coords) const{
    return *cells[coords.r * width + coords.c];
}

int Map::getDisplayCells(Coords coords) const{
    if (isBox(coords)){
        if (getCells(coords).getValue() == 2)
            return 5; // we want to display a box that is done

        return 3; // we want to display a box
    }
    if (coords == player.getCoords())
        return 4; // we want to display the player
    return getCells(coords).getValue();
}

void Map::setPlayerCoords(Coords coords){
    player.setCoords(coords);
}

void Map::addBox(Coords coords){
    boxes.emplace_back(coords);
}

void Map::addDoneBox(Coords coords){
    boxes.emplace_back(coords, true);
}

bool Map::isBox(Coords coords) const{
    // std::find_if cherche un élément qui valide la condition de la fonction lambda
    auto it = std::find_if(boxes.begin(), boxes.end(), [&coords](const MobileEntity& box) {
        return box.getCoords() == coords;
    });

    // Si l'itérateur n'a pas atteint la fin, c'est qu'une caisse a été trouvée
    return it != boxes.end();
}

bool Map::winCheck() const{
    /*
    int depotCount = 0;
    int donedBoxCount = 0;

    for (int r = 0; r < height; r++)
        for (int c = 0; c < width; c++)
        {
            if (cells[r * width + c]->getValue() == 2){
                depotCount++;
                if (isBox({r, c}))
                    donedBoxCount++;
            }
        }
    if (depotCount == donedBoxCount)
        return 1;

    return 0;
    */

    for(const auto& box : boxes){
        if (!box.isDone())
            return false;
    }
    return true;
}
