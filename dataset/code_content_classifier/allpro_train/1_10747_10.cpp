#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
string s;
int m;
long long ans = 0;
vector<pair<int, int> > g[2006];
int vis[2006], cnt, has[2006];
int dfs(int x, int now) {
  vis[x] = now;
  has[x] = 1;
  bool ok = 1;
  for (int i = 0; i < g[x].size(); i++) {
    if (vis[g[x][i].first] != -1) {
      if (vis[g[x][i].first] != now ^ (g[x][i].second)) return 0;
    }
    if (!has[g[x][i].first]) ok &= dfs(g[x][i].first, now ^ (g[x][i].second));
  }
  return ok;
}
int main() {
  cin >> s;
  m = s.size();
  s = "0" + s;
  for (int i = 1; i < m; i++) {
    long long res = 1;
    memset(vis, -1, sizeof(vis));
    memset(has, 0, sizeof(has));
    for (int j = 0; j < 2006; j++) g[j].clear();
    for (int k = 1, j = m; k < j; k++, j--)
      g[k].push_back(make_pair(j, 0)), g[j].push_back(make_pair(k, 0));
    for (int k = 1, j = i; k < j; k++, j--)
      g[k + m].push_back(make_pair(j + m, 0)),
          g[j + m].push_back(make_pair(k + m, 0));
    for (int j = m - i + 1, k = 1; j <= m; j++, k++) {
      if (s[j] == '1')
        g[j].push_back(make_pair(k + m, 1)),
            g[k + m].push_back(make_pair(j, 1));
      if (s[j] == '0')
        g[j].push_back(make_pair(k + m, 0)),
            g[k + m].push_back(make_pair(j, 0));
    }
    for (int j = 1; j <= m - i; j++)
      if (s[j] != '?') vis[j] = s[j] - '0';
    vis[1 + m] = 1;
    if (!dfs(1 + m, 1)) res *= 0;
    for (int j = 1; j <= m - i && res > 0; j++)
      if (!has[j] && vis[j] != -1) {
        if (!dfs(j, vis[j])) res *= 0;
      }
    for (int j = 1; j <= m + i && res > 0; j++)
      if (!has[j]) {
        if (!dfs(j, 0))
          res = 0;
        else
          res = res * 2 % MOD;
      }
    ans = (ans + res) % MOD;
  }
  cout << ans;
}
