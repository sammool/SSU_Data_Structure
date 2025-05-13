#include "transaction.h"

Transaction::Transaction(int quantity, int price)
    :quantity(quantity), price(price){}

int Transaction::getPrice() const{
    return this->price;
}
int Transaction::getQuantity() const{
    return this->quantity;
}
void Transaction::setQuantity(int quantity){
    this->quantity = quantity;
}