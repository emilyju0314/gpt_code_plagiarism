#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, l, m, a[100009], i, x, y, ans = 0, cnt = 0, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= n; i++) {
    cin >> x;
    if (x == 1) {
      cnt += a[i];
      a[i] = 0;
    }
    a[i] = a[i - 1] + a[i];
  }
  for (i = m; i <= n; i++) {
    l = a[i] - a[i - m];
    ans = max(ans, l);
  }
  cout << ans + cnt;
  return 0;
}
