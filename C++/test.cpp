#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;


int main()
{
  int A[4][4] = {{1, -3 ,-4, 7},{-9, -5, 1, 0},{1, 6, 3,-10},{-4, 0, 6, -1}};
  int max_otric;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      cout << setw(5) << A[i][j];
    }
    cout << endl;
  }

  for(int j = 0; j < 4; j++)
  {
    for(int i = 0; i < 4; i++)
    {
      if(((i + j) == 3) && (A[i][j] < 0))
      {
        if(max_otric > A[i][j])
          max_otric = A[i][j];
      }
    }
  }
  cout << max_otric << endl;

  int S[4];
  for(int j = 0; j < 4; j++)
  {
    int sum = 0;
    for(int i = 0; i < 4; i++)
    {
      if(A[i][j] < 0)
        sum += A[i][j];
    }
    S[j] = sum;
  }

  for(int i = 0; i < 4; i++)
  {
    cout << setw(5) << S[i];
  }

  return 0;
}
