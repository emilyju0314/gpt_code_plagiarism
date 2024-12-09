#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;
long long n, k, mx, ans, cnt;
long long a[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == k && a[i]) {
      ans++;
      a[i] = 0;
    }
    if (i != k && !a[i]) {
      ans++;
      a[i] = inf;
      cnt++;
    }
  }
  sort(a + 1, a + 1 + n);
  for (long long i = 1; i <= n; i++) {
    if (a[i] == mx) {
      continue;
    }
    if (a[i] == mx + 1) {
      mx++;
      continue;
    }
    ans++;
    mx++;
    n--;
    i--;
  }
  cout << ans - cnt;
}
