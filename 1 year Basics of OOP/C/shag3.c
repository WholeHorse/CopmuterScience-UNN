#include <stdio.h>


void print_array(int A[], unsigned long long int size)
{
  for(int i = 0; i < size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

void change_array(int p[], unsigned long long size)
{
  p[0] = 10;
  p[1] = 20;
}


int main()
{
  int b[] = {3,6,4,6,4,32,400};
  print_array(b, sizeof(b)/sizeof(int));
  print_array(b, 4);

  change_array(b, 7);
  //print_array(b, 7);
  return 0;
}










/*
int a[5] = {1, 3, 4, 5, 6};
  int b[] = {3,6,4,6,4,32,400};

  printf("%llu\n", sizeof(b)/sizeof(int));

  for(int i = 0; i < sizeof(b)/sizeof(int); i++)
  {
    b[i] = i * i;
    printf("%d ", b[i]);
  }
*/