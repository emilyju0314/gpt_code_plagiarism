#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const int LIM = 5e5 + 5, MOD = 1e9 + 7;
int t, n, m, k, x, y, w;
int h[LIM];
vector<int> lf;
vector<int> v[LIM];
int ans = 0;
void dfs(int u, int p) {
  h[u] = h[p] + 1;
  for (auto& it : v[u])
    if (it != p) dfs(it, u);
  if (v[u].size() == 1 and u) lf.push_back(h[u]);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    --x, --y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (auto& it : v[0]) {
    h[it] = -1;
    lf.clear();
    dfs(it, 0);
    sort(lf.begin(), lf.end());
    int cans = 0;
    for (auto& it : lf) {
      if (it <= cans)
        cans++;
      else
        cans = it;
    }
    ans = max(ans, cans);
  }
  cout << ans << '\n';
  return 0;
}
