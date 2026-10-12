#ifndef LOAD_H
#define LOAD_H

#include <filesystem>
#include "Map.h"

class Load {
public:
    static Map LoadMap(const std::filesystem::path& path);

private:
    static int charToCell(char c, Coords coords, Map& map);
};

#endif // LOAD_H
