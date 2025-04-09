#include <iostream>
#include <sstream>
#include "scores.h"
using namespace std;

int main(int argc, char** argv) {
  int N;
  cin >> N;
  Scores scores(N);
  
  string line;
  
  while(getline(cin,line)){
    stringstream ss(line);
    string command;
    getline(ss,command,',');

    if(command == "ADD"){
      string name, strScore;
      getline(ss,name,',');
      getline(ss,strScore,',');
      int score = stoi(strScore);

      scores.add(name,score);
    }
    else if(command == "PRINT"){
      scores.print();
    }
    else if(command == "FIND-NAME"){
      string name;
      getline(ss,name,',');
      scores.findName(name);
    }
    else if(command == "FIND-RANGE"){
      string start,end;
      getline(ss,start,',');
      getline(ss,end,',');
      scores.findRange(stoi(start),stoi(end));
    }
    else if(command == "REMOVE-NAME"){
      string name;
      getline(ss,name,',');
      scores.removeName(name);
    }
    else if(command == "REMOVE-SCORE"){
      string score;
      getline(ss,score,',');
      scores.removeScore(stoi(score));
    }
    else if(command == "REMOVE-ALL"){
      scores.removeAll();
    }
    else if(command == "QUIT"){
      break;
    }
  }
  
  return 0;
}