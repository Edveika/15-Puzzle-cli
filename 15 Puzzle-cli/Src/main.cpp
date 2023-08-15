#include <iostream>
#include <memory>

#include "Tile/Tile.h"
#include "Board/Board.h"
#include "Input/Input.h"
#include "Render/Render.h"
#include "Game/Game.h"
#include "Player/Player.h"
#include "Timer/Timer.h"

#define OBJECT_CREATION_FAILED 1

int main()
{
    srand(time(NULL));

    std::shared_ptr<Board> board = std::make_shared<Board>();
    if (!board)
        return OBJECT_CREATION_FAILED;

    std::shared_ptr<Player> player = std::make_shared<Player>(board);
    if (!player)
        return OBJECT_CREATION_FAILED;

    std::shared_ptr<Game> game = std::make_shared<Game>(player);
    if (!game)
        return OBJECT_CREATION_FAILED;
    
    std::shared_ptr<Timer> timer = std::make_shared<Timer>();
    if (!timer)
        return OBJECT_CREATION_FAILED;

    while (!game->victory_check())
    {
        game->update();
        game->render();
    }

    timer->stop();

    std::cout << "You win!!!" <<std::endl;
    std::cout << "Moves: " << player->get_move_count() << std::endl;
    std::cout << "Time spent: " << timer->get_time_elapsed() << " seconds" << std::endl;

    return 0;
}