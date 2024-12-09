#include <bits/stdc++.h>
using namespace std;
const long long N = 2020;
const long long LOG = 22;
const long long INF = 8e18;
const long long MOD = 1e9 + 7;
int n, a[N];
int m, b[N];
long long sa, sb;
inline void solve() {
  sa = accumulate(a, a + n, 0ll);
  sb = accumulate(b, b + m, 0ll);
  long long ansv = INF;
  vector<pair<int, int> > ansp;
  {
    long long curv = abs(sa - sb);
    if (ansv > curv) {
      ansv = curv;
      ansp.clear();
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      sa += b[j] - a[i];
      sb += a[i] - b[j];
      long long curv = abs(sa - sb);
      if (ansv > curv) {
        ansv = curv;
        ansp.clear();
        ansp.push_back(make_pair(i, j));
      }
      sa -= b[j] - a[i];
      sb -= a[i] - b[j];
    }
  map<long long, pair<int, int> > z;
  for (int j = 0; j < n; j++)
    for (int i = 0; i < j; i++) z[2ll * (a[i] + a[j])] = make_pair(i, j);
  for (int j = 0; j < m; j++)
    for (int i = 0; i < j; i++) {
      long long val = sa - sb + 2ll * (b[i] + b[j]);
      auto it = z.lower_bound(val);
      if (it != z.begin()) it--;
      for (int k = 0; k < 2; k++) {
        if (it == z.end()) break;
        long long curv = abs(val - it->first);
        pair<int, int> p = it->second;
        assert(abs(sa - 2ll * (a[p.first] + a[p.second]) -
                   (sb - 2ll * (b[i] + b[j]))) == curv);
        if (ansv > curv) {
          ansv = curv;
          ansp.clear();
          ansp.push_back(make_pair(p.first, i));
          ansp.push_back(make_pair(p.second, j));
        }
        it++;
      }
    }
  assert(ansv != INF);
  cout << ansv << '\n';
  cout << (int)(ansp.size()) << '\n';
  for (int i = 0; i < (int)(ansp.size()); i++)
    cout << ansp[i].first + 1 << ' ' << ansp[i].second + 1 << '\n';
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int j = 0; j < m; j++) cin >> b[j];
  solve();
  return 0;
}
