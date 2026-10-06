#include "Load.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

int Load::charToCell(char c, std::size_t i, std::size_t j) {
    switch (c) {
        case ' ': return 0;
        default:
            throw std::runtime_error(
                "LoadMap : caractere inconnu '" + std::string(1, c) + "' a la case (" + std::to_string(i) + ", " + std::to_string(j) + ")");
    }
}

Map Load::LoadMap(const std::filesystem::path& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("LoadMap : impossible d'ouvrir " + path.string());
    }

    std::string line;
    if (!std::getline(file, line)) {
        throw std::runtime_error("LoadMap : fichier vide " + path.string());
    }

    std::istringstream header(line);
    int height;
    int width;
    if (!(header >> height >>width) || height <= 0 || width <= 0) {
        throw std::runtime_error("LoadMap : premiere ligne invalide, attendu \"hauteur largeur\"");
    }

    Map map(width, height);

    for (int i = 0; i < map.get_height(); ++i) {
        if (!std::getline(file, line)) {
            throw std::runtime_error("LoadMap : il manque des lignes (attendu " + std::to_string(map.get_height()) + ", lu " + std::to_string(i) + ")");
        }
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if ((int)line.size() != map.get_width()) {
            throw std::runtime_error("LoadMap : ligne " + std::to_string(i) + " pas de bonne longueur (" + std::to_string(line.size()) + " > " + std::to_string(map.get_width()) + ")");
        }
        for (std::size_t j = 0; j < line.size(); ++j) {
            map.set_cells(i, j, charToCell(line[j], i, j));
        }
    }

    return map;
}
