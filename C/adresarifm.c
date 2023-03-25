#include <stdio.h>

typedef struct {
    int a;
    int b;
    char c;
}Type;


int main()
{

    Type Obj[3] = { {1,2,'A'}, {2,3,'B'}, {3,4,'C'} };
    Type * p = Obj;
    Type * q = p;
    q++;

    int * pi = (int *)q;
    pi++;
    *pi = -1;
    printf("%d\n", q->b);

    q++;
    int count = q-p;
    printf("count = %d sizeof Type = %lld", count, sizeof(Type));
    return 0;
}