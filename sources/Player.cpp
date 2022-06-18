#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    Player::Player(Game &game, string &name){
        this->money = 0;        
        this->name =name;
        this->currentGame = &game;
        this->isAlive = true;
        currentGame->add_player(*this);
    }//constructor
    Player::~Player(){  }//deconstructor

    void Player::income(){
        checkGame();
        checkTurn();
        if (this->money >= MAXCOINS){
            throw runtime_error("max coins exedded");
        }
        this->money += 1;
        this->currentGame->lastActions[this->name].second = "income";
        this->currentGame->update_game();   
    }//coin++

    void Player::foreign_aid(){ 
        this->income();
        this->income();
        this->currentGame->lastActions[this->name].second = "foreign_aid";
        this->currentGame->update_game();
    }//coins+=2

    void Player::coup(Player &other){
        checkTurn();

        if (!(other.isAlive)){
            throw runtime_error("already dead");
        }
        if (this->money < MINCOUP){
            throw runtime_error("not enough money");
        }
        for (auto &p : this->currentGame->playersVect){
            if (p->name == other.name){
                other.isAlive = false;
                this->currentGame->lastActions[this->name].second = "coup";
                this->money -= MINCOUP;
                this->currentGame->update_game();
                return;
            }
        }
    }//killing other player

    string Player::role(){
        return this->job;
    } //whoami

    int Player::coins(){
        return this->money;
    }//$$$

    void Player::checkTurn(){
        if (!(this->isAlive)){ 
            throw runtime_error("already dead");
            }

        if (this->currentGame->playersVect[0]->name != this->name){
                throw runtime_error("this shouldent be your turn now");
            }
    }

    void Player::checkGame(){
        if (this->currentGame->playersVect.size() < 2){
            throw runtime_error("need to be more players"); 
        }
        this->currentGame->isStarted = true;
    }

}