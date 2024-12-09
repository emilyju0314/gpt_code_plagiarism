#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
int n, k, a[N], l[N], r[N], ans;
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if (a[i] % k != a[i - 1] % k) {
      cout << -1 << '\n';
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] /= k;
  }
  sort(a, a + n);
  for (int i = 1; i < n; i++) {
    l[i] = l[i - 1] + i * (a[i] - a[i - 1]);
  }
  for (int i = n - 2; i >= 0; i--) {
    r[i] = r[i + 1] + (n - i - 1) * (a[i + 1] - a[i]);
  }
  ans = l[0] + r[0];
  cout << ans << '\n';
}
