#include <iostream>
#include <cmath>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}
    void print() const {
        cout << "(" << x << "," << y << ") ";
    }
    /*
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    double vlength(const Point& other) const {
        int dx = other.getX() - x;
        int dy = other.getY() - y;
        return sqrt(dx * dx + dy * dy);
    }
    */
    Point sub(const Point& other) const {
        return Point(other.x - x, other.y - y);
    }

    double len() const {
        return sqrt(x * x + y * y);
    }
};

class Vector {
    Point p1;
    Point p2;
public:
    Vector(const Point& p1 = Point(1, 1), const Point& p2 = Point(5, 5)) : p1(p1), p2(p2) {}
    void print() const {
        p1.print();
        p2.print();
        cout << endl;
    }
    /*
    double length() const {
        return p1.vlength(p2); 
    }
    */

    double length() const {
        return (p1.sub(p2)).len();
    }
};

int main() {
    Point a(1, 2), b(3, 4);
    Vector v1(a, b);
    v1.print(); // (1,2) (3,4)

    Vector v2;
    v2.print(); // (1,1) (5,5)

    cout << v1.length() << endl; // sqrt(13)

    return 0;
}