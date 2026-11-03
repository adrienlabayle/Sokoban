#ifndef MAP_H
#define MAP_H

#include <vector>
#include <algorithm>
#include <memory>

#include "Coords.h"

#include "player.h"
#include "Box.h"
#include "floor.h"
#include "Depot.h"
#include "wall.h"

class Map {

    private:
        int height = 0;
        int width = 0;
        std::vector<std::unique_ptr<StaticEntity>> cells;
        Player player;
        std::vector<Box> boxes;

    public:
        Map(int width = 0, int height = 0);

        bool moveBox(Coords pos, Coords wantedPos);
        void movePlayer(Direction dir);

        int getHeight() const;
        int getWidth() const;

        void setCells(Coords coords, std::unique_ptr<StaticEntity>&& staticEntity);
        const StaticEntity& getCells(Coords coords) const;

        int getDisplayCells(Coords coords) const;

        void setPlayerCoords(Coords coords);

        void addBox(Coords coords);
        bool isBox(Coords coords) const;

        bool winCheck() const;

};

#endif // MAP_H
