#include <iostream>
#include <map>
#include <string>

#include "commands.hpp"

#include "rating.hpp"
using namespace std;
int main() {	
    commands::Game g;
	g.newin(19);
	g.play(1, 1);
    g.end();
	map<string, void*>Commands;
	string sInput;
	Commands[sInput];
	/*cout << a2dGame[][] << endl;*/
	cin.get();
}

void test(){
    // The test player. Example taken from
    // http://www.glicko.net/glicko/glicko2.pdf
    Glicko::Rating player(1500, 200);

    // The three opponents
    Glicko::Rating player1(1400, 30);
    Glicko::Rating player2(1550, 100);
    Glicko::Rating player3(1700, 300);

    // Simulate 3 games and update the ratings
    Glicko::Rating players[3] = { player1, player2, player3 };
    double scores[3] = { 1.0, 0.0, 0.0 };
    player.Update(3, players, scores);
    player.Apply();

    std::cout << player << std::endl;

}