#include <iostream>
#include <memory>
using namespace std;

//class Complex;

class Point 
{
    int x, y;
    public:
    Point(int x, int y) : x(x), y(y)
    {
    }
    friend void print(class Complex &, Point &);
};

class Complex
{
    double re, im;

    public:
    Complex(double r, double i) : re(r), im(i)
    {

    }
    friend void print(Complex &, Point &);
};

void print(Complex & r, Point & p)
{
    cout << "Complex = " << r.re << " " << r.im << endl;
    cout << "Point = " << p.x << " " << p.y << endl;
}

int main()
{
    Complex X(1,2), Y(3,4);
    Point P(1,2);
    print(Y, P);

    return 0;
}