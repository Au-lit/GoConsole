export module commands;
import std.core;

using namespace std;
export {
//bool exiting = false;
namespace commands {
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
				for (int j = 0; j < boardSize; j++) a2dGame[i][j] = 2;
			}
			//cout << "Record game? [Y]es/[N]o" << endl;
			//cin >> internalInput;
			//if ()
			//Recorder.clear();
			blackTurn = false;
		}
		inline void pass() {
			blackTurn = !blackTurn;
			print();//?
		}
		int play(/*int x, int y*/) {
			int x, y = 0;
			cout << "Position x, y" << endl;
			cin >> x, y;
			a2dGame[x][y] = blackTurn + 3;
			print();
			a2dGame[x][y] = blackTurn;
			current++;
			blackTurn = !blackTurn;
			//Recorder.emplace(current, blackTurn, x, y);
			return x, y;//ici uniquement pour embellir
		}
		void end() {
			current = 1;
			blackTurn = true;
			for (int i = 0; i < boardSize; ++i) delete a2dGame[i];
			delete a2dGame;
		}
		int score();
		Game() {
			blackTurn = true;
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
		void print() {
			for (int i = 0; i < boardSize; i++) {
				for (int j = 0; j < boardSize; j++) cout << a2dGame[i][j] << " ";
				cout << endl;
			}
		}
		struct Recorder {
			vector<int> turn;
			vector<bool> player;//might be changed later to a string with mySlq
			vector<array<int, 2>> pos;
		};
		//map<int, bool, xyPos> Recorder;
	};
}
}