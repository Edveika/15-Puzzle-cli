#pragma once
#include <memory>

#include "../Player/Player.h"

class Game
{
private:
    std::shared_ptr<Render> m_render;
    std::shared_ptr<Player> m_player;
    std::shared_ptr<Board> m_board;
    
public:
    Game(std::shared_ptr<Player> &player);

    void update();
    void render();
    bool victory_check();
};