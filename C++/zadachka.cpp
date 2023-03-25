#include <iostream>
using namespace std;

class Rational
{
    int numerator;
    int denominator;

    public:
    Rational() : numerator(1), denominator(2) {}
    Rational(int num) : numerator(num), denominator(3) {}
    Rational(int num, int den) : numerator(num), denominator(den) {}

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    double convert() const {
        double num = numerator;
        double denom = denominator;
        return num / denom;
    }

    Rational add(const Rational& sn) const {
        int num = numerator * sn.denominator + sn.numerator * denominator;
        int den = denominator * sn.denominator;
        return Rational(num, den);
    }

    Rational sub(const Rational& sn) const {
        int num = numerator * sn.denominator - sn.numerator * denominator;
        int den = denominator * sn.denominator;
        return Rational(num, den);
    }

    Rational mul(const Rational& sn) const {
        int num = numerator * sn.numerator;
        int den = denominator * sn.denominator;
        return Rational(num, den);
    }

    // >
    bool IsBigger(const Rational& sn) const {
        return (numerator * sn.denominator) > (sn.numerator * denominator);
    }
    // <
    bool IsLess(const Rational& sn) const {
        return (numerator * sn.denominator) < (sn.numerator * denominator);
    }
    // =
    bool IsEqual(const Rational& sn) const {
        return (numerator == sn.numerator) && (denominator == sn.denominator);
    }

};

int main()
{
    const Rational r1; 
    r1.print(); //1/2
    const Rational r2 = 5;
    r2.print(); //5/3
    const Rational r3(-8, 3);
    r3.print(); //-8/3

    cout << r1.convert() << endl; //0.5
    Rational r4 = r1.add(r2); //1/2 + 5/3
    r4.print(); //13/6
    r4 = r1.sub(r2); //1/2 - 5/3
    r4.print(); //-7/6
    r4 = r1.mul(r2); //1/2 * 5/3
    r4.print(); //5/6

    (r1.add(r2)).mul(r3).print();


    return 0;
}