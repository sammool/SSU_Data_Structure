#include <iostream>
#include "vector2.h"

using namespace std;

int main(int argc, char** argv) {
  double x1, y1, x2, y2, scalar;
  cin >> x1 >> y1 >> x2 >> y2 >> scalar;

  Vector2 v1(x1, y1);
  Vector2 v2(x2, y2);

  cout << v1 + v2 << endl;
  cout << scalar * v1 << endl;
  cout << v1 * v2 << endl;
  return 0;
}