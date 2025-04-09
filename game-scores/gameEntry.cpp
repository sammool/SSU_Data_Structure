#include "gameEntry.h"

GameEntry::GameEntry(){}
GameEntry::GameEntry(const string& name, int score){
    this->name = name;
    this->score = score;
}

string GameEntry::getName() const {
    return this->name;
}

int GameEntry::getScore() const{
    return this->score;
}