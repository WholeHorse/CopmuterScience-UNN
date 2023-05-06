#include <stdio.h>
#include <string.h>

void reversestr(char * p, int i, int j)
{
    char t;
    while(i < j)
    {
        t = p[i];
        p[i] = p[j];
        p[j] = t;
        i++;
        j--;
    }
}

void swapstr(char * p)
{
    int fs = 0, ss = strlen(p) - 1;
    reversestr(p, 0, strlen(p) - 1);
    while(p[fs] != ' ') fs++;
    while(p[ss] != ' ') ss--; 

    reversestr(p, 0, fs - 1);
    reversestr(p, ss + 1, strlen(p) - 1);
    reversestr(p, fs, ss);
}

int main()
{
    char str[] = "one two three four";
    swapstr(str);
    puts(str);
    return 0; 
}