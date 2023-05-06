#include <stdio.h>
/* функция принимает a - массив, size - размер массива,
функция считает количество локальных минимумов в массиве
и возвращает их количество, возвращает -1 при size < 3 */

int sum_matrix(int a[][], int size)
{
    int sum;
    for(int n = 0; n < 3; n++)
    {
        for(int m = 0; m < 3; m += 2)
        {
            sum += a[n][m];
        }
    }
    return sum;
}


int main()
{
    int a[3][3] = {6, 3, 4, 1, 4, 1};
    
    printf("%d", sum_matrix(a, sizeof(a)/sizeof(int)));
    return 0;
}

