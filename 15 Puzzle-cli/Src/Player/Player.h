#pragma once
#include <memory>

class Player
{
private:
	enum MoveDirections
	{
		MOVE_DIRECTION_NONE,
		MOVE_DIRECTION_UP,
		MOVE_DIRECTION_DOWN,
		MOVE_DIRECTION_LEFT,
		MOVE_DIRECTION_RIGHT
	};

	std::shared_ptr<Board> m_board;
	std::shared_ptr<Tile> m_movable_tile;
	std::shared_ptr<Input> m_input;
	Coordinate m_new_movable_tile_coord;
	int m_move_count;

private:
	std::shared_ptr<Tile> get_new_movable_tile();

public:
	Player(std::shared_ptr<Board>& board);

	bool move_movable_tile();
	void update_board();
	int get_move_direction();
	int get_move_count() { return m_move_count; }
	std::shared_ptr<Board> get_board() { if (m_board)return m_board; else return nullptr; }
	std::shared_ptr<Tile> get_movable_tile() { if (m_board->get_movable_tile()) return m_board->get_movable_tile(); else return nullptr; }
};