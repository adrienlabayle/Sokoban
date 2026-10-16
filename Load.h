#ifndef LOAD_H
#define LOAD_H

#include <filesystem>
#include "Map.h"

class Load {

    private:
        static int charToCell(char c, Coords coords, Map& map);

    public:
        static Map LoadMap(const std::filesystem::path& path);

};

#endif // LOAD_H
