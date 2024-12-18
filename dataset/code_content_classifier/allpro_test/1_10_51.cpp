#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
void solve() {
  int n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  int ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  ll s = 1ll * n * m;
  if (ax != bx || ay != by) s -= 1ll * r * c;
  ll K = k;
  ll res = 1;
  const int md = 1e9 + 7;
  while (s) {
    if (s & 1) {
      res *= K;
      res %= md;
    }
    s >>= 1;
    K *= K;
    K %= md;
  }
  cout << res % md << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int i = 0; i < (t); ++i) {
    solve();
  }
  return 0;
}
