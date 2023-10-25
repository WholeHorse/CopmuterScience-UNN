#include <iostream>
using namespace std;

class Complex{
    double re, im;
    public:
    Complex(double r, double i) : re(r), im(i) {}
    void print() const { 
        cout << re << " " << im << endl;
    }
    operator double() const{
        return re + im;
    }
    operator int() const{
        return re + im;
    }
};

int main()
{
    Complex X(1.2, 3.4), Y(5.6, 7.8);    
    cout << double(X) << endl; //1. double temp = X.operator double(); 2. cout << temp << endl;
    cout << int(X) + double(Y) << endl;  //static_cast<double>(X) явный вызов в С++ или как в C double(X)


    return 0;
}