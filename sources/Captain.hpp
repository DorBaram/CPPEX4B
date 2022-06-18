#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Player.hpp"
#include "Game.hpp"
#pragma once
namespace coup{
    class Captain :public Player{
        
        public:
            int stolen;
            Captain(Game &game, string name); //constructor
            ~Captain();                      //deconstructor                         
            void block(Player &other);
            void steal(Player &other);
    };
}