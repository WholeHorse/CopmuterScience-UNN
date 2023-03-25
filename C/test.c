#include <stdio.h>
int main()
{
    int sum;
    int i = 0;
    int a[] = {1, 2, 0, 3, 3, 0};
    for(; i < sizeof(a)/sizeof(int); i++)
    {
        if(a[i] == 0)
        {
            
            for(; i < sizeof(a)/sizeof(int); i++)
        }
    }

    return 0;
}