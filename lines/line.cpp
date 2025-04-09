#include "line.h"
#include <iostream>
const double error = 1e-9;

  Line::Line(): m(0), b(0) {}
  Line::Line(double slope, double yIntercept)
    :m(slope), b(yIntercept) {}

  double Line::getSlope(){
    return m;
  }
  double Line::getYIntercept(){
    return b;
  }

  bool Line::isParallel(const Line& other){
    return this->m == other.m;
  }
  bool Line::isCoincident(const Line& other){
    return (this->m == other.m) && (this->b == other.b);
  }
  double Line::getIntersectionX(const Line& other){
        double intersectionX = ((other.b - this->b) / (this->m - other.m));
        return intersectionX;
    }