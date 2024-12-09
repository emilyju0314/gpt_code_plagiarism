#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], b[N], dp[N], sz[N], cur[N], ans, cnt, l, r, mid, x, y;
vector<int> g[N];
void dfs1(int v, int pr = -1) {
  sz[v] = 1;
  for (int to : g[v]) {
    if (to != pr) {
      dfs1(to, v);
      sz[v] += sz[to];
    }
  }
}
void dfs2(int v, int pr = -1) {
  int all = 0, mx1 = 0, mx2 = 0;
  for (int to : g[v]) {
    if (to != pr) {
      dfs2(to, v);
      cur[v] += cur[to];
      if (dp[to] == sz[to]) {
        all += sz[to];
      } else if (dp[to] > mx1) {
        mx2 = mx1;
        mx1 = dp[to];
      } else if (dp[to] > mx2) {
        mx2 = dp[to];
      }
    }
  }
  if (!b[v]) {
    dp[v] = 0;
  } else {
    dp[v] = all + mx1 + 1;
    cur[v]++;
  }
  if (n - sz[v] == cnt - cur[v]) {
    all += n - sz[v];
  }
  if (b[v]) {
    ans = max(ans, all + mx1 + mx2 + 1);
  }
}
inline bool check(int x) {
  ans = cnt = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = sz[i] = cur[i] = 0;
    b[i] = a[i] >= x;
    cnt += b[i];
  }
  dfs1(1);
  dfs2(1);
  return ans >= m;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  r = 1e6;
  while (r - l > 1) {
    mid = (r + l) >> 1;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (check(r)) {
    cout << r;
  } else {
    cout << l;
  }
}
