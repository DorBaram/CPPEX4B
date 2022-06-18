
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

#include "Player.hpp"
using namespace std;

#pragma once

int const MAXNUMOFPLAYERS = 6;
namespace coup{
        class Game{
        
        public:
            int numOfPlayers,turnOf;
            bool isStarted;
            vector<coup::Player*> allivePlayers;  //list of all alive players
            deque<coup::Player*> playersVect;     //list of the current order of players (to play)
            unordered_map <string , pair<coup::Player* ,string>> lastActions;

            ~Game();
            string turn();          
            string winner();
            vector<string> players();
            void add_player(coup::Player &p);
            void update_game();
    };
}