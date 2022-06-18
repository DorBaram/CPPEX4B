#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Player.hpp"
#include "Game.hpp"
#pragma once
namespace coup{
    class Contessa :public Player{
        
        public:
            Contessa(Game &game, string name); //constructor
            ~Contessa();                      //deconstructor                         
            void block(Player &other);
    };
}