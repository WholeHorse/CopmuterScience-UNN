#include <iostream>
using namespace std;


class Complex
{
    const double re;
    const double im;
    int c;

    public:
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) //инициализация как re = r ...
    {
        c = 10;
    }

    void change()
    {
        c = 20;
    }

    void print() const
    {
        cout << re << " " << im << endl;
    }
};

int main()
{
    Complex X; // 0.0 0.0
    Complex Y(1.2), Z(3.4, 5.6); // 1.2 0.0, 3.4 5.6
    Y.print();

    return 0;
}