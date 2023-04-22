#include <iostream>
using namespace std;

class ArProg{
    int a1, d;
    public:
    ArProg(int a1 = 1, int d = 1): a1(a1), d(d){}

    int operator[](int index) const{
        return (a1 + (index - 1) * d);
    }
    int operator()(int n) const{
        return ((a1 + (*this)[n])/2. *n); //так же operator[](n)
    }
    int operator()(int i, int j) const{
        return (((*this)[i] + (*this)[j]) / 2. * (j-i+1));
    }
};
    

int main()
{
    const ArProg a1(2, 3); // 2, 5, 8, 11, 14, 17, 20, 23
    cout << a1[4] << endl; // 11
    cout << a1(5) << endl; // a1+a2+...+a5, 40
    cout << a1(3, 7) << endl; // a3+a4+...+a7, 70

    return 0;
}