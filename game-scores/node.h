#include <iostream>
#include "gameEntry.h"

class Node{
public:
    Node() : gameEntry(), next(NULL), prev(NULL) {}
private:
    GameEntry gameEntry;
    Node* next;
    Node* prev;
    friend class LinkedList;
};