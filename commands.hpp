#pragma once
namespace commands {
	namespace rating {
	void display(std::string);
	void display();
	}
	class Game {
	public:
		void newin(int boardDimesion);
		void play(int x, int y);
		void end();
	private:
		bool blackTurn;
		int boardSize = 0;
		int** a2dGame;
		void print();
	};
}