#include <bits/stdc++.h>
using namespace std;
int n, d, i, v[101], k, y, c, C, E, D, e;
int main() {
  cin >> n >> d;
  for (i = 1; i <= n; i++) cin >> v[i];
  k = 2 * n;
  for (i = 2; i <= n; i++) {
    if (v[i] - v[i - 1] <= 2 * d) k -= 2;
    if (v[i] - v[i - 1] == 2 * d) y++;
  }
  cout << k + y;
  return 0;
}
