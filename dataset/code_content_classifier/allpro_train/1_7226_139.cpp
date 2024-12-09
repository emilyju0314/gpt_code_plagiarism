#include <bits/stdc++.h>
using namespace std;
int h, t, R, n, m;
pair<int, int> a[222];
pair<int, int> b[222];
int dp[222][222];
int dis[222][222];
int cal(int h, int t) {
  if (h + t > R) return 0;
  int &ret = dp[h][t];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 1; i <= min(n, h); i++) {
    int nh = h - i + a[i].first;
    int nt = t + a[i].second;
    ret = max(ret, 1 + cal(nh, nt));
  }
  for (int i = 1; i <= min(m, t); i++) {
    int nh = h + b[i].first;
    int nt = t - i + b[i].second;
    ret = max(ret, 1 + cal(nh, nt));
  }
  return ret;
}
int vis[222][222];
void dfs(int h, int t) {
  if (h + t > R) return;
  vis[h][t] = 1;
  for (int i = 1; i <= min(n, h); i++) {
    int nh = h - i + a[i].first;
    int nt = t + a[i].second;
    if (vis[nh][nt] == 1) {
      cout << "Draw" << '\n';
      exit(0);
    }
    if (vis[nh][nt] == 0) dfs(nh, nt);
  }
  for (int i = 1; i <= min(m, t); i++) {
    int nh = h + b[i].first;
    int nt = t - i + b[i].second;
    if (vis[nh][nt] == 1) {
      cout << "Draw" << '\n';
      exit(0);
    }
    if (vis[nh][nt] == 0) dfs(nh, nt);
  }
  vis[h][t] = 2;
}
void bfs(int h, int t) {
  queue<pair<int, int> > q;
  q.push({h, t});
  dis[h][t] = 0;
  vis[h][t] = 1;
  while (!q.empty()) {
    h = q.front().first;
    t = q.front().second;
    q.pop();
    if (h + t > R) continue;
    for (int i = 1; i <= min(n, h); i++) {
      int nh = h - i + a[i].first;
      int nt = t + a[i].second;
      if (nh + nt > R) continue;
      if (vis[nh][nt]) continue;
      q.push({nh, nt});
      dis[nh][nt] = dis[h][t] + 1;
      vis[nh][nt] = 1;
    }
    for (int i = 1; i <= min(m, t); i++) {
      int nh = h + b[i].first;
      int nt = t - i + b[i].second;
      if (nh + nt > R) continue;
      if (vis[nh][nt]) continue;
      q.push({nh, nt});
      dis[nh][nt] = dis[h][t] + 1;
      vis[nh][nt] = 1;
    }
  }
  if (vis[0][0]) {
    cout << "Ivan" << '\n';
    cout << dis[0][0] << '\n';
    exit(0);
  }
  memset(vis, 0, sizeof vis);
}
int main() {
  cin >> h >> t >> R;
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
    int nh = h - i + a[i].first;
    int nt = t + a[i].second;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &b[i].first, &b[i].second);
    int nh = h + b[i].first;
    int nt = t - i + b[i].second;
  }
  bfs(h, t);
  dfs(h, t);
  memset(dp, -1, sizeof dp);
  cout << "Zmey" << '\n';
  cout << cal(h, t) << '\n';
}
