#ifndef DISPLAY_H
#define DISPLAY_H

#include <QPainter>

#include "Map.h"

class Display
{
public:
    Display();

    void DisplayMap(QPainter* p, int width, int height, const Map& map) const;

private:
    QPixmap wallTexture{"E:/ADRIEN_2026/C++/Sokoban/images/wall.png"};
    QPixmap boxTexture{"E:/ADRIEN_2026/C++/Sokoban/images/box.png"};
    QPixmap depotTexture{"E:/ADRIEN_2026/C++/Sokoban/images/depot.png"};
    QPixmap playerTexture{"E:/ADRIEN_2026/C++/Sokoban/images/player.png"};
};

#endif // DISPLAY_H
