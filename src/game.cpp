#include "game.h"

Game::Game(Map&& m) :
    map(std::move(m))
{

}

void Game::show(QPainter* p, int width, int height) const
{
    display.DisplayMap(p, width, height, map);
}

void Game::reset(Map&& m){
    map = std::move(m);
}
