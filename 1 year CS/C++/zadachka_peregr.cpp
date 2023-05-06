#include <iostream>
using namespace std;

class Complex
{
    double re, im;
    public:
    Complex(double r, double i) : re(r), im(i){}

    Complex operator-() const { 
        return Complex(-re, -im); 
    }
    const Complex & operator+() const{ 
        return *this; 
    }
    const Complex operator++(int) { 
        //return Complex(re++, im++); // в одну строчку
        Complex t(*this); 
        re++; im++; 
        return t; 
    }
    const Complex operator--(int) { 
        Complex t(*this); 
        re--; im--; 
        return t; 
    }
    Complex & operator++() { 
        re++; im++; 
        return *this; 
    }
    Complex & operator--() { 
        re--; im--; 
        return *this; 
    }
    void print() const{
        cout<<re<<" "<<im<<endl;
    }
};

int main()
{
    Complex X(1.2, 3.4); 
    Complex Y = X++;
    Y.print(); // 1.2 3.4
    X.print(); // 2.2 4.4
    //(X++)++; // ошибька

    return 0;
}