#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, k, a, b, q, t, day, v, p, f[2][maxn], c[maxn], d[maxn], mn;
void add(int val, int x, int v) {
  for (; x < maxn; x += x & -x) {
    f[val][x] += v;
  }
}
int sum(int val, int x) {
  int ret = 0;
  for (; x; x -= x & -x) {
    ret += f[val][x];
  }
  return ret;
}
void solve() {
  cin >> n >> k >> a >> b >> q;
  while (q--) {
    cin >> t;
    t--;
    if (!t) {
      cin >> day >> v;
      mn = min(d[day] + v, a) - d[day];
      d[day] += mn;
      add(1, maxn - day, mn);
      mn = min(c[day] + v, b) - c[day];
      c[day] += mn;
      add(0, day, mn);
    } else {
      cin >> p;
      cout << sum(0, p - 1) + sum(1, maxn - (p + k)) << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
