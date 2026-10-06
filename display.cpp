#include "display.h"

Display::Display() {

}

void Display::DisplayMap(QPainter* p, int width, int height, const Map& map) const{
    int w = map.get_width();
    int h = map.get_height();
    
    int cell_w = width / w;
    int cell_h = height / h;

    QColor gridColor1(20, 30, 45);   // bleu nuit
    QColor gridColor2(30, 45, 65);   // bleu acier
    
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            switch (map.get_cells(i, j)) {
            case 0: {
                // Si (i + j) est pair -> couleur 1, sinon -> couleur 2
                QColor currentColor = ((i + j) & 1) ? gridColor2 : gridColor1;

                p->setPen(QPen(currentColor, 1));
                p->fillRect(j * cell_w, i * cell_h, cell_w, cell_h, QBrush(currentColor));
                p->drawRect(j * cell_w, i * cell_h, cell_w, cell_h);
                break;
            }
            default:
                break;
            }
        }
}
