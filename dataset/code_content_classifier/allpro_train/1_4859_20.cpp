#include <bits/stdc++.h>
using namespace std;
long long mod(long long x) {
  return ((x % 1000000007 + 1000000007) % 1000000007);
}
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
void solve() {
  long long c, m, x;
  cin >> c >> m >> x;
  long long ans = min(c, min(m, x));
  c -= ans;
  m -= ans;
  if (!c || !m) {
    cout << ans << "\n";
    return;
  }
  long long temp = c + m;
  temp /= 3;
  ans += min(c, min(m, temp));
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
