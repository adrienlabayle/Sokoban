#ifndef ASTARSTATE_H
#define ASTARSTATE_H

#pragma once

#include <vector>
#include "coords.h"

struct AStarState {
    Coords playerPos;
    std::vector<Coords> boxes;

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
