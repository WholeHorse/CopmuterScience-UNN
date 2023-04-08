#include <iostream>
using namespace std;

class Complex{

    double re;
    double im;
    static int c;

    public:
    Complex(double r = 0.0, double i = 0.0): re(r), im(i) {c++;}
    Complex(const Complex & r) : re(r.re), im(r.im) {c++;}
    ~Complex() {c--;}
    static void get_counter(){
        cout<<"counter = "<<c<<endl;
    } 
};

int Complex::c = 0; 

void create(){
    Complex X, Z;
    Complex::get_counter(); 
}

int main()
{
    Complex X(1,2);
    Complex Y;
    Complex::get_counter(); // 2
    create(); // 4
    Complex::get_counter(); // 2
    Complex Z(X);
    Complex::get_counter(); // 3
    return 0;
}