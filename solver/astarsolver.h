#ifndef ASTARSOLVER_H
#define ASTARSOLVER_H

#pragma once

#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include "AStarState.h"

// Structure pour un nœud de l'arbre de recherche A*
struct AStarNode {
    AStarState state;
    int gCost; // Coût réel depuis le départ (nombre de mouvements)
    int hCost; // Estimation heuristique jusqu'au but
    int fCost() const { return gCost + hCost; }

    // Pour trier la priority_queue (on veut le plus petit fCost en premier)
    bool operator>(const AStarNode& other) const {
        return fCost() > other.fCost();
    }
};

class AStarSolver {
public:
    AStarSolver(const Map& initialMap);

    // Lance la résolution. Renvoie une liste de directions (ou mouvements) pour réussir la map.
    // Pour l'instant, on retourne un booléen pour savoir si une solution existe.
    bool solve();

private:
    const Map* initialMap;

    // Calcule l'heuristique (Distance de Manhattan pour commencer)
    int calculateHeuristic(const AStarState& state) const;

    // Génère tous les états valides atteignables en 1 coup depuis l'état actuel
    std::vector<std::pair<AStarState, Direction>> getNeighbors(const AStarState& state) const;

    // Petite fonction utilitaire pour simuler un mouvement de joueur/caisse sur un état donné
    bool simulateMove(AStarState& state, Direction dir) const;
};

#endif // ASTARSOLVER_H
