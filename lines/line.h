
class Line {
    private:
      double m; // slope
      double b; // intercept
    
    public:
      Line();
      Line(double slope, double yIntercept);
    
      double getSlope();
      double getYIntercept();
    
      bool isParallel(const Line& other);
      bool isCoincident(const Line& other);
      double getIntersectionX(const Line& other);
    };