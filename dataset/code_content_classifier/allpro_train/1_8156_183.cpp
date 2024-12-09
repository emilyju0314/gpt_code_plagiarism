#include <bits/stdc++.h>
using namespace std;
long long powermod(long long a, long long b) {
  if (b == 0) return 1;
  long long x = powermod(a, b / 2);
  x = x * x;
  if (b & 1) x = x * a;
  return x;
}
long long i, j, k;
long long ans = 9e18;
long long nr, ng, nb;
long long sq(long long x) { return x * x; }
void findmin(vector<long long> a, vector<long long> b, vector<long long> c) {
  for (auto x : a) {
    auto y = lower_bound((b).begin(), (b).end(), x);
    auto z = upper_bound((c).begin(), (c).end(), x);
    if (y == b.end() || z == c.begin()) continue;
    z--;
    ans = min(ans, sq(x - *y) + sq(x - *z) + sq(*z - *y));
  }
}
void solve() {
  cin >> nr >> ng >> nb;
  vector<long long> r(nr), g(ng), b(nb);
  for (i = (0); i < (nr); i++) cin >> r[i];
  for (i = (0); i < (ng); i++) cin >> g[i];
  for (i = (0); i < (nb); i++) cin >> b[i];
  sort((r).begin(), (r).end()), sort((g).begin(), (g).end()),
      sort((b).begin(), (b).end());
  ans = 9e18;
  findmin(r, g, b);
  findmin(r, b, g);
  findmin(g, r, b);
  findmin(g, b, r);
  findmin(b, r, g);
  findmin(b, g, r);
  cout << ans;
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
