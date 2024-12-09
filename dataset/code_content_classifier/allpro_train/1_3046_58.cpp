#include <bits/stdc++.h>
using namespace std;
const long long int inf = 9e18;
long long int t, n, m, a, b, c, ans;
vector<long long int> prr, cum(2e5 + 1, 0);
vector<vector<long long int>> dis(2e5 + 1, vector<long long int>(3, 0));
vector<long long int> edges[200001];
vector<bool> rec(2e5 + 1, false);
void bfs(int x, int f) {
  list<int> que;
  rec[x] = true, dis[x][f] = 0;
  que.push_back(x);
  while (!que.empty()) {
    x = que.front();
    que.pop_front();
    ;
    for (int i = 0; i < edges[x].size(); i++)
      if (!rec[edges[x][i]])
        dis[edges[x][i]][f] = dis[x][f] + 1, rec[edges[x][i]] = true,
        que.push_back(edges[x][i]);
  }
}
void solve() {
  prr.clear(), ans = inf;
  cin >> n >> m >> a >> b >> c;
  ;
  for (int i = 0; i < m; i++) cum[i] = 0;
  ;
  for (int i = 0; i < n; i++) edges[i].clear();
  ;
  for (int i = 0; i < n; i++) dis[i][0] = dis[i][1] = dis[i][2] = 0;
  prr.resize(m), a--, b--, c--;
  ;
  for (int i = 0; i < m; i++) cin >> prr[i];
  sort(prr.begin(), prr.end());
  cum[0] = prr[0];
  ;
  for (int i = 1; i < m; i++) cum[i] = cum[i - 1] + prr[i];
  ;
  for (int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    x--, y--;
    edges[x].push_back(y), edges[y].push_back(x);
  }
  bfs(a, 0);
  ;
  for (int i = 0; i < n; i++) rec[i] = false;
  bfs(b, 1);
  ;
  for (int i = 0; i < n; i++) rec[i] = false;
  bfs(c, 2);
  ;
  for (int i = 0; i < n; i++) rec[i] = false;
  ;
  for (int i = 0; i < n; i++) {
    if (dis[i][0] + dis[i][1] + dis[i][2] - 1 >= m) continue;
    if (dis[i][0] + dis[i][1] + dis[i][2] - 1 < 0) ans = 0;
    if (i == b)
      ans = min(ans, cum[dis[i][0] + dis[i][2] - 1]);
    else
      ans = min(
          ans, cum[dis[i][0] + dis[i][1] + dis[i][2] - 1] + cum[dis[i][1] - 1]);
  }
  cout << ans << "\n";
}
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> t;
  while (t--) {
    solve();
  }
}
