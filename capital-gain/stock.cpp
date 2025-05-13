#include "stock.h"

StockTrade::StockTrade(){
    head = nullptr;
    tail = nullptr;
}

void StockTrade::buy(int quantity, int price){
    Transaction* recentBuy = new Transaction(quantity,price);
    if(tail){
        tail->next = recentBuy;
    }else{
        head = recentBuy;
    }
    tail = recentBuy;
    totalQuantity += quantity;
}

void StockTrade::sell(int quantity, int price){
    if(totalQuantity < quantity){
        throw SellMoreSharedException(quantity-totalQuantity);
    }
    
    while(quantity>0){
        int curPrice = head->getPrice();
        int curQuantity = head->getQuantity();

        //매도할 수 있는 주식이 더 많을 때 + 큐에서 삭제
        if(curQuantity<=quantity){
            totalGain += curQuantity * (price - curPrice);
            totalQuantity-=curQuantity;
            quantity-=curQuantity;
            
            Transaction* temp = head;
            head = head->next;
            delete temp;
            
            if (head == nullptr) {
                tail = nullptr;
            }
        } else{
            //매도할 수 있는 주식이 더 적을 때
            head->setQuantity(curQuantity - quantity);
            totalGain += quantity * (price - curPrice);
            totalQuantity-=quantity;
            quantity = 0;

        }       
    }
}
int StockTrade::getTotalGain() const{
    return totalGain;
}

SellMoreSharedException::SellMoreSharedException(int insufficientQuantity)
        :insufficientQuantity(insufficientQuantity){}
int SellMoreSharedException::getInsufficientQuantity() const{
    return insufficientQuantity;
}