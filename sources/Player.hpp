
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

#pragma once
#include "Game.hpp"

const int MINCOUP = 7;
const int MAXCOINS = 10;

namespace coup{
        class Player{

        public:
            string name;
            string job;
            int money;
            bool isAlive;
            coup::Game* currentGame;
            Player(Game &game, string &name);
            ~Player();                          //deconstructor
            void income();                      //coin++
            void foreign_aid();                 //coins+=2
            virtual void coup(Player &other);   //killing other player
            string role();                      //whoami
            int coins();                        //$$$
            void checkTurn();
            void checkGame();
    };
}