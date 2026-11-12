#ifndef LOAD_H
#define LOAD_H

#include <filesystem>
#include "Map.h"

class Load {

    private:
        static std::unique_ptr<StaticEntity> charToCell(char c, Coords coords, Map& map);

    public:
        static Map loadMap(const std::filesystem::path& path);

};

#endif // LOAD_H
