#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>

#include "../Tile/Tile.h"
#include "../Board/Board.h"
#include "../Input/Input.h"
#include "../Render/Render.h"
#include "../Player/Player.h"
#include "Game.h"

Game::Game(std::shared_ptr<Player>& player) : m_player{ player }, m_render{ std::make_shared<Render>() }
{
	if (!m_player)
		throw std::invalid_argument("m_player was nullptr");
	else if (!m_render)
		throw std::invalid_argument("m_render was nullptr");
	else if (!m_player->get_board())
		throw std::invalid_argument("m_player->get_board() was nullptr");

	m_board = m_player->get_board();
	m_render->render_board(m_board);
}

void Game::update()
{
	while (!m_player->move_movable_tile())
		; // Null statement, does nothing

	// When we got out input, board will be updated and then rendered
	m_player->update_board();
}

void Game::render()
{
	// NOTE: cls works only on windows
	system("cls");
	m_render->render_board(m_board);
}

bool Game::victory_check()
{
	std::vector<std::shared_ptr<Tile>> board_tiles = m_player->get_board()->get_tiles();

	// Iterates though the vector and checks if all of the tile digits are in order
	// NOTE: size - 1 because we dont want to check our movable tile
	for (int i = 0; i < board_tiles.size() - 1; ++i)
	{
		if (!board_tiles[i])
			break;

		if (board_tiles[i]->get_digit() != i + 1)
			return false;
	}

	return true;
}