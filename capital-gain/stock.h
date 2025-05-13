#include "transaction.h"

class StockTrade{
private:
    int totalGain = 0;
    int totalQuantity = 0;
    Transaction* head;
    Transaction* tail;
public:
    StockTrade();
    int getTotalGain() const;
    void buy(int quantity, int price);
    void sell(int quantity, int price);
};

class SellMoreSharedException{
private:
    int insufficientQuantity;
public:
    SellMoreSharedException(int insufficientQuantity);
    int getInsufficientQuantity() const;
};