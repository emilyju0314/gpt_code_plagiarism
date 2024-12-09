#include <bits/stdc++.h>
int B = 400;
using namespace std;
const long long inf = 1e18;
int MOD = 1e9 + 7;
const int mxn = 200010;
vector<pair<long long, long long> > g[mxn];
int n, k;
bool chk(long long dis) {
  queue<int> q;
  int deg[mxn] = {0};
  long long W[mxn] = {0};
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) q.push(i);
    if (g[i].size() > 2) cnt++;
    deg[i] = (int)(g[i].size());
  }
  int vis[mxn] = {0};
  int remain = n;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < g[x].size(); i++) {
      int u = g[x][i].first, wt = g[x][i].second;
      if (vis[u]) continue;
      if (wt + W[x] > dis) continue;
      W[u] = max(W[u], wt + W[x]);
      deg[u]--;
      if (deg[u] == 2) cnt--;
      remain--;
      vis[x] = 1;
      if (deg[u] == 1) q.push(u);
    }
  }
  return (cnt == 0 && remain <= k);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  long long sum = 0;
  for (int i = 0; i < n - 1; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back(make_pair(b, w));
    g[b].push_back(make_pair(a, w));
    sum += w;
  }
  long long hi = sum, lo = 0;
  long long ans = 0;
  while (hi >= lo) {
    long long mid = (hi + lo) / 2;
    if (chk(mid))
      hi = mid - 1, ans = mid;
    else
      lo = mid + 1;
  }
  cout << ans << endl;
}
