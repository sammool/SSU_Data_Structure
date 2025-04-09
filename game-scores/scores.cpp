#include "scores.h"

Scores::Scores(int N) : maxEntires(N) {};
Scores::~Scores(){}

void Scores::add(const string& name, int score){
    GameEntry entry(name, score);
    
    if(list.size() < maxEntires){
        list.insert(entry);
    }
    else{
        int lastEntityScore = list.getLastEntry().getScore();
        string lastEntityName = list.getLastEntry().getName();
        if((score > lastEntityScore) || (score == lastEntityScore && entry.getName() < lastEntityName )){
            list.removeBack();
            list.insert(entry);
        }
    }
} 

void Scores::print(){
    list.print();
}

void Scores::findName(const string& name){
    std::cout << list.findName(name) <<std::endl;
}

void Scores::findRange(int start, int end){
    list.findRange(start, end);
}

void Scores::removeName(const string& name){
    list.removeName(name);
}

void Scores::removeScore(int score){
    list.removeScore(score);
}

void Scores::removeAll(){
    list.removeAll();
}