#include <stdio.h>

int main()
{
    /*
    int i = 5;
    while(i--);
    printf("%d", i);
    */
    /*
    int i, j = 20;
    while(j != 5 && (i = j))
    {
        printf("%d %d\n", i, j--);
    }
    */
    /*
    for(int i = 0, j = 10; i < 10; i++, j--) 
        printf("i = %d\t j = %d \n", i, j);

    int i = 0;
    for(; i < 10;)
    {
        puts("HELLO");
        i++;
    }
    */
    /*
    for(;;){
        puts("HELLO");
    }
    */

    int Sum = 0, i = 0; // 0+1+2...+8+10
    while(i <= 10)
    {
        if(i == 8){
            i++;
            continue;
        }
        Sum += i;
        i++;
    }



    return 0;
}
