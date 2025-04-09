#include <iostream>
using namespace std;

class GameEntry{
public:
    GameEntry();
    GameEntry(const string& name, int score);
    string getName() const;
    int getScore() const;
private:
    string name;
    int score;
};