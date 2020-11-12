#include <string>

#include "commands.hpp"

#include "rating.hpp"
using namespace std;
namespace commands {
	namespace rating {
		void Display(string player) {
	
		}
		void display() {
	
		} 
	}
	void Game::print() {
		
	}
	void Game::newin(int boardDimension) {
		a2dGame = new int* [boardDimension];
		for (int i = 0; i < boardDimension; i++) {
			a2dGame[i] = new int[boardDimension];
			for (int j = 0; j < boardDimension; j++) {
				a2dGame[i][j] = 0;
			}
		}
	}
	void Game::play(int x, int y) {
		a2dGame[x][y];
	}
	void Game::end() {
		Glicko::Rating player(Glicko::kDefaultR, Glicko::kDefaultRD);

		Glicko::Rating player1(1400, 30);
		Glicko::Rating player2(1550, 100);

		Glicko::Rating players[2] = { player1, player2};
		double scores[2] = { 1.0, 0.0 };
		player.Update(2, players, scores);
		player.Apply();
		cout << player1 << " , " << player2 << endl;
	}
}