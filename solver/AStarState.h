#ifndef ASTARSTATE_H
#define ASTARSTATE_H

#pragma once

#include <vector>

#include "coords.h"
#include "Map.h"

struct AStarState {
    Coords playerPos;
    std::vector<Coords> boxes;

    AStarState(const Map& map) {
        playerPos = map.getPlayerCoords();
        for (const auto& box : map.getBoxes()) {
            boxes.push_back(box.getCoords());
        }
        std::sort(boxes.begin(), boxes.end()); // always sort the boxes !
    }

    // operateur de comparaison indispensable pour stocker les états
    // dans un std::set (la "Closed List" de A*)
    bool operator<(const AStarState& other) const {
        if (!(playerPos == other.playerPos)) {
            return playerPos < other.playerPos;
        }
        return boxes < other.boxes;
    }

    bool operator==(const AStarState& other) const {
        return playerPos == other.playerPos && boxes == other.boxes;
    }
};

#endif // ASTARSTATE_H
