#include <string>
#include <stdexcept>

#include "../Input/Input.h"
#include "../Tile/Tile.h"
#include "../Board/Board.h"
#include "Player.h"

Player::Player(std::shared_ptr<Board>& board)
	: m_board{ board }, m_movable_tile{ board->get_movable_tile() }, m_input{ new Input }
{
	if (!m_board)
		throw std::invalid_argument("m_board was nullptr");
	else if (!m_movable_tile)
		throw std::invalid_argument("m_movable_tile was nullptr");
	else if (!m_input)
		throw std::invalid_argument("m_input was nullptr");

	m_move_count = 0;
	m_new_movable_tile_coord = m_movable_tile->get_coord();
}

int Player::get_move_direction()
{
	int move_direction = MOVE_DIRECTION_NONE;
	char player_input = m_input->get_input();

	switch (player_input)
	{
	case 'w':
		move_direction = MOVE_DIRECTION_UP;
		break;
	case 's':
		move_direction = MOVE_DIRECTION_DOWN;
		break;
	case 'a':
		move_direction = MOVE_DIRECTION_LEFT;
		break;
	case 'd':
		move_direction = MOVE_DIRECTION_RIGHT;
		break;
	default:
		break;
	}

	return move_direction;
}

bool Player::move_movable_tile()
{
	int move_direction = get_move_direction();

	if (move_direction == MOVE_DIRECTION_UP)
	{
		if (m_new_movable_tile_coord.y - 1 >= 0)
		{
			m_new_movable_tile_coord.y -= 1;
			return true;
		}
	}
	else if (move_direction == MOVE_DIRECTION_DOWN)
	{
		if (m_new_movable_tile_coord.y + 1 < m_board->get_board_height())
		{
			m_new_movable_tile_coord.y += 1;
			return true;
		}
	}
	else if (move_direction == MOVE_DIRECTION_LEFT)
	{
		if (m_new_movable_tile_coord.x - 1 >= 0)
		{
			m_new_movable_tile_coord.x -= 1;
			return true;
		}
	}
	else if (move_direction == MOVE_DIRECTION_RIGHT)
	{
		if (m_new_movable_tile_coord.x + 1 < m_board->get_board_width())
		{
			m_new_movable_tile_coord.x += 1;
			return true;
		}
	}

	return false;
}

std::shared_ptr<Tile> Player::get_new_movable_tile()
{
	// Finds new tile for the movable tile after it its position has changed
	int i_new = m_board->find_tile_index(m_new_movable_tile_coord);

	if (!m_board || i_new == Board::INDEX_ERROR_TILE_NOT_FOUND || !m_board->get_tiles()[i_new])
		return nullptr;

	return m_board->get_tiles()[i_new];
}

void Player::update_board()
{
	std::shared_ptr<Tile> new_movable_tile = get_new_movable_tile();
	std::shared_ptr<Tile> old_movable_tile = m_board->get_movable_tile();

	if (!(new_movable_tile || old_movable_tile))
		return;

	// Sets new movable tile ptr to point to the tile in new movable tile's position
	m_board->set_movable_tile(new_movable_tile);

	// Swaps digits of old movable tile and new movable tile
	std::swap(old_movable_tile->get_digit_ref(), new_movable_tile->get_digit_ref());

	// This keeps track of how many moves in total were made
	++m_move_count;
}