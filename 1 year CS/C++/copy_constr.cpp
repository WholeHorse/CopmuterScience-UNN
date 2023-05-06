#include <iostream>
using namespace std;

/*
Complex(const Complex& r) : re(r.re), im(r.im) {} конструктор копирования
*/

class Complex{
    double re;
    double im = 2.0;

    public:
    Complex(double r, double i) : re(r), im(i) {}
    Complex(double r) : re(r) {}
    Complex(const Complex& r) : re(r.re), im(r.im) {
        cout << " Copy \n";
    }
    void print() const { 
        cout << re << " " << im << endl;
    }
};

void create_copy(Complex R){
    R.print();
}

Complex get_copy(){
    Complex X(3.4, 1.2);
    X.print();
    return X;
}

int main(){
    Complex X(4,5), Y(3.4);
    Complex Z(X); //вызов конструктора копирования / Complex Z = X;
    Z.print();
    create_copy(X);
    get_copy().print();

    return 0;
}