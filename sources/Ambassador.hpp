#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Player.hpp"
#include "Game.hpp"
#pragma once
namespace coup{
    class Ambassador :public Player{
        
        public:
            Ambassador(Game &game, string name);//constructor
            ~Ambassador();                      //deconstructor                         
            void block(Player &other);
            void transfer(Player &to,Player &from);
    };
}