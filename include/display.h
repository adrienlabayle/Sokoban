#ifndef DISPLAY_H
#define DISPLAY_H

#include <QPainter>

#include "Map.h"

class Display {

    private:
        QPixmap wallTexture{":/images/images/wall.png"};
        QPixmap boxTexture{":/images/images/box.png"};
        QPixmap depotTexture{":/images/images/depot.png"};
        QPixmap playerTexture{":/images/images/player.png"};
        QPixmap boxDoneTexture{":/images/images/boxDone.png"};

    public:
        Display();
        void DisplayMap(QPainter* p, int width, int height, const Map& map) const;

};

#endif // DISPLAY_H
