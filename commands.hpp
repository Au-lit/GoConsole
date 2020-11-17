#pragma once
extern bool exiting;
namespace commands {
	namespace rating {
	void display(std::string);
	void display();
	}
	class Game {
	public:
		//TODO: Pour le bot final changer pour prendre l'argument de fonction immédiatement.
		void newin(/*int boardDimesion*/);
		void play(/*int x, int y*/);
		void end();
		Game();
	private:
		bool blackTurn;
		int boardSize;
		int** a2dGame;
		void print();
	};
	inline void quit() { exiting = true; }
}