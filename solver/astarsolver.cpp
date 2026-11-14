#include "AStarSolver.h"
#include <iostream>

AStarSolver::AStarSolver(const Map& initialMapArg) : initialMap(&initialMapArg) {
    int height = initialMap->getHeight();
    int width = initialMap->getWidth();
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            if (initialMap->getCells({r, c}).getValue() == 2) {
                depots.push_back({r, c});
            }
        }
    }
}

// simple heuristique : sum of the manhattan distance between each box and his closest depot
int AStarSolver::calculateHeuristic(const AStarState& state) const {
    int h = 0;

    // for each box, find the minimal distance towards an available depot
    for (const auto& box : state.boxes) {
        int minDst = 999999;
        for (const auto& depot : depots) {
            int dst = std::abs(box.r - depot.r) + std::abs(box.c - depot.c);
            if (dst < minDst) {
                minDst = dst;
            }
        }
        h += minDst;
    }

    return h;
}

// simulation of a move on a given state; WATCHOUT : we check the cells, box and player positions on the current stat and not the initial map, which can be both different
bool AStarSolver::simulateMove(AStarState& state, Direction dir) const {
    int dr = 0;
    int dc = 0;

    switch (dir) {
    case Direction::Left:  dc--; break;
    case Direction::Right: dc++; break;
    case Direction::Up:    dr--; break;
    case Direction::Down:  dr++; break;
    default: break;
    }

    Coords wantedCoords = state.playerPos + Coords{dr, dc};
    int height = initialMap->getHeight();
    int width = initialMap->getWidth();

    // check if the wanted position is in the map and not a wall
    if (wantedCoords.c >= 0 && wantedCoords.c < width && wantedCoords.r >= 0 && wantedCoords.r < height) {
        if (initialMap->getCells(wantedCoords).getValue() == 1) {
            return false; // Wall
        }

        // chek if there is a box on the wanted pos
        auto it = std::find(state.boxes.begin(), state.boxes.end(), wantedCoords);
        if (it != state.boxes.end()) {
            // there is a box at the wanted coords, so we check behind her if we can move her
            Coords boxWantedCoords = {wantedCoords.r + dr, wantedCoords.c + dc};

            // check if the next cell is valid (in the map and not a wall or an other box)
            if (boxWantedCoords.c >= 0 && boxWantedCoords.c < width && boxWantedCoords.r >= 0 && boxWantedCoords.r < height) {
                if (initialMap->getCells(boxWantedCoords).getValue() != 1) {
                    auto itOtherBox = std::find(state.boxes.begin(), state.boxes.end(), boxWantedCoords);
                    if (itOtherBox == state.boxes.end()) {
                        // the cell at the wanted box coords is in the map, not a wall and not a wall, so we can move both of the player and the box
                        *it = boxWantedCoords;
                        // important: keep the box sorted, so that the operator< of the std::set can work well
                        std::sort(state.boxes.begin(), state.boxes.end());
                        state.playerPos = wantedCoords;
                        return true;
                    }
                }
            }
            return false; // the box cant be push
        } else {
            // empty case or depot, the player simply move in the wanted direction
            state.playerPos = wantedCoords;
            return true;
        }
    }
    return false;
}

// generate the valid neighbors (simulate the move for each direction and stock the given stats)
std::vector<std::pair<AStarState, Direction>> AStarSolver::getNeighbors(const AStarState& state) const {
    std::vector<std::pair<AStarState, Direction>> neighbors;
    Direction directions[] = {Direction::Up, Direction::Down, Direction::Left, Direction::Right};

    for (Direction dir : directions) {
        AStarState newState = state; // copy of the actual state
        if (simulateMove(newState, dir)) {
            neighbors.push_back({newState, dir});
        }
    }

    return neighbors;
}

// main algorithme A*
bool AStarSolver::solve() {
    // 1. build the initial state from the map
    AStarState startState(*initialMap);

    // 2. data structure of the A*; the openList is a heap that pop the best AStarNode, the one with the lowest fCost
    std::priority_queue<AStarNode, std::vector<AStarNode>, std::greater<AStarNode>> openList;
    std::set<AStarState> closedList; // the closedList is a bst(binary search tree) self-balanced by the black-red rotations logics
    // the goal of the closedList is to archive all the state already seen,
    // this way we dont have to modify the AStarNodes in the openList whene needed which is not really possible,
    // instead we just add a new node in the openList and check in the closedList each time if the current state has been already seen

    // 3. put the initial AStarNode in the openList
    int startH = calculateHeuristic(startState);
    openList.push({startState, 0, startH});

    while (!openList.empty()) {
        // get the node with the lowest fCost
        AStarNode currentNode = openList.top();
        openList.pop();

        // win condition : are all the boxes on a depot ?
        if (currentNode.hCost == 0) {
            std::cout << "Solution trouvee en " << currentNode.gCost << " mouvements !" << std::endl;
            return true;
        }

        // if the state has already been checked, we pass
        if (closedList.count(currentNode.state)) {
            continue;
        }
        closedList.insert(currentNode.state);

        // explore the neighbors (4 directions)
        for (auto& [neighborState, moveDir] : getNeighbors(currentNode.state)) {
            if (closedList.count(neighborState)) {
                continue;
            }

            int tentativeGCost = currentNode.gCost + 1;
            int hCost = calculateHeuristic(neighborState);

            openList.push({neighborState, tentativeGCost, hCost});
        }
    }

    std::cout << "Aucune solution trouvee (map insoluble)." << std::endl;
    return false;
}
