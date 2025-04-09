#include "node.h"
class LinkedList{
public:
    LinkedList();
    void insert(const GameEntry& entry);
    void print();
    GameEntry& getLastEntry() const;
    int size() const;
    void removeBack();
    int findName(const string& name);
    void findRange(int start, int end);
    void removeName(const string& name);
    void removeScore(int score);
    void removeAll();
private:
    int count;
    Node* head;
    Node* tail;
    friend class Scores;
};