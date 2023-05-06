#include <stdio.h>

//Бурыкин Михаил

void fac(int n)
{
  int step = 2;
  if (n <= 0) return;
  if (n == 1)
  { 
  puts("1");
  return;
  }
  printf("%d = ", n);
  while(n != 1)
  {
    if(n % step == 0)
    {
      printf("%d ", step);
      n /= step;
    }
    else(step++);
  }
}


int main()
{
  fac(20);
} 
