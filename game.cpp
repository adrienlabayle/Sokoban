#include "game.h"

Game::Game(Map&& map) :
    m_map(std::move(map))
{

}

void Game::Show(QPainter* p, int width, int height) const
{
    m_display.DisplayMap(p, width, height, m_map);
}
