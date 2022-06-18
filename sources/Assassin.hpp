#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Player.hpp"
#include "Game.hpp"
#pragma once
namespace coup{
    class Assassin :public Player{

        public:
            Assassin(Game &game, string name); //constructor
            ~Assassin();                      //deconstructor  
            void coup(Player &other) override;                       
    };
}