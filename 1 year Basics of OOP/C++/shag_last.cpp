#include <iostream>
using namespace std;
/*
void F(int & r)
{
    cout << "int &  \n";
}

void F(const int & r)
{
    cout << "const int &  \n";
}
*/

class Complex{
    double re, im;
    public:
    Complex(double re, double im): re(re), im(im) {}
    void print() const{
        cout << re << " " << im << endl;
    }
    void print(){ 
        cout << re << " " << im << endl;
    }//не конст объекты, ссылки и указатели
};

int main()
{
    

    return 0;
}