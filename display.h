#ifndef DISPLAY_H
#define DISPLAY_H

#include <QPainter>

#include "Map.h"

class Display
{
public:
    Display();

    void DisplayMap(QPainter* p, int width, int height, const Map& map) const;
};

#endif // DISPLAY_H
