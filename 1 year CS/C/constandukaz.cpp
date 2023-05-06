#include <stdio.h>

/*
int * p = &a; Чтение и запись (Не работает с const)
const int * p = &a; Чтение
int * const p = %a; Указатель нельзя изменять, но данные по нему можно
*/

int main()
{
    const int a = 10;
    int b = 12;
    const int * p = &a;

    const int c = 23;
    const int * const q = &c;

    int A[] = {1,2,3,4,5};
    const int * pA = A;
    pA += 2;

    const int * qA = pA;


    return 0;
}