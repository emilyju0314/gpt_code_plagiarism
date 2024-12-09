#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 5e18;
const long long K = 500;
const long long N = 1e5 + 10;
bool check(vector<long long> a, long long x) {
  long long n = (long long)a.size();
  vector<long long> delta(n);
  for (long long i = n - 1; i > 1; i--) {
    long long can = min(a[i] + delta[i] - x, a[i]) / 3;
    delta[i - 1] += can;
    delta[i - 2] += 2 * can;
  }
  for (long long i = 0; i < n; i++) a[i] += delta[i];
  bool ok = true;
  for (long long i = 0; i < n; i++) {
    if (a[i] < x) ok = false;
  }
  return ok;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long l = 0, r = 1e14;
  while (l < r) {
    long long m = l + r + 1 >> 1;
    if (check(a, m))
      l = m;
    else
      r = m - 1;
  }
  cout << l << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
