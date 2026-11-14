#include "Load.h"

#include <QFile>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

std::unique_ptr<StaticEntity> Load::charToCell(char c, Coords coords, Map& map) {
    switch (c) {
        case ' ': return std::make_unique<Floor>(coords);
        case 'P': // we have to keep the information of what is under the player
            map.setPlayerCoords(coords);
            return std::make_unique<Floor>(coords);
        case 'x': return std::make_unique<Wall>(coords);
        case '-': return std::make_unique<Depot>(coords);
        case '+':
            map.addBox(coords);
            return std::make_unique<Floor>(coords);
        case '=':
            map.addDoneBox(coords);
            return std::make_unique<Depot>(coords);
        default:
            throw std::runtime_error("LoadMap : caractere inconnu '" + std::string(1, c) + "' a la case (" + std::to_string(coords.r) + ", " + std::to_string(coords.c) + ")");
    }
}

Map Load::loadMap(const std::filesystem::path& path) {
    QFile qfile(QString::fromStdString(path.string()));
    if (!qfile.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("LoadMap : impossible d'ouvrir " + path.string());
    }
    std::istringstream file(qfile.readAll().toStdString());

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

    for (int i = 0; i < map.getHeight(); ++i) {
        if (!std::getline(file, line)) {
            throw std::runtime_error("LoadMap : il manque des lignes (attendu " + std::to_string(map.getHeight()) + ", lu " + std::to_string(i) + ")");
        }
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if ((int)line.size() != map.getWidth()) {
            throw std::runtime_error("LoadMap : ligne " + std::to_string(i) + " pas de bonne longueur (" + std::to_string(line.size()) + " > " + std::to_string(map.getWidth()) + ")");
        }
        for (int j = 0; j < (int)line.size(); ++j) {
            map.setCells({i, j}, charToCell(line[j], {i, j}, map));
        }
    }

    return map;
}
