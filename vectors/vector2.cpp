#include "vector2.h"

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(double x, double y) : x(x), y(y) {}
double Vector2::getX() const{
    return x;
}
double Vector2::getY() const{
    return y;
}

Vector2 operator+(const Vector2& lhs, const Vector2& rhs){
   return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2 operator*(double scalar, const Vector2& rhs){
    return Vector2(scalar * rhs.x, scalar * rhs.y);
}

Vector2 operator*(const Vector2& lhs, double scalar){
    return Vector2(scalar * lhs.x, scalar * lhs.y);
}

double operator*(const Vector2& lhs, const Vector2& rhs){
    return (lhs.x * rhs.x) + (lhs.y * rhs.y);    
}

std::ostream& operator<<(std::ostream& out, const Vector2& vector){
    out << vector.x << " " << vector.y; 
    return out;
}