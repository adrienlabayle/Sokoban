#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include <vector>

class Map {
private:
    int m_height = 0;
    int m_width = 0;
    std::vector<int> m_cells;

public:
    Map(int width = 0, int height = 0);

    int get_height() const;
    int get_width() const;
    void set_cells(int row, int col, int val);
    int get_cells(int row, int col) const;
};

#endif // MAP_H
