#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Captain.hpp"

namespace coup{
            Captain::Captain(Game &game,string name):Player(game,name){
                this->job = "Captain";
                this->stolen =0;
            }
            Captain::~Captain(){
            } //deconstructor                                     
            void Captain::block(Player &other){
                checkTurn();
                for (auto &p : this->currentGame->playersVect){
                    if ((p->name == other.name) && (other.isAlive) && (other.job == "Captain") && (other.currentGame->lastActions.at(other.name).second == "steal")){
                        Player *assaulted = this->currentGame->lastActions[other.name].first;
                        Captain *temp = (Captain *)(&other);
                        if (assaulted->isAlive) {
                            assaulted->money += temp->stolen;
                            if (temp->money >= 2){
                                temp->money -= temp->stolen;
                            }
                            else {temp->money = 0;}
                            this->currentGame->lastActions[this->name].first = &other;
                            this->currentGame->lastActions[this->name].second = "block";
                            return;
                    }
                }
                throw runtime_error("error block");
                }
            }

            void Captain::steal(Player &other){   
                checkTurn();
                for(auto &p : this->currentGame->playersVect){
                    if ((p->name == other.name) && (other.isAlive)){
                        if (this->money >= MAXCOINS){
                            this ->coup(other);
                            return;
                        }
                        if (other.money == 1){
                            other.money -=1;
                            this->money +=1;
                            this->stolen =1;
                        }
                        if (other.money >=2){
                            other.money -=2;
                            this->money +=2;
                            this->stolen =2;
                        }
                        else{throw runtime_error("error steal");
                        }
                        this->currentGame->lastActions[this->name].first = &other; 
                        this->currentGame->lastActions[this->name].second = "steal";
                        this->currentGame->update_game();
                    }
                }  
                throw runtime_error("error steal");          
            }
}