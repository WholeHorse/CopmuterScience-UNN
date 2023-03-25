#include <stdio.h>

//Бурыкин Михаил
int main()
{
  int first = 1, second = 1, i = 2, n = 7, sum;
  while(i <= n)
  {
    sum = first + second;
    first = second;
    second = sum;
    i++;
  }
  printf("Number n(%d) = %d", n, sum);
  return 0;
} 