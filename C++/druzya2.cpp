#include <iostream>
using namespace std;

class Point 
{
    int x, y;
    public:
    Point(int x, int y) : x(x), y(y)
    {}
    void print(class Complex &) const;
};

class Complex
{
    double re, im;

    public:
    Complex(double r, double i) : re(r), im(i)
    {}
    friend void Point::print(Complex &) const;
};

void Point::print(Complex & r) const
{
    cout << "Complex = " << r.re << " " << r.im << endl;
    cout << "Point = " << x << " " << y << endl;
}

int main()
{
    Complex X(1,2), Y(3,4);
    Point P(1,2);
    p.print(Y);

    return 0;
}