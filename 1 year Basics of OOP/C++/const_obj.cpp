#include <iostream>
using namespace std;

class Complex
{
    private:
    const double re, im;
    int c;
    public:
    Complex(double r, double i) : re(r), im(i)
    {
        c = 20;
    }

    void print() const // если не изменяется в функциях, то обяз. пишем
    {
        cout << re << " " << im << endl;
    }

    void change()
    {
        c = 100;
    }

};
/*
1. Для const объектов всегда должен быть вызван только const метод
2. Для не const объекта можно вызывать const и не const методы
3. Поля класса, помеченные как const невозможно изменить не const методом
*/

int main()
{
    const Complex X(1.2, 3.4);
    X.print();
    Complex Y(5.6, 7.8);
    Y.change();

    return 0;
}