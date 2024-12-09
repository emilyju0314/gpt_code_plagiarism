#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, m;
set<int> adj[MAXN];
int per[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (int d = 0; d < 100; d++) {
    for (int i = 1; i <= n; i++) {
      per[i] = i;
    }
    random_shuffle(per + 1, per + n + 1);
    per[0] = per[n];
    bool can = true;
    for (int i = 0; i < m; i++) {
      if (adj[per[i]].count(per[i + 1])) can = false;
    }
    if (can) {
      for (int i = 0; i < m; i++) {
        cout << per[i] << ' ' << per[i + 1] << endl;
      }
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
