#include <iostream>
using namespace std;

class Complex{
    double re;
    double im;

    public:
    Complex(double r = 0.0, double i = 0.0) : re(), im() {}
    void print() const { 
        cout << re << " " << im << endl;
    }
    Complex & operator ()(double r, double i)
    {
        re+=r; im+=i;
        return *this;
    }
};

int main()
{
    Complex X(1.2, 3.4);
    X(2,3)(4,5); 
    X.print(); //7.2 11.4

    return 0;
}