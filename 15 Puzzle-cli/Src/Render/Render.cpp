#include <iostream>

#include "../Tile/Tile.h"
#include "../Board/Board.h"
#include "Render.h"

void Render::render_board(std::shared_ptr<Board> &board)
{
	for (int y = 0; y < board->get_board_height(); ++y)
	{
		for (int x = 0; x < board->get_board_width(); ++x)
		{
			for (int i = 0; i < board->get_tiles().size(); ++i)
			{
				std::shared_ptr<Tile> i_tile = board->get_tiles()[i];
				
				if (!i_tile)
					break;

				int i_tile_pos_x = i_tile->get_coord().x;
				int i_tile_pos_y = i_tile->get_coord().y;

				if (x == i_tile_pos_x && y == i_tile_pos_y)
				{
					if (i_tile->get_digit() != 0)
					{
						if (i_tile->get_digit() < 10)
						{
							std::cout << i_tile->get_digit() << "  ";
						}
						else
						{
							std::cout << i_tile->get_digit() << " ";
						}
					}
					else
					{
						std::cout << " " << "  ";
					}
				}
			}
		}
		std::cout << std::endl;
	}
}