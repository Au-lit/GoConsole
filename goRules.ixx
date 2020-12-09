#pragma once
#include <array>
#include "commands.ixx"
import go;
export module goRules;

export{
	namespace goRules {
		inline bool playIsValid(int x, int y, go::Game::A2dGame_t& a2dGame) { return a2d[x][y] == 2; }
		inline bool playIsValid(std::array<int, 2> locPos, go::Game::A2dGame_t& a2dGame) { return a2d[locPos[0]][locPos[1]] == 2; }
		inline bool hasLiberty() {
			return false;
		}
	}
}