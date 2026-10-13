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
    QPixmap wallTexture{"C:/Users/masth/IMDS5A/Projet_5A/Sokoban_final/images/wall.png"};
    QPixmap boxTexture{"C:/Users/masth/IMDS5A/Projet_5A/Sokoban_final/images/box.png"};
    QPixmap depotTexture{"C:/Users/masth/IMDS5A/Projet_5A/Sokoban_final/images/depot.png"};
    QPixmap playerTexture{"C:/Users/masth/IMDS5A/Projet_5A/Sokoban_final/images/player.png"};
};

#endif // DISPLAY_H
