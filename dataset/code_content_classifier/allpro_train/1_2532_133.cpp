#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 5001;
const int INF = 1e9;
vector<int> g[MAXN];
int c[MAXN];
int f = 0;
struct comp {
  int f, s, v;
  comp() {}
  comp(int f1, int s1, int v1) {
    f = f1;
    s = s1;
    v = v1;
  }
};
int s = 0, t = 0;
void dfs(int v, int cc) {
  c[v] = cc + 1;
  if (cc)
    t++;
  else
    s++;
  for (int i : g[v]) {
    if (!c[i])
      dfs(i, cc ^ 1);
    else if (c[i] == c[v])
      f = 1;
  }
}
int ans[MAXN];
void dfs_ans(int v, int cc) {
  ans[v] = cc + 1;
  for (int i : g[v]) {
    if (!ans[i]) dfs_ans(i, cc ^ 1);
  }
}
bitset<5001> dp[MAXN];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  vector<comp> cp;
  for (int i = 0; i < n; i++) {
    if (!c[i]) {
      s = 0, t = 0;
      dfs(i, 0);
      cp.emplace_back(s, t, i);
    }
  }
  if (f) {
    cout << "NO\n";
    return 0;
  }
  dp[0][0] = 1;
  int N = (int)cp.size();
  for (int i = 1; i <= N; i++) {
    dp[i] |= (dp[i - 1] << cp[i - 1].f);
    dp[i] |= (dp[i - 1] << cp[i - 1].s);
  }
  if (!dp[N][n2]) {
    cout << "NO\n";
    return 0;
  }
  int cur = n2;
  for (int i = N; i > 0; i--) {
    int sz = cp[i - 1].f;
    if (cur >= sz && dp[i - 1][cur - sz]) {
      dfs_ans(cp[i - 1].v, 1);
      cur -= sz;
      continue;
    }
    sz = cp[i - 1].s;
    if (cur >= sz && dp[i - 1][cur - sz]) {
      dfs_ans(cp[i - 1].v, 0);
      cur -= sz;
      continue;
    }
    assert(0);
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    if (ans[i] == 1) {
      if (n1) {
        cout << 1;
        n1--;
      } else
        cout << 3;
    } else
      cout << 2;
  }
  cout << '\n';
  return 0;
}
