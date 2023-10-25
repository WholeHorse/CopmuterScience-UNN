#include <iostream>
using namespace std;

class Complex{
    double re, im;
    public:
    Complex(double r, double i) : re(r), im(i) {}
    Complex(double r) : re(r), im(1.0) {
        cout << " Complex (double )\n";
    }

    void print() const { 
        cout << re << " " << im << endl;
    }
    operator double() const{
        cout << "double \n";
        return re + im;
    }
    Complex operator+(const Complex & r) const {
        cout << " operator+ (const Complex & )\n";
        return Complex(re+ r.re, im+ r.im);
    }
};

int main()
{
    Complex X(1.2, 3.4), Y(5.6, 7.8);    
    X + Y;
    X + Complex(3.4);
    cout << X;
    double d = X;
    3.4 + X;

    return 0;
}