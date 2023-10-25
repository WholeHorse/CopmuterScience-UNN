#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcopy(char *s)
{
    char *p = (char*) malloc(strlen(s) + 1); 
    strcpy(p, s);
    return p;    
}

int main ()
{
    char S[] = "Hello world";
    char * p = strcopy(S);
    p[0] = 'X';
    puts(p);
    free(p);
    p = NULL;

    return 0;
}