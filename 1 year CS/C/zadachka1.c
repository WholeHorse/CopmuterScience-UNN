#include <stdio.h>
/*
1 возр
2 убыв
0 одинак
-1 неупор
*/

int ArraySt(int * p, int size)
{
    int asc = 0, desc = 0, eq = 0, tmp;
    for(int i = 0; i < size - 1; i++){
        if(p[i] > p[i+1]){
            asc = 1;
        }

        if(p[i] < p[i+1]){
            desc = 1;
        }

        if(p[i] != p[i+1]){
            eq = 1;
        }
    }
    if(asc == 0) return 1;
    else if(desc == 0) return 2;
    else if(eq == 0) return 0;
    else return -1;
}

int main()
{
    int A[] = {-90, -78, 0, 0, 4, 6, 8};
    printf("A = %d", ArraySt(A, sizeof(A)/sizeof(int)));
    return 0;
}