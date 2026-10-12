#include "game.h"

Game::Game(Map&& m) :
    map(std::move(m))
{

}

void Game::Show(QPainter* p, int width, int height) const
{
    display.DisplayMap(p, width, height, map);
}
