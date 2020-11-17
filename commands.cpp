#include <iostream>
#include <array>

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
	Game::Game() {
		bool blackTurn = false;
		int boardSize = 0;
		int** a2dGame = 0;
	}
	void Game::print() {
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				cout << a2dGame[i][j]<< " ";
			}
			cout << endl;
		}
	}
	//TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
	void Game::newin() {
		cout << "Enter the board size." << endl;
		cin >> boardSize;
		//boardSize = boardDimension;
		a2dGame = new int* [boardSize];
		for (int i = 0; i < boardSize; i++) {
			a2dGame[i] = new int[boardSize];
			for (int j = 0; j < boardSize; j++) {
				a2dGame[i][j] = 2;
			}
		}

	}
	//TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
	void Game::play(/*int x, int y*/) {
		int x;
		int y;
		cout << "Position x" << endl;
		cin >> x;
		cout << "Position y" << endl;
		cin >> y;
		a2dGame[x][y]= blackTurn;
		print();
	}
	void Game::end() {
		Glicko::Rating player(Glicko::kDefaultR, Glicko::kDefaultRD);
		cout << player << endl;
		Glicko::Rating player1(1400, 30);
		Glicko::Rating player2(1550, 100);

		Glicko::Rating players[2] = { player1, player2};
		double scores[2] = { 1.0, 0.0 };
		player.Update(2, players, scores);
		player.Apply();
		cout << player << endl;
		cout << player1 << " , " << player2 << endl;
	}
}