#include <bits/stdc++.h>
using namespace std;
template <class C>
inline bool in_(const typename C::key_type& k, const C& A) {
  return A.find(k) != A.end();
}
inline bool in_(const string& s, const string& S) {
  return S.find(s) != string::npos;
}
const int inf = 1e9;
const int maxv = 1e5 + 5;
int dp[maxv], vis[maxv], lucky[maxv];
set<int> G[maxv];
bool islucky(int x) {
  bool good = true;
  while (x) {
    good &= (x % 10 == 4 || x % 10 == 7);
    x /= 10;
  }
  return good;
}
int dfs(const int u) {
  vis[u]++;
  int size = 1;
  for (__typeof((G[u]).begin()) v = (G[u]).begin(); v != (G[u]).end(); ++v)
    if (!vis[*v]) size += dfs(*v);
  return size;
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = (1); i < (maxv); ++i) lucky[i] = islucky(i);
  int n, m;
  while (cin >> n >> m) {
    for (int i = (1); i < (n + 1); ++i) vis[i] = 0, dp[i] = inf, G[i].clear();
    for (int _ = (0); _ < (m); ++_) {
      int u, v;
      cin >> u >> v;
      G[u].insert(v);
      G[v].insert(u);
    }
    map<int, int> cnt;
    for (int i = (1); i < (n + 1); ++i)
      if (!vis[i]) cnt[dfs(i)]++;
    dp[0] = 0;
    for (__typeof((cnt).begin()) x = (cnt).begin(); x != (cnt).end(); ++x) {
      const int w = x->first;
      int m = x->second;
      int c = 1;
      while (c <= m) {
        for (int j = (n); j > (c * w - 1); --j)
          dp[j] = min(dp[j], dp[j - c * w] + c);
        m -= c;
        c *= 2;
      }
      if (m) {
        for (int j = (n); j > (m * w - 1); --j)
          dp[j] = min(dp[j], dp[j - m * w] + m);
      }
    }
    int ans = inf;
    for (int i = (1); i < (n + 1); ++i)
      if (lucky[i]) ans = min(ans, dp[i]);
    ans = ans < inf ? ans - 1 : -1;
    cout << ans << endl;
  }
  return 0;
}
