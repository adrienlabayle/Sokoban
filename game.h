#ifndef GAME_H
#define GAME_H

#include <iostream>

#include <vector>

#include "display.h"
#include "Load.h"

class Game
{
public:
    Game(Map&& map);

    void Show(QPainter* p, int width, int height) const;

private:
    Display m_display;
    Map m_map;
};

#endif // GAME_H
