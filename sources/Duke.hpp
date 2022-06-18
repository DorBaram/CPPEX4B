#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Player.hpp"
#include "Game.hpp"
#pragma once
namespace coup{
    class Duke :public Player{
   
        public:
            Duke(Game &game, string name);//constructor
            ~Duke();                      //deconstructor                         
            void block(Player &other);
            void tax();
    };
}