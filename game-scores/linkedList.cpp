#include "linkedList.h"
LinkedList::LinkedList(){
    count = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

void LinkedList::insert(const GameEntry& entry){
    Node* newNode = new Node;
    newNode->gameEntry = entry;

    Node* current = head->next;
    //current의 앞에 삽입
    while(current!=tail){
        int score = current->gameEntry.getScore();
        string name = current->gameEntry.getName();

        if((entry.getScore() > score) || (entry.getScore() == score && entry.getName()< name)){ //점수가 더 클 때, 같을 때는 사전순으로 삽입.
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            count++;
            return;
        }
        current = current->next;
    }
    newNode->prev = tail->prev;
    newNode->next = tail;
    tail->prev->next = newNode;
    tail->prev=newNode;
    count++;
    return;
}

GameEntry& LinkedList::getLastEntry() const{
    return tail->prev->gameEntry;
}

int LinkedList::size() const{
    return count;
}

void LinkedList::removeBack(){
    Node* target = tail->prev;
    Node* before = target->prev;

    before->next = tail;
    tail->prev = before;
    count--;
    delete target;
}

void LinkedList::print(){
    Node* current = head->next;
    if(current==tail){
        std::cout << "EMPTY" << std::endl;
        return;
    }

    while(current!=tail){
        std::cout<<current->gameEntry.getName()
        <<","<<current->gameEntry.getScore()<<endl;
        current = current->next;
    }
    return;
}

int LinkedList::findName(const string& name){
    Node* current = head->next;
    while(current!=tail){
        if(current->gameEntry.getName() == name){
            return current->gameEntry.getScore();
        }
        current = current -> next;
    }
    return -1;
}

void LinkedList::findRange(int start, int end){
    Node* current = head->next;
    bool isFirst = true;

    while(current!=tail){
        GameEntry entry = current->gameEntry;
        if(entry.getScore()>=start && entry.getScore()<=end){
            if(!isFirst){
                std::cout<<',';
            }
            isFirst = false;
            std::cout<<entry.getName();
        }
        current = current->next;
    }
    std::cout<<endl;
}

void LinkedList::removeName(const string& name){
    Node* current = head->next;
    while(current!=tail){
        GameEntry& entry = current->gameEntry;
        if(entry.getName() == name){
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            count--;
            return;
        }
        current = current->next;
    }
}

void LinkedList::removeScore(int score){
    Node* current = head->next;
    while(current!=tail){
        GameEntry& entry = current->gameEntry;
        if(entry.getScore() < score)
            break;
        if(entry.getScore() == score){
            Node* toDelete = current;
            current = current->next; //current 삭제 되기 전에 저장

            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            delete toDelete;
            count--;
        }else{
            current = current->next;
        }
    }
    return;
}

void LinkedList::removeAll(){
    Node* current = head->next;
    while(current!=tail){
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head->next = tail;
    tail->prev = head;
    count = 0;
}