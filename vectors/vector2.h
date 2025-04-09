#include <iostream>

class Vector2 {
private:
  double x;
  double y;
    
public:
  Vector2();
  Vector2(double x, double y);

  double getX() const;
  double getY() const;

  friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
  friend Vector2 operator*(double scalar, const Vector2& rhs);
  friend Vector2 operator*(const Vector2& lhs, double scalar);
  friend double operator*(const Vector2& lhs, const Vector2& rhs);
  friend std::ostream& operator<<(std::ostream& out, const Vector2& vector);
};