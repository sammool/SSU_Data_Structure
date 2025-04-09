#include "polynomial.h"

Polynomial::Polynomial(int maxDegree){
    this->maxDegree = maxDegree;
    array = new long long[maxDegree + 1]();
}
Polynomial::~Polynomial(){
    delete[] array;
}

void Polynomial::setValue(long long coefficient, int degree){
    this->array[degree] = coefficient;
}

bool Polynomial::isEmpty(){
    for(int i=0; i<=maxDegree; i++){
        if(array[i]!=0)
            return false;
    }
    return true;
}

Polynomial operator+(const Polynomial& x, const Polynomial& y){
    Polynomial z;
    for(int i=0; i<=99; i++){
        z.array[i] = x.array[i] + y.array[i];
    }
    return z;
}

Polynomial operator-(const Polynomial& x, const Polynomial& y){
    Polynomial z;
    for(int i=0; i<=99; i++){
        z.array[i] = x.array[i] - y.array[i];
    }
    return z;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial){
    for(int i=99; i>=0; i--){
        if(polynomial.array[i] == 0)
            continue;
        out << polynomial.array[i] << " " << i << std::endl;
    }
    return out;
}