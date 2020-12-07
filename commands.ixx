//import std.core;
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <future>
export module commands;
using namespace std;
export {
	namespace commands {
		namespace rating {
			void display(string player);
			void display();
		}
		void help() {
			cout << "Not yet implemented." << endl;
		}
		void help(int page) {
			cout << "Not yet implemented." << endl;
		}
		class Game {
		public:
			//TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
			void newin(/*int boardDimesion*/) {
				cout << "Enter the board size: ";
				cin >> boardSize;
				future<void> makeBoard = async(launch::async, [&]() {
					a2dGame = new int* [boardSize];
					for (int i = 0; i < boardSize; i++) {
						a2dGame[i] = new int[boardSize];
						for (int j = 0; j < boardSize; j++) a2dGame[i][j] = 2;
					}}
				);
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
				makeBoard.get();
			}
			inline void pass() {
				blackTurn = !blackTurn;
				print();//?
			}
			//TODO:
			pair<int, int> play(/*int x, int y*/) {
				int x, y = 0;
				cout << "Position x, y:" << endl;
				cin >> x, y;
				a2dGame[x][y] = blackTurn + 3;
				print();
				a2dGame[x][y] = blackTurn;
				current++;
				blackTurn = !blackTurn;
				//if (doRecord = true) 
					Rec.record(current, blackTurn, x, y);
				return {x, y};
			}
			void end() {
				current = 1;
				blackTurn = true;

				auto [scPlayer1, scplayer2] = score();

				for (int i = 0; i < boardSize; ++i) delete a2dGame[i];
				delete a2dGame;
			}
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
			bool blackTurn;
			int boardSize;
			int** a2dGame;
			int current;
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
				vector<int> turn;
				vector<bool> player;//might be changed later to a string with mySlq
				vector<array<int, 2>> pos;
			}Rec;
		};
	}
}