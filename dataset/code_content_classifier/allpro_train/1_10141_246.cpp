#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int N = 3e5 + 10;
const int M = 11;
const double PI = acos(-1.0);
bool debug = false;
inline int read() {
  int x = 0;
  bool sign = false;
  char alpha = 0;
  while (!isdigit(alpha)) sign |= alpha == '-', alpha = getchar();
  while (isdigit(alpha))
    x = (x << 1) + (x << 3) + (alpha ^ 48), alpha = getchar();
  return sign ? -x : x;
}
vector<pair<int, int> > son[N];
int belong[N], tin[N], low[N], now_time, scc_cnt, l[N], v[N];
stack<int> s;
void dfs(int o, int id) {
  tin[o] = low[o] = ++now_time;
  s.push(o);
  for (auto it : son[o]) {
    int v = it.first;
    if (!tin[v]) dfs(v, it.second);
    if (!belong[v] && id != it.second) low[o] = min(low[o], low[v]);
  }
  if (tin[o] == low[o]) {
    scc_cnt++;
    int now;
    while (true) {
      now = s.top();
      s.pop();
      belong[now] = scc_cnt;
      if (now == o) break;
    }
  }
}
vector<int> _son[N];
int _v[N], dp[N][2], id[N], deep[N], gg1[N], gg2[N];
void dfs1(int o, int f) {
  deep[o] = deep[f] + 1;
  int si = 0, to;
  for (auto it : _son[o]) {
    if (it == f) continue;
    dfs1(it, o);
    if (dp[it][1]) si++, to = it;
  }
  if (_v[o]) {
    dp[o][0] = 0, dp[o][1] = 1;
    for (auto it : _son[o]) {
      if (it == f || !dp[it][1]) continue;
      dp[o][1] =
          dp[o][1] * 1ll *
          (dp[it][0] + dp[it][1] * 1ll * (deep[it] - deep[o]) % 998244353) %
          998244353;
    }
  } else {
    if (si >= 2) {
      dp[o][0] = 1, dp[o][1] = 0;
      int zz = _son[o].size();
      for (int i = 1, it; i <= zz; ++i) {
        it = _son[o][i - 1];
        if (it == f || !dp[it][1])
          gg1[i] = 1;
        else
          gg1[i] =
              (dp[it][0] + dp[it][1] * 1ll * (deep[it] - deep[o])) % 998244353;
      }
      gg2[zz + 1] = 1, gg1[0] = 1;
      for (int i = zz; i >= 1; --i)
        gg2[i] = gg1[i] * 1ll * gg2[i + 1] % 998244353;
      for (int i = 1; i <= zz; ++i)
        gg1[i] = gg1[i] * 1ll * gg1[i - 1] % 998244353;
      dp[o][0] = gg1[zz];
      for (int i = 1, it; i <= zz; ++i) {
        it = _son[o][i - 1];
        if (it == f || !dp[it][1]) continue;
        dp[o][1] +=
            gg1[i - 1] * 1ll * gg2[i + 1] % 998244353 * dp[it][1] % 998244353;
        if (dp[o][1] >= 998244353) dp[o][1] -= 998244353;
      }
    } else {
      if (si == 1)
        dp[o][0] = dp[to][0], dp[o][1] = dp[to][1], deep[o] = deep[to];
    }
  }
}
void scc(int n) {
  for (int i = 1; i <= n; ++i) tin[i] = low[i] = belong[i] = 0;
  while (s.size()) s.pop();
  now_time = scc_cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!belong[i]) dfs(i, 0);
  }
  bool flag = true;
  int root = 0;
  for (int i = 1, to; i <= n && flag; ++i) {
    to = belong[i];
    if (_v[to] && v[i])
      flag = v[i] == _v[to];
    else if (v[i])
      _v[to] = v[i], root = to;
    for (auto it : son[i])
      if (to != belong[it.first]) _son[to].push_back(belong[it.first]);
  }
  if (!flag) {
    puts("0");
    return;
  }
  dfs1(root, 0);
  printf("%d\n", dp[root][1]);
}
int main() {
  int n = read(), k = read();
  int tot = n;
  for (int i = 1, u; i <= n; ++i) {
    v[i] = read();
    if (l[v[i]] && v[i]) {
      u = l[v[i]];
      son[i].push_back({u, tot});
      son[u].push_back({i, tot++});
    }
    l[v[i]] = i;
  }
  for (int i = 1, u, vv; i < n; ++i) {
    u = read(), vv = read();
    son[u].push_back({vv, i}), son[vv].push_back({u, i});
  }
  scc(n);
  return 0;
}
