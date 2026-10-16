#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include "display.h"
#include "Load.h"

class Game {

    private:
        Display display;

    public:
        Game(Map&& m);
        void Show(QPainter* p, int width, int height) const;
        Map map;

};

#endif // GAME_H
