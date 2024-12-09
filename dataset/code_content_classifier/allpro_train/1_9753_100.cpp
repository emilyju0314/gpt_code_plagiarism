#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100005;
int n, cnt;
vector<int> G[MaxN], ans;
map<vector<int>, int> fm;
map<pair<int, int>, int> mf;
int dfs(int x, int f) {
  if (mf.count({x, f})) return mf[{x, f}];
  vector<int> now;
  for (int nxt : G[x])
    if (nxt != f) now.emplace_back(dfs(nxt, x));
  sort(now.begin(), now.end());
  if (!fm.count(now)) fm[now] = ++cnt;
  return mf[{x, f}] = fm[now];
}
void Init() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) sort(G[i].begin(), G[i].end());
}
void Main() {
  for (int i = 1; i <= n; ++i)
    if (G[i].size() < 4) {
      ans.emplace_back(dfs(i, 0));
    }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << ans.size() << endl;
}
int main() {
  Init();
  Main();
  return 0;
}
