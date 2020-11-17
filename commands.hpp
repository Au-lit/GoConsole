#pragma once
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
	private:
		bool blackTurn;
		int boardSize = 0;
		int** a2dGame;
		void print();
	};
}