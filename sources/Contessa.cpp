#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Contessa.hpp"

namespace coup{
            Contessa::Contessa(Game &game, string name):Player(game,name){
                this->job = "Contessa";
            }
            Contessa::~Contessa(){
            } //deconstructor                         
            void Contessa::block(Player &other){
                if (!(this->isAlive)){
                    throw runtime_error("contessa already dead");
                }
                checkTurn();
                for(auto &p : this->currentGame->playersVect){
                    if ((p->name == other.name) && (other.isAlive) && (other.job == "Assassin") && (this->currentGame->lastActions.at(other.name).second == "coupAssassin")){
                        this->currentGame->lastActions[other.name].first->isAlive = true;
                        this->currentGame->lastActions[this->name].first = &other;
                        this->currentGame->lastActions[this->name].second = "block";
                        return;
                    }
            }
            throw runtime_error("block failed");
        }
}