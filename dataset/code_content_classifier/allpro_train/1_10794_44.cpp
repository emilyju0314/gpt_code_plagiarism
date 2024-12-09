#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, j, y, i, k, t, len, x, c, p;
  cin >> n;
  for (i = 1; i <= n; i++) {
    x = i * i - (i - 1);
    y = i * i + i;
    if (n >= x && i * i >= n) {
      cout << 4 * i;
      return;
    } else if (n > i * i && n <= y) {
      cout << (4 * i) + 2;
      return;
    }
  }
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
