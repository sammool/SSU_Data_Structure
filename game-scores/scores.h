#include "linkedList.h"
class Scores{
public:
    Scores(int N);
    ~Scores();
    void add(const string& name, int score);
    void print();
    void findName(const string& name);
    void findRange(int minScore, int maxScore);
    void removeName(const string& name);
    void removeScore(int score);
    void removeAll();

private:
    int maxEntires;
    LinkedList list;
};