#include <math.h>
#include <iostream>
using namespace std;

int main()
{
  int n, ans, C[N];
  cin >> n;
  for(int i=0; i < n; i++)
  {
    int x;
    cin >> x;
    C[x+1000] = 1;
  }
  ans = 0;
  for(int i = 0; i < M; i++)
  {
    ans += C[i]
  }
  cout << ans;
}