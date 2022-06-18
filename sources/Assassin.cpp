#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Assassin.hpp"

namespace coup{
            Assassin::Assassin(Game &game, string name):Player(game,name){
                this->job = "Assassin";
            }
            Assassin::~Assassin(){  } //deconstructor  

            void Assassin::coup(Player &p) {
            checkTurn();
            if (this->money >= MINCOUP) {
                Player::coup(p);
            }
            else {
                if (this->money < 3) {
                    throw runtime_error("not enough money");
                    return;}
                for (auto &i: this->currentGame->playersVect) {
                    if (i->name == p.name) {
                        if (!(p.isAlive)) {
                            throw runtime_error("error coup");
                            return;}
                        p.isAlive=false; // dead
                        this->money -= 3;
                        this->currentGame->lastActions[this->name].first = &p;
                        this->currentGame->lastActions[this->name].second = "coupAssassin";
                        this->currentGame->update_game();
                        return;
                        }
                    }
                }
                throw invalid_argument("no player p");
                }
                
            }
    
