#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Ambassador.hpp"
#include "Captain.hpp"

namespace coup{
            Ambassador::Ambassador(Game &game, string name):Player(game, name){
                this->job = "Ambassador";
            }
            Ambassador::~Ambassador(){ }                          
            void Ambassador::block(Player &other){
                if (!(this->isAlive)){
                    throw runtime_error("cannot block if dead");
                }
                for (auto &p : this->currentGame->playersVect){
                    if ((p->name ==other.name) && (other.job == "Captain") && (this->currentGame->lastActions[other.name].second == "steal")){
                        Captain *tmp = (Captain *)(&other);     
                        this->currentGame->lastActions[other.name].first->money += tmp->stolen; // give back the money
                        tmp->money -=tmp->stolen;
                        if (tmp->money <0){
                            tmp->money =0;
                        }
                        this->currentGame->lastActions[this->name].first = &other;
                        this->currentGame->lastActions[this->name].second = "block";
                        return;
                    }
                }
                  throw runtime_error("error blocking");            
            }

            void Ambassador::transfer(Player &from,Player &to){
                checkTurn();
                 for (auto &p : this->currentGame->playersVect){
                    if ((p->name ==to.name) && (p->isAlive)){
                        for (auto &q : this->currentGame->playersVect){
                            if ((q->name ==from.name) && (q->isAlive)){
                                from.money -=1;
                                to.money +=1;
                                this->currentGame->lastActions[this->name].first = nullptr;
                                this->currentGame->lastActions[this->name].second = "transfer";
                                this->currentGame->update_game();
                                return;
                            }
                        }
                    }
                }
                throw runtime_error("error transfering");      
            }
}