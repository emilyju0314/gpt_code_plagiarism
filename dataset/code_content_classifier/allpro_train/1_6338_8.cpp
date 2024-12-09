#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
const int mod = 1e9 + 7;
long long p, f;
long long a, b;
long long s, w;
long long now(long long c) {
  if (c * s > p) return 0;
  long long tot = 0;
  tot += c;
  long long p1 = p - c * s;
  long long a1 = a - c;
  tot += min(b, p1 / w);
  long long b1 = b - min(b, p1 / w);
  tot += min(a1, f / s);
  long long f1 = f - min(a1, f / s) * s;
  tot += min(b1, f1 / w);
  return tot;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(cin.failbit);
  long long t = 1;
  cin >> t;
  while (t--) {
    cin >> p >> f;
    cin >> a >> b;
    cin >> s >> w;
    if (s > w) swap(s, w), swap(a, b);
    ll ans = 0;
    for (long long i = 0; i <= a; i++) {
      ans = max(ans, now(i));
    }
    cout << ans << endl;
  }
}
