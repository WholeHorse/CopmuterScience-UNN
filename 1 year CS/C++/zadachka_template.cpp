#include <iostream>
using namespace std;

class Complex{

    double re, im;
    public:
    Complex(double r, double i): re(r), im(i) {};
    void print() const{
        cout<<re<<" "<<im<<endl;
    }
    bool operator<(const int x) const{
        return re < x || im < x;
    }
    Complex operator-() const {
        return Complex( ((re < 0) ? -re:re), ((im< 0) ? - im:im));
    } 
};

template<class T>
    void Swap(T & x, T & y){
            T temp = x;
            x = y;
            y = temp;
    }

template<class T>
T Abs(const T & r) {
    return (r < 0) ? -r : r;
}


int main()
{
    Complex X(1.2, 3.4), Y(5.6, 7.8);
    cout << Abs(X) << endl;

    return 0; 
}