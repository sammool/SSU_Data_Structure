#include <iostream>
#include "stock.h"
using namespace std;

int main(int argc, char** argv) {
  StockTrade st;

  while(1){
    
      char c;
      cin >> c;
        if(c=='b'){
          int a,b;
          cin >> a >> b;
          st.buy(a,b);
        }
        else if(c=='s'){
          int a,b;
          cin >> a >> b;
            try{
              st.sell(a,b);
            }catch(SellMoreSharedException e){
              cout << "Insufficient shares:" << e.getInsufficientQuantity();
              return 0;
            }
            
        }
        else if(c=='g'){
          cout << st.getTotalGain() << endl;
        }
        else if(c=='q'){
          return 0;
        } 
  }
}