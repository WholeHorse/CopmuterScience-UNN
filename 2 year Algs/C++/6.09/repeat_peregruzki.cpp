#include <iostream>
using namespace std;

/*
    Есть всегда:
    1. Complex(){}
    2. Complex(const Complex & r) : re(r.re), im(r.im){}
    3. ~Complex(){}
    4. operator=

    Перегрузки:
    Бинарные операторы
        ТИП operator @ (arg 1)
        {
            ...
            return arg 1;
        }

    Унарные операторы
        ТИП operator @ ()
        {
            ...
        }
*/

class Complex{
    double re, im;

    public:
    Complex(double r, double i){
        re = r;
        im = i;
    }
    Complex(double r){
        re = r;
        im = 2.0;
    }
    Complex(){
        re = 1.0;
        im = 2.0;
    }
    void print() const {
        cout << re << " " << im << endl;
    }
    Complex add(Complex & t) const{
        t.re += re;
        t.im += im;
        return t;
    }
    Complex operator+(Complex & t) const{
        t.re += re;
        t.im += im;
        return t;
    }
    void operator+=(Complex & t){
        re += t.re;
        im += t.im;
    }
    const Complex operator++(int){ //const добавляет ошибку компиляции, при Y(++)++
        Complex temp(re, im);
        re++; im++;
        return temp;
    }
    Complex operator++(){
        re++; im++;
        return *this;
    }
};

int main()
{
    Complex X, Y(3.4, 5.6);
    Complex Z = Complex(7.8, 9.8);
    Complex W(5.6); // == Complex W = 5.6;
    Complex T = Y; // == Complex T(Y) ...
    // (X + Y).print();
    //X+=Y;
    //X.print();

    Complex F = Y++; 
    F.print(); // 3.4, 4.5             F=Y, Y+=1;
    Y.print(); // 4.4, 5.5

    int a = 5;
    int b = ++a; // a = 6, b = 6 || ++(++a) OK

    Complex L = ++X;
    L.print();
    X.print();

    return 0;
}