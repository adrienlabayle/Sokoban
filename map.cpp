#include "map.h"

Map::Map(int width, int height) :
    m_width(width), m_height(height)
{
    m_cells.assign(m_height * m_width, 0);
}

int Map::get_height() const{
    return m_height;
}

int Map::get_width() const{
    return m_width;
}

void Map::set_cells(int row, int col, int val){
    m_cells[row * m_width + col] = val;
}

int Map::get_cells(int row, int col) const{
    return m_cells[row * m_width + col];
}
