//import std.core;
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <future>
#include <variant>

#include "Glicko2/rating.hpp"
//#include <mysqlx/xdevapi.h>

//#include "goRules.hpp"

//import goRules;
export module go;

using namespace std;
export {
	namespace go {
		namespace rating {
			void display(string player);
			void display();
		}
		void help() { cout << "Not yet implemented." << endl; }
		void help(int page) { cout << "Not yet implemented." << endl; }
		//Classe (abstraite) de remplacement pour la méthode Game::score() ect.
		class Ruleset {
		public:
			virtual pair<double, double> score(int** array2d) {
				double komi;
				double scoreW, scoreB;
				return { scoreW, scoreB };
			}
		};
		class Japanese : public Ruleset {
		public:
			pair<double, double> score(int** array2d) {
				double komi = 6.5;
				double scoreW = 0.0, scoreB = 0.0;
				return { scoreW, scoreB };
			}
		};
		class Game {
		public:
			using BoardState_t = enum { white, black, empty };
			template<size_t size> using Array2d = array<array<BoardState_t, size>, size>;
			using A2dGame_t = variant<Array2d<19>, Array2d<13>, Array2d<9>>;
			template<size_t size = 25> void createBoard(size_t boardSize, A2dGame_t& a2dGame) {
				if (size != boardSize) {
					if constexpr (size == 0) throw;
					else return createBoard<size - 1>(boardSize, a2dGame);
				}
				a2dGame = Array2d<size>{};
				//a2dGame = new int* [boardSize];
				for (int i = 0; i < boardSize; i++) {
				//	a2dGame[i] = new int[boardSize];
					for (int j = 0; j < boardSize; j++) a2dGame[i][j] = 2;
				}
			}

			//TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement. (?)
			void newin(/*int boardDimesion*/) {
				cout << "Enter the board size (9, 13, 19): ";
				cin >> boardSize;
				//future<void> makeBoard = async(launch::async, [&]() {});
				createBoard(boardSize, a2dGame);
				//array<array<boardState, boardSize>>;
				{
					char input;
					//cout << "Record? ([Y]es; [N]o)" << endl;
					//cin >> input;
					//input = 'Y' ? doRecord = true : doRecord = false;
					cout << "Score evaluation technique:" << endl;
					cin >> input;
				}
				blackTurn = true;
				cout << "Complete." << endl;
				//makeBoard.get();
			}
			inline void pass() {
				++current;
				blackTurn = !blackTurn;
				print();//?
			}
			//TODO:
			pair<int, int> play(/*int x, int y*/) {
				size_t x, y = 0;
				cout << "Position x, y:" << endl;
				cin >> x, y;
				//goRules::playIsValid(x,y,a2dGame);//if true do the rest of the stuff otherwise return "Not allowed"
				a2dGame[x][y] = blackTurn + 3;
				print();
				a2dGame[x][y] = blackTurn;
				current++;
				blackTurn = !blackTurn;
				//if (doRecord = true) 
					rec.record(current, blackTurn, x, y);
				return {x, y};
			}
			void end() {
				//TODO: Change to the func cited line 20.
				auto [scPlayer1, scplayer2] = score();

				Glicko::Rating player;
				Glicko::Rating player1(1400, 30);
				Glicko::Rating player2(1550, 100);
				Glicko::Rating players[2] = { player1, player2 };
				double scores[2] = { 1.0, 0.0 };
				player.Update(2, players, scores);
				player.Apply();

				rec.saveGame("Player 1", "Player 2");//Voir précédent "TODO:"
				current = 1;
				blackTurn = true;
			}
			//À remplacer par une classe abstraite citée ligne 20.
			pair<int,int> score() {
				int scPlayer1 = 0, scplayer2 = 0;
				return {scPlayer1, scplayer2};
			}
			Game() {
				blackTurn = true;
				boardSize = 0;
				current = 1;
			}
		private:
			variant<Array2d<19>, Array2d<13>, Array2d<9>> a2dGame;
			bool blackTurn;
			int boardSize;
			//int** a2dGame;
			int current;
			int capturedW, capturedB;
			//bool doRecord;
			//Prints the game.
			void print() {
				for (int i = 0; i < boardSize; i++) {
					for (int j = 0; j < boardSize; j++) cout << a2dGame[i][j] << " ";
					cout << endl;
				}
			}
			struct Recorder {
				inline bool record(int locTurn, bool whTurn, int x, int y) {
					array<int, 2> locToArray = { x,y };
					turn.push_back(locTurn), player.push_back(whTurn), pos.push_back(locToArray);
					return true;
				}
				inline bool record(int locTurn, bool whTurn, array<int, 2> locPos) {
					turn.push_back(locTurn), player.push_back(whTurn), pos.push_back(locPos);
					return true;
				}
				//To mySql.
				bool saveGame(string player1, string player2) {
					return true;
				}
				vector<int> turn;
				vector<bool> player;//might be changed later to a string with mySlq EDIT:bad idea
				vector<array<int, 2>> pos;
			}rec;
		};
	}
}