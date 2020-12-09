//import std.core;
#include <map>
#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <array>

//#include "\include\sleepy_discord\sleepy_discord.h"
//#include "C:/Program Files/MySQL/MySQL Connector C++ 8.0/include/mysqlx/xdevapi.h"

import go;

int main() {
    using namespace std;
    bool exiting = false;
    string sInput;
    go::Game g;
    map<string, function<void()>> Commands;
    Commands.emplace("end"s, [&g]() {g.end(); });
    Commands.emplace("newGame"s, [&g]() {g.newin(); });
    Commands.emplace("play"s, [&g]() {g.play(); });
    Commands.emplace("exit"s, [&]() {exiting = true; });
    Commands.emplace("pass"s, [&g]() {g.pass(); });
    Commands.emplace("help"s, [&]() {go::help(); });
    while(!exiting) {
        cin >> sInput;
        try { Commands[sInput](); }
        catch (...) { cerr << sInput << " is not a command." << endl; }
    }
    cout << "Program exiting." << endl;
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