#include "display.h"

#include <QDebug>

Display::Display() {

}

void Display::DisplayMap(QPainter* p, int width, int height, const Map& map) const{
    int w = map.getWidth();
    int h = map.getHeight();
    
    int cell_w = width / w;
    int cell_h = height / h;

    QColor gridColor1(20, 30, 45);   // bleu nuit
    QColor gridColor2(30, 45, 65);   // bleu acier
    
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            QBrush currentBruch;
            switch (map.getDisplayCells({i, j}))
            {
            case 0: {
                QColor currentColor = ((i + j) & 1) ? gridColor2 : gridColor1;
                currentBruch.setStyle(Qt::SolidPattern);
                currentBruch.setColor(currentColor);
                break;
            }
            case 1:
                currentBruch.setTexture(wallTexture.scaled(cell_w, cell_h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
                break;
            case 2:
                currentBruch.setTexture(depotTexture.scaled(cell_w, cell_h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
                break;
            case 3:
                currentBruch.setTexture(boxTexture.scaled(cell_w, cell_h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
                break;
            case 4:
                currentBruch.setTexture(playerTexture.scaled(cell_w, cell_h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
                break;
            }

            //p->setPen(QPen(Qt::white, 1));
            p->fillRect(j * cell_w, i * cell_h, cell_w, cell_h, currentBruch);
            //p->drawRect(j * cell_w, i * cell_h, cell_w, cell_h);
        }
}
