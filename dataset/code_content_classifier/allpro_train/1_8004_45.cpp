#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18, M = 1e9 + 7;
const long long int N = 1;
long long int func(long long int n, long long int m, long long int k) {
  long long int a, b;
  if (k > (n - 1)) {
    a = 1, k -= (n - 1);
    if (k > (m - 1)) return -1;
    b = m / (k + 1);
    return (a * b);
  } else {
    a = n / (k + 1);
    return (a * m);
  }
}
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int ans = max(func(n, m, k), func(m, n, k));
  cout << ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
