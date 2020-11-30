//#pragma once
//#include <string>
//#include "rating.hpp"
////import std.core;
//#include <iostream>
//#include <vector>
//#include <map>
//import std.core;
//export module commandsOld;
//#define xyPos int, int
//extern bool exiting;
//export namespace commands {
//	namespace rating {
//	void display(std::string player);
//	void display();
//	}
//	void help(int page);
//	class Game {
//	public:
//		//TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
//		void newin(/*int boardDimesion*/);
//		void pass();
//		int play(/*int x, int y*/);
//		void end();
//		int score();
//		Game();
//	private:
//		//string internalInput;
//		bool blackTurn;
//		int boardSize;
//		int** a2dGame;
//		int current;
//		void print();
//		//map<int, bool, xyPos> Recorder;
//	};
//	inline void quit() { exiting = true; }
//}
//
//
//
//
//using namespace std;
//using namespace commands;
//void rating::display(string player) {}
//void rating::display() {}
//void help(int page) {}
//Game::Game() {
//	blackTurn = false;
//	boardSize = 0;
//	current = 1;
//	a2dGame = nullptr;
//	//Recorder;
//}
//void Game::print() {
//	for (int i = 0; i < boardSize; i++) {
//		for (int j = 0; j < boardSize; j++) {
//			cout << a2dGame[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
////TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
//void Game::newin() {//boardSize = boardDimension;
//	cout << "Enter the board size." << endl;
//	cin >> boardSize;
//	a2dGame = new int* [boardSize];
//	for (int i = 0; i < boardSize; i++) {
//		a2dGame[i] = new int[boardSize];
//		for (int j = 0; j < boardSize; j++) {
//			a2dGame[i][j] = 2;
//		}
//	}
//	//cout << "Record game? [Y]es/[N]o" << endl;
//	//cin >> internalInput;
//	//if ()
//	//Recorder.clear();
//	blackTurn = true;
//	cout << "Game created" << endl;
//}
//void Game::pass() {
//	blackTurn = !blackTurn;
//	print();//?
//}
////TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
//int Game::play(/*int x, int y*/) {
//	int x, y;
//	cout << "Position x y" << endl;
//	cin >> x >> y;
//	//cout << "Position y" << endl;
//	//cin >> y;
//	a2dGame[x][y] = blackTurn + 3;
//	print();
//	a2dGame[x][y] = blackTurn;
//	blackTurn = !blackTurn;
//	++current;
//	//Recorder.emplace(current, blackTurn, x, y);
//	return x, y;//ici uniquement pour embellir
//}
//void Game::end() {
//	Glicko::Rating player(Glicko::kDefaultR, Glicko::kDefaultRD);
//	cout << player << endl;
//	Glicko::Rating player1(1400, 30);
//	Glicko::Rating player2(1550, 100);
//
//	Glicko::Rating players[2] = { player1, player2 };
//	double scores[2] = { 1.0, 0.0 };
//	player.Update(2, players, scores);
//	player.Apply();
//	cout << player << endl;
//	cout << player1 << " , " << player2 << endl;
//}
//int Game::score() {
//	int scoreWhite = 0;
//	int scoreBlack = 0;
//	return scoreBlack, scoreWhite;
//}