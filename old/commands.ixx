import std.core;
export module commands;

extern bool exiting;
using namespace std;
export namespace commands {
	namespace rating {
		void display(string player);
		void display();
	}
	void help(int page);
	class Game {
	public:
		//TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
		void newin(/*int boardDimesion*/) {//boardSize = boardDimension;
			cout << "Enter the board size." << endl;
			cin >> boardSize;
			a2dGame = new int* [boardSize];
			for (int i = 0; i < boardSize; i++) {
				a2dGame[i] = new int[boardSize];
				for (int j = 0; j < boardSize; j++) {
					a2dGame[i][j] = 2;
				}
			}
			//cout << "Record game? [Y]es/[N]o" << endl;
			//cin >> internalInput;
			//if ()
			//Recorder.clear();
			blackTurn = false;
		}
		void pass();
		int play(/*int x, int y*/);
		void end();
		int score();
		Game() {
			blackTurn = false;
			boardSize = 0;
			current = 1;
			//Recorder;
		}
	private:
		//string internalInput;
		bool blackTurn;
		int boardSize;
		int** a2dGame;
		int current;
		void print();
		//map<int, bool, xyPos> Recorder;
	};
	inline void quit() { exiting = true; }
}