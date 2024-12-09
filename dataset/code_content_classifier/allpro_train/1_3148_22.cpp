#include <bits/stdc++.h>
using namespace std;
long long dis_up[300006];
long long dis_down[300006];
long long mark[300006];
vector<long long> v[300006];
void dfs(long long root, long long par) {
  for (auto it : v[root]) {
    if (it == par) continue;
    dfs(it, root);
    if (dis_down[it] > 0) {
      dis_down[root] = max(dis_down[it] + 1LL, dis_down[root]);
    }
    if (mark[it] == 1) {
      dis_down[root] = max(1LL, dis_down[root]);
    }
  }
}
void dfs2(long long root, long long par) {
  long long max1 = 0, max2 = 0;
  long long ok = 0;
  for (auto it : v[root]) {
    if (it != par) {
      if (dis_up[root] > 0)
        dis_up[it] = max(dis_up[it], dis_up[root] + 1);
      else if (mark[root])
        dis_up[it] = max(dis_up[it], 1LL);
      if (mark[it]) ok++;
      if (dis_down[it] >= max1) {
        max2 = max1;
        max1 = dis_down[it];
      } else {
        max2 = max(dis_down[it], max2);
      }
    }
  }
  for (auto it : v[root]) {
    if (it != par) {
      if (ok > 1) {
        dis_up[it] = max(dis_up[it], 2LL);
      } else if (ok == 1) {
        if (!mark[it]) dis_up[it] = max(dis_up[it], 2LL);
      }
      if (dis_down[it] == max1)
        dis_up[it] =
            max(dis_up[it], max2 == 0 ? 0 : max(dis_up[it], (max2 + 2)));
      else
        dis_up[it] = max(dis_up[it], max1 == 0 ? 0 : (max1 + 2));
      dfs2(it, root);
    }
  }
}
void solve() {
  long long n, m, d;
  cin >> n >> m >> d;
  for (long long i = 0; i < m; i++) {
    long long a;
    cin >> a;
    mark[a] = 1;
  }
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dis_up[0] = dis_up[1] = -2000000000000000005;
  dfs(1, 0);
  dfs2(1, 0);
  long long ans = 0;
  cout << "\n";
  for (long long i = 1; i <= n; i++) {
    if (dis_up[i] <= d && dis_down[i] <= d) {
      ans++;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
