#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h, i, j, l, r, x, sum = 0;
  int a[1000] = {0};
  cin >> n >> h >> m;
  for (i = 1; i <= n; i++) a[i] = h;
  for (i = 1; i <= m; i++) {
    cin >> l >> r >> x;
    for (j = l; j <= r; j++) {
      if (x < a[j]) a[j] = x;
    }
  }
  for (i = 1; i <= n; i++) {
    sum += (a[i] * a[i]);
  }
  cout << sum << endl;
  return 0;
}
