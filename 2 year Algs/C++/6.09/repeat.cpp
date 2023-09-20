#include <iostream>
using namespace std;


class Complex{
    double re = 1.0, im = 2.0;

    public:
    Complex() = default;
    Complex(double r, double i) : re(r), im(i) {}

    void print() const {
        cout << re << " " << im << endl;
    }
};

class Pointer {
    Complex* ptr = NULL;

public:
    Pointer() = default;
    Pointer(Complex* p) : ptr(p) {}
    Pointer(const Pointer&) = default;
    
    Complex* operator->() const {
        return ptr;
    }

    Complex operator*(){
        return *ptr;
    }

    Pointer& operator++() {
        ++ptr;
        return *this;
    }
};

int main()
{
    Complex X(3.4, 5.6);
    Pointer p1 = & X;
    Pointer p2;

    //p1->print();
    //(*p2).print();

    Complex Y[] = {Complex(1.2, 3.4), Complex(5.6, 7.8), Complex(7.2, 8.9)};
    p1 = &Y[0];
    p1->print();

    ++p1;
    p1->print(); //5.6, 7.8


    return 0;
}