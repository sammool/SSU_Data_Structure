#include <iostream>
#include "polynomial.h"
int main(int argc, char** argv) {
  int n1, n2;
  Polynomial p1;
  Polynomial p2;

  std::cin >> n1;
  for(int i=0; i<n1; i++){
    long long coefficient;
    int degree;
    std::cin >> coefficient >> degree;
    p1.setValue(coefficient, degree);
  }

  std::cin >> n2;
  for(int i=0; i<n2; i++){
    long long coefficient;
    int degree;
    std::cin >> coefficient >> degree;
    p2.setValue(coefficient, degree);
  }

  Polynomial add = p1 + p2;
  Polynomial sub = p1 - p2;
  
  if(add.isEmpty()){
    std::cout << 0 << " " << 0 << std::endl;
  }
  else{
    std::cout << add;
  }
  
  if(sub.isEmpty()){
    std::cout << 0 << " " << 0 << std::endl;
  }
  else{
    std::cout << sub;
  }
  
  return 0;
}