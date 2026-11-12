/*
#include "AStarSolver.h"
#include <iostream>

AStarSolver::AStarSolver(const Map& initialMap) : initialMap(initialMap) {}

// simple heuristique : sum of the manhattan distance between each box and his closest depot
int AStarSolver::calculateHeuristic(const AStarState& state) const {
    int h = 0;
    int height = initialMap.getHeight();
    int width = initialMap.getWidth();

    // get all the depots of the initial map
    std::vector<Coords> depots;
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            if (initialMap.getCells({r, c}).getValue() == 2) { // 2 = depot
                depots.push_back({r, c});
            }
        }
    }

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

// Simulation d'un mouvement sur un état donné
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
    int height = initialMap.getHeight();
    int width = initialMap.getWidth();

    // Vérifier les limites et les murs (1 = mur dans ton code)
    if (wantedCoords.c >= 0 && wantedCoords.c < width && wantedCoords.r >= 0 && wantedCoords.r < height) {
        if (initialMap.getCells(wantedCoords).getValue() == 1) {
            return false; // Mur
        }

        // Vérifier si une caisse est sur la case souhaitée
        auto it = std::find(state.boxes.begin(), state.boxes.end(), wantedCoords);
        if (it != state.boxes.end()) {
            // C'est une caisse, on regarde derrière elle
            Coords boxWantedCoords = {wantedCoords.r + dr, wantedCoords.c + dc};

            // Vérifier si la case derrière la caisse est valide (dans la map, pas un mur, pas une autre caisse)
            if (boxWantedCoords.c >= 0 && boxWantedCoords.c < width && boxWantedCoords.r >= 0 && boxWantedCoords.r < height) {
                if (initialMap.getCells(boxWantedCoords).getValue() != 1) {
                    auto itOtherBox = std::find(state.boxes.begin(), state.boxes.end(), boxWantedCoords);
                    if (itOtherBox == state.boxes.end()) {
                        // On peut bouger la caisse et le joueur
                        *it = boxWantedCoords;
                        // Important : garder les caisses triées pour que l'opérateur < du std::set fonctionne bien
                        std::sort(state.boxes.begin(), state.boxes.end());
                        state.playerPos = wantedCoords;
                        return true;
                    }
                }
            }
            return false; // La caisse ne peut pas être poussée
        } else {
            // Case vide ou dépôt, le joueur avance simplement
            state.playerPos = wantedCoords;
            return true;
        }
    }
    return false;
}

// Générer les voisins valides
std::vector<std::pair<AStarState, Direction>> AStarSolver::getNeighbors(const AStarState& state) const {
    std::vector<std::pair<AStarState, Direction>> neighbors;
    Direction directions[] = {Direction::Up, Direction::Down, Direction::Left, Direction::Right};

    for (Direction dir : directions) {
        AStarState newState = state; // Copie de l'état actuel
        if (simulateMove(newState, dir)) {
            neighbors.push_back({newState, dir});
        }
    }

    return neighbors;
}

// Algorithme A* principal
bool AStarSolver::solve() {
    // 1. Construire l'état initial à partir de la Map
    AStarState startState;

    // Récupérer la position du joueur (en supposant que tu as un getter player.getCoords() dans Map)
    startState.playerPos = initialMap.getPlayerCoords(); // Adapte le nom du getter si besoin

    // Récupérer les coordonnées de toutes les caisses
    for (const auto& box : initialMap.getBoxes()) { // Adapte si ton getter s'appelle autrement (ex: getBoxes())
        startState.boxes.push_back(box.getCoords());
    }
    // Très important : trier les caisses pour que la comparaison d'états fonctionne bien
    std::sort(startState.boxes.begin(), startState.boxes.end());

    // 2. Structures de données du A*
    std::priority_queue<AStarNode, std::vector<AStarNode>, std::greater<AStarNode>> openList;
    std::set<AStarState> closedList;

    // 3. Mettre l'état initial dans l'Open List
    int startH = calculateHeuristic(startState);
    openList.push({startState, 0, startH});

    while (!openList.empty()) {
        // Récupérer le nœud avec le plus petit fCost
        AStarNode currentNode = openList.top();
        openList.pop();

        // Condition de victoire : est-ce que toutes les caisses sont sur un dépôt ?
        // (Tu peux créer une petite fonction winCheck adaptée à l'état, ou utiliser la logique existante)
        if (calculateHeuristic(currentNode.state) == 0) {
            std::cout << "Solution trouvee en " << currentNode.gCost << " mouvements !" << std::endl;
            return true;
        }

        // Si l'état a déjà été visité, on l'ignore
        if (closedList.count(currentNode.state)) {
            continue;
        }
        closedList.insert(currentNode.state);

        // Explorer les voisins (les 4 directions)
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
*/