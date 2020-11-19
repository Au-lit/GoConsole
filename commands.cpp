#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>

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
		blackTurn = false;
		boardSize = 0;
		a2dGame = 0;
		current = 0;
		Recorder;
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
	void Game::newin() {//boardSize = boardDimension;
		cout << "Enter the board size." << endl;
		cin >> boardSize;
		boardSize++;
		a2dGame = new int* [boardSize];
		for (int i = 0; i < boardSize; i++) {
			a2dGame[i] = new int[boardSize];
			for (int j = 0; j < boardSize; j++) {
				a2dGame[i][j] = 2;
			}
		}
		//cout << "Record game? [Y]es/[N]o" << endl;
		//cin >> internalInput;
		Recorder.clear();
	}
	void Game::pass() {
		blackTurn = !blackTurn;
		print();//?
	}
	//TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
	void Game::play(/*int x, int y*/) {
		int x;
		int y;
		cout << "Position x" << endl;
		cin >> x;
		cout << "Position y" << endl;
		cin >> y;
		a2dGame[x][y] = blackTurn + 2;
		print();
		a2dGame[x][y] = blackTurn;
		current++;
		Recorder.emplace(current, blackTurn, x, y);
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