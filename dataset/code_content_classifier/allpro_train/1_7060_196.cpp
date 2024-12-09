#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t;
  cin >> n >> k >> t;
  int s = (t * n * k) / 100;
  int x = s / k;
  int y = s - x * k;
  for (int i = 0; i < n; ++i)
    if (i < x)
      cout << k << " ";
    else if (i == x)
      cout << (int)y << " ";
    else
      cout << 0 << " ";
  cout << endl;
}
