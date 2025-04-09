#include <iostream>

class Polynomial{
private:
    int maxDegree;
    long long* array;

public:
    Polynomial(int maxDegree = 99);
    ~Polynomial();

    bool isEmpty();
    void setValue(long long coefficient, int degree);
    friend Polynomial operator+(const Polynomial& x, const Polynomial& y);
    friend Polynomial operator-(const Polynomial& x, const Polynomial& y);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial);

};