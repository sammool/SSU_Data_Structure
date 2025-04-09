#include <iostream>
#include "line.h"

int main(int argc, char** argv) {
  double slope1, intercept1, slope2, intercept2;
  std::cin >> slope1 >> intercept1 >> slope2 >> intercept2;

  Line line1(slope1, intercept1);
  Line line2(slope2, intercept2);

  if(line1.isCoincident(line2)){
    std::cout << 'i' << std::endl;
  }
  else if(line1.isParallel(line2)){
    std::cout << 'p' << std::endl;
  }
  else{
    std::cout << line1.getIntersectionX(line2) << std::endl;
  }
  return 0;
}