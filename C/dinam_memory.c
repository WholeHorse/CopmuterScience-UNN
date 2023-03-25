#include <stdio.h>
#include <stdlib.h>

int * CreateArray(int size)
{
    int * p = (int *) calloc(size, sizeof(int));
    if(!p) exit(1);
    p[0] = 23;
    p[size-1] = 43;
    return p;
}

void GetArray(int * p)
{
    p[0] = 10;
    p[9] = 18;
}

int main()
{
    /* Работа с динамической памятью
    int * q = (int *) malloc(40);
    //q[0] .... q[9]
    free(q);
    q = NULL;
    */

    int * q = CreateArray(10);
    printf("%d %d \n", q[0], q[9]);
    GetArray(q);
    printf("%d %d \n", q[0], q[9]);
    free(q);
    q = NULL;
    return 0;
}