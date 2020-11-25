#include <iostream>
#include <functional>
#include <map>
#include <vector>
//import std.core;

#include "commands.hpp"

#include "rating.hpp"

bool exiting = false;
int main() {
    using namespace std;
    string sInput;
    commands::Game g;
    g.Game::Game();
    map<string, function<void()>> Commands;
    Commands.emplace("end"s , [&g]() {g.end(); });
    Commands.emplace("newGame"s, [&g]() {g.newin(); });
    Commands.emplace("play"s, [&g]() {g.play(); });
    Commands.emplace("exit"s, [&]() {commands::quit(); });
    while(!exiting) {
        cin >> sInput;
        //if (Commands.find(sInput) == Commands.end());
        try {
            Commands.find(sInput) != Commands.end() ? Commands[sInput]():throw Commands;
            //Commands[sInput]();
        }
        catch(map<string, function<void() >> tr) {
            cerr << sInput << " is not a command." << endl;}
    }
    cout << "program exiting" << endl;
    return 0;
}

//void test(){
//    // The test player. Example taken from
//    // http://www.glicko.net/glicko/glicko2.pdf
//    Glicko::Rating player(1500, 200);
//
//    // The three opponents
//    Glicko::Rating player1(1400, 30);
//    Glicko::Rating player2(1550, 100);
//    Glicko::Rating player3(1700, 300);
//
//    // Simulate 3 games and update the ratings
//    Glicko::Rating players[3] = { player1, player2, player3 };
//    double scores[3] = { 1.0, 0.0, 0.0 };
//    player.Update(3, players, scores);
//    player.Apply();
//
//    std::cout << player << std::endl;
//
//}