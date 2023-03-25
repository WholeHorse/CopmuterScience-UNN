#include <stdio.h>

int main()
{
    enum Color {red, blue, green, black};
    // enum Test {A, B, C = 4, D, X = -2, Y} t1, t2 = D;
    // enum {A, B, C = 0, D, X = 2, Y};
    enum {A, B, C = 0, D, X = 2, Y} t1 = X, t2;
    t2 = Y;

    enum Color c1, c2;
    c2 = red;
    printf("%d %d", Y, c2);

    typedef unsigned uint;
    uint a = 10;

    typedef enum Color Color;
    Color c3 = blue;

    typedef enum {AA, BB, CC, DD, XX, ZZ} my_type;


    my_type tt1 = AA;


    return 0;
}