#include <iostream>
using namespace std;

template <class T>
void F(T a)
{
    cout << a << " Template F" << endl; 
}

void F(double a)
{
    cout << a << " double" << endl; 
}

template <class T1, class T2>
void G(T1 & a, T2 & b)
{
    cout << a << ' ' << b << " Template D" << endl;
}

int main()
{
    F(12);
    F(12.2);
    F("eksdi");
    F<double>(12.3);
    int a = 12;
    float f = 4.5f;
    G(a, f); // double, char

    double d = 34.5;
    char c = 'A';
    G(d, c); // double, char

    return 0;
}