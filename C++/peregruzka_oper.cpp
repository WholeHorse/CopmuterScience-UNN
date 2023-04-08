#include <iostream>
using namespace std;

class Complex
{
    double re, im;
    public:
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i){}
    void peint() const{
        cout<<re<<" "<<im<<endl;
    }

    Complex operator+(const Complex & r) const{
        return Complex(re + r.re, im + r.im);
    }

    Complex& operator+=(const Complex & r){ 
        re += r.re;
        im += r.im;
        return *this;
    }

    Complex& operator=(const Complex & r){ 
        if(this != &r){
            re = r.re;
            im = r.im;
        }
        return *this;
    }

    void print() const{
        cout<<re<<" "<<im<<endl;
    }
    friend Complex operator+(double, const Complex &);
};

Complex operator+(double d, const Complex & r){
    return Complex(d + r.re, d + r.im);
}

int main()
{
    Complex X(1,2), Y(3,4);
    4.5 + X; // X.re += 4.5, X.im += 4.5
    X.print(); // 5.5 6.5
    return 0;
}