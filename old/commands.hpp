#pragma once
#define xyPos int, int
extern bool exiting;
namespace commands {
	namespace rating {
	void display(std::string);
	void display();
	}
	void help(int page);
	class Game {
	public:
		//TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
		void newin(/*int boardDimesion*/);
		void pass();
		int play(/*int x, int y*/);
		void end();
		Game();
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