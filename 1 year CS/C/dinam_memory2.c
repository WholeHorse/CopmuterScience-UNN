#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * p = calloc(10, sizeof(int));
    if(!p) exit(1);

    for(int i = 0; i < 10; i++) printf("%d", p[i]);
    free(p);
    p = NULL;

    char * q = (char *) malloc(10);

    strcpy(q, "\nHello");
    puts(q);
    free(q);
    q = NULL;
}