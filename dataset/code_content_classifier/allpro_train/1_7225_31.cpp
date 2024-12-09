#include <bits/stdc++.h>
using namespace std;
int x;
int f(int b) {
  int y = 0;
  while (b != 0) {
    if (b % 2 == 1) y++;
    b /= 2;
  }
  return y;
}
int main() {
  int y, g, i, n, m, k, a[1001], r, count = 0;
  cin >> n >> m >> k;
  for (i = 0; i <= m; i++) {
    cin >> a[i];
  }
  x = a[m];
  for (i = 0; i < m; i++) {
    y = x ^ a[i];
    r = f(y);
    if (r <= k) count++;
  }
  cout << count << endl;
}
