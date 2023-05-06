#include <iostream>
#include <cmath>
using namespace std;

class Complex{
    double re;
    double im;
public:
    Complex(double r, double i): re(r), im(i) {}

    void print() const{
        cout << re << " " << im << endl;
    }

    bool operator>(const Complex & r)const{
        return sqrt(re*re + im*im) > sqrt(r.re*r.re + r.im*r.im);
    }

    bool operator<(const Complex & r)const{
        return !(*this > r);
    }

    bool operator==(const Complex & r)const{
        return !(*this > r) && !(r > *this);
    }

    bool operator>=(const Complex & r)const{
        return !(r > *this);
    }

    bool operator<=(const Complex & r)const{
        return !(*this > r);
    }
};

int main()
{
    Complex X(1.3, 3.4), Y(1.2, 4.5), Z(5.6, 8.9);
    cout << (Z > Y); // 1
    cout << (Z < Y);
    cout << (Z <= Z);
    return 0;
}
