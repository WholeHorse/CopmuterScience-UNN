#include <iostream>
using namespace std;

class Complex
{
    double re, im;
    public:
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i){}
    friend ostream & operator<<(ostream&, const Complex &);
    friend istream & operator >>(istream &, Complex &);
};
ostream & operator <<(ostream & out, const Complex & r){
    return out << r.re << " " << r.im << endl;
}
istream & operator >>(istream & in, Complex & r){
    return in >> r.re >> r.im;
}

int main()
{
    Complex X(1.2, 3.4), Y(3.4, 5.6);
    cin >> X;
    cout << X << Y;

    return 0;
}