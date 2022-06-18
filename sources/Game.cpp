#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Game.hpp"

namespace coup{
    Game::Game(){
    this-> numOfPlayers = 0;
    this-> turnOf = 0;
    this-> isStarted = false;
    }

    Game::~Game(){    }

    string Game::turn(){
        for(auto &i : this->playersVect){
            if (i -> isAlive){
                return(i->name);
            }  
        }
        throw runtime_error("no more alive players");
    }    
    string Game::winner(){
        if (!isStarted){
            throw runtime_error("the game did not start yet");
        }
        
        if (playersVect.size() == 1){
            return playersVect[0]->name;
        }
        throw runtime_error("the game has more than one player");
    }

    vector<string> Game::players(){
        vector<string> v;
        for(auto &i : this->playersVect){
            if (i -> isAlive){
                v.push_back(i->name);
            }  
        }
        return v;
    }

    void Game::add_player(Player &p){
        if (isStarted){
            throw runtime_error("already started");
        }
        if (this->numOfPlayers > MAXNUMOFPLAYERS-1){
            throw runtime_error("already maxed players");
        }

        this->playersVect.push_back(&p);
        this->allivePlayers.push_back(&p);
        this->lastActions[p.name] = pair{nullptr,""};
    }

    void Game::update_game(){
        this->playersVect.push_back(this->playersVect[0]);
        this->playersVect.pop_front();
        while (!(this->playersVect[0]->isAlive)){
            this->playersVect.pop_front();  //all the killed players are now out
        }
    }
}