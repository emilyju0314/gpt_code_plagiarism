#include <bits/stdc++.h>
using namespace std;
const int N = 550000;
unordered_map<int, int> H[N];
vector<int> cand, adj[N];
int p[N], c[N], pos[N], vis[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (v == p[n]) cand.push_back(u);
    adj[u].push_back(v);
    H[u][v] = 1;
  }
  sort(cand.begin(), cand.end(), [](int x, int y) { return pos[x] > pos[y]; });
  int ans = 0;
  vector<int> stones;
  int removed = 0;
  for (int x : cand) {
    for (int y : adj[x])
      if (pos[y] > pos[x] && y != p[n] && !vis[y]) c[x]++;
    int cur = pos[x];
    if (n - 1 - cur - removed == c[x]) {
      removed++;
      vis[x] = 1;
    }
  }
  cout << removed << endl;
  return 0;
}
