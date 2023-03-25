#include <math.h>
#include <stdio.h>

int main()
{
  float a, b, c;
  float tax_rate = 10;
  float p, S, tax;
  printf("Input sides: ");
  scanf_s("%f %f %f", &a, &b, &c);
  p = (a + b + c) / 2;
  S = sqrt(p * (p - a) * (p - b) * (p - c));
  tax = tax_rate * S;
  printf("Tax = %.2f", tax);
  return 0;
}
