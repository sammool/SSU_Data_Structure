#include<iostream>

class Transaction{
private:
    int quantity;
    int price;
    Transaction *next;
    friend class StockTrade;
public:
    Transaction(int quantity, int price);
    int getPrice() const;
    int getQuantity() const;
    void setQuantity(int quantity);
};