#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Duke.hpp"

namespace coup{
            Duke::Duke(Game &game, string name):Player(game,name){
                this->job = "Duke";
            }
            Duke::~Duke(){
            } //deconstructor 

            void Duke::block(Player &other){
                checkTurn();
                for(auto &p : this->currentGame->playersVect){
                    if ((p->name == other.name) && (other.isAlive)&& (this->currentGame->lastActions.at(other.name).second == "foreignAid")){
                        other.money =- 2;
                        this->currentGame->lastActions[this->name].first = &other;
                        this->currentGame->lastActions[this->name].second = "block";
                        return;
                    }
                }
                throw runtime_error("block failed");
            }
            
            void Duke::tax(){
                checkTurn();
                if (this->money >= MAXCOINS){
                    throw runtime_error("cant have more than 10 coins");
                }
                this->money +=3;
                this->currentGame->lastActions[this->name].first = this;
                this->currentGame->lastActions[this->name].second = "tax";
                this->currentGame->update_game();
            }
}