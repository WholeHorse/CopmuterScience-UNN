#include <iostream>
using namespace std;

/*
    Complex() {}
    ~Complex() {}
    Complex (const Complex & r) : re(r.re), im(r.im) {}
*/
class  Complex{
    double re;
    double im = 2.0;

    public:
    Complex (double r, double i): re(r), im(i) {
        cout<<"double , double \n ";
    }
    Complex (double r) : re(r) {}

    Complex (const Complex & r) : re(r.re), im(r.im) {
        cout<<" Copy \n";
    }

    void print() const{
        cout<<re<<" "<<im<<endl; 
    }
    void set_re(double r){
        re = r;
    }
};

void create_copy(Complex R){
        R.print();
}

Complex get_copy(){
    Complex X(3.4, 1.2);
    X.set_re(4.5);
    return X;
}

int main()
{
    Complex X(4,5), Y(3.4);
    Complex Z(X); // Complex Z = X; 
    Z.print();
    create_copy(X);
    get_copy().print();
    return 0;
}