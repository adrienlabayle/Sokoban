#ifndef LOAD_H
#define LOAD_H

#include <filesystem>
#include "Map.h"

class Load {
public:
    static Map LoadMap(const std::filesystem::path& path);

private:
    static int charToCell(char c, std::size_t i, std::size_t j);
};

#endif // LOAD_H
