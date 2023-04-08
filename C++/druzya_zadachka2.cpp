#include <iostream>
using namespace std;

class Point{
    int x, y;
    public:
    Point(int x, int y) : x(x), y(y){}
    void print() const
    {
        cout << "(" << x << "," << y << ") ";
    }
};

class Vector {
    Point p1;
    Point p2;
    public:
    Vector(const Point & p1 = Point(1, 1), const Point & p2 = Point(5, 5)) : p1(p1), p2(p2) {}
    void print() const {
        p1.print();
        p2.print();
        cout << endl;
    }
};

int main()
{
    Point a(1,2), b(3,4);
    Vector v1(a,b);
    v1.print(); // (1,2) (3,4)

    Vector v2;
    v2.print(); // (1,1) (5,5)

    //v1.add(v2);

    return 0;
}